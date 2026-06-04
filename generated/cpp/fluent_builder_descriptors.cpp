// particle-params
static const FluentParamDescriptor kParticleParamsDescs[] = {
    {"flags", 'i', 0},
    {"start_color", 'v', 1},
    {"start_alpha", 'f', 2},
    {"end_color", 'v', 3},
    {"end_alpha", 'f', 4},
    {"start_scale", 'v', 5},
    {"end_scale", 'v', 6},
    {"part_max_age", 'f', 7},
    {"accel", 'v', 8},
    {"pattern", 'i', 9},
    {"innerangle", 'f', 10},
    {"outerangle", 'f', 11},
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
    {"start_glow", 'f', 26},
    {"end_glow", 'f', 27},
};
static FluentBuilderDef* kParticleParamsDef = fluent_builder_def_build(
    "ParticleSystem", "LinkParticleSystem",
    kParticleParamsDescs, std::size(kParticleParamsDescs));
slua_open_fluent_builder(L, "llparticle", "ParticleParams", kParticleParamsDef);
static const FluentFlagDescriptor kParticleParamFlagDescs[] = {
    {"interp_color", 0x1, 0},
    {"interp_scale", 0x2, 0},
    {"bounce", 0x4, 0},
    {"wind", 0x8, 0},
    {"follow", 0x10, 0},
    {"follow_velocity", 0x20, 0},
    {"target_pos", 0x40, 0},
    {"target_linear", 0x80, 0},
    {"emissive", 0x100, 0},
    {"ribbon", 0x400, 0},
};
fluent_builder_def_add_flags(kParticleParamsDef, kParticleParamFlagDescs, std::size(kParticleParamFlagDescs));