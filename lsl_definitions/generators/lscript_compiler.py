"""Generators for lscript compiler files (lexer, parser, tree nodes, C++ constants)."""

from __future__ import annotations

from lsl_definitions.generators.base import register
from lsl_definitions.lsl import LSLArgument, LSLDefinitions, LSLEvent, LSLType
from lsl_definitions.utils import splice_str, to_c_str

_LEXER_CONST_COMMENT = "/* GENERATED LEXER CONSTANTS */"
_LEXER_EVENT_COMMENT = "/* GENERATED LEXER EVENTS */"
_LEXER_COORD_TEMPLATE = '"%(name)s" { count(); return(%(name)s); }\n'
_LEXER_NUMERIC_TEMPLATE = '"%s" { count(); yylval.%sval = %s; return(%s); }\n'
_LEXER_STR_TEMPLATE = (
    '"%s" { yylval.sval = new char[%d]; strcpy(yylval.sval, "%s"); return(STRING_CONSTANT); }\n'
)
_LEXER_BLACKLIST = {
    # These are special in the lexer for inexplicable reasons.
    "TRUE",
    "FALSE",
    # These events have weird names :(
    "listen",
    "changed",
    "linkset_data",
    "on_rez",
}


@register("gen_lexer_file")
def gen_lexer_file(definitions: LSLDefinitions, template_path: str) -> str:
    """Generate lexer bits for indra.in.l"""
    with open(template_path, "r") as f:
        lexer_template = f.read()

    generated_events = ""
    for event in definitions.events.values():
        if event.name in _LEXER_BLACKLIST:
            continue
        generated_events += '"%s" { count(); return(%s); }\n' % (event.name, event.name.upper())
    lexer_template = splice_str(lexer_template, _LEXER_EVENT_COMMENT, generated_events)

    generated_constants = ""
    for const in definitions.constants.values():
        if const.name in _LEXER_BLACKLIST:
            continue

        if const.type in (LSLType.VECTOR, LSLType.ROTATION):
            # We can't easily generate constant definitions for these, they
            # _must_ be manually defined in the parser as well. Just generate the boilerplate
            # to pull in their definition from the parser.
            generated_constants += _LEXER_COORD_TEMPLATE % {"name": const.name}
        elif const.type == LSLType.FLOAT:
            generated_constants += _LEXER_NUMERIC_TEMPLATE % (
                const.name,
                "f",
                const.value + "f",
                "FP_CONSTANT",
            )
        elif const.type == LSLType.INTEGER:
            generated_constants += _LEXER_NUMERIC_TEMPLATE % (
                const.name,
                "i",
                const.value,
                "INTEGER_CONSTANT",
            )
        elif const.type == LSLType.STRING:
            c_str = to_c_str(const.value)
            c_str_len = len(const.value.encode("utf8")) + 1
            generated_constants += _LEXER_STR_TEMPLATE % (const.name, c_str_len, c_str)
        else:
            raise ValueError(f"Unknown constant type {const.type!r}")
    lexer_template = splice_str(lexer_template, _LEXER_CONST_COMMENT, generated_constants)

    return lexer_template


_PARSER_EVENT_SWITCH_COMMENT = "/* GENERATED PARSER EVENT SWITCH */"
_PARSER_EVENT_TYPES_COMMENT = "/* GENERATED PARSER EVENT TYPES */"
_PARSER_EVENT_TOKENS_COMMENT = "/* GENERATED PARSER EVENT TOKENS */"
_PARSER_EVENT_DEFINITIONS_COMMENT = "/* GENERATED PARSER EVENT DEFINITIONS */"

# These have weird idiosyncrasies in their existing naming conventions, don't generate.
_PARSER_TYPES_BLACKLIST = {
    "listen",
    "on_rez",
    "linkset_data",
    "changed",
}
_PARSER_DEFINITIONS_BLACKLIST = {
    "listen",
    "on_rez",
    "linkset_data",
    "changed",
    "at_target",
    "not_at_target",
    "at_rot_target",
    "not_at_rot_target",
    "run_time_permissions",
    "experience_permissions",
    "experience_permissions_denied",
    "remote_data",
}


def _event_to_class_name(event: LSLEvent) -> str:
    return event.name.title().replace("_", "").replace("Http", "HTTP")


