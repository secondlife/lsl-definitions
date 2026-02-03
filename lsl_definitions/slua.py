"""SLua (Server Lua) data models and parser."""

from __future__ import annotations

import abc
import dataclasses
import re
from typing import TYPE_CHECKING, Any, List, Literal, Optional, Set, TextIO

import llsd
import yaml

from lsl_definitions.utils import escape_python, remove_worthless

if TYPE_CHECKING:
    from lsl_definitions.lsl import LSLDefinitions


@dataclasses.dataclass
class SLuaProperty:
    """Property definition"""

    name: str
    type: str
    value: str | None = None
    comment: str = ""
    slua_removed: bool = False
    """This property is in Luau but not SLua"""
    private: bool = False
    """Whether this should this be included in the syntax file"""
    modifiable: Literal["read-only", "new-fields", "override-fields", "full-write"] = "read-only"
    """https://kampfkarren.github.io/selene/usage/std.html#properties"""

    def to_keywords_dict(self) -> dict:
        return {
            "tooltip": self.comment,
            "type": self.type,
            **({"value": escape_python(self.value)} if self.value is not None else {}),
        }

    def to_luau_def(self) -> str:
        return f"{self.name}: {self.type}"


@dataclasses.dataclass
class SLuaParameter:
    """
    Function/method parameter
    - Regular parameters require both name and type
    - Self parameters only need name (type is implicit)
    - Variadic parameters need name "..." and type
    """

    name: str
    type: Optional[str] = None
    selene_type: Any = None
    """a custom Selene type for this parameter, in case auto-detection fails"""
    comment: str = ""
    optional: bool | None = None
    observes: Literal["read-write", "read", "write"] | None = None
    """See https://kampfkarren.github.io/selene/usage/std.html#observes."""

    def to_luau_def(self) -> str:
        if self.type is None:
            return self.name
        elif self.name == "...":
            return self.type
        else:
            return f"{self.name}: {self.type}"


@dataclasses.dataclass
class SLuaFunctionBase(abc.ABC):
    name: str = ""
    typeParameters: List[str] = dataclasses.field(default_factory=list)
    parameters: List[SLuaParameter] = dataclasses.field(default_factory=list)
    returnType: str = "()"
    comment: str = ""

    @property
    def type_parameters_string(self) -> str:
        if not self.typeParameters:
            return ""
        return "<" + ", ".join(self.typeParameters) + ">"

    @property
    def parameters_string(self) -> str:
        return "(" + ", ".join(p.to_luau_def() for p in self.parameters) + ")"

    @property
    def type_def_string(self) -> str:
        return self.type_parameters_string + self.parameters_string + " -> " + self.returnType


@dataclasses.dataclass
class SLuaFunctionOverload(SLuaFunctionBase):
    pass


@dataclasses.dataclass
class SLuaFunction(SLuaFunctionBase):
    """Full function or method signature with optional overloads"""

    private: bool = False
    deprecated: bool = False
    must_use: bool = False
    """Emit a warning if the return value is not used.
    See https://kampfkarren.github.io/selene/usage/std.html#must_use."""
    overloads: List[SLuaFunctionOverload] = dataclasses.field(default_factory=list)

    @property
    def deprecated_string(self) -> str:
        if not self.deprecated:
            return ""
        return "@deprecated "

    def to_keywords_dict(self) -> dict:
        return remove_worthless(
            {
                "type-arguments": self.typeParameters,
                "arguments": [
                    {
                        a.name: {
                            "tooltip": a.comment,
                            "type": a.type,
                        }
                    }
                    for a in self.parameters
                ],
                "deprecated": self.deprecated,
                "energy": 10.0,
                "return": self.returnType,
                "sleep": 0.0,
                "tooltip": self.comment,
            }
        )

    def write_luau_global_def(self, f: TextIO, indent: int = 0) -> None:
        """For declaring global functions and class/extern type methods"""
        if self.overloads:
            # the function format can't handle overloads
            self.write_luau_table_def(f, indent, suffix="")
        else:
            f.write(f"{'  ' * indent}")
            f.write(self.deprecated_string)
            f.write(f"function {self.name}")
            f.write(self.type_parameters_string)
            f.write(self.parameters_string)
            f.write(f": {self.returnType}\n")

    def write_luau_table_def(self, f: TextIO, indent: int = 0, suffix=",") -> None:
        """For declaring functions within a table/module"""
        f.write(f"{'  ' * indent}{self.name}: ")
        f.write(self.deprecated_string)
        if not self.overloads:
            f.write(self.type_def_string)
        else:
            f.write("(")
            f.write(self.type_def_string)
            for overload in self.overloads:
                f.write(f")\n{'  ' * (indent + 1)}& (")
                f.write(overload.type_def_string)
            f.write(")")
        f.write(suffix)
        f.write("\n")


