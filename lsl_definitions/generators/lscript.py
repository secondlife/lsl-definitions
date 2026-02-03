"""Generators for lscript library, Mono bindings, and Lua registrations."""

from __future__ import annotations

import re

from lsl_definitions.generators.base import register
from lsl_definitions.lsl import LSLDefinitions, LSLFunction, LSLType
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
            args_def = '"%s"' % "".join(x.type.meta.library_abbr for x in func.arguments)
        else:
            # Using `nullptr` instead of `""` saves a worthless array alloc inside `runllib_common()`.
            args_def = "nullptr"

        if func.ret_type == LSLType.VOID:
            # Using `nullptr` instead of `""` saves a worthless alloc inside `runllib_common()`.
            ret_def = "nullptr"
        else:
            ret_def = '"%s"' % func.ret_type.meta.library_abbr

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
    with open(template_path, "r") as f:
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
                    args_strs.append(f"object[] {arg.name}")
                    args_strs.append(f"int {arg.name}_len")
                else:
                    args_strs.append(f"{arg.type.meta.cs_name} {arg.name}")

            args_str = ", ".join(args_strs)
            new_defs += (
                f"        public extern static {ret_str} {func.name}Internal({args_str});\n\n"
            )

            # Now for the wrapper implementation
            args_str = ", ".join(f"{a.type.meta.cs_name} {a.name}" for a in func.arguments)
            new_defs += (
                f"        public static {func.ret_type.meta.cs_name} {func.name}({args_str}) {{\n"
            )

            call_args = []
            for arg in func.arguments:
                if arg.type == LSLType.LIST:
                    call_args.append(f"ToArrayNoCopy({arg.name})")
                    call_args.append(f"{arg.name}.Count")
                else:
                    call_args.append(arg.name)

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
            args_str = ", ".join(f"{a.type.meta.cs_name} {a.name}" for a in func.arguments)
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
def gen_lua_registrations(definitions: LSLDefinitions, *, pure_only: int = 0) -> str:
    """Generate Lua function registrations"""
    bindings = []
    for func in definitions.functions.values():
        if not func.pure and pure_only:
            continue
        # `ll` prefix is superfluous for namespacing functions, this is all going to live
        # in the `ll` module.
        assert func.name.startswith("ll")
        func_name = func.name[2:]

        binding = """
{"%(func_name)s", [](lua_State *L) {
    LLScriptLibData args[%(num_args)d];
    const LSCRIPTType types[] = {%(arg_types)s};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, %(num_args)d, types, args);
    return call_lib_func_lua(L, %(func_id)d, %(num_args)d, args, %(ret_type)s);
}}
        """ % {
            "num_args": len(func.arguments),
            "ret_type": func.ret_type.meta.lst_name,
            "arg_types": ", ".join(a.type.meta.lst_name for a in func.arguments),
            "func_id": func.func_id,
            "func_name": func_name,
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
        binding = "    "
        if const.type == LSLType.KEY or is_uuid(const.value):
            # This is a bit weird. UUID constants don't exist in LSL, but they do in Lua.
            # Make these an actual UUID if we can to make comparison easier.
            binding += f'luaSL_pushuuidstring(L, "{to_c_str(const.value)}");'
        elif const.type == LSLType.STRING:
            binding += f'lua_pushstring(L, "{to_c_str(const.value)}");'
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