@register("gen_parser_file")
def gen_parser_file(definitions: LSLDefinitions, template_path: str) -> str:
    """Generate parser bits for indra.in.y"""
    with open(template_path, "r") as f:
        parser_template: str = f.read()

    generated_event_tokens = ""
    generated_event_types = ""
    generated_event_definitions = ""
    generated_event_switch = ""

    for event in definitions.events.values():
        if event.name not in _PARSER_TYPES_BLACKLIST:
            generated_event_tokens += f"%token    {event.name.upper()}\n"
            generated_event_types += f"%type<event>    {event.name}\n"
            generated_event_switch += (
                """
    | %s compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }
"""
                % event.name
            )
        if event.name not in _PARSER_DEFINITIONS_BLACKLIST:
            generated_event_definitions += f"{event.name}\n"
            generated_event_definitions += f"    : {event.name.upper()} '(' "

            # Generate the header with args
            first_arg = True
            for arg in event.arguments:
                if not first_arg:
                    generated_event_definitions += " ',' "
                type_token = str(arg.type).upper()
                type_token = {
                    "KEY": "LLKEY",
                    "ROTATION": "QUATERNION",
                }.get(type_token, type_token)
                generated_event_definitions += f"{type_token} IDENTIFIER "
                first_arg = False
            generated_event_definitions += " ')'\n    {\n"

            # Now for the body
            arg_idx = 4
            for i, arg in enumerate(event.arguments):
                generated_event_definitions += f"""
        LLScriptIdentifier	*id{i} = new LLScriptIdentifier(gLine, gColumn, ${arg_idx});
        gAllocationManager->addAllocation(id{i});
"""
                arg_idx += 3

            event_class = _event_to_class_name(event)
            arg_str = ", ".join("id%d" % x for x in range(0, len(event.arguments)))
            if arg_str:
                arg_str = ", " + arg_str
            generated_event_definitions += (
                f"        $$ = new LLScript{event_class}Event(gLine, gColumn{arg_str});\n"
            )

            generated_event_definitions += "    }\n    ;\n\n"

    parser_template = splice_str(
        parser_template, _PARSER_EVENT_TOKENS_COMMENT, generated_event_tokens
    )
    parser_template = splice_str(
        parser_template, _PARSER_EVENT_TYPES_COMMENT, generated_event_types
    )
    parser_template = splice_str(
        parser_template, _PARSER_EVENT_SWITCH_COMMENT, generated_event_switch
    )
    parser_template = splice_str(
        parser_template, _PARSER_EVENT_DEFINITIONS_COMMENT, generated_event_definitions
    )

    return parser_template


def _arg_to_member_name(arg: LSLArgument) -> str:
    if arg.name[0].upper() != arg.name[0]:
        return "m" + arg.name.title().replace("_", "")
    # Probably already title case.
    return "m" + arg.name


_TREE_BLACKLIST = {
    # Basically everything, except state_entry() and game_control(),
    # New events are not meant to be in here, this is just meant to reduce
    # a huge diff churn.
    "link_message",
    "touch_start",
    "dataserver",
    "transaction_result",
    "at_target",
    "experience_permissions_denied",
    "http_response",
    "not_at_rot_target",
    "at_rot_target",
    "remote_data",
    "path_update",
    "listen",
    "money",
    "email",
    "run_time_permissions",
    "not_at_target",
    "http_request",
    "collision_start",
    "land_collision_end",
    "no_sensor",
    "state_exit",
    "object_rez",
    "experience_permissions",
    "collision",
    "linkset_data",
    "collision_end",
    "attach",
    "touch",
    "timer",
    "changed",
    "sensor",
    "moving_start",
    "touch_end",
    "land_collision",
    "control",
    "on_rez",
    "land_collision_start",
    "moving_end",
}


_TREE_CLASS_DECL_TEMPLATE = """class LLScript%(class_name)sEvent : public LLScriptEvent
{
public:
    LLScript%(class_name)sEvent(S32 line, S32 col%(constructor_args)s)
        : LLScriptEvent(line, col, LSTT_%(event_upper)s)
%(member_initializers)s
    {
    }

    ~LLScript%(class_name)sEvent()
    {
    }

    void recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype,
                 BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count,
                 LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize,
                 LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata);
    S32 getSize();

%(members)s
};

"""


@register("gen_tree_header_file")
def gen_tree_header_file(definitions: LSLDefinitions) -> str:
    """Generate event node class declarations for lscript_tree.h"""
    generated_tree_header = ""
    for event in definitions.events.values():
        if event.name in _TREE_BLACKLIST:
            continue
        constructor_args = "".join(f", LLScriptIdentifier *{x.name}" for x in event.arguments)
        member_initializers = "\n".join(
            f"        , {_arg_to_member_name(x)}({x.name})" for x in event.arguments
        )
        members = "\n".join(
            f"    LLScriptIdentifier *{_arg_to_member_name(x)};" for x in event.arguments
        )
        generated_tree_header += _TREE_CLASS_DECL_TEMPLATE % {
            "class_name": _event_to_class_name(event),
            "event_upper": event.name.upper(),
            "members": members,
            "member_initializers": member_initializers,
            "constructor_args": constructor_args,
        }
    return generated_tree_header


_TREE_CLASS_DEF_TEMPLATE = """
void LLScript%(class_name)sEvent::recurse(
    LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg,
    LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk,
    LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
    if (gErrorToText.getErrors())
    {
        return;
    }
    switch(pass)
    {
    case LSCP_PRETTY_PRINT:
    case LSCP_EMIT_ASSEMBLY:
        fdotabs(fp, tabs, tabsize);
        fprintf(fp, "%(event_name)s( ");
%(emit_assembly)s
        fprintf(fp, " )\\n");
        break;
    case LSCP_SCOPE_PASS1:
      checkForDuplicateHandler(fp, this, scope, "%(event_name)s");
%(scope_pass1)s
        break;
    case LSCP_RESOURCE:
        {
            // we're just tryng to determine how much space the variable needs
            if (%(first_scope_entry)s)
            {
%(resource_scope_entries)s
            }
        }
        break;
    case LSCP_EMIT_BYTE_CODE:
        {
#ifdef LSL_INCLUDE_DEBUG_INFO
            char name[] = "%(event_name)s";
            chunk->addBytes(name, strlen(name) + 1);
%(event_debug_info)s
#endif
        }
        break;
    case LSCP_EMIT_CIL_ASSEMBLY:
        fdotabs(fp, tabs, tabsize);
        fprintf(fp, "%(event_name)s(");
%(emit_cil)s
        fprintf(fp, ")");
        break;
    default:
%(default_recurse)s
        break;
    }
}

S32 LLScript%(class_name)sEvent::getSize()
{
    return %(event_size)d;
}
"""

_RECURSE_BOILERPLATE = (
    "->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, "
    "chunk, heap, stacksize, entry, entrycount, NULL);"
)


@register("gen_tree_source_file")
def gen_tree_source_file(definitions: LSLDefinitions) -> str:
    """Generate event node implementations for lscript_tree.cpp"""
    generated_tree_source = ""
    for event in definitions.events.values():
        if event.name in _TREE_BLACKLIST:
            continue

        default_recurse = "\n".join(
            f"        {_arg_to_member_name(x)}{_RECURSE_BOILERPLATE};" for x in event.arguments
        )

        emit_cil = ""
        event_debug_info = ""
        resource_scope_entries = ""
        scope_pass1 = ""
        emit_assembly = ""
        first_scope_entry = None
        for arg in event.arguments:
            emit_cil += (
                f'        fprintf(fp, "{", " if emit_cil else ""}{arg.type.meta.cil_name} ");\n'
            )
            emit_cil += f"        {_arg_to_member_name(arg)}{_RECURSE_BOILERPLATE}\n"

            id_name = f"{_arg_to_member_name(arg)}->mName"
            event_debug_info += f"            chunk->addBytes({id_name}, strlen({id_name}) + 1);\n"

            id_scope_entry = f"{_arg_to_member_name(arg)}->mScopeEntry"
            if not first_scope_entry:
                first_scope_entry = id_scope_entry

            resource_scope_entries += f"                {id_scope_entry}->mOffset = (S32)count;\n"
            resource_scope_entries += (
                f"                {id_scope_entry}->mSize = {arg.type.meta.lso_size};\n"
            )
            resource_scope_entries += f"                count += {id_scope_entry}->mSize;\n"

            emit_assembly += (
                f'        fprintf(fp, "{", " if emit_assembly else ""}{arg.type!s} ");\n'
            )
            emit_assembly += f"        {_arg_to_member_name(arg)}{_RECURSE_BOILERPLATE}\n"

            member_name = _arg_to_member_name(arg)
            scope_pass1 += f"""
        if (scope->checkEntry({_arg_to_member_name(arg)}->mName))
        {{
            gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
        }}
        else
        {{
            {member_name}->mScopeEntry = scope->addEntry({member_name}->mName, LIT_VARIABLE, {arg.type.meta.lst_name});
        }}
"""

        if emit_cil:
            # If we emitted anything for arguments we need to emit a space before and after parens.
            emit_cil = '        fprintf(fp, " ");\n' + emit_cil
            emit_cil += '        fprintf(fp, " ");\n'

        generated_tree_source += _TREE_CLASS_DEF_TEMPLATE % {
            "class_name": _event_to_class_name(event),
            "event_name": event.name,
            "default_recurse": default_recurse,
            "event_size": sum(x.type.meta.lso_size for x in event.arguments),
            "first_scope_entry": first_scope_entry or "false",
            "resource_scope_entries": resource_scope_entries,
            "event_debug_info": event_debug_info,
            "emit_cil": emit_cil,
            "scope_pass1": scope_pass1,
            "emit_assembly": emit_assembly,
        }
    return generated_tree_source


@register("gen_cpp_constants")
def gen_cpp_constants(definitions: LSLDefinitions) -> str:
    """Generate C++ constants header (lllslconstants_generated.h)"""
    cpp_constants = "#pragma once\n\n// Generated file, do not edit directly!\n\n"

    for const in definitions.constants.values():
        # We don't want to generate these since they create a dependency on llmath
        # and their constexpr-ness is suspect.
        if const.type in (LSLType.ROTATION, LSLType.VECTOR):
            continue

        cpp_constants += f"constexpr {const.type.meta.cpp_name} LSL_GEN_{const.name.upper()} = "
        if const.type == LSLType.STRING:
            cpp_constants += f'"{to_c_str(const.value)}"'
        elif const.type in (LSLType.INTEGER, LSLType.FLOAT):
            cpp_constants += const.value
        cpp_constants += ";\n"

    return cpp_constants