@dataclasses.dataclass
class SLuaTypeAlias:
    """Type alias definition"""

    name: str
    definition: str
    selene_type: Any
    comment: str = ""
    export: bool = False
    """Whether this type is available to users"""

    def to_keywords_dict(self) -> dict:
        definition = self.to_luau_def()
        if len(definition) > 200:
            definition = ""
        return {
            "tooltip": f"{self.comment}\n{definition}".strip(),
        }

    def to_luau_def(self) -> str:
        export_str = "export " if self.export else ""
        return f"{export_str}type {self.name} = {self.definition}"


@dataclasses.dataclass
class SLuaClassDeclaration:
    """Class declaration with properties and methods"""

    name: str
    properties: List[SLuaProperty]
    methods: List[SLuaFunction]
    comment: str = ""

    def to_keywords_dict(self) -> dict:
        return {"tooltip": self.comment}

    def write_luau_def(self, f: TextIO) -> None:
        f.write(f"declare extern type {self.name} with\n")
        for prop in self.properties:
            f.write(f"  {prop.to_luau_def()}\n")
        for func in self.methods:
            func.write_luau_global_def(f, indent=1)
        f.write("end\n\n")


@dataclasses.dataclass
class SLuaModule:
    """Module declaration with constants and functions"""

    name: str
    callable: Optional[SLuaFunction]
    constants: List[SLuaProperty]
    functions: List[SLuaFunction]
    comment: str = ""

    def to_keywords_functions_dict(self) -> dict:
        functions = {}
        if self.callable:
            functions[self.name] = self.callable.to_keywords_dict()
        else:
            functions[self.name] = {"energy": -1.0, "tooltip": self.comment}
        functions.update(
            {
                f"{self.name}.{func.name}": func.to_keywords_dict()
                for func in sorted(self.functions, key=lambda x: x.name)
                if not func.private
            }
        )
        return functions

    def to_keywords_constants_dict(self) -> dict:
        return {
            f"{self.name}.{prop.name}": prop.to_keywords_dict()
            for prop in sorted(self.constants, key=lambda x: x.name)
        }

    def write_luau_def(self, f: TextIO) -> None:
        f.write(f"""
---------------------------
-- Global Table: {self.name}
---------------------------

declare {self.name}: """)
        if self.callable:
            f.write("(")
            f.write(self.callable.type_def_string)
            f.write(") & ")
        f.write("{\n")
        for prop in self.constants:
            f.write(f"  {prop.to_luau_def()},\n")
        for func in self.functions:
            if func.private:
                continue
            func.write_luau_table_def(f, indent=1)
        f.write("}\n\n")


@dataclasses.dataclass
class SLuaDefinitions:
    """Parsed SLua definitions with type validation."""

    # 1. Luau builtins. Typecheckers already know about these
    controls: dict  # same structure as LSLDefinitions.controls
    builtinTypes: dict  # same structure as LSLDefinitions.types
    builtinConstants: List[SLuaProperty]
    builtinFunctions: List[SLuaFunction]

    # 2. SLua base classes. These only depend on Luau builtins
    baseClasses: List[SLuaClassDeclaration]
    typeAliases: List[SLuaTypeAlias]

    # 3. SLua standard library. Depends on base classes
    classes: List[SLuaClassDeclaration]
    globalFunctions: List[SLuaFunction]
    modules: List[SLuaModule]
    globalVariables: List[SLuaProperty]
    globalConstants: List[SLuaProperty]

    # All known type names, populated by parser
    type_names: Set[str] = dataclasses.field(default_factory=set)

    _TYPE_SEPERATORS_RE = re.compile(
        r"[ \n?&|,{}\[\]()]|\.\.\.|typeof|->|[a-zA-Z0-9_]*:|\"[a-zA-Z0-9_]*\""
    )

    def validate_type(self, type_str: str, known_type_names: Set[str] | None = None) -> str:
        """Validate that a type string only references known types."""
        if not type_str:
            raise ValueError("Type may not be empty")
        if known_type_names is None:
            known_type_names = self.type_names
        if type_str in known_type_names:
            return type_str
        subtypes = self._TYPE_SEPERATORS_RE.split(type_str)
        unknown_subtypes = set(subtypes) - known_type_names - {""}
        if not unknown_subtypes:
            return type_str
        raise ValueError(f"Unknown types {unknown_subtypes} in definition {type_str!r}")

    def validate_type_params(self, type_params: List[str]) -> Set[str]:
        """Validate type parameters and return the set of known types including them."""
        known_types = set(self.type_names)
        for type_param in type_params:
            type_param = type_param.replace("...", "", 1)
            if not re.match(r"\A[_a-zA-Z][_a-zA-Z0-9]*\Z", type_param):
                raise ValueError(f"{type_param!r} is not a valid identifier")
            if type_param in known_types:
                raise ValueError(f"{type_param!r} is already defined")
            known_types.add(type_param)
        return known_types

    def generate_ll_modules(self, lsl: "LSLDefinitions") -> None:
        """Generate ll and llcompat module content from LSL definitions."""
        LLDetectedEventName_alias = next(
            m for m in self.typeAliases if m.name == "LLDetectedEventName"
        )
        LLNonDetectedEventName_alias = next(
            m for m in self.typeAliases if m.name == "LLNonDetectedEventName"
        )
        LLEventName_alias = next(m for m in self.typeAliases if m.name == "LLEventName")
        LLEvents_class = next(m for m in self.classes if m.name == "LLEvents")

        for event in lsl.events.values():
            if event.slua_removed:
                continue
            event_func = SLuaFunction(
                name=event.name,
                comment=event.tooltip,
                deprecated=event.deprecated or event.slua_deprecated,
                parameters=[
                    SLuaParameter(
                        name=a.name,
                        comment=a.tooltip,
                        type=self.validate_type(a.compute_slua_type()),
                    )
                    for a in event.arguments
                ],
            )
            if event.detected_semantics:
                LLDetectedEventName_alias.selene_type.append(event.name)
                type_def = "LLDetectedEventHandler?"
            else:
                LLNonDetectedEventName_alias.selene_type.append(event.name)
                type_def = event_func.type_def_string
                overload_parameters = [
                    SLuaParameter("self", type="LLEvents"),
                    SLuaParameter("event", type=f'"{event.name}"'),
                    SLuaParameter("callback", type=type_def),
                ]
                for register_func in LLEvents_class.methods:
                    if register_func.name in {"on", "once"}:
                        register_func.overloads.append(
                            SLuaFunctionOverload(
                                name=register_func.name,
                                comment=event.tooltip,
                                parameters=overload_parameters,
                                returnType=type_def,
                            )
                        )
                    elif register_func.name == "off":
                        register_func.overloads.append(
                            SLuaFunctionOverload(
                                name=register_func.name,
                                comment=event.tooltip,
                                parameters=overload_parameters,
                                returnType=register_func.returnType,
                            )
                        )
                type_def = f"({type_def})?"
            event_prop = SLuaProperty(
                name=event.name,
                comment=event.tooltip,
                type=type_def,
                modifiable="override-fields",
            )
            LLEvents_class.properties.append(event_prop)

        LLDetectedEventName_alias.definition = " | ".join(
            f'"{name}"' for name in LLDetectedEventName_alias.selene_type
        )
        LLNonDetectedEventName_alias.definition = " | ".join(
            f'"{name}"' for name in LLNonDetectedEventName_alias.selene_type
        )
        LLEventName_alias.selene_type = (
            LLDetectedEventName_alias.selene_type + LLNonDetectedEventName_alias.selene_type
        )
        for register_func in LLEvents_class.methods:
            if register_func.name in {"off", "on", "once"}:
                register_func.parameters = [
                    SLuaParameter("self", type="LLEvents"),
                    SLuaParameter("event", type="LLDetectedEventName"),
                    SLuaParameter("callback", type="LLDetectedEventHandler"),
                ]
            if register_func.name in {"on", "once"}:
                register_func.returnType = "LLDetectedEventHandler"

        ll_module = next(m for m in self.modules if m.name == "ll")
        llcompat_module = next(m for m in self.modules if m.name == "llcompat")
        DetectedEvent_class = next(m for m in self.baseClasses if m.name == "DetectedEvent")

        for func in lsl.functions.values():
            if func.private:
                continue
            known_types = self.validate_type_params(func.type_arguments)
            ll_func = SLuaFunction(
                name=func.compute_slua_name(with_module=False),
                comment=func.tooltip,
                deprecated=func.deprecated or func.slua_deprecated or func.detected_semantics,
                typeParameters=func.type_arguments,
                parameters=[
                    SLuaParameter(
                        name=a.name,
                        comment=a.tooltip,
                        type=self.validate_type(a.compute_slua_type(), known_types),
                    )
                    for a in func.arguments
                ],
                returnType=self.validate_type(func.compute_slua_type(), known_types),
                must_use=func.must_use or func.pure,
            )
            llcompat_func = SLuaFunction(
                name=ll_func.name,
                comment=ll_func.comment,
                deprecated=True,
                typeParameters=ll_func.typeParameters,
                parameters=ll_func.parameters,
                returnType=self.validate_type(func.compute_slua_type(llcompat=True), known_types),
                must_use=ll_func.must_use,
            )
            if not func.slua_removed:
                ll_module.functions.append(ll_func)
            llcompat_module.functions.append(llcompat_func)
            if func.detected_semantics:
                name = ll_func.name.replace("Detected", "Get")
                name = name[0].lower() + name[1:]
                detected_func = SLuaFunction(
                    name=name,
                    comment=ll_func.comment,
                    deprecated=False,
                    typeParameters=ll_func.typeParameters,
                    parameters=ll_func.parameters[:],
                    returnType=ll_func.returnType,
                    must_use=ll_func.must_use,
                )
                detected_func.parameters[0] = SLuaParameter(name="self")
                DetectedEvent_class.methods.append(detected_func)

        for const in lsl.constants.values():
            if const.slua_removed:
                continue
            prop = SLuaProperty(
                name=const.name,
                comment=const.tooltip,
                type=self.validate_type(const.slua_type or const.type.meta.slua_name),
                value=const.value,
                private=const.private,
            )
            self.globalConstants.append(prop)


class SLuaDefinitionParser:
    def __init__(self):
        self._type_names: Set[str] = set()
        self._global_scope: Set[str] = set()

    def parse_file(self, name: str) -> SLuaDefinitions:
        if name.endswith(".llsd"):
            return self._parse_llsd_file(name)
        return self._parse_yaml_file(name)

    def _parse_yaml_file(self, name: str) -> SLuaDefinitions:
        with open(name, "rb") as f:
            return self._parse_dict(yaml.safe_load(f.read()))

    def _parse_llsd_file(self, name: str) -> SLuaDefinitions:
        with open(name, "rb") as f:
            return self._parse_llsd_blob(f.read())

    def _parse_llsd_blob(self, llsd_blob: bytes) -> SLuaDefinitions:
        return self._parse_dict(llsd.parse_xml(llsd_blob))

    def _parse_dict(self, def_dict: dict) -> SLuaDefinitions:
        # 1. Luau builtins
        builtin_types = dict(def_dict["builtinTypes"])
        self._type_names.update(builtin_types.keys())

        controls = dict(def_dict["controls"])
        self._global_scope.update(controls.keys())

        # nil, true, false are also valid type literals
        self._type_names.update(const["name"] for const in def_dict["builtinConstants"])
        builtin_constants = [
            self._validate_property(const, self._global_scope, const=True)
            for const in def_dict["builtinConstants"]
        ]
        builtin_functions = [
            self._validate_function(func, self._global_scope)
            for func in def_dict["builtinFunctions"]
        ]

        # 2. SLua base classes
        base_classes = [self._validate_class(class_) for class_ in def_dict["baseClasses"]]
        type_aliases = [self._validate_type_alias(alias) for alias in def_dict["typeAliases"]]

        # 3. SLua standard library
        classes = [self._validate_class(class_) for class_ in def_dict["classes"]]
        global_functions = [
            self._validate_function(func, self._global_scope)
            for func in def_dict["globalFunctions"]
        ]
        modules = [self._validate_module(module) for module in def_dict["modules"]]
        global_variables = [
            self._validate_property(const, self._global_scope)
            for const in def_dict["globalVariables"]
        ]

        return SLuaDefinitions(
            controls=controls,
            builtinTypes=builtin_types,
            builtinConstants=builtin_constants,
            builtinFunctions=builtin_functions,
            baseClasses=base_classes,
            typeAliases=type_aliases,
            classes=classes,
            globalFunctions=global_functions,
            modules=modules,
            globalVariables=global_variables,
            globalConstants=[],
            type_names=self._type_names,
        )

    def _validate_module(self, data: dict) -> SLuaModule:
        module = SLuaModule(
            name=data["name"],
            comment=data.get("comment", ""),
            callable=None,
            constants=[],
            functions=[],
        )
        try:
            self._validate_identifier(module.name)
            self._validate_scope(module.name, self._global_scope)
            module_scope: Set[str] = set()
            callable = data.get("callable")
            if callable is not None:
                module.callable = self._validate_function(callable, module_scope)
                if module.callable.name != module.name:
                    raise ValueError("module.callable.name must match module.name")
                module_scope.clear()
            module.constants = [
                self._validate_property(prop, module_scope, const=True)
                for prop in data.get("constants", [])
            ]
            module.functions = [
                self._validate_function(function, module_scope)
                for function in data.get("functions", [])
            ]
        except Exception as e:
            raise ValueError(f"In module {module.name}: {e}") from e
        return module

    def _validate_class(self, data: dict) -> SLuaClassDeclaration:
        class_ = SLuaClassDeclaration(
            name=data["name"],
            comment=data.get("comment", ""),
            properties=[],
            methods=[],
        )
        try:
            self._validate_identifier(class_.name)
            self._validate_scope(class_.name, self._type_names)
            class_scope: Set[str] = set()
            class_.properties = [
                self._validate_property(prop, class_scope) for prop in data.get("properties", [])
            ]
            class_.methods = [
                self._validate_function(method, class_scope, class_name=class_.name)
                for method in data.get("methods", [])
            ]
        except Exception as e:
            raise ValueError(f"In class {class_.name}: {e}") from e
        return class_

    def _validate_function(
        self, data: dict, scope: Set[str], class_name: str | None = None
    ) -> SLuaFunction:
        try:
            func = SLuaFunction(
                name=data["name"],
                typeParameters=data.get("typeParameters", []),
                parameters=[
                    SLuaParameter(selene_type=p.pop("selene-type", None), **p)
                    for p in data.get("parameters", [])
                ],
                returnType=data.get("returnType", "()"),
                comment=data.get("comment", ""),
                deprecated=data.get("deprecated", False),
                private=data.get("private", False),
                must_use=data.get("must-use", False),
            )
            self._validate_identifier(func.name)
            self._validate_scope(func.name, scope)
            self._validate_function_signature(func, class_name)
            known_types = self._validate_type_params(func.typeParameters)
            self._validate_type(func.returnType, known_types)
            for overload_data in data.get("overloads", []):
                overload = SLuaFunctionOverload(
                    name=func.name,
                    typeParameters=overload_data.get("typeParameters", []),
                    parameters=[
                        SLuaParameter(selene_type=p.pop("selene-type", None), **p)
                        for p in overload_data.get("parameters", [])
                    ],
                    returnType=overload_data.get("returnType", "()"),
                    comment=overload_data.get("comment", ""),
                )
                self._validate_function_signature(overload)
                func.overloads.append(overload)
            return func
        except Exception as e:
            raise ValueError(f"In function {data['name']}: {e}") from e

    def _validate_type_alias(self, data: dict) -> SLuaTypeAlias:
        alias = SLuaTypeAlias(selene_type=data.pop("selene-type"), **data)
        try:
            self._validate_identifier(alias.name)
            self._validate_type(alias.definition)
            # add it to scope only after validating type, to ensure it isn't recursive
            self._validate_scope(alias.name, self._type_names)
        except Exception as e:
            raise ValueError(f"In type alias {alias.name}: {e}") from e
        return alias

    def _validate_property(self, data: dict, scope: Set[str], const: bool = False) -> SLuaProperty:
        prop = SLuaProperty(slua_removed=data.pop("slua-removed", False), **data)
        self._validate_identifier(prop.name)
        self._validate_scope(prop.name, scope)
        if const and prop.type != "any" and prop.value is None:
            raise ValueError(f"Constant {prop.name} must have a value")
        self._validate_type(prop.type)
        return prop

    def _validate_function_signature(
        self, func: SLuaFunctionBase, class_name: str | None = None
    ) -> None:
        known_types = self._validate_type_params(func.typeParameters)
        self._validate_type(func.returnType, known_types)
        params = func.parameters
        params_scope: Set[str] = set()
        if class_name is not None:
            if not (
                params
                and params[0].name == "self"
                and (params[0].type is None or params[0].type == class_name)
            ):
                raise ValueError(f"Method {func.name} missing self parameter")
            params_scope.add("self")
            params = params[1:]
        if params and params[-1].name == "...":
            self._validate_type(params[-1].type, known_types)
            params = params[:-1]
        for param in params:
            self._validate_identifier(param.name)
            self._validate_scope(param.name, params_scope)
            self._validate_type(param.type, known_types)

    def _validate_type_params(self, type_params: List[str]) -> Set[str]:
        known_types = set(self._type_names)
        for type_param in type_params:
            type_param = type_param.replace("...", "", 1)
            self._validate_identifier(type_param)
            self._validate_scope(type_param, known_types)
        return known_types

    _TYPE_SEPERATORS_RE = re.compile(
        r"[ \n?&|,{}\[\]()]|\.\.\.|typeof|->|[a-zA-Z0-9_]*:|\"[a-zA-Z0-9_]*\""
    )

    def _validate_type(self, type_str: str, known_type_names: Set[str] | None = None) -> str:
        if not type_str:
            raise ValueError("Type may not be empty")
        if known_type_names is None:
            known_type_names = self._type_names
        if type_str in known_type_names:
            return type_str
        subtypes = self._TYPE_SEPERATORS_RE.split(type_str)
        unknown_subtypes = set(subtypes) - known_type_names - {""}
        if not unknown_subtypes:
            return type_str
        raise ValueError(f"Unknown types {unknown_subtypes} in definition {type_str!r}")

    def _validate_scope(self, name: str, scope: Set[str]) -> None:
        if name in scope:
            raise ValueError(f"{name!r} is already defined in this scope")
        scope.add(name)

    _IDENTIFIER_RE = re.compile(r"\A[_a-zA-Z][_a-zA-Z0-9]*\Z")

    def _validate_identifier(self, name: str) -> None:
        if not re.match(self._IDENTIFIER_RE, name):
            raise ValueError(f"{name!r} is not a valid identifier")
