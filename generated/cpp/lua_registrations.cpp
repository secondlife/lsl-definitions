
{"Abs", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 6, 1, args, LST_INTEGER);
}}
        ,
{"Acos", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 172, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"AddToLandBanList", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 310, 2, args, LST_NULL);
}}
        ,
{"AddToLandPassList", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 240, 2, args, LST_NULL);
}}
        ,
{"AdjustDamage", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 555, 2, args, LST_NULL);
}}
        ,
{"AdjustSoundVolume", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 207, 1, args, LST_NULL);
}}
        ,
{"AgentInExperience", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 392, 1, args, LST_INTEGER);
}}
        ,
{"AllowInventoryDrop", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 176, 1, args, LST_NULL);
}}
        ,
{"AngleBetween", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_QUATERNION, LST_QUATERNION};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 174, 2, args, LST_FLOATINGPOINT);
}}
        ,
{"ApplyImpulse", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 72, 2, args, LST_NULL);
}}
        ,
{"ApplyRotationalImpulse", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 73, 2, args, LST_NULL);
}}
        ,
{"Asin", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 173, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"Atan2", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 3, 2, args, LST_FLOATINGPOINT);
}}
        ,
{"AttachToAvatar", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 113, 1, args, LST_NULL);
}}
        ,
{"AttachToAvatarTemp", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 391, 1, args, LST_NULL);
}}
        ,
{"AvatarOnLinkSitTarget", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 376, 1, args, LST_KEY);
}}
        ,
{"AvatarOnSitTarget", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 239, 0, args, LST_KEY);
}}
        ,
{"Axes2Rot", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_VECTOR, LST_VECTOR, LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 17, 3, args, LST_QUATERNION);
}}
        ,
{"AxisAngle2Rot", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 169, 2, args, LST_QUATERNION);
}}
        ,
{"Base64ToInteger", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 281, 1, args, LST_INTEGER);
}}
        ,
{"Base64ToString", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 261, 1, args, LST_STRING);
}}
        ,
{"BreakAllLinks", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 143, 0, args, LST_NULL);
}}
        ,
{"BreakLink", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 142, 1, args, LST_NULL);
}}
        ,
{"CSV2List", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 196, 1, args, LST_LIST);
}}
        ,
{"CastRay", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_VECTOR, LST_VECTOR, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 363, 3, args, LST_LIST);
}}
        ,
{"Ceil", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 10, 1, args, LST_INTEGER);
}}
        ,
{"Char", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 526, 1, args, LST_STRING);
}}
        ,
{"ClearCameraParams", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 314, 0, args, LST_NULL);
}}
        ,
{"ClearExperience", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 411, 2, args, LST_NULL);
}}
        ,
{"ClearExperiencePermissions", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 385, 1, args, LST_NULL);
}}
        ,
{"ClearLinkMedia", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 373, 2, args, LST_INTEGER);
}}
        ,
{"ClearPrimMedia", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 352, 1, args, LST_INTEGER);
}}
        ,
{"CloseRemoteDataChannel", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 257, 1, args, LST_NULL);
}}
        ,
{"Cloud", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 43, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"CollisionFilter", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_KEY, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 110, 3, args, LST_NULL);
}}
        ,
{"CollisionSound", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 160, 2, args, LST_NULL);
}}
        ,
{"CollisionSprite", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 161, 1, args, LST_NULL);
}}
        ,
{"ComputeHash", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 548, 2, args, LST_STRING);
}}
        ,
{"Cos", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 1, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"CreateCharacter", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 399, 1, args, LST_NULL);
}}
        ,
{"CreateKeyValue", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 387, 2, args, LST_KEY);
}}
        ,
{"CreateLink", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 141, 2, args, LST_NULL);
}}
        ,
{"Damage", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_KEY, LST_FLOATINGPOINT, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 671, 3, args, LST_NULL);
}}
        ,
{"DataSizeKeyValue", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 600, 0, args, LST_KEY);
}}
        ,
{"DeleteCharacter", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 405, 0, args, LST_NULL);
}}
        ,
{"DeleteKeyValue", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 390, 1, args, LST_KEY);
}}
        ,
{"DeleteSubList", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 193, 3, args, LST_LIST);
}}
        ,
{"DeleteSubString", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 95, 3, args, LST_STRING);
}}
        ,
{"DerezObject", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 509, 2, args, LST_INTEGER);
}}
        ,
{"DetachFromAvatar", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 114, 0, args, LST_NULL);
}}
        ,
{"DetectedDamage", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 554, 1, args, LST_LIST);
}}
        ,
{"DetectedGrab", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 37, 1, args, LST_VECTOR);
}}
        ,
{"DetectedGroup", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 39, 1, args, LST_INTEGER);
}}
        ,
{"DetectedKey", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 32, 1, args, LST_KEY);
}}
        ,
{"DetectedLinkNumber", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 40, 1, args, LST_INTEGER);
}}
        ,
{"DetectedName", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 31, 1, args, LST_STRING);
}}
        ,
{"DetectedOwner", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 33, 1, args, LST_KEY);
}}
        ,
{"DetectedPos", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 35, 1, args, LST_VECTOR);
}}
        ,
{"DetectedRezzer", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 553, 1, args, LST_KEY);
}}
        ,
{"DetectedRot", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 38, 1, args, LST_QUATERNION);
}}
        ,
{"DetectedTouchBinormal", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 341, 1, args, LST_VECTOR);
}}
        ,
{"DetectedTouchFace", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 338, 1, args, LST_INTEGER);
}}
        ,
{"DetectedTouchNormal", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 340, 1, args, LST_VECTOR);
}}
        ,
{"DetectedTouchPos", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 339, 1, args, LST_VECTOR);
}}
        ,
{"DetectedTouchST", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 342, 1, args, LST_VECTOR);
}}
        ,
{"DetectedTouchUV", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 337, 1, args, LST_VECTOR);
}}
        ,
{"DetectedType", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 34, 1, args, LST_INTEGER);
}}
        ,
{"DetectedVel", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 36, 1, args, LST_VECTOR);
}}
        ,
{"Dialog", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_KEY, LST_STRING, LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 247, 4, args, LST_NULL);
}}
        ,
{"Die", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 41, 0, args, LST_NULL);
}}
        ,
{"DumpList2String", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 245, 2, args, LST_STRING);
}}
        ,
{"EdgeOfWorld", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 205, 2, args, LST_INTEGER);
}}
        ,
{"EjectFromLand", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 213, 1, args, LST_NULL);
}}
        ,
{"Email", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 119, 3, args, LST_NULL);
}}
        ,
{"EscapeURL", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 307, 1, args, LST_STRING);
}}
        ,
{"Euler2Rot", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 16, 1, args, LST_QUATERNION);
}}
        ,
{"Evade", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 407, 2, args, LST_NULL);
}}
        ,
{"ExecCharacterCmd", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 404, 2, args, LST_NULL);
}}
        ,
{"Fabs", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 7, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"FindNotecardTextCount", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 507, 3, args, LST_KEY);
}}
        ,
{"FindNotecardTextSync", [](lua_State *L) {
    LLScriptLibData args[5];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING, LST_INTEGER, LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 5, types, args);
    return call_lib_func_lua(L, 508, 5, args, LST_LIST);
}}
        ,
{"FleeFrom", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_VECTOR, LST_FLOATINGPOINT, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 402, 3, args, LST_NULL);
}}
        ,
{"Floor", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 9, 1, args, LST_INTEGER);
}}
        ,
{"ForceMouselook", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 294, 1, args, LST_NULL);
}}
        ,
{"Frand", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 8, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"GenerateKey", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 383, 0, args, LST_KEY);
}}
        ,
{"GetAccel", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 78, 0, args, LST_VECTOR);
}}
        ,
{"GetAgentInfo", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 206, 1, args, LST_INTEGER);
}}
        ,
{"GetAgentLanguage", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 336, 1, args, LST_STRING);
}}
        ,
{"GetAgentList", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 412, 2, args, LST_LIST);
}}
        ,
{"GetAgentSize", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 218, 1, args, LST_VECTOR);
}}
        ,
{"GetAlpha", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 50, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"GetAndResetTime", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 84, 0, args, LST_FLOATINGPOINT);
}}
        ,
{"GetAnimation", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 162, 1, args, LST_STRING);
}}
        ,
{"GetAnimationList", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 266, 1, args, LST_LIST);
}}
        ,
{"GetAnimationOverride", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 500, 1, args, LST_STRING);
}}
        ,
{"GetAttached", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 224, 0, args, LST_INTEGER);
}}
        ,
{"GetAttachedList", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 523, 1, args, LST_LIST);
}}
        ,
{"GetAttachedListFiltered", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 518, 2, args, LST_LIST);
}}
        ,
{"GetBoundingBox", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 277, 1, args, LST_LIST);
}}
        ,
{"GetCameraAspect", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 545, 0, args, LST_FLOATINGPOINT);
}}
        ,
{"GetCameraFOV", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 546, 0, args, LST_FLOATINGPOINT);
}}
        ,
{"GetCameraPos", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 303, 0, args, LST_VECTOR);
}}
        ,
{"GetCameraRot", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 304, 0, args, LST_QUATERNION);
}}
        ,
{"GetCenterOfMass", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 183, 0, args, LST_VECTOR);
}}
        ,
{"GetClosestNavPoint", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 408, 2, args, LST_LIST);
}}
        ,
{"GetColor", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 52, 1, args, LST_VECTOR);
}}
        ,
{"GetCreator", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 272, 0, args, LST_KEY);
}}
        ,
{"GetDate", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 204, 0, args, LST_STRING);
}}
        ,
{"GetDayLength", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 703, 0, args, LST_INTEGER);
}}
        ,
{"GetDayOffset", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 705, 0, args, LST_INTEGER);
}}
        ,
{"GetDisplayName", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 360, 1, args, LST_STRING);
}}
        ,
{"GetEnergy", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 149, 0, args, LST_FLOATINGPOINT);
}}
        ,
{"GetEnv", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 362, 1, args, LST_STRING);
}}
        ,
{"GetEnvironment", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 711, 2, args, LST_LIST);
}}
        ,
{"GetExperienceDetails", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 409, 1, args, LST_LIST);
}}
        ,
{"GetExperienceErrorMessage", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 603, 1, args, LST_STRING);
}}
        ,
{"GetExperienceList", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 410, 1, args, LST_LIST);
}}
        ,
{"GetForce", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 65, 0, args, LST_VECTOR);
}}
        ,
{"GetFreeMemory", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 225, 0, args, LST_INTEGER);
}}
        ,
{"GetFreeURLs", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 344, 0, args, LST_INTEGER);
}}
        ,
{"GetGMTclock", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 282, 0, args, LST_FLOATINGPOINT);
}}
        ,
{"GetGeometricCenter", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 278, 0, args, LST_VECTOR);
}}
        ,
{"GetHTTPHeader", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 349, 2, args, LST_STRING);
}}
        ,
{"GetHealth", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 552, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"GetInventoryAcquireTime", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 529, 1, args, LST_STRING);
}}
        ,
{"GetInventoryCreator", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 291, 1, args, LST_KEY);
}}
        ,
{"GetInventoryDesc", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 543, 1, args, LST_STRING);
}}
        ,
{"GetInventoryKey", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 175, 1, args, LST_KEY);
}}
        ,
{"GetInventoryName", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 147, 2, args, LST_STRING);
}}
        ,
{"GetInventoryNumber", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 146, 1, args, LST_INTEGER);
}}
        ,
{"GetInventoryPermMask", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 289, 2, args, LST_INTEGER);
}}
        ,
{"GetInventoryType", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 301, 1, args, LST_INTEGER);
}}
        ,
{"GetKey", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 121, 0, args, LST_KEY);
}}
        ,
{"GetLandOwnerAt", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 216, 1, args, LST_KEY);
}}
        ,
{"GetLinkKey", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 144, 1, args, LST_KEY);
}}
        ,
{"GetLinkMedia", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 372, 3, args, LST_LIST);
}}
        ,
{"GetLinkName", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 145, 1, args, LST_STRING);
}}
        ,
{"GetLinkNumber", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 139, 0, args, LST_INTEGER);
}}
        ,
{"GetLinkNumberOfSides", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 357, 1, args, LST_INTEGER);
}}
        ,
{"GetLinkPrimitiveParams", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 354, 2, args, LST_LIST);
}}
        ,
{"GetLinkSitFlags", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 551, 1, args, LST_INTEGER);
}}
        ,
{"GetListEntryType", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 194, 2, args, LST_INTEGER);
}}
        ,
{"GetListLength", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 185, 1, args, LST_INTEGER);
}}
        ,
{"GetLocalPos", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 60, 0, args, LST_VECTOR);
}}
        ,
{"GetLocalRot", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 63, 0, args, LST_QUATERNION);
}}
        ,
{"GetMass", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 109, 0, args, LST_FLOATINGPOINT);
}}
        ,
{"GetMassMKS", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 382, 0, args, LST_FLOATINGPOINT);
}}
        ,
{"GetMaxScaleFactor", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 591, 0, args, LST_FLOATINGPOINT);
}}
        ,
{"GetMemoryLimit", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 370, 0, args, LST_INTEGER);
}}
        ,
{"GetMinScaleFactor", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 590, 0, args, LST_FLOATINGPOINT);
}}
        ,
{"GetMoonDirection", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 701, 0, args, LST_VECTOR);
}}
        ,
{"GetMoonRotation", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 709, 0, args, LST_QUATERNION);
}}
        ,
{"GetNextEmail", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 120, 2, args, LST_NULL);
}}
        ,
{"GetNotecardLine", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 217, 2, args, LST_KEY);
}}
        ,
{"GetNotecardLineSync", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 549, 2, args, LST_STRING);
}}
        ,
{"GetNumberOfNotecardLines", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 276, 1, args, LST_KEY);
}}
        ,
{"GetNumberOfPrims", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 275, 0, args, LST_INTEGER);
}}
        ,
{"GetNumberOfSides", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 168, 0, args, LST_INTEGER);
}}
        ,
{"GetObjectAnimationNames", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 506, 0, args, LST_LIST);
}}
        ,
{"GetObjectDesc", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 270, 0, args, LST_STRING);
}}
        ,
{"GetObjectDetails", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 332, 2, args, LST_LIST);
}}
        ,
{"GetObjectLinkKey", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 532, 2, args, LST_KEY);
}}
        ,
{"GetObjectMass", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 295, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"GetObjectName", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 202, 0, args, LST_STRING);
}}
        ,
{"GetObjectPermMask", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 287, 1, args, LST_INTEGER);
}}
        ,
{"GetObjectPrimCount", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 323, 1, args, LST_INTEGER);
}}
        ,
{"GetOmega", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 79, 0, args, LST_VECTOR);
}}
        ,
{"GetOwner", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 117, 0, args, LST_KEY);
}}
        ,
{"GetOwnerKey", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 182, 1, args, LST_KEY);
}}
        ,
{"GetParcelDetails", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 327, 2, args, LST_LIST);
}}
        ,
{"GetParcelFlags", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 317, 1, args, LST_INTEGER);
}}
        ,
{"GetParcelMaxPrims", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 326, 2, args, LST_INTEGER);
}}
        ,
{"GetParcelMusicURL", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 396, 0, args, LST_STRING);
}}
        ,
{"GetParcelPrimCount", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_VECTOR, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 325, 3, args, LST_INTEGER);
}}
        ,
{"GetParcelPrimOwners", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 324, 1, args, LST_LIST);
}}
        ,
{"GetPermissions", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 138, 0, args, LST_INTEGER);
}}
        ,
{"GetPermissionsKey", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 137, 0, args, LST_KEY);
}}
        ,
{"GetPhysicsMaterial", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 381, 0, args, LST_LIST);
}}
        ,
{"GetPos", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 59, 0, args, LST_VECTOR);
}}
        ,
{"GetPrimMediaParams", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 351, 2, args, LST_LIST);
}}
        ,
{"GetPrimitiveParams", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 279, 1, args, LST_LIST);
}}
        ,
{"GetRegionAgentCount", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 334, 0, args, LST_INTEGER);
}}
        ,
{"GetRegionCorner", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 199, 0, args, LST_VECTOR);
}}
        ,
{"GetRegionDayLength", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 704, 0, args, LST_INTEGER);
}}
        ,
{"GetRegionDayOffset", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 706, 0, args, LST_INTEGER);
}}
        ,
{"GetRegionFPS", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 228, 0, args, LST_FLOATINGPOINT);
}}
        ,
{"GetRegionFlags", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 318, 0, args, LST_INTEGER);
}}
        ,
{"GetRegionMoonDirection", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 702, 0, args, LST_VECTOR);
}}
        ,
{"GetRegionMoonRotation", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 710, 0, args, LST_QUATERNION);
}}
        ,
{"GetRegionName", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 226, 0, args, LST_STRING);
}}
        ,
{"GetRegionSunDirection", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 700, 0, args, LST_VECTOR);
}}
        ,
{"GetRegionSunRotation", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 708, 0, args, LST_QUATERNION);
}}
        ,
{"GetRegionTimeDilation", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 227, 0, args, LST_FLOATINGPOINT);
}}
        ,
{"GetRegionTimeOfDay", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 712, 0, args, LST_FLOATINGPOINT);
}}
        ,
{"GetRenderMaterial", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 760, 1, args, LST_STRING);
}}
        ,
{"GetRootPosition", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 268, 0, args, LST_VECTOR);
}}
        ,
{"GetRootRotation", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 269, 0, args, LST_QUATERNION);
}}
        ,
{"GetRot", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 62, 0, args, LST_QUATERNION);
}}
        ,
{"GetSPMaxMemory", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 365, 0, args, LST_INTEGER);
}}
        ,
{"GetScale", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 48, 0, args, LST_VECTOR);
}}
        ,
{"GetScriptName", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 167, 0, args, LST_STRING);
}}
        ,
{"GetScriptState", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 250, 1, args, LST_INTEGER);
}}
        ,
{"GetSimStats", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 415, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"GetSimulatorHostname", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 283, 0, args, LST_STRING);
}}
        ,
{"GetStartParameter", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 134, 0, args, LST_INTEGER);
}}
        ,
{"GetStartString", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 556, 0, args, LST_STRING);
}}
        ,
{"GetStaticPath", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_VECTOR, LST_VECTOR, LST_FLOATINGPOINT, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 413, 4, args, LST_LIST);
}}
        ,
{"GetStatus", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 46, 1, args, LST_INTEGER);
}}
        ,
{"GetSubString", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 94, 3, args, LST_STRING);
}}
        ,
{"GetSunDirection", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 177, 0, args, LST_VECTOR);
}}
        ,
{"GetSunRotation", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 707, 0, args, LST_QUATERNION);
}}
        ,
{"GetTexture", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 57, 1, args, LST_STRING);
}}
        ,
{"GetTextureOffset", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 178, 1, args, LST_VECTOR);
}}
        ,
{"GetTextureRot", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 180, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"GetTextureScale", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 179, 1, args, LST_VECTOR);
}}
        ,
{"GetTime", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 82, 0, args, LST_FLOATINGPOINT);
}}
        ,
{"GetTimeOfDay", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 80, 0, args, LST_FLOATINGPOINT);
}}
        ,
{"GetTimestamp", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 273, 0, args, LST_STRING);
}}
        ,
{"GetTorque", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 75, 0, args, LST_VECTOR);
}}
        ,
{"GetUnixTime", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 316, 0, args, LST_INTEGER);
}}
        ,
{"GetUsedMemory", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 366, 0, args, LST_INTEGER);
}}
        ,
{"GetUsername", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 358, 1, args, LST_STRING);
}}
        ,
{"GetVel", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 77, 0, args, LST_VECTOR);
}}
        ,
{"GetVisualParams", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 530, 2, args, LST_LIST);
}}
        ,
{"GetWallclock", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 81, 0, args, LST_FLOATINGPOINT);
}}
        ,
{"GiveAgentInventory", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_KEY, LST_STRING, LST_LIST, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 517, 4, args, LST_INTEGER);
}}
        ,
{"GiveInventory", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 150, 2, args, LST_NULL);
}}
        ,
{"GiveInventoryList", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_KEY, LST_STRING, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 231, 3, args, LST_NULL);
}}
        ,
{"GiveMoney", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 99, 2, args, LST_INTEGER);
}}
        ,
{"GodLikeRezObject", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 135, 2, args, LST_NULL);
}}
        ,
{"Ground", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 42, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"GroundContour", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 223, 1, args, LST_VECTOR);
}}
        ,
{"GroundNormal", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 222, 1, args, LST_VECTOR);
}}
        ,
{"GroundRepel", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT, LST_INTEGER, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 230, 3, args, LST_NULL);
}}
        ,
{"GroundSlope", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 221, 1, args, LST_VECTOR);
}}
        ,
{"HMAC", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 538, 3, args, LST_STRING);
}}
        ,
{"HTTPRequest", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_LIST, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 320, 3, args, LST_KEY);
}}
        ,
{"HTTPResponse", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_KEY, LST_INTEGER, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 348, 3, args, LST_NULL);
}}
        ,
{"Hash", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 528, 1, args, LST_INTEGER);
}}
        ,
{"InsertString", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 96, 3, args, LST_STRING);
}}
        ,
{"InstantMessage", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 118, 2, args, LST_NULL);
}}
        ,
{"IntegerToBase64", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 280, 1, args, LST_STRING);
}}
        ,
{"IsFriend", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 542, 1, args, LST_INTEGER);
}}
        ,
{"IsLinkGLTFMaterial", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 559, 2, args, LST_INTEGER);
}}
        ,
{"Json2List", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 513, 1, args, LST_LIST);
}}
        ,
{"JsonGetValue", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 511, 2, args, LST_STRING);
}}
        ,
{"JsonSetValue", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_LIST, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 510, 3, args, LST_STRING);
}}
        ,
{"JsonValueType", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 512, 2, args, LST_STRING);
}}
        ,
{"Key2Name", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 210, 1, args, LST_STRING);
}}
        ,
{"KeyCountKeyValue", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 601, 0, args, LST_KEY);
}}
        ,
{"KeysKeyValue", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 602, 2, args, LST_KEY);
}}
        ,
{"Linear2sRGB", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 715, 1, args, LST_VECTOR);
}}
        ,
{"LinkAdjustSoundVolume", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 535, 2, args, LST_NULL);
}}
        ,
{"LinkParticleSystem", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 355, 2, args, LST_NULL);
}}
        ,
{"LinkPlaySound", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_INTEGER, LST_STRING, LST_FLOATINGPOINT, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 533, 4, args, LST_NULL);
}}
        ,
{"LinkSetSoundQueueing", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 537, 2, args, LST_NULL);
}}
        ,
{"LinkSetSoundRadius", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 536, 2, args, LST_NULL);
}}
        ,
{"LinkSitTarget", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_INTEGER, LST_VECTOR, LST_QUATERNION};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 375, 3, args, LST_NULL);
}}
        ,
{"LinkStopSound", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 534, 1, args, LST_NULL);
}}
        ,
{"LinksetDataAvailable", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 654, 0, args, LST_INTEGER);
}}
        ,
{"LinksetDataCountFound", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 661, 1, args, LST_INTEGER);
}}
        ,
{"LinksetDataCountKeys", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 653, 0, args, LST_INTEGER);
}}
        ,
{"LinksetDataDelete", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 652, 1, args, LST_INTEGER);
}}
        ,
{"LinksetDataDeleteFound", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 662, 2, args, LST_LIST);
}}
        ,
{"LinksetDataDeleteProtected", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 660, 2, args, LST_INTEGER);
}}
        ,
{"LinksetDataFindKeys", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 657, 3, args, LST_LIST);
}}
        ,
{"LinksetDataListKeys", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 656, 2, args, LST_LIST);
}}
        ,
{"LinksetDataRead", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 651, 1, args, LST_STRING);
}}
        ,
{"LinksetDataReadProtected", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 659, 2, args, LST_STRING);
}}
        ,
{"LinksetDataReset", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 655, 0, args, LST_NULL);
}}
        ,
{"LinksetDataWrite", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 650, 2, args, LST_INTEGER);
}}
        ,
{"LinksetDataWriteProtected", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 658, 3, args, LST_INTEGER);
}}
        ,
{"List2CSV", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 195, 1, args, LST_STRING);
}}
        ,
{"List2Float", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 187, 2, args, LST_FLOATINGPOINT);
}}
        ,
{"List2Integer", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 186, 2, args, LST_INTEGER);
}}
        ,
{"List2Json", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 514, 2, args, LST_STRING);
}}
        ,
{"List2Key", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 189, 2, args, LST_KEY);
}}
        ,
{"List2List", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 192, 3, args, LST_LIST);
}}
        ,
{"List2ListSlice", [](lua_State *L) {
    LLScriptLibData args[5];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER, LST_INTEGER, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 5, types, args);
    return call_lib_func_lua(L, 801, 5, args, LST_LIST);
}}
        ,
{"List2ListStrided", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 198, 4, args, LST_LIST);
}}
        ,
{"List2Rot", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 191, 2, args, LST_QUATERNION);
}}
        ,
{"List2String", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 188, 2, args, LST_STRING);
}}
        ,
{"List2Vector", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 190, 2, args, LST_VECTOR);
}}
        ,
{"ListFindList", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 201, 2, args, LST_INTEGER);
}}
        ,
{"ListFindListNext", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_LIST, LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 803, 3, args, LST_INTEGER);
}}
        ,
{"ListFindStrided", [](lua_State *L) {
    LLScriptLibData args[5];
    const LSCRIPTType types[] = {LST_LIST, LST_LIST, LST_INTEGER, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 5, types, args);
    return call_lib_func_lua(L, 800, 5, args, LST_INTEGER);
}}
        ,
{"ListInsertList", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_LIST, LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 200, 3, args, LST_LIST);
}}
        ,
{"ListRandomize", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 197, 2, args, LST_LIST);
}}
        ,
{"ListReplaceList", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_LIST, LST_LIST, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 296, 4, args, LST_LIST);
}}
        ,
{"ListSort", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 184, 3, args, LST_LIST);
}}
        ,
{"ListSortStrided", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 802, 4, args, LST_LIST);
}}
        ,
{"ListStatistics", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 315, 2, args, LST_FLOATINGPOINT);
}}
        ,
{"Listen", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_INTEGER, LST_STRING, LST_KEY, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 25, 4, args, LST_INTEGER);
}}
        ,
{"ListenControl", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 26, 2, args, LST_NULL);
}}
        ,
{"ListenRemove", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 27, 1, args, LST_NULL);
}}
        ,
{"LoadURL", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_KEY, LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 297, 3, args, LST_NULL);
}}
        ,
{"Log", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 265, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"Log10", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 264, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"LookAt", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_VECTOR, LST_FLOATINGPOINT, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 105, 3, args, LST_NULL);
}}
        ,
{"LoopSound", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 87, 2, args, LST_NULL);
}}
        ,
{"LoopSoundMaster", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 88, 2, args, LST_NULL);
}}
        ,
{"LoopSoundSlave", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 89, 2, args, LST_NULL);
}}
        ,
{"MD5String", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 258, 2, args, LST_STRING);
}}
        ,
{"MakeExplosion", [](lua_State *L) {
    LLScriptLibData args[7];
    const LSCRIPTType types[] = {LST_INTEGER, LST_FLOATINGPOINT, LST_FLOATINGPOINT, LST_FLOATINGPOINT, LST_FLOATINGPOINT, LST_STRING, LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 7, types, args);
    return call_lib_func_lua(L, 100, 7, args, LST_NULL);
}}
        ,
{"MakeFire", [](lua_State *L) {
    LLScriptLibData args[7];
    const LSCRIPTType types[] = {LST_INTEGER, LST_FLOATINGPOINT, LST_FLOATINGPOINT, LST_FLOATINGPOINT, LST_FLOATINGPOINT, LST_STRING, LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 7, types, args);
    return call_lib_func_lua(L, 103, 7, args, LST_NULL);
}}
        ,
{"MakeFountain", [](lua_State *L) {
    LLScriptLibData args[9];
    const LSCRIPTType types[] = {LST_INTEGER, LST_FLOATINGPOINT, LST_FLOATINGPOINT, LST_FLOATINGPOINT, LST_FLOATINGPOINT, LST_INTEGER, LST_STRING, LST_VECTOR, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 9, types, args);
    return call_lib_func_lua(L, 101, 9, args, LST_NULL);
}}
        ,
{"MakeSmoke", [](lua_State *L) {
    LLScriptLibData args[7];
    const LSCRIPTType types[] = {LST_INTEGER, LST_FLOATINGPOINT, LST_FLOATINGPOINT, LST_FLOATINGPOINT, LST_FLOATINGPOINT, LST_STRING, LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 7, types, args);
    return call_lib_func_lua(L, 102, 7, args, LST_NULL);
}}
        ,
{"ManageEstateAccess", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 393, 2, args, LST_INTEGER);
}}
        ,
{"MapBeacon", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_VECTOR, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 516, 3, args, LST_NULL);
}}
        ,
{"MapDestination", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_VECTOR, LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 309, 3, args, LST_NULL);
}}
        ,
{"MessageLinked", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER, LST_STRING, LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 164, 4, args, LST_NULL);
}}
        ,
{"MinEventDelay", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 125, 1, args, LST_NULL);
}}
        ,
{"ModPow", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 300, 3, args, LST_INTEGER);
}}
        ,
{"ModifyLand", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 159, 2, args, LST_NULL);
}}
        ,
{"MoveToTarget", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 70, 2, args, LST_NULL);
}}
        ,
{"Name2Key", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 524, 1, args, LST_KEY);
}}
        ,
{"NavigateTo", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 398, 2, args, LST_NULL);
}}
        ,
{"OffsetTexture", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT, LST_FLOATINGPOINT, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 55, 3, args, LST_NULL);
}}
        ,
{"OpenFloater", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 604, 3, args, LST_INTEGER);
}}
        ,
{"OpenRemoteDataChannel", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 254, 0, args, LST_NULL);
}}
        ,
{"Ord", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 527, 2, args, LST_INTEGER);
}}
        ,
{"OverMyLand", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 215, 1, args, LST_INTEGER);
}}
        ,
{"OwnerSay", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 292, 1, args, LST_NULL);
}}
        ,
{"ParcelMediaCommandList", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 298, 1, args, LST_NULL);
}}
        ,
{"ParcelMediaQuery", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 299, 1, args, LST_LIST);
}}
        ,
{"ParseString2List", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_LIST, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 214, 3, args, LST_LIST);
}}
        ,
{"ParseStringKeepNulls", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_LIST, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 285, 3, args, LST_LIST);
}}
        ,
{"ParticleSystem", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 229, 1, args, LST_NULL);
}}
        ,
{"PassCollisions", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 166, 1, args, LST_NULL);
}}
        ,
{"PassTouches", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 154, 1, args, LST_NULL);
}}
        ,
{"PatrolPoints", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 403, 2, args, LST_NULL);
}}
        ,
{"PlaySound", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 86, 2, args, LST_NULL);
}}
        ,
{"PlaySoundSlave", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 90, 2, args, LST_NULL);
}}
        ,
{"PointAt", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 131, 1, args, LST_NULL);
}}
        ,
{"Pow", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 5, 2, args, LST_FLOATINGPOINT);
}}
        ,
{"PreloadSound", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 93, 1, args, LST_NULL);
}}
        ,
{"Pursue", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 400, 2, args, LST_NULL);
}}
        ,
{"PushObject", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_KEY, LST_VECTOR, LST_VECTOR, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 165, 4, args, LST_NULL);
}}
        ,
{"ReadKeyValue", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 388, 1, args, LST_KEY);
}}
        ,
{"RefreshPrimURL", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 306, 0, args, LST_NULL);
}}
        ,
{"RegionSay", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 331, 2, args, LST_NULL);
}}
        ,
{"RegionSayTo", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_KEY, LST_INTEGER, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 364, 3, args, LST_NULL);
}}
        ,
{"ReleaseCamera", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 116, 1, args, LST_NULL);
}}
        ,
{"ReleaseControls", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 112, 0, args, LST_NULL);
}}
        ,
{"ReleaseURL", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 347, 1, args, LST_NULL);
}}
        ,
{"RemoteDataReply", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_KEY, LST_KEY, LST_STRING, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 256, 4, args, LST_NULL);
}}
        ,
{"RemoteDataSetRegion", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 263, 0, args, LST_NULL);
}}
        ,
{"RemoteLoadScript", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_KEY, LST_STRING, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 251, 4, args, LST_NULL);
}}
        ,
{"RemoteLoadScriptPin", [](lua_State *L) {
    LLScriptLibData args[5];
    const LSCRIPTType types[] = {LST_KEY, LST_STRING, LST_INTEGER, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 5, types, args);
    return call_lib_func_lua(L, 253, 5, args, LST_NULL);
}}
        ,
{"RemoveFromLandBanList", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 312, 1, args, LST_NULL);
}}
        ,
{"RemoveFromLandPassList", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 311, 1, args, LST_NULL);
}}
        ,
{"RemoveInventory", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 151, 1, args, LST_NULL);
}}
        ,
{"RemoveVehicleFlags", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 237, 1, args, LST_NULL);
}}
        ,
{"ReplaceAgentEnvironment", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_KEY, LST_FLOATINGPOINT, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 713, 3, args, LST_INTEGER);
}}
        ,
{"ReplaceEnvironment", [](lua_State *L) {
    LLScriptLibData args[5];
    const LSCRIPTType types[] = {LST_VECTOR, LST_STRING, LST_INTEGER, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 5, types, args);
    return call_lib_func_lua(L, 718, 5, args, LST_INTEGER);
}}
        ,
{"ReplaceSubString", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING, LST_STRING, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 541, 4, args, LST_STRING);
}}
        ,
{"RequestAgentData", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 155, 2, args, LST_KEY);
}}
        ,
{"RequestDisplayName", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 361, 1, args, LST_KEY);
}}
        ,
{"RequestExperiencePermissions", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 384, 2, args, LST_NULL);
}}
        ,
{"RequestInventoryData", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 156, 1, args, LST_KEY);
}}
        ,
{"RequestPermissions", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 136, 2, args, LST_NULL);
}}
        ,
{"RequestSecureURL", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 346, 0, args, LST_KEY);
}}
        ,
{"RequestSimulatorData", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 293, 2, args, LST_KEY);
}}
        ,
{"RequestURL", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 345, 0, args, LST_KEY);
}}
        ,
{"RequestUserKey", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 525, 1, args, LST_KEY);
}}
        ,
{"RequestUsername", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 359, 1, args, LST_KEY);
}}
        ,
{"ResetAnimationOverride", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 502, 1, args, LST_NULL);
}}
        ,
{"ResetLandBanList", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 321, 0, args, LST_NULL);
}}
        ,
{"ResetLandPassList", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 322, 0, args, LST_NULL);
}}
        ,
{"ResetOtherScript", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 249, 1, args, LST_NULL);
}}
        ,
{"ResetScript", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 163, 0, args, LST_NULL);
}}
        ,
{"ResetTime", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 83, 0, args, LST_NULL);
}}
        ,
{"ReturnObjectsByID", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 520, 1, args, LST_INTEGER);
}}
        ,
{"ReturnObjectsByOwner", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 521, 2, args, LST_INTEGER);
}}
        ,
{"RezAtRoot", [](lua_State *L) {
    LLScriptLibData args[5];
    const LSCRIPTType types[] = {LST_STRING, LST_VECTOR, LST_VECTOR, LST_QUATERNION, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 5, types, args);
    return call_lib_func_lua(L, 286, 5, args, LST_NULL);
}}
        ,
{"RezObject", [](lua_State *L) {
    LLScriptLibData args[5];
    const LSCRIPTType types[] = {LST_STRING, LST_VECTOR, LST_VECTOR, LST_QUATERNION, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 5, types, args);
    return call_lib_func_lua(L, 104, 5, args, LST_NULL);
}}
        ,
{"RezObjectWithParams", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 544, 2, args, LST_KEY);
}}
        ,
{"Rot2Angle", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_QUATERNION};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 171, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"Rot2Axis", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_QUATERNION};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 170, 1, args, LST_VECTOR);
}}
        ,
{"Rot2Euler", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_QUATERNION};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 15, 1, args, LST_VECTOR);
}}
        ,
{"Rot2Fwd", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_QUATERNION};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 18, 1, args, LST_VECTOR);
}}
        ,
{"Rot2Left", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_QUATERNION};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 19, 1, args, LST_VECTOR);
}}
        ,
{"Rot2Up", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_QUATERNION};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 20, 1, args, LST_VECTOR);
}}
        ,
{"RotBetween", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 21, 2, args, LST_QUATERNION);
}}
        ,
{"RotLookAt", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_QUATERNION, LST_FLOATINGPOINT, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 127, 3, args, LST_NULL);
}}
        ,
{"RotTarget", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_QUATERNION, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 68, 2, args, LST_INTEGER);
}}
        ,
{"RotTargetRemove", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 69, 1, args, LST_NULL);
}}
        ,
{"RotateTexture", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 56, 2, args, LST_NULL);
}}
        ,
{"Round", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 11, 1, args, LST_INTEGER);
}}
        ,
{"SHA1String", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 343, 1, args, LST_STRING);
}}
        ,
{"SHA256String", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 531, 1, args, LST_STRING);
}}
        ,
{"SameGroup", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 219, 1, args, LST_INTEGER);
}}
        ,
{"Say", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 23, 2, args, LST_NULL);
}}
        ,
{"ScaleByFactor", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 592, 1, args, LST_INTEGER);
}}
        ,
{"ScaleTexture", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT, LST_FLOATINGPOINT, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 54, 3, args, LST_NULL);
}}
        ,
{"ScriptDanger", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 246, 1, args, LST_INTEGER);
}}
        ,
{"ScriptProfiler", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 367, 1, args, LST_NULL);
}}
        ,
{"SendRemoteData", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_KEY, LST_STRING, LST_INTEGER, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 255, 4, args, LST_KEY);
}}
        ,
{"Sensor", [](lua_State *L) {
    LLScriptLibData args[5];
    const LSCRIPTType types[] = {LST_STRING, LST_KEY, LST_INTEGER, LST_FLOATINGPOINT, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 5, types, args);
    return call_lib_func_lua(L, 28, 5, args, LST_NULL);
}}
        ,
{"SensorRemove", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 30, 0, args, LST_NULL);
}}
        ,
{"SensorRepeat", [](lua_State *L) {
    LLScriptLibData args[6];
    const LSCRIPTType types[] = {LST_STRING, LST_KEY, LST_INTEGER, LST_FLOATINGPOINT, LST_FLOATINGPOINT, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 6, types, args);
    return call_lib_func_lua(L, 29, 6, args, LST_NULL);
}}
        ,
{"SetAgentEnvironment", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_KEY, LST_FLOATINGPOINT, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 714, 3, args, LST_INTEGER);
}}
        ,
{"SetAgentRot", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_QUATERNION, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 515, 2, args, LST_NULL);
}}
        ,
{"SetAlpha", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 51, 2, args, LST_NULL);
}}
        ,
{"SetAngularVelocity", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 379, 2, args, LST_NULL);
}}
        ,
{"SetAnimationOverride", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 501, 2, args, LST_NULL);
}}
        ,
{"SetBuoyancy", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 122, 1, args, LST_NULL);
}}
        ,
{"SetCameraAtOffset", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 244, 1, args, LST_NULL);
}}
        ,
{"SetCameraEyeOffset", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 243, 1, args, LST_NULL);
}}
        ,
{"SetCameraParams", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 313, 1, args, LST_NULL);
}}
        ,
{"SetClickAction", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 333, 1, args, LST_NULL);
}}
        ,
{"SetColor", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 49, 2, args, LST_NULL);
}}
        ,
{"SetContentType", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 374, 2, args, LST_NULL);
}}
        ,
{"SetDamage", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 157, 1, args, LST_NULL);
}}
        ,
{"SetEnvironment", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 717, 2, args, LST_INTEGER);
}}
        ,
{"SetExperienceKey", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 386, 1, args, LST_INTEGER);
}}
        ,
{"SetForce", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 64, 2, args, LST_NULL);
}}
        ,
{"SetForceAndTorque", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_VECTOR, LST_VECTOR, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 76, 3, args, LST_NULL);
}}
        ,
{"SetGroundTexture", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 558, 1, args, LST_INTEGER);
}}
        ,
{"SetHoverHeight", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT, LST_INTEGER, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 123, 3, args, LST_NULL);
}}
        ,
{"SetInventoryPermMask", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 290, 3, args, LST_NULL);
}}
        ,
{"SetKeyframedMotion", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 394, 2, args, LST_NULL);
}}
        ,
{"SetLinkAlpha", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_INTEGER, LST_FLOATINGPOINT, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 274, 3, args, LST_NULL);
}}
        ,
{"SetLinkCamera", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_INTEGER, LST_VECTOR, LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 377, 3, args, LST_NULL);
}}
        ,
{"SetLinkColor", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_INTEGER, LST_VECTOR, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 140, 3, args, LST_NULL);
}}
        ,
{"SetLinkGLTFOverrides", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 560, 3, args, LST_NULL);
}}
        ,
{"SetLinkMedia", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 371, 3, args, LST_INTEGER);
}}
        ,
{"SetLinkPrimitiveParams", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 328, 2, args, LST_NULL);
}}
        ,
{"SetLinkPrimitiveParamsFast", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 353, 2, args, LST_NULL);
}}
        ,
{"SetLinkRenderMaterial", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_INTEGER, LST_STRING, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 762, 3, args, LST_NULL);
}}
        ,
{"SetLinkSitFlags", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 550, 2, args, LST_NULL);
}}
        ,
{"SetLinkTexture", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_INTEGER, LST_STRING, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 329, 3, args, LST_NULL);
}}
        ,
{"SetLinkTextureAnim", [](lua_State *L) {
    LLScriptLibData args[8];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER, LST_INTEGER, LST_INTEGER, LST_INTEGER, LST_FLOATINGPOINT, LST_FLOATINGPOINT, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 8, types, args);
    return call_lib_func_lua(L, 356, 8, args, LST_NULL);
}}
        ,
{"SetLocalRot", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_QUATERNION};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 284, 1, args, LST_NULL);
}}
        ,
{"SetMemoryLimit", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 369, 1, args, LST_INTEGER);
}}
        ,
{"SetObjectDesc", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 271, 1, args, LST_NULL);
}}
        ,
{"SetObjectName", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 203, 1, args, LST_NULL);
}}
        ,
{"SetObjectPermMask", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 288, 2, args, LST_NULL);
}}
        ,
{"SetParcelForSale", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 561, 2, args, LST_INTEGER);
}}
        ,
{"SetParcelMusicURL", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 267, 1, args, LST_NULL);
}}
        ,
{"SetPayPrice", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 302, 2, args, LST_NULL);
}}
        ,
{"SetPhysicsMaterial", [](lua_State *L) {
    LLScriptLibData args[5];
    const LSCRIPTType types[] = {LST_INTEGER, LST_FLOATINGPOINT, LST_FLOATINGPOINT, LST_FLOATINGPOINT, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 5, types, args);
    return call_lib_func_lua(L, 380, 5, args, LST_NULL);
}}
        ,
{"SetPos", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 58, 1, args, LST_NULL);
}}
        ,
{"SetPrimMediaParams", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 350, 2, args, LST_INTEGER);
}}
        ,
{"SetPrimURL", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 305, 1, args, LST_NULL);
}}
        ,
{"SetPrimitiveParams", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 259, 1, args, LST_NULL);
}}
        ,
{"SetRegionPos", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 397, 1, args, LST_INTEGER);
}}
        ,
{"SetRemoteScriptAccessPin", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 252, 1, args, LST_NULL);
}}
        ,
{"SetRenderMaterial", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 761, 2, args, LST_NULL);
}}
        ,
{"SetRot", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_QUATERNION};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 61, 1, args, LST_NULL);
}}
        ,
{"SetScale", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 47, 1, args, LST_NULL);
}}
        ,
{"SetScriptState", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 148, 2, args, LST_NULL);
}}
        ,
{"SetSitText", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 242, 1, args, LST_NULL);
}}
        ,
{"SetSoundQueueing", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 208, 1, args, LST_NULL);
}}
        ,
{"SetSoundRadius", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 209, 1, args, LST_NULL);
}}
        ,
{"SetStatus", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 45, 2, args, LST_NULL);
}}
        ,
{"SetText", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_VECTOR, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 152, 3, args, LST_NULL);
}}
        ,
{"SetTexture", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 53, 2, args, LST_NULL);
}}
        ,
{"SetTextureAnim", [](lua_State *L) {
    LLScriptLibData args[7];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER, LST_INTEGER, LST_INTEGER, LST_FLOATINGPOINT, LST_FLOATINGPOINT, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 7, types, args);
    return call_lib_func_lua(L, 211, 7, args, LST_NULL);
}}
        ,
{"SetTimerEvent", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 107, 1, args, LST_NULL);
}}
        ,
{"SetTorque", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 74, 2, args, LST_NULL);
}}
        ,
{"SetTouchText", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 241, 1, args, LST_NULL);
}}
        ,
{"SetVehicleFlags", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 236, 1, args, LST_NULL);
}}
        ,
{"SetVehicleFloatParam", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 233, 2, args, LST_NULL);
}}
        ,
{"SetVehicleRotationParam", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_QUATERNION};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 235, 2, args, LST_NULL);
}}
        ,
{"SetVehicleType", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 232, 1, args, LST_NULL);
}}
        ,
{"SetVehicleVectorParam", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 234, 2, args, LST_NULL);
}}
        ,
{"SetVelocity", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 378, 2, args, LST_NULL);
}}
        ,
{"Shout", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 24, 2, args, LST_NULL);
}}
        ,
{"SignRSA", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 539, 3, args, LST_STRING);
}}
        ,
{"Sin", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 0, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"SitOnLink", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 503, 2, args, LST_INTEGER);
}}
        ,
{"SitTarget", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_QUATERNION};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 238, 2, args, LST_NULL);
}}
        ,
{"Sleep", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 108, 1, args, LST_NULL);
}}
        ,
{"Sound", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_STRING, LST_FLOATINGPOINT, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 85, 4, args, LST_NULL);
}}
        ,
{"SoundPreload", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 126, 1, args, LST_NULL);
}}
        ,
{"Sqrt", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 4, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"StartAnimation", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 129, 1, args, LST_NULL);
}}
        ,
{"StartObjectAnimation", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 504, 1, args, LST_NULL);
}}
        ,
{"StopAnimation", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 130, 1, args, LST_NULL);
}}
        ,
{"StopHover", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 124, 0, args, LST_NULL);
}}
        ,
{"StopLookAt", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 106, 0, args, LST_NULL);
}}
        ,
{"StopMoveToTarget", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 71, 0, args, LST_NULL);
}}
        ,
{"StopObjectAnimation", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 505, 1, args, LST_NULL);
}}
        ,
{"StopPointAt", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 132, 0, args, LST_NULL);
}}
        ,
{"StopSound", [](lua_State *L) {
    LLScriptLibData args[0];
    const LSCRIPTType types[] = {};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 0, types, args);
    return call_lib_func_lua(L, 92, 0, args, LST_NULL);
}}
        ,
{"StringLength", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 128, 1, args, LST_INTEGER);
}}
        ,
{"StringToBase64", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 260, 1, args, LST_STRING);
}}
        ,
{"StringTrim", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 330, 2, args, LST_STRING);
}}
        ,
{"SubStringIndex", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 181, 2, args, LST_INTEGER);
}}
        ,
{"TakeCamera", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 115, 1, args, LST_NULL);
}}
        ,
{"TakeControls", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 111, 3, args, LST_NULL);
}}
        ,
{"Tan", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 2, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"Target", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 66, 2, args, LST_INTEGER);
}}
        ,
{"TargetOmega", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_VECTOR, LST_FLOATINGPOINT, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 133, 3, args, LST_NULL);
}}
        ,
{"TargetRemove", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 67, 1, args, LST_NULL);
}}
        ,
{"TargetedEmail", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_INTEGER, LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 750, 3, args, LST_NULL);
}}
        ,
{"TeleportAgent", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_KEY, LST_STRING, LST_VECTOR, LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 368, 4, args, LST_NULL);
}}
        ,
{"TeleportAgentGlobalCoords", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_KEY, LST_VECTOR, LST_VECTOR, LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 414, 4, args, LST_NULL);
}}
        ,
{"TeleportAgentHome", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 158, 1, args, LST_NULL);
}}
        ,
{"TextBox", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_KEY, LST_STRING, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 335, 3, args, LST_NULL);
}}
        ,
{"ToLower", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 98, 1, args, LST_STRING);
}}
        ,
{"ToUpper", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 97, 1, args, LST_STRING);
}}
        ,
{"TransferLindenDollars", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 395, 2, args, LST_KEY);
}}
        ,
{"TransferOwnership", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_KEY, LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 519, 3, args, LST_INTEGER);
}}
        ,
{"TriggerSound", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 91, 2, args, LST_NULL);
}}
        ,
{"TriggerSoundLimited", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_STRING, LST_FLOATINGPOINT, LST_VECTOR, LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 212, 4, args, LST_NULL);
}}
        ,
{"UnSit", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 220, 1, args, LST_NULL);
}}
        ,
{"UnescapeURL", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 308, 1, args, LST_STRING);
}}
        ,
{"UpdateCharacter", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 406, 1, args, LST_NULL);
}}
        ,
{"UpdateKeyValue", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING, LST_INTEGER, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 389, 4, args, LST_KEY);
}}
        ,
{"VecDist", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 14, 2, args, LST_FLOATINGPOINT);
}}
        ,
{"VecMag", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 12, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"VecNorm", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 13, 1, args, LST_VECTOR);
}}
        ,
{"VerifyRSA", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING, LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    return call_lib_func_lua(L, 540, 4, args, LST_INTEGER);
}}
        ,
{"VolumeDetect", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 248, 1, args, LST_NULL);
}}
        ,
{"WanderWithin", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_VECTOR, LST_VECTOR, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    return call_lib_func_lua(L, 401, 3, args, LST_NULL);
}}
        ,
{"Water", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 153, 1, args, LST_FLOATINGPOINT);
}}
        ,
{"Whisper", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 22, 2, args, LST_NULL);
}}
        ,
{"Wind", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 44, 1, args, LST_VECTOR);
}}
        ,
{"WorldPosToHUD", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 547, 1, args, LST_VECTOR);
}}
        ,
{"XorBase64", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 522, 2, args, LST_STRING);
}}
        ,
{"XorBase64Strings", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 262, 2, args, LST_STRING);
}}
        ,
{"XorBase64StringsCorrect", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    return call_lib_func_lua(L, 319, 2, args, LST_STRING);
}}
        ,
{"sRGB2Linear", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    return call_lib_func_lua(L, 716, 1, args, LST_VECTOR);
}}
        