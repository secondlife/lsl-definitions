"""Generators for lscript library, Mono bindings, and Lua registrations."""

from __future__ import annotations

# ruff: noqa: UP031  # Allow % formatting
import re

from lsl_definitions.generators.base import register
from lsl_definitions.lsl import LSLDefinitions, LSLFunction, LSLType
from lsl_definitions.rulesets import _VALUE_TYPE_TO_SEMANTIC, expand_table_ruleset
from lsl_definitions.utils import is_uuid, splice_str, to_c_str


@register("gen_lscript_library_defs")
def gen_lscript_library_defs(definitions: LSLDefinitions) -> str:
    """Generate function definitions for lscript_library.cpp

    Example:
    dangerousAddFunction(6, "llAbs", "i", "i", 10.0f, 0.0f, false);
    dangerousAddFunction(172, "llAcos", "f", "f", 10.0f, 0.0f, false);
    dangerousAddFunction(310, "llAddToLandBanList", "", "kf", 10.0f, 0.1f, false);
    """
    func_defs = ""
    for func in definitions.functions.values():
        if func.arguments:
            args_def = f'"{"".join(x.type.meta.library_abbr for x in func.arguments)}"'
        else:
            # Using `nullptr` instead of `""` saves a worthless array alloc inside `runllib_common()`.
            args_def = "nullptr"

        if func.ret_type == LSLType.VOID:
            # Using `nullptr` instead of `""` saves a worthless alloc inside `runllib_common()`.
            ret_def = "nullptr"
        else:
            ret_def = f'"{func.ret_type.meta.library_abbr}"'

        func_defs += (
            f'dangerousAddFunction({func.func_id}, "{func.name}", {ret_def}, {args_def}, '
            f"{func.energy}f, {func.sleep}f, {func.mono_sleep}f, {str(func.god_mode).lower()});\n"
        )

    return func_defs


_MONO_CS_LIBRARY_DEFS_COMMENT = "/* GENERATED FUNCTION BINDINGS */"
# Everything we don't want to automatically generate function stubs for. This is pretty much every existing function,
# since we don't really know if they did anything weird in their implementation or definition (maybe differing
# energy / sleep values.) Better to leave them alone and only generate new functions.
# For testing, we omit from this blacklist `llAxisAngle2Rot` and `llListSortStrided`, and manually verify the output.
# C# reserved keywords that must be escaped with @ when used as identifiers
_CS_RESERVED_KEYWORDS = {
    "abstract",
    "as",
    "base",
    "bool",
    "break",
    "byte",
    "case",
    "catch",
    "char",
    "checked",
    "class",
    "const",
    "continue",
    "decimal",
    "default",
    "delegate",
    "do",
    "double",
    "else",
    "enum",
    "event",
    "explicit",
    "extern",
    "false",
    "finally",
    "fixed",
    "float",
    "for",
    "foreach",
    "goto",
    "if",
    "implicit",
    "in",
    "int",
    "interface",
    "internal",
    "is",
    "lock",
    "long",
    "namespace",
    "new",
    "null",
    "object",
    "operator",
    "out",
    "override",
    "params",
    "private",
    "protected",
    "public",
    "readonly",
    "ref",
    "return",
    "sbyte",
    "sealed",
    "short",
    "sizeof",
    "stackalloc",
    "static",
    "string",
    "struct",
    "switch",
    "this",
    "throw",
    "true",
    "try",
    "typeof",
    "uint",
    "ulong",
    "unchecked",
    "unsafe",
    "ushort",
    "using",
    "virtual",
    "void",
    "volatile",
    "while",
}


def _cs_ident(name: str) -> str:
    """Escape a C# reserved keyword by prefixing with @."""
    return f"@{name}" if name in _CS_RESERVED_KEYWORDS else name


_OLD_FUNC_BLACKLIST = {
    "llGiveInventory",
    "llModPow",
    "llDetectedTouchNormal",
    "llNavigateTo",
    "llAddToLandPassList",
    "llGetScriptState",
    "llGetObjectDesc",
    "llPreloadSound",
    "llWind",
    "llCollisionFilter",
    "llGetVel",
    "llGetOwnerKey",
    "llGetNotecardLine",
    "llStopHover",
    "llGetInventoryName",
    "llJson2List",
    "llSay",
    "llGetAgentList",
    "llRequestAgentData",
    "llGetLinkSitFlags",
    "llJsonValueType",
    "llGetCameraRot",
    "llWorldPosToHUD",
    "llGetInventoryDesc",
    "llLinkSetSoundQueueing",
    "llGetEnvironment",
    "llGetInventoryPermMask",
    "llLinksetDataWrite",
    "llSetTextureAnim",
    "llCSV2List",
    "llGetMassMKS",
    "llAvatarOnSitTarget",
    "llCeil",
    "llCos",
    "llMapDestination",
    "llDetectedTouchPos",
    "llDetectedLinkNumber",
    "llReleaseControls",
    "llStopLookAt",
    "llEscapeURL",
    "llTriggerSoundLimited",
    "llSetParcelMusicURL",
    "llSetScriptState",
    "llRezObjectWithParams",
    "llStopPointAt",
    "llGetNumberOfNotecardLines",
    "llGetOwner",
    "llsRGB2Linear",
    "llGetGMTclock",
    "llGetStaticPath",
    "llLoadURL",
    "llInsertString",
    "llDeleteSubList",
    "llRot2Left",
    "llReturnObjectsByOwner",
    "llSubStringIndex",
    "llGetStatus",
    "llRemoteLoadScript",
    "llStopMoveToTarget",
    "llRound",
    "llParticleSystem",
    "llSensorRemove",
    "llSetContentType",
    "llGetAccel",
    "llLoopSoundMaster",
    "llRegionSay",
    "llGetSPMaxMemory",
    "llListFindStrided",
    "llGetRegionAgentCount",
    "llSetBuoyancy",
    "llDetectedType",
    "llSetPayPrice",
    "llSetRot",
    "llSetClickAction",
    "llSetLinkPrimitiveParams",
    "llLinksetDataWriteProtected",
    "llGroundNormal",
    "llLinkStopSound",
    "llList2ListStrided",
    "llReturnObjectsByID",
    "llList2String",
    "llWanderWithin",
    "llListStatistics",
    "llDetectedTouchBinormal",
    "llGetTexture",
    "llSetLinkCamera",
    "llEvade",
    "llGetRegionTimeDilation",
    "llCreateLink",
    "llGetCameraFOV",
    "llDetectedGrab",
    "llSameGroup",
    "llSetLinkAlpha",
    "llLinksetDataDelete",
    "llRot2Euler",
    "llGetDayOffset",
    "llTakeCamera",
    "llRequestSecureURL",
    "llGetAttached",
    "llRotateTexture",
    "llGetInventoryKey",
    "llSetSoundQueueing",
    "llList2Vector",
    "llTeleportAgent",
    "llSetExperienceKey",
    "llDialog",
    "llSetTorque",
    "llTargetedEmail",
    "llGetLinkName",
    "llGetParcelMusicURL",
    "llSetVehicleType",
    "llVecDist",
    "llGetPrimitiveParams",
    "llGetRegionMoonRotation",
    "llLinkSetSoundRadius",
    "llReplaceEnvironment",
    "llLinksetDataCountFound",
    "llListFindList",
    "llRequestDisplayName",
    "llGroundContour",
    "llGetParcelMaxPrims",
    "llClearExperience",
    "llList2Float",
    "llGetFreeURLs",
    "llRemoteLoadScriptPin",
    "llGetLinkNumber",
    "llGetAndResetTime",
    "llSleep",
    "llTransferLindenDollars",
    "llGetEnergy",
    "llGetKey",
    "llRequestUserKey",
    "llUnescapeURL",
    "llGetFreeMemory",
    "llFleeFrom",
    "llGetSimulatorHostname",
    "llGetMoonDirection",
    "llClearExperiencePermissions",
    "llLinksetDataDeleteFound",
    "llPassTouches",
    "llPursue",
    "llUnSit",
    "llGetUsername",
    "llGetLinkKey",
    "llApplyImpulse",
    "llCreateCharacter",
    "llListFindListNext",
    "llSetScale",
    "llSetAgentEnvironment",
    "llSetEnvironment",
    "llGetTime",
    "llGetRegionDayOffset",
    "llKey2Name",
    "llMoveToTarget",
    "llRequestUsername",
    "llSetText",
    "llGetRot",
    "llGetDayLength",
    "llSetForce",
    "llSetVehicleFloatParam",
    "llGetRegionTimeOfDay",
    "llKeyCountKeyValue",
    "llSetSoundRadius",
    "llCreateKeyValue",
    "llGetAgentSize",
    "llAxes2Rot",
    "llDeleteSubString",
    "llReplaceSubString",
    "llAddToLandBanList",
    "llChar",
    "llDeleteCharacter",
    "llCollisionSound",
    "llMakeFire",
    "llName2Key",
    "llParseStringKeepNulls",
    "llGetDate",
    "llGetNotecardLineSync",
    "llGetMoonRotation",
    "llBase64ToInteger",
    "llGetClosestNavPoint",
    "llStringToBase64",
    "llTeleportAgentHome",
    "llLinksetDataListKeys",
    "llAdjustSoundVolume",
    "llMakeFountain",
    "llRemoveInventory",
    "llDetectedTouchUV",
    "llAllowInventoryDrop",
    "llSetObjectPermMask",
    "llXorBase64StringsCorrect",
    "llGetNumberOfSides",
    "llDetectedTouchFace",
    "llTarget",
    "llAcos",
    "llFrand",
    "llStopObjectAnimation",
    "llSetLinkColor",
    "llAbs",
    "llSetTimerEvent",
    "llGetExperienceList",
    "llDie",
    "llAngleBetween",
    "llSetPrimMediaParams",
    "llSetLinkMedia",
    "llGenerateKey",
    "llListRandomize",
    "llGetSubString",
    "llReleaseURL",
    "llGetRegionCorner",
    "llMakeSmoke",
    "llLinksetDataFindKeys",
    "llSetLinkTextureAnim",
    "llOrd",
    "llDetectedName",
    "llGetLinkMedia",
    "llGetAnimation",
    "llEjectFromLand",
    "llTeleportAgentGlobalCoords",
    "llTriggerSound",
    "llLinksetDataReadProtected",
    "llAsin",
    "llSqrt",
    "llGetListEntryType",
    "llRot2Up",
    "llSetStatus",
    "llAttachToAvatar",
    "llGetObjectDetails",
    "llSetCameraAtOffset",
    "llGetAlpha",
    "llBase64ToString",
    "llGetCreator",
    "llRequestInventoryData",
    "llHTTPResponse",
    "llDumpList2String",
    "llIntegerToBase64",
    "llGetRegionDayLength",
    "llRezObject",
    "llList2List",
    "llForceMouselook",
    "llGetTextureOffset",
    "llTargetOmega",
    "llDataSizeKeyValue",
    "llMD5String",
    "llReleaseCamera",
    "llGetSimStats",
    "llGetObjectPermMask",
    "llSendRemoteData",
    "llGetListLength",
    "llShout",
    "llStringTrim",
    "llAgentInExperience",
    "llGetExperienceDetails",
    "llGetRegionFlags",
    "llSetCameraParams",
    "llGetUsedMemory",
    "llLinksetDataAvailable",
    "llHash",
    "llRotLookAt",
    "llFabs",
    "llTakeControls",
    "llTan",
    "llApplyRotationalImpulse",
    "llTargetRemove",
    "llSetObjectDesc",
    "llSetSitText",
    "llGetAnimationOverride",
    "llSetMemoryLimit",
    "llClearCameraParams",
    "llLoopSound",
    "llGetPermissions",
    "llList2ListSlice",
    "llLinksetDataDeleteProtected",
    "llSetVehicleRotationParam",
    "llList2Key",
    "llFloor",
    "llGetStartParameter",
    "llSetPrimURL",
    "llLinkAdjustSoundVolume",
    "llVerifyRSA",
    "llRemoveFromLandPassList",
    "llSetInventoryPermMask",
    "llListSort",
    "llResetScript",
    "llKeysKeyValue",
    "llComputeHash",
    "llGetMaxScaleFactor",
    "llGroundSlope",
    "llStartAnimation",
    "llResetLandBanList",
    "llGetRootPosition",
    "llSetCameraEyeOffset",
    "llSHA256String",
    "llPassCollisions",
    "llStopAnimation",
    "llSetKeyframedMotion",
    "llLog",
    "llUpdateCharacter",
    "llGetObjectPrimCount",
    "llPlaySound",
    "llSetAnimationOverride",
    "llGetAgentLanguage",
    "llSoundPreload",
    "llSetHoverHeight",
    "llResetTime",
    "llGetLocalRot",
    "llJsonSetValue",
    "llSetLocalRot",
    "llMinEventDelay",
    "llGetParcelDetails",
    "llSensor",
    "llRefreshPrimURL",
    "llCloud",
    "llStringLength",
    "llStopSound",
    "llWater",
    "llRot2Axis",
    "llClearLinkMedia",
    "llResetAnimationOverride",
    "llSetAngularVelocity",
    "llSetRemoteScriptAccessPin",
    "llPow",
    "llGetExperienceErrorMessage",
    "llParseString2List",
    "llDetectedTouchST",
    "llList2Integer",
    "llLinksetDataReset",
    "llOwnerSay",
    "llGetInventoryType",
    "llGetWallclock",
    "llDetectedOwner",
    "llDetectedGroup",
    "llGetCameraPos",
    "llMakeExplosion",
    "llGetScriptName",
    "llSignRSA",
    "llScriptDanger",
    "llSetObjectName",
    "llRotTargetRemove",
    "llSetRenderMaterial",
    "llReplaceAgentEnvironment",
    "llGetOmega",
    "llBreakAllLinks",
    "llHTTPRequest",
    "llReadKeyValue",
    "llLinear2sRGB",
    "llUpdateKeyValue",
    "llSetPhysicsMaterial",
    "llHMAC",
    "llRegionSayTo",
    "llRequestSimulatorData",
    "llRemoveFromLandBanList",
    "llRemoteDataReply",
    "llVolumeDetect",
    "llGetRenderMaterial",
    "llGetRegionMoonDirection",
    "llLinkSitTarget",
    "llManageEstateAccess",
    "llToUpper",
    "llScriptProfiler",
    "llEmail",
    "llLookAt",
    "llJsonGetValue",
    "llRotBetween",
    "llGetNextEmail",
    "llLinksetDataRead",
    "llLinkParticleSystem",
    "llParcelMediaCommandList",
    "llCloseRemoteDataChannel",
    "llLog10",
    "llSetLinkRenderMaterial",
    "llGetSunDirection",
    "llGetRegionSunRotation",
    "llGetForce",
    "llScaleByFactor",
    "llExecCharacterCmd",
    "llGetBoundingBox",
    "llScaleTexture",
    "llSetAlpha",
    "llTextBox",
    "llGetMass",
    "llSetTexture",
    "llSin",
    "llGetParcelPrimCount",
    "llGetObjectMass",
    "llSetPrimitiveParams",
    "llGiveMoney",
    "llBreakLink",
    "llSitTarget",
    "llGround",
    "llDetectedPos",
    "llGetUnixTime",
    "llDetachFromAvatar",
    "llGetSunRotation",
    "llGetColor",
    "llMessageLinked",
    "llOpenRemoteDataChannel",
    "llGetPos",
    "llGetTextureRot",
    "llGetLocalPos",
    "llRot2Fwd",
    "llStartObjectAnimation",
    "llGetObjectLinkKey",
    "llGetRootRotation",
    "llList2CSV",
    "llAtan2",
    "llRemoveVehicleFlags",
    "llSetRegionPos",
    "llGetObjectAnimationNames",
    "llRezAtRoot",
    "llPointAt",
    "llModifyLand",
    "llListenRemove",
    "llGetObjectName",
    "llList2Rot",
    "llVecNorm",
    "llSound",
    "llDetectedVel",
    "llListen",
    "llAttachToAvatarTemp",
    "llInstantMessage",
    "llRotTarget",
    "llListenControl",
    "llGetPermissionsKey",
    "llGetEnv",
    "llResetOtherScript",
    "llLoopSoundSlave",
    "llOverMyLand",
    "llSetPos",
    "llGetTimestamp",
    "llGodLikeRezObject",
    "llGetMinScaleFactor",
    "llPlaySoundSlave",
    "llSetDamage",
    "llRemoteDataSetRegion",
    "llEuler2Rot",
    "llSetLinkTexture",
    "llDeleteKeyValue",
    "llGetAttachedList",
    "llGetLinkNumberOfSides",
    "llSetTouchText",
    "llXorBase64Strings",
    "llWhisper",
    "llGetRegionFPS",
    "llXorBase64",
    "llGroundRepel",
    "llListInsertList",
    "llGetMemoryLimit",
    "llGetScale",
    "llOpenFloater",
    "llGetDisplayName",
    "llGetNumberOfPrims",
    "llGetInventoryAcquireTime",
    "llSetForceAndTorque",
    "llGiveInventoryList",
    "llGetTorque",
    "llSetColor",
    "llCollisionSprite",
    "llAvatarOnLinkSitTarget",
    "llGetAgentInfo",
    "llRot2Angle",
    "llToLower",
    "llGetTextureScale",
    "llSetLinkPrimitiveParamsFast",
    "llRequestPermissions",
    "llGetGeometricCenter",
    "llResetLandPassList",
    "llSitOnLink",
    "llGetRegionName",
    "llSetVelocity",
    "llGetLinkPrimitiveParams",
    "llOffsetTexture",
    "llGetInventoryNumber",
    "llGetTimeOfDay",
    "llLinksetDataCountKeys",
    "llGetInventoryCreator",
    "llPatrolPoints",
    "llParcelMediaQuery",
    "llVecMag",
    "llSetVehicleFlags",
    "llSetLinkSitFlags",
    "llGetParcelPrimOwners",
    "llGetRegionSunDirection",
    "llLinkPlaySound",
    "llGetPrimMediaParams",
    "llGetLandOwnerAt",
    "llRequestURL",
    "llSHA1String",
    "llEdgeOfWorld",
    "llGetPhysicsMaterial",
    "llListReplaceList",
    "llGetCameraAspect",
    "llSetVehicleVectorParam",
    "llRequestExperiencePermissions",
    "llDetectedRot",
    "llGetHTTPHeader",
    "llGetParcelFlags",
    "llDetectedKey",
    "llList2Json",
    "llCastRay",
    "llSensorRepeat",
    "llGetCenterOfMass",
    "llPushObject",
    "llGetVisualParams",
    "llIsFriend",
    "llClearPrimMedia",
    "llGetAnimationList",
    "llDamage",
    "llDetectedRezzer",
}


def _any_arg_list(func: LSLFunction) -> bool:
    return any(a.type == LSLType.LIST for a in func.arguments)


def _any_list(func: LSLFunction) -> bool:
    return func.ret_type == LSLType.LIST or _any_arg_list(func)


@register("gen_mono_library_defs")
def gen_mono_library_defs(definitions: LSLDefinitions, template_path: str) -> str:
    """Generate C# bindings for LslLibrary.cs

    Example:
    [MethodImplAttribute(MethodImplOptions.InternalCall)]
    public extern static void llAdjustDamage(int Number, float Damage);
    [MethodImplAttribute(MethodImplOptions.InternalCall)]
    public extern static object[] llDetectedDamageInternal(int Number);

    public static ArrayList llDetectedDamage(int Number) {
        return ToArrayListNoCopy(llDetectedDamageInternal(Number));
    }
    """
    with open(template_path) as f:
        template = f.read()

    new_defs = ""
    for func in definitions.functions.values():
        if func.name in _OLD_FUNC_BLACKLIST:
            continue
        new_defs += "        [MethodImplAttribute(MethodImplOptions.InternalCall)]\n"
        if _any_list(func):
            # If the function does anything with lists we need special wrapper code
            # Write the internal implementation
            ret_str = "object[]" if func.ret_type == LSLType.LIST else func.ret_type.meta.cs_name

            args_strs = []
            for arg in func.arguments:
                if arg.type == LSLType.LIST:
                    args_strs.append(f"object[] {_cs_ident(arg.name)}")
                    args_strs.append(f"int {arg.name}_len")
                else:
                    args_strs.append(f"{arg.type.meta.cs_name} {_cs_ident(arg.name)}")

            args_str = ", ".join(args_strs)
            new_defs += (
                f"        public extern static {ret_str} {func.name}Internal({args_str});\n\n"
            )

            # Now for the wrapper implementation
            args_str = ", ".join(
                f"{a.type.meta.cs_name} {_cs_ident(a.name)}" for a in func.arguments
            )
            new_defs += (
                f"        public static {func.ret_type.meta.cs_name} {func.name}({args_str}) {{\n"
            )

            call_args = []
            for arg in func.arguments:
                if arg.type == LSLType.LIST:
                    call_args.append(f"ToArrayNoCopy({_cs_ident(arg.name)})")
                    call_args.append(f"{_cs_ident(arg.name)}.Count")
                else:
                    call_args.append(_cs_ident(arg.name))

            call_expr = f"{func.name}Internal({', '.join(call_args)})"
            if func.ret_type == LSLType.LIST:
                # List returns don't have a length component like list args, the embedding
                # code must infer the length through Mono APIs.
                call_expr = f"ToArrayListNoCopy({call_expr})"
            if func.ret_type == LSLType.VOID:
                # Mono very much dislikes using a return from an otherwise void function
                new_defs += f"            {call_expr};\n"
            else:
                new_defs += f"            return {call_expr};\n"
            new_defs += "        }\n\n"
        else:
            args_str = ", ".join(
                f"{a.type.meta.cs_name} {_cs_ident(a.name)}" for a in func.arguments
            )
            new_defs += f"        public extern static {func.ret_type.meta.cs_name} {func.name}({args_str});\n"

    return splice_str(template, _MONO_CS_LIBRARY_DEFS_COMMENT, new_defs)


def _func_name_to_impl_name(name: str) -> str:
    """
    Converts llHTTPRequestXYZ to http_request_xyz_func

    This is the expected form for LSL func implementations
    """
    assert name.startswith("ll")
    name = name[2:]

    # Foo2Bar -> FooToBar and FOO2Bar -> FOOToBar, where applicable
    name = re.sub(r"(?<=[a-zA-Z])2(?=[A-Z])", "To", name)

    # Base64ToString -> base64_to_string
    # HTTPRequest -> http_request
    pattern = re.compile(r"(?<=[a-z0-9])(?=[A-Z])|(?<=[A-Z])(?=[A-Z][a-z])")
    return pattern.sub("_", name).lower() + "_func"


@register("gen_mono_bind_interfaces")
def gen_mono_bind_interfaces(definitions: LSLDefinitions) -> str:
    """Generate Mono internal call bindings

    Example:

    static void _mono_binding_wander_within_func(MonoVectorType p0, MonoVectorType p1, MonoListType p2, S32 p2_length)
    {
        LLScriptLibData args[3];
        LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
        LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
        LLScriptLibDataHelper<MonoListType>::set(args[2], p2, p2_length);
        LLScriptLibData retval;
        retval.mType = LST_NULL;
        // Where 401 is the function ID and 10.0 and 0.0 are the energy and sleep for the function
        // Using the function ID is ideal because it allows us to avoid binding to a specific implementation
        // of a function if we want to mock in our tests.
        call_lib_func(401, retval, args, 10.0, 0.0);
        return LLScriptLibDataHelper<void>::get(retval);
    }

    ...

    void mono_internal_call_init_generated()
    {
    // ...
        mono_add_internal_call("LindenLab.SecondLife.Library::llWanderWithinInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_wander_within_func)));
    // ...
    }
    """
    binding_calls = ""
    functions = ""
    for func in definitions.functions.values():
        if func.native:
            # Naturally, we don't need to bind native functions. They're native!
            continue

        # Bind to Mono VM
        # We use "Internal" as a suffix if either a retval or arg is a list
        # because there should be a C# wrapper deal with array<->ArrayList conversion.
        mono_func_name = f"{func.name}Internal" if _any_list(func) else func.name
        impl_name = _func_name_to_impl_name(func.name)

        arg_spec = []
        function_stmts = [
            f"LLScriptLibData args[{len(func.arguments)}];",
        ]
        for i, arg in enumerate(func.arguments):
            arg_bind_name = arg.type.meta.mono_bind_name
            arg_spec.append(f"{arg_bind_name} p{i}")
            if arg.type == LSLType.LIST:
                # Lists have both the array _and a length_ when passed as args
                arg_spec.append(f"S32 p{i}_length")
                function_stmts.append(
                    f"LLScriptLibDataHelper<{arg_bind_name}>::set(args[{i}], p{i}, p{i}_length);"
                )
            else:
                function_stmts.append(
                    f"LLScriptLibDataHelper<{arg_bind_name}>::set(args[{i}], p{i});"
                )

        ret_bind_name = func.ret_type.meta.mono_bind_name
        function_stmts.extend(
            [
                "LLScriptLibData retval;",
                f"retval.mType = {func.ret_type.meta.lst_name};",
                f"call_lib_func({func.func_id}, retval, {len(func.arguments)}, args, {func.energy}, {func.mono_sleep});",
                f"return LLScriptLibDataHelper<{ret_bind_name}>::get(retval);",
            ]
        )
        function_stmts_str = "\n    ".join(function_stmts)

        functions += f"static {ret_bind_name} _mono_binding_{impl_name}({', '.join(arg_spec)})\n{{\n    {function_stmts_str}\n}}\n\n"

        binding_calls += (
            f'    mono_add_internal_call("LindenLab.SecondLife.Library::{mono_func_name}",'
            f" fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_{impl_name})));\n"
        )

    binding_file_code = """
extern "C"
{
#include <mono/metadata/metadata.h>
#include <mono/metadata/object.h>
#include <mono/jit/jit.h>
}

#include "llscriptexecutemono.h"
#include "llmonointerfacehelpers.h"

typedef void (*PtrType)();

%s

void mono_internal_call_init_generated()
{
%s
}
""" % (functions, binding_calls)
    return binding_file_code


@register("gen_lscript_interface")
def gen_lscript_interface(definitions: LSLDefinitions) -> str:
    """Generate binding code for lscript_interface.cpp

    void task_lscript_init_generated()
    {
        gScriptLibrary.assignExec("llAxisAngle2Rot", axis_angle_to_rot_func);
        gScriptLibrary.assignExec("llListSortStrided", list_sort_strided_func);
        // ...
    }
    """
    assign_execs = ""
    for func in definitions.functions.values():
        impl_name = _func_name_to_impl_name(func.name)
        if func.name in _OLD_FUNC_BLACKLIST:
            continue
        # Meh. If this is an older function it should be explicitly bound by `gScriptLibrary.assignExec()`.
        # Bind to LSO VM
        assign_execs += f'    gScriptLibrary.assignExec("{func.name}", {impl_name});\n'

    function_code = (
        """
void task_lscript_init_generated()
{
%s
}
"""
        % assign_execs
    )
    return function_code


@register("gen_lua_registrations")
def gen_lua_registrations(definitions: LSLDefinitions, *, compat_mode: int = 0) -> str:
    """Generate lambdas to handle incoming Lua calls that wrap ll*() lscript functions

    Note: This file is included inside an array initializer, so it cannot have
    file-scope declarations. The ruleset def pointers (kParticleParamsDef, etc.)
    must be visible from ruleset_builder_descriptors being included earlier.
    """
    bindings = []
    for func in definitions.functions.values():
        if compat_mode != func.need_compat:
            continue
        # `ll` prefix is superfluous for namespacing functions, this is all going to live
        # in the `ll` module.
        assert func.name.startswith("ll")
        func_name = func.name[2:]
        prelude = ""

        # Generate ruleset coercion calls for arguments with ruleset annotations.
        # These must happen BEFORE extract_lua_args() since they modify the stack.
        coercion_lines = []
        for arg_idx, arg in enumerate(func.arguments):
            if arg.ruleset:
                ruleset_data = definitions.builder_rulesets[arg.ruleset]
                enum_name = ruleset_data["enum"]
                def_name = f"k{enum_name}sDef"
                lua_pos = arg_idx + 1  # 1-based Lua stack position
                coercion_lines.append(f"    slua_ruleset_coerce(L, {lua_pos}, {def_name});")
        coercion_block = "\n".join(coercion_lines) + "\n" if coercion_lines else ""

        # If we're not a simple function we need to run an interrupt when the
        # function _ends_ too, so we don't run over our time budget. This is
        # for functions which may run excessively long, where we don't want
        # control to flow into a place where we can't interrupt before we
        # do our next yield check.
        # Really, purity isn't a good basis for this, but they tend to be trivial
        # functions, so it's good enough for now.
        if not func.pure:
            prelude += "    luau_interruptoncalltail(L);\n"

        if func.need_compat:
            prelude += "    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));\n"

        if any(a.index_semantics for a in func.arguments):
            # If we're not in compat mode
            prelude += "    if (!compat_mode)\n    {\n"
            for arg_idx, arg in enumerate(func.arguments):
                if arg.index_semantics:
                    assert arg.type == LSLType.INTEGER
                    # This function will fix up the index to be 0-based or throw an error if 0 was passed.
                    prelude += f"        args[{arg_idx}].mInteger = luaSL_checkindexlike(L, {arg_idx + 1});\n"
            prelude += "    }\n"

        binding = """
{"%(func_name)s", [](lua_State *L) {
%(coercion_block)s    LLScriptLibData args[%(num_args)d];
    const LSCRIPTType types[] = {%(arg_types)s};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, %(num_args)d, types, args);
%(prelude)s
    return call_lib_func_lua(L, %(func_id)d, %(num_args)d, args, %(ret_type)s, %(bool_semantics)s, %(index_semantics)s);
}}
        """ % {
            "num_args": len(func.arguments),
            "ret_type": func.ret_type.meta.lst_name,
            "arg_types": ", ".join(a.type.meta.lst_name for a in func.arguments),
            "func_id": func.func_id,
            "func_name": func_name,
            "coercion_block": coercion_block,
            "prelude": prelude if prelude.strip() else "    // no prelude",
            "index_semantics": "false" if not func.index_semantics else "!compat_mode",
            "bool_semantics": "false" if not func.bool_semantics else "!compat_mode",
        }
        bindings.append(binding)

    return ",".join(bindings)


@register("gen_lua_constant_definitions")
def gen_lua_constant_definitions(definitions: LSLDefinitions) -> str:
    """Generate Lua constant definitions"""
    # TODO: This would be much better as a constant folding pass in the compiler.
    #  there are a ton of constants and putting them all in the runtime environment
    #  is not free.
    bindings = []
    for const in definitions.constants.values():
        if const.slua_removed:
            continue
        binding = "    "
        if const.type == LSLType.KEY or is_uuid(const.value):
            # This is a bit weird. UUID constants don't exist in LSL, but they do in Lua.
            # Make these an actual UUID if we can to make comparison easier.
            binding += f'luaSL_pushuuidstring(L, "{to_c_str(const.value)}");'
        elif const.type == LSLType.STRING:
            binding += f'lua_pushstring(L, "{to_c_str(const.value_raw)}");'
        elif const.type == LSLType.INTEGER:
            binding += f"luaSL_pushnativeinteger(L, {const.value});"
        elif const.type == LSLType.FLOAT:
            binding += f"lua_pushnumber(L, {const.value});"
        elif const.type == LSLType.VECTOR:
            binding += f"lua_pushvector(L, {const.value[1:-1]});"
        elif const.type == LSLType.ROTATION:
            binding += f"luaSL_pushquaternion(L, {const.value[1:-1]});"
        else:
            raise ValueError(f"Can't generate Lua constant for {const.name} of type {const.type}")

        binding += f'\n    lua_setglobal(L, "{to_c_str(const.name)}");\n'
        bindings.append(binding)
    return "\n".join(bindings)


@register("gen_ruleset_builder_descriptors")
def gen_ruleset_builder_descriptors(definitions: LSLDefinitions) -> str:
    """Generate RulesetParamDescriptor arrays and dispatch wrappers for all type:table rulesets.

    For each ruleset, emits:
      - RulesetParamDescriptor array (file scope)
      - RulesetFlagDescriptor array if flag-enum present (file scope)
      - RulesetBuilderDef* pointer (file scope, NOT static - accessible to lua_registrations.cpp)
      - a lambda dispatch wrapper (inside init_ruleset_builders)
      - a slua_register_ruleset_fn call (inside init_ruleset_builders)

    The resulting fragment is #include'd at file scope. Call init_ruleset_builders(L) to register.
    """
    _semantic_map = _VALUE_TYPE_TO_SEMANTIC

    def _inspect_dispatch_fn(dispatch_fn_name: str):
        """Inspect ll{dispatch_fn_name}'s argument list.

        Returns (prefix_args, suffix_args, has_link, ret_type) where:
          prefix_args: list of (name, lsl_type, is_link) for args before the list
          suffix_args: list of (name, lsl_type) for args after the list
          has_link: whether any prefix arg is a link integer
        Raises ValueError if no list argument is found.
        """
        full_name = "ll" + dispatch_fn_name
        func = definitions.functions.get(full_name)
        if func is None:
            raise ValueError(f"dispatch-fn '{full_name}' not found in definitions")

        args = func.arguments
        # Find the list argument -- it may appear anywhere in the signature.
        list_idx = next((i for i, a in enumerate(args) if a.type == LSLType.LIST), None)
        if list_idx is None:
            raise ValueError(f"{full_name}: no list argument found in signature")

        prefix_result = []
        has_link = False
        for arg in args[:list_idx]:
            is_link = arg.type == LSLType.INTEGER and "link" in arg.name.lower()
            if is_link:
                has_link = True
            prefix_result.append((arg.name, arg.type, is_link))

        suffix_result = [(arg.name, arg.type) for arg in args[list_idx + 1 :]]

        return prefix_result, suffix_result, has_link, func.ret_type

    def _lua_fn_to_cpp_name(lua_fn: str) -> str:
        """Convert camelCase Lua function name to snake_case C++ variable name.
        e.g. particleSystem -> particle_system
        """
        return re.sub(r"(?<=[a-z0-9])(?=[A-Z])", "_", lua_fn).lower()

    def _build_wrapper(
        cpp_name: str,
        dispatch_fn: str,
        prefix_args: list,
        suffix_args: list,
        has_link: bool,
        ret_type: LSLType,
    ) -> str:
        """Emit a C++ lambda that reads Lua args, serializes params, and calls ll.dispatch_fn.

        Lua stack layout:
          1 .. P   : non-link prefix args (in LL order, skipping link)
          P+1      : params table
          P+2 ..   : suffix args (in LL order)
          last     : link (optional, if has_link)
        LL call order: original LL order (prefix args, rules list, suffix args).
        """
        non_link_prefix_count = sum(1 for _, _, is_link in prefix_args if not is_link)
        params_lua_pos = non_link_prefix_count + 1
        suffix_start_lua_pos = params_lua_pos + 1
        link_lua_pos = suffix_start_lua_pos + len(suffix_args)
        total_ll_args = len(prefix_args) + 1 + len(suffix_args)  # prefix + rules + suffix

        lines = []

        # Read non-link INTEGER prefix args into C variables (positions 1..P, in LL order).
        # Non-integer prefix args stay on the Lua stack and are pushed by value later.
        lua_pos = 1
        prefix_lua_positions: dict[str, int] = {}
        for arg_name, arg_type, is_link in prefix_args:
            if not is_link:
                prefix_lua_positions[arg_name] = lua_pos
                if arg_type == LSLType.INTEGER:
                    lines.append(
                        f"        int {arg_name.lower()} = luaL_checkinteger(L, {lua_pos});"
                    )
                lua_pos += 1

        # Similarly for suffix args (start after the params table slot).
        lua_pos += 1  # skip params_lua_pos
        suffix_lua_positions: dict[str, int] = {}
        for arg_name, arg_type in suffix_args:
            suffix_lua_positions[arg_name] = lua_pos
            if arg_type == LSLType.INTEGER:
                lines.append(
                    f"        int {arg_name.lower()}_s = luaL_optinteger(L, {lua_pos}, 0);"
                )
            lua_pos += 1

        # Read optional link arg (comes after suffix args on the Lua stack).
        if has_link:
            lines.append(
                f"        int link = lua_isnoneornil(L, {link_lua_pos}) "
                f"? SLUA_LINK_THIS : luaL_checkinteger(L, {link_lua_pos});"
            )

        # Serialize params table into a flat rules list.
        lines.append(f"        slua_ruleset_serialize(L, {params_lua_pos}, def);")
        lines.append("        int rules_idx = lua_gettop(L);")

        # Dispatch to ll.* in original LL order.
        lines.append('        lua_rawgetfield(L, LUA_BASEGLOBALSINDEX, "ll");')
        lines.append(f'        lua_rawgetfield(L, -1, "{dispatch_fn}");')

        # Push prefix args in LL order.
        for arg_name, arg_type, is_link in prefix_args:
            if is_link:
                lines.append("        lua_pushinteger(L, link);")
            elif arg_type == LSLType.INTEGER:
                lines.append(f"        lua_pushinteger(L, {arg_name.lower()});")
            else:
                lines.append(f"        lua_pushvalue(L, {prefix_lua_positions[arg_name]});")

        # Push the serialized rules list.
        lines.append("        lua_pushvalue(L, rules_idx);")

        # Push suffix args in LL order.
        for arg_name, arg_type in suffix_args:
            pos = suffix_lua_positions[arg_name]
            if arg_type == LSLType.INTEGER:
                lines.append(f"        lua_pushinteger(L, {arg_name.lower()}_s);")
            elif arg_type == LSLType.FLOAT:
                lines.append(
                    f"        if (lua_isnoneornil(L, {pos})) lua_pushnumber(L, 0.0); else lua_pushvalue(L, {pos});"
                )
            elif arg_type in (LSLType.STRING, LSLType.KEY):
                lines.append(
                    f'        if (lua_isnoneornil(L, {pos})) lua_pushliteral(L, ""); else lua_pushvalue(L, {pos});'
                )
            elif arg_type == LSLType.VECTOR:
                lines.append(
                    f"        if (lua_isnoneornil(L, {pos})) lua_pushvector(L, 0.0f, 0.0f, 0.0f); else lua_pushvalue(L, {pos});"
                )
            elif arg_type == LSLType.ROTATION:
                lines.append(
                    f"        if (lua_isnoneornil(L, {pos})) luaSL_pushquaternion(L, 0.0f, 0.0f, 0.0f, 1.0f); else lua_pushvalue(L, {pos});"
                )
            else:
                lines.append(f"        lua_pushvalue(L, {pos});")

        nresults = 0 if ret_type == LSLType.VOID else 1
        lines.append(f"        lua_call(L, {total_ll_args}, {nresults});")
        lines.append(f"        return {nresults};")

        body = "\n".join(lines)
        return (
            f"auto {cpp_name} = [](lua_State* L) -> int {{\n"
            f"        const auto* def = (const RulesetBuilderDef*)lua_tolightuserdata(L, lua_upvalueindex(1));\n"
            f"{body}\n"
            f"    }};"
        )

    file_scope_sections = []
    function_body_lines = []

    for ruleset_name, ruleset_data in definitions.builder_rulesets.items():
        if ruleset_data.get("type", "builder") != "table":
            continue

        enum_name = ruleset_data["enum"]
        dispatch_fn = ruleset_data.get("dispatch-fn")

        # Descriptor array/def names derived from the enum name.
        # e.g. ParticleParam -> kParticleParamsDescs, kParticleParamsDef
        array_name = f"k{enum_name}sDescs"
        def_name = f"k{enum_name}sDef"

        desc_lines = []
        for desc in expand_table_ruleset(definitions, ruleset_name):
            name = desc.pretty_name if desc.pretty_name else desc.strict_name
            sem = _semantic_map[desc.value_type]
            desc_lines.append(f"    {{\"{name}\", '{sem}', {desc.tag}}},")

        param_body = "\n".join(desc_lines)
        file_scope = (
            f"// {ruleset_name}\n"
            f"static const RulesetParamDescriptor {array_name}[] = {{\n{param_body}\n}};\n"
        )

        flag_enum_name = ruleset_data.get("flag-enum")
        flag_field = ruleset_data.get("flag-field")
        if flag_enum_name and flag_field:
            flag_enum = definitions.enums[flag_enum_name]
            filler_tokens = set(ruleset_data.get("filler-tokens", []))
            prefix = flag_enum.prefix

            # Find field_tag from the already-computed param descriptors.
            field_tag = None
            for desc in expand_table_ruleset(definitions, ruleset_name):
                eff_name = desc.pretty_name if desc.pretty_name else desc.strict_name
                if eff_name == flag_field:
                    field_tag = desc.tag
                    break
            if field_tag is None:
                raise ValueError(
                    f"{ruleset_name}: flag-field '{flag_field}' not found in descriptor list"
                )

            # Enumerate flag constants sorted by numeric value.
            flag_consts = sorted(
                (
                    c
                    for c in definitions.constants.values()
                    if any(e.name == flag_enum_name for e in c.member_of) and not c.private
                ),
                key=lambda c: int(c.value, 0),
            )

            flag_suffix = (ruleset_data.get("flag-mask") or "").lower()
            flag_array_name = f"k{enum_name}FlagDescs"
            flag_lines = []
            for const in flag_consts:
                if const.pretty_name:
                    prop_name = const.pretty_name
                else:
                    name = const.name
                    strict = (name[len(prefix) :] if name.startswith(prefix) else name).lower()
                    if flag_suffix and strict.endswith(flag_suffix):
                        strict = strict[: -len(flag_suffix)]
                    tokens = [t for t in strict.split("_") if t not in filler_tokens]
                    prop_name = "_".join(tokens) if tokens else strict
                mask = int(const.value, 0)
                flag_lines.append(f'    {{"{prop_name}", 0x{mask:x}, {field_tag}}},')

            flag_body = "\n".join(flag_lines)
            file_scope += (
                f"static const RulesetFlagDescriptor {flag_array_name}[] = {{\n{flag_body}\n}};\n"
            )

            # Build def with flags in a single static initializer (file scope, NOT static).
            file_scope += (
                f"RulesetBuilderDef* {def_name} = []() {{\n"
                f"    auto* d = ruleset_builder_def_build({array_name}, std::size({array_name}));\n"
                f"    ruleset_builder_def_add_flags(d, {flag_array_name}, std::size({flag_array_name}));\n"
                f"    return d;\n"
                f"}}();\n"
            )
        else:
            # Simple def pointer (file scope, NOT static).
            file_scope += (
                f"RulesetBuilderDef* {def_name} = "
                f"ruleset_builder_def_build({array_name}, std::size({array_name}));\n"
            )

        file_scope_sections.append(file_scope)

        # Build lambda and registration (inside function body)
        if dispatch_fn is not None:
            lua_module = ruleset_data["lua-module"]
            lua_fn = ruleset_data["lua-fn"]
            prefix_args, suffix_args, has_link, ret_type = _inspect_dispatch_fn(dispatch_fn)
            cpp_name = _lua_fn_to_cpp_name(lua_fn)

            wrapper = _build_wrapper(
                cpp_name, dispatch_fn, prefix_args, suffix_args, has_link, ret_type
            )
            function_body_lines.append(f"    {wrapper}")
            function_body_lines.append(
                f'    slua_register_ruleset_fn(L, "{lua_module}", "{lua_fn}", {cpp_name}, {def_name});'
            )
            function_body_lines.append("")

    # Combine: file scope declarations, then the function
    result = "\n".join(file_scope_sections)
    result += "\ninline void init_ruleset_builders(lua_State* L) {\n"
    result += "\n".join(function_body_lines)
    result += "}\n"

    return result


@register("gen_lscript_library_bind_pure")
def gen_lscript_library_bind_pure(definitions: LSLDefinitions) -> str:
    """Generate pure function bindings for test harnesses

    Used by `bind_pure_lscript_functions(LLScriptLibrary& library)`.
    """

    assign_execs = ""
    for func in definitions.functions.values():
        if not func.pure:
            continue

        impl_name = _func_name_to_impl_name(func.name)
        assign_execs += f'    library.assignExec("{func.name}", {impl_name});\n'
    return assign_execs
