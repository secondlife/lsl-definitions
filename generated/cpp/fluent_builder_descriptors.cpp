// particle-params
static const FluentParamDescriptor kParticleParamsDescs[] = {
    {"flags", 'i', 0},
    {"color_begin", 'v', 1},
    {"alpha_begin", 'f', 2},
    {"color_end", 'v', 3},
    {"alpha_end", 'f', 4},
    {"scale_begin", 'v', 5},
    {"scale_end", 'v', 6},
    {"part_max_age", 'f', 7},
    {"accel", 'v', 8},
    {"pattern", 'i', 9},
    {"angle_inner", 'f', 10},
    {"angle_outer", 'f', 11},
    {"texture", 'a', 12},
    {"burst_rate", 'f', 13},
    {"burst_count", 'i', 15},
    {"burst_radius", 'f', 16},
    {"burst_speed_min", 'f', 17},
    {"burst_speed_max", 'f', 18},
    {"src_max_age", 'f', 19},
    {"target_key", 'k', 20},
    {"omega", 'v', 21},
    {"angle_begin", 'f', 22},
    {"angle_end", 'f', 23},
    {"blend_func_source", 'i', 24},
    {"blend_func_dest", 'i', 25},
    {"glow_begin", 'f', 26},
    {"glow_end", 'f', 27},
};
static const FluentFlagDescriptor kParticleParamFlagDescs[] = {
    {"color_interp", 0x1, 0},
    {"scale_interp", 0x2, 0},
    {"bounce", 0x4, 0},
    {"wind", 0x8, 0},
    {"follow", 0x10, 0},
    {"follow_velocity", 0x20, 0},
    {"target_pos", 0x40, 0},
    {"target_linear", 0x80, 0},
    {"emissive", 0x100, 0},
    {"ribbon", 0x400, 0},
};
static FluentBuilderDef* kParticleParamsDef = []() {
    auto* d = fluent_builder_def_build(kParticleParamsDescs, std::size(kParticleParamsDescs));
    fluent_builder_def_add_flags(d, kParticleParamFlagDescs, std::size(kParticleParamFlagDescs));
    return d;
}();
auto particle_system = [](lua_State* L) -> int {
    const auto* def = (const FluentBuilderDef*)lua_tolightuserdata(L, lua_upvalueindex(1));
    int link = lua_isnoneornil(L, 2) ? SLUA_LINK_THIS : luaL_checkinteger(L, 2);
    slua_fluent_serialize(L, 1, def);
    int rules_idx = lua_gettop(L);
    lua_rawgetfield(L, LUA_BASEGLOBALSINDEX, "ll");
    lua_rawgetfield(L, -1, "LinkParticleSystem");
    lua_pushinteger(L, link);
    lua_pushvalue(L, rules_idx);
    lua_call(L, 2, 0);
    return 0;
};
slua_register_fluent_fn(L, "llprim", "particleSystem", particle_system, kParticleParamsDef);

// prim-media-params
static const FluentParamDescriptor kPrimMediaParamsDescs[] = {
    {"alt_image_enable", 'b', 0},
    {"controls", 'i', 1},
    {"current_url", 's', 2},
    {"home_url", 's', 3},
    {"auto_loop", 'b', 4},
    {"auto_play", 'b', 5},
    {"auto_scale", 'b', 6},
    {"auto_zoom", 'b', 7},
    {"first_click_interact", 'b', 8},
    {"width_pixels", 'i', 9},
    {"height_pixels", 'i', 10},
    {"whitelist_enable", 'b', 11},
    {"whitelist", 'C', 12},
    {"perms_interact", 'i', 13},
    {"perms_control", 'i', 14},
};
static FluentBuilderDef* kPrimMediaParamsDef = fluent_builder_def_build(kPrimMediaParamsDescs, std::size(kPrimMediaParamsDescs));
auto set_media = [](lua_State* L) -> int {
    const auto* def = (const FluentBuilderDef*)lua_tolightuserdata(L, lua_upvalueindex(1));
    int face = luaL_checkinteger(L, 1);
    int link = lua_isnoneornil(L, 3) ? SLUA_LINK_THIS : luaL_checkinteger(L, 3);
    slua_fluent_serialize(L, 2, def);
    int rules_idx = lua_gettop(L);
    lua_rawgetfield(L, LUA_BASEGLOBALSINDEX, "ll");
    lua_rawgetfield(L, -1, "SetLinkMedia");
    lua_pushinteger(L, link);
    lua_pushinteger(L, face);
    lua_pushvalue(L, rules_idx);
    lua_call(L, 3, 0);
    return 0;
};
slua_register_fluent_fn(L, "llprim", "setMedia", set_media, kPrimMediaParamsDef);