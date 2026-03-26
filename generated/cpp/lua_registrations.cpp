
{"AdjustDamage", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 555, 2, args, LST_NULL, false, false);
}}
        ,
{"AgentInExperience", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 392, 1, args, LST_INTEGER, !compat_mode, false);
}}
        ,
{"DeleteSubList", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[1].mInteger = luaSL_checkindexlike(L, 2);
        args[2].mInteger = luaSL_checkindexlike(L, 3);
    }

    return call_lib_func_lua(L, 193, 3, args, LST_LIST, false, false);
}}
        ,
{"DeleteSubString", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[1].mInteger = luaSL_checkindexlike(L, 2);
        args[2].mInteger = luaSL_checkindexlike(L, 3);
    }

    return call_lib_func_lua(L, 95, 3, args, LST_STRING, false, false);
}}
        ,
{"DerezObject", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 509, 2, args, LST_INTEGER, !compat_mode, false);
}}
        ,
{"DetectedDamage", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 554, 1, args, LST_LIST, false, false);
}}
        ,
{"DetectedGrab", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 37, 1, args, LST_VECTOR, false, false);
}}
        ,
{"DetectedGroup", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 39, 1, args, LST_INTEGER, !compat_mode, false);
}}
        ,
{"DetectedKey", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 32, 1, args, LST_KEY, false, false);
}}
        ,
{"DetectedLinkNumber", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 40, 1, args, LST_INTEGER, false, false);
}}
        ,
{"DetectedName", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 31, 1, args, LST_STRING, false, false);
}}
        ,
{"DetectedOwner", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 33, 1, args, LST_KEY, false, false);
}}
        ,
{"DetectedPos", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 35, 1, args, LST_VECTOR, false, false);
}}
        ,
{"DetectedRezzer", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 553, 1, args, LST_KEY, false, false);
}}
        ,
{"DetectedRot", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 38, 1, args, LST_QUATERNION, false, false);
}}
        ,
{"DetectedTouchBinormal", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 341, 1, args, LST_VECTOR, false, false);
}}
        ,
{"DetectedTouchFace", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 338, 1, args, LST_INTEGER, false, false);
}}
        ,
{"DetectedTouchNormal", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 340, 1, args, LST_VECTOR, false, false);
}}
        ,
{"DetectedTouchPos", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 339, 1, args, LST_VECTOR, false, false);
}}
        ,
{"DetectedTouchST", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 342, 1, args, LST_VECTOR, false, false);
}}
        ,
{"DetectedTouchUV", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 337, 1, args, LST_VECTOR, false, false);
}}
        ,
{"DetectedType", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 34, 1, args, LST_INTEGER, false, false);
}}
        ,
{"DetectedVel", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 36, 1, args, LST_VECTOR, false, false);
}}
        ,
{"EdgeOfWorld", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 205, 2, args, LST_INTEGER, !compat_mode, false);
}}
        ,
{"FindNotecardTextSync", [](lua_State *L) {
    LLScriptLibData args[5];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING, LST_INTEGER, LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 5, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[2].mInteger = luaSL_checkindexlike(L, 3);
    }

    return call_lib_func_lua(L, 508, 5, args, LST_LIST, false, !compat_mode);
}}
        ,
{"GetEnvironment", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 711, 2, args, LST_LIST, !compat_mode, false);
}}
        ,
{"GetInventoryName", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[1].mInteger = luaSL_checkindexlike(L, 2);
    }

    return call_lib_func_lua(L, 147, 2, args, LST_STRING, false, false);
}}
        ,
{"GetLinkMedia", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 372, 3, args, LST_LIST, !compat_mode, false);
}}
        ,
{"GetLinkPrimitiveParams", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 354, 2, args, LST_LIST, !compat_mode, false);
}}
        ,
{"GetListEntryType", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[1].mInteger = luaSL_checkindexlike(L, 2);
    }

    return call_lib_func_lua(L, 194, 2, args, LST_INTEGER, false, false);
}}
        ,
{"GetNotecardLine", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[1].mInteger = luaSL_checkindexlike(L, 2);
    }

    return call_lib_func_lua(L, 217, 2, args, LST_KEY, false, false);
}}
        ,
{"GetNotecardLineSync", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[1].mInteger = luaSL_checkindexlike(L, 2);
    }

    return call_lib_func_lua(L, 549, 2, args, LST_STRING, false, false);
}}
        ,
{"GetObjectDetails", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_KEY, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 332, 2, args, LST_LIST, !compat_mode, false);
}}
        ,
{"GetParcelDetails", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_VECTOR, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 327, 2, args, LST_LIST, !compat_mode, false);
}}
        ,
{"GetPrimMediaParams", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 351, 2, args, LST_LIST, !compat_mode, false);
}}
        ,
{"GetPrimitiveParams", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 279, 1, args, LST_LIST, !compat_mode, false);
}}
        ,
{"GetScriptState", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 250, 1, args, LST_INTEGER, !compat_mode, false);
}}
        ,
{"GetStatus", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 46, 1, args, LST_INTEGER, !compat_mode, false);
}}
        ,
{"GetSubString", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[1].mInteger = luaSL_checkindexlike(L, 2);
        args[2].mInteger = luaSL_checkindexlike(L, 3);
    }

    return call_lib_func_lua(L, 94, 3, args, LST_STRING, false, false);
}}
        ,
{"InsertString", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[1].mInteger = luaSL_checkindexlike(L, 2);
    }

    return call_lib_func_lua(L, 96, 3, args, LST_STRING, false, false);
}}
        ,
{"IsFriend", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 542, 1, args, LST_INTEGER, !compat_mode, false);
}}
        ,
{"IsLinkGLTFMaterial", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 559, 2, args, LST_INTEGER, !compat_mode, false);
}}
        ,
{"KeysKeyValue", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 602, 2, args, LST_KEY, false, false);
}}
        ,
{"LinksetDataFindKeys", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[1].mInteger = luaSL_checkindexlike(L, 2);
    }

    return call_lib_func_lua(L, 657, 3, args, LST_LIST, false, false);
}}
        ,
{"LinksetDataListKeys", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[0].mInteger = luaSL_checkindexlike(L, 1);
    }

    return call_lib_func_lua(L, 656, 2, args, LST_LIST, false, false);
}}
        ,
{"List2Float", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[1].mInteger = luaSL_checkindexlike(L, 2);
    }

    return call_lib_func_lua(L, 187, 2, args, LST_FLOATINGPOINT, false, false);
}}
        ,
{"List2Integer", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[1].mInteger = luaSL_checkindexlike(L, 2);
    }

    return call_lib_func_lua(L, 186, 2, args, LST_INTEGER, false, false);
}}
        ,
{"List2Key", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[1].mInteger = luaSL_checkindexlike(L, 2);
    }

    return call_lib_func_lua(L, 189, 2, args, LST_KEY, false, false);
}}
        ,
{"List2List", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[1].mInteger = luaSL_checkindexlike(L, 2);
        args[2].mInteger = luaSL_checkindexlike(L, 3);
    }

    return call_lib_func_lua(L, 192, 3, args, LST_LIST, false, false);
}}
        ,
{"List2ListSlice", [](lua_State *L) {
    LLScriptLibData args[5];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER, LST_INTEGER, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 5, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[1].mInteger = luaSL_checkindexlike(L, 2);
        args[2].mInteger = luaSL_checkindexlike(L, 3);
        args[4].mInteger = luaSL_checkindexlike(L, 5);
    }

    return call_lib_func_lua(L, 801, 5, args, LST_LIST, false, false);
}}
        ,
{"List2ListStrided", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[1].mInteger = luaSL_checkindexlike(L, 2);
        args[2].mInteger = luaSL_checkindexlike(L, 3);
    }

    return call_lib_func_lua(L, 198, 4, args, LST_LIST, false, false);
}}
        ,
{"List2Rot", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[1].mInteger = luaSL_checkindexlike(L, 2);
    }

    return call_lib_func_lua(L, 191, 2, args, LST_QUATERNION, false, false);
}}
        ,
{"List2String", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[1].mInteger = luaSL_checkindexlike(L, 2);
    }

    return call_lib_func_lua(L, 188, 2, args, LST_STRING, false, false);
}}
        ,
{"List2Vector", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[1].mInteger = luaSL_checkindexlike(L, 2);
    }

    return call_lib_func_lua(L, 190, 2, args, LST_VECTOR, false, false);
}}
        ,
{"ListFindList", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_LIST, LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 201, 2, args, LST_INTEGER, false, !compat_mode);
}}
        ,
{"ListFindListNext", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_LIST, LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[2].mInteger = luaSL_checkindexlike(L, 3);
    }

    return call_lib_func_lua(L, 803, 3, args, LST_INTEGER, false, !compat_mode);
}}
        ,
{"ListFindStrided", [](lua_State *L) {
    LLScriptLibData args[5];
    const LSCRIPTType types[] = {LST_LIST, LST_LIST, LST_INTEGER, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 5, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[2].mInteger = luaSL_checkindexlike(L, 3);
        args[3].mInteger = luaSL_checkindexlike(L, 4);
    }

    return call_lib_func_lua(L, 800, 5, args, LST_INTEGER, false, !compat_mode);
}}
        ,
{"ListInsertList", [](lua_State *L) {
    LLScriptLibData args[3];
    const LSCRIPTType types[] = {LST_LIST, LST_LIST, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 3, types, args);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[2].mInteger = luaSL_checkindexlike(L, 3);
    }

    return call_lib_func_lua(L, 200, 3, args, LST_LIST, false, false);
}}
        ,
{"ListReplaceList", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_LIST, LST_LIST, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[2].mInteger = luaSL_checkindexlike(L, 3);
        args[3].mInteger = luaSL_checkindexlike(L, 4);
    }

    return call_lib_func_lua(L, 296, 4, args, LST_LIST, false, false);
}}
        ,
{"ListSortStrided", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_LIST, LST_INTEGER, LST_INTEGER, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[2].mInteger = luaSL_checkindexlike(L, 3);
    }

    return call_lib_func_lua(L, 802, 4, args, LST_LIST, false, false);
}}
        ,
{"ManageEstateAccess", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_INTEGER, LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 393, 2, args, LST_INTEGER, !compat_mode, false);
}}
        ,
{"Ord", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));
    if (!compat_mode)
    {
        args[1].mInteger = luaSL_checkindexlike(L, 2);
    }

    return call_lib_func_lua(L, 527, 2, args, LST_INTEGER, false, false);
}}
        ,
{"OverMyLand", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 215, 1, args, LST_INTEGER, !compat_mode, false);
}}
        ,
{"ParcelMediaQuery", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_LIST};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 299, 1, args, LST_LIST, !compat_mode, false);
}}
        ,
{"SameGroup", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_KEY};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 219, 1, args, LST_INTEGER, !compat_mode, false);
}}
        ,
{"ScaleByFactor", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_FLOATINGPOINT};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 592, 1, args, LST_INTEGER, !compat_mode, false);
}}
        ,
{"ScriptDanger", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 246, 1, args, LST_INTEGER, !compat_mode, false);
}}
        ,
{"SetMemoryLimit", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_INTEGER};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 369, 1, args, LST_INTEGER, !compat_mode, false);
}}
        ,
{"SetRegionPos", [](lua_State *L) {
    LLScriptLibData args[1];
    const LSCRIPTType types[] = {LST_VECTOR};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 1, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 397, 1, args, LST_INTEGER, !compat_mode, false);
}}
        ,
{"SubStringIndex", [](lua_State *L) {
    LLScriptLibData args[2];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 2, types, args);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 181, 2, args, LST_INTEGER, false, !compat_mode);
}}
        ,
{"VerifyRSA", [](lua_State *L) {
    LLScriptLibData args[4];
    const LSCRIPTType types[] = {LST_STRING, LST_STRING, LST_STRING, LST_STRING};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, 4, types, args);
    luau_interruptoncalltail(L);
    const bool compat_mode = lua_toboolean(L, lua_upvalueindex(1));

    return call_lib_func_lua(L, 540, 4, args, LST_INTEGER, !compat_mode, false);
}}
        