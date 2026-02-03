
extern "C"
{
#include <mono/metadata/metadata.h>
#include <mono/metadata/object.h>
#include <mono/jit/jit.h>
}

#include "llscriptexecutemono.h"
#include "llmonointerfacehelpers.h"

typedef void (*PtrType)();

static void _mono_binding_add_to_land_ban_list_func(MonoKeyType p0, F32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(310, retval, 2, args, 10.0, 0.1);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_add_to_land_pass_list_func(MonoKeyType p0, F32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(240, retval, 2, args, 10.0, 0.1);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_adjust_damage_func(S32 p0, F32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(555, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_adjust_sound_volume_func(F32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<F32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(207, retval, 1, args, 10.0, 0.1);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_agent_in_experience_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(392, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_allow_inventory_drop_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(176, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static F32 _mono_binding_angle_between_func(MonoQuaternionType p0, MonoQuaternionType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoQuaternionType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoQuaternionType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(174, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static void _mono_binding_apply_impulse_func(MonoVectorType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(72, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_apply_rotational_impulse_func(MonoVectorType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(73, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_attach_to_avatar_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(113, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_attach_to_avatar_temp_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(391, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoKeyType _mono_binding_avatar_on_link_sit_target_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(376, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoKeyType _mono_binding_avatar_on_sit_target_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(239, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoQuaternionType _mono_binding_axes_to_rot_func(MonoVectorType p0, MonoVectorType p1, MonoVectorType p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoVectorType>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_QUATERNION;
    call_lib_func(17, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoQuaternionType>::get(retval);
}

static MonoQuaternionType _mono_binding_axis_angle_to_rot_func(MonoVectorType p0, F32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_QUATERNION;
    call_lib_func(169, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoQuaternionType>::get(retval);
}

static S32 _mono_binding_base64_to_integer_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(281, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoStringType _mono_binding_base64_to_string_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(261, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static void _mono_binding_break_all_links_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(143, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_break_link_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(142, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoListType _mono_binding_csv_to_list_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(196, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoListType _mono_binding_cast_ray_func(MonoVectorType p0, MonoVectorType p1, MonoListType p2, S32 p2_length)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoListType>::set(args[2], p2, p2_length);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(363, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoStringType _mono_binding_char_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(526, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static void _mono_binding_clear_camera_params_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(314, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_clear_experience_func(MonoKeyType p0, MonoKeyType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoKeyType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(411, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_clear_experience_permissions_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(385, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_clear_link_media_func(S32 p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(373, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_clear_prim_media_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(352, retval, 1, args, 10.0, 1.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_close_remote_data_channel_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(257, retval, 1, args, 10.0, 1.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static F32 _mono_binding_cloud_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(43, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static void _mono_binding_collision_filter_func(MonoStringType p0, MonoKeyType p1, S32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoKeyType>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(110, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_collision_sound_func(MonoStringType p0, F32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(160, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_collision_sprite_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(161, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoStringType _mono_binding_compute_hash_func(MonoStringType p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(548, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static void _mono_binding_create_character_func(MonoListType p0, S32 p0_length)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(399, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoKeyType _mono_binding_create_key_value_func(MonoStringType p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(387, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static void _mono_binding_create_link_func(MonoKeyType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(141, retval, 2, args, 10.0, 0.1);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_damage_func(MonoKeyType p0, F32 p1, S32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(671, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoKeyType _mono_binding_data_size_key_value_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(600, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static void _mono_binding_delete_character_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(405, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoKeyType _mono_binding_delete_key_value_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(390, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoStringType _mono_binding_delete_sub_string_func(MonoStringType p0, S32 p1, S32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(95, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static S32 _mono_binding_derez_object_func(MonoKeyType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(509, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_detach_from_avatar_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(114, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoListType _mono_binding_detected_damage_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(554, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoVectorType _mono_binding_detected_grab_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(37, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static S32 _mono_binding_detected_group_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(39, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoKeyType _mono_binding_detected_key_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(32, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static S32 _mono_binding_detected_link_number_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(40, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoStringType _mono_binding_detected_name_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(31, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoKeyType _mono_binding_detected_owner_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(33, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoVectorType _mono_binding_detected_pos_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(35, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoKeyType _mono_binding_detected_rezzer_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(553, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoQuaternionType _mono_binding_detected_rot_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_QUATERNION;
    call_lib_func(38, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoQuaternionType>::get(retval);
}

static MonoVectorType _mono_binding_detected_touch_binormal_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(341, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static S32 _mono_binding_detected_touch_face_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(338, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoVectorType _mono_binding_detected_touch_normal_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(340, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoVectorType _mono_binding_detected_touch_pos_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(339, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoVectorType _mono_binding_detected_touch_st_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(342, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoVectorType _mono_binding_detected_touch_uv_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(337, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static S32 _mono_binding_detected_type_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(34, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoVectorType _mono_binding_detected_vel_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(36, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static void _mono_binding_dialog_func(MonoKeyType p0, MonoStringType p1, MonoListType p2, S32 p2_length, S32 p3)
{
    LLScriptLibData args[4];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoListType>::set(args[2], p2, p2_length);
    LLScriptLibDataHelper<S32>::set(args[3], p3);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(247, retval, 4, args, 10.0, 1.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_die_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(41, retval, 0, args, 0.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_edge_of_world_func(MonoVectorType p0, MonoVectorType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(205, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_eject_from_land_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(213, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_email_func(MonoStringType p0, MonoStringType p1, MonoStringType p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoStringType>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(119, retval, 3, args, 10.0, 20.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoStringType _mono_binding_escape_url_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(307, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoQuaternionType _mono_binding_euler_to_rot_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_QUATERNION;
    call_lib_func(16, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoQuaternionType>::get(retval);
}

static void _mono_binding_evade_func(MonoKeyType p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(407, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_exec_character_cmd_func(S32 p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(404, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoKeyType _mono_binding_find_notecard_text_count_func(MonoStringType p0, MonoStringType p1, MonoListType p2, S32 p2_length)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoListType>::set(args[2], p2, p2_length);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(507, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoListType _mono_binding_find_notecard_text_sync_func(MonoStringType p0, MonoStringType p1, S32 p2, S32 p3, MonoListType p4, S32 p4_length)
{
    LLScriptLibData args[5];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibDataHelper<S32>::set(args[3], p3);
    LLScriptLibDataHelper<MonoListType>::set(args[4], p4, p4_length);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(508, retval, 5, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static void _mono_binding_flee_from_func(MonoVectorType p0, F32 p1, MonoListType p2, S32 p2_length)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibDataHelper<MonoListType>::set(args[2], p2, p2_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(402, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_force_mouselook_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(294, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static F32 _mono_binding_frand_func(F32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<F32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(8, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static MonoKeyType _mono_binding_generate_key_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(383, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoVectorType _mono_binding_get_accel_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(78, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static S32 _mono_binding_get_agent_info_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(206, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoStringType _mono_binding_get_agent_language_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(336, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoListType _mono_binding_get_agent_list_func(S32 p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(412, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoVectorType _mono_binding_get_agent_size_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(218, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static F32 _mono_binding_get_alpha_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(50, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static F32 _mono_binding_get_and_reset_time_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(84, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static MonoStringType _mono_binding_get_animation_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(162, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoListType _mono_binding_get_animation_list_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(266, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoStringType _mono_binding_get_animation_override_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(500, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static S32 _mono_binding_get_attached_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(224, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoListType _mono_binding_get_attached_list_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(523, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoListType _mono_binding_get_attached_list_filtered_func(MonoKeyType p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(518, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoListType _mono_binding_get_bounding_box_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(277, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static F32 _mono_binding_get_camera_aspect_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(545, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static F32 _mono_binding_get_camera_fov_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(546, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static MonoVectorType _mono_binding_get_camera_pos_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(303, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoQuaternionType _mono_binding_get_camera_rot_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_QUATERNION;
    call_lib_func(304, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoQuaternionType>::get(retval);
}

static MonoVectorType _mono_binding_get_center_of_mass_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(183, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoListType _mono_binding_get_closest_nav_point_func(MonoVectorType p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(408, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoVectorType _mono_binding_get_color_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(52, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoKeyType _mono_binding_get_creator_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(272, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoStringType _mono_binding_get_date_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(204, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static S32 _mono_binding_get_day_length_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(703, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_get_day_offset_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(705, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoStringType _mono_binding_get_display_name_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(360, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static F32 _mono_binding_get_energy_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(149, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static MonoStringType _mono_binding_get_env_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(362, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoListType _mono_binding_get_environment_func(MonoVectorType p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(711, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoListType _mono_binding_get_experience_details_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(409, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoStringType _mono_binding_get_experience_error_message_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(603, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoListType _mono_binding_get_experience_list_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(410, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoVectorType _mono_binding_get_force_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(65, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static S32 _mono_binding_get_free_memory_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(225, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_get_free_ur_ls_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(344, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static F32 _mono_binding_get_gm_tclock_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(282, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static MonoVectorType _mono_binding_get_geometric_center_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(278, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoStringType _mono_binding_get_http_header_func(MonoKeyType p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(349, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static F32 _mono_binding_get_health_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(552, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static MonoStringType _mono_binding_get_inventory_acquire_time_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(529, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoKeyType _mono_binding_get_inventory_creator_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(291, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoStringType _mono_binding_get_inventory_desc_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(543, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoKeyType _mono_binding_get_inventory_key_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(175, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoStringType _mono_binding_get_inventory_name_func(S32 p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(147, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static S32 _mono_binding_get_inventory_number_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(146, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_get_inventory_perm_mask_func(MonoStringType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(289, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_get_inventory_type_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(301, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoKeyType _mono_binding_get_key_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(121, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoKeyType _mono_binding_get_land_owner_at_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(216, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoKeyType _mono_binding_get_link_key_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(144, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoListType _mono_binding_get_link_media_func(S32 p0, S32 p1, MonoListType p2, S32 p2_length)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<MonoListType>::set(args[2], p2, p2_length);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(372, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoStringType _mono_binding_get_link_name_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(145, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static S32 _mono_binding_get_link_number_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(139, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_get_link_number_of_sides_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(357, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoListType _mono_binding_get_link_primitive_params_func(S32 p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(354, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static S32 _mono_binding_get_link_sit_flags_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(551, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoVectorType _mono_binding_get_local_pos_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(60, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoQuaternionType _mono_binding_get_local_rot_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_QUATERNION;
    call_lib_func(63, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoQuaternionType>::get(retval);
}

static F32 _mono_binding_get_mass_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(109, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static F32 _mono_binding_get_mass_mks_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(382, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static F32 _mono_binding_get_max_scale_factor_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(591, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static S32 _mono_binding_get_memory_limit_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(370, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static F32 _mono_binding_get_min_scale_factor_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(590, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static MonoVectorType _mono_binding_get_moon_direction_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(701, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoQuaternionType _mono_binding_get_moon_rotation_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_QUATERNION;
    call_lib_func(709, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoQuaternionType>::get(retval);
}

static void _mono_binding_get_next_email_func(MonoStringType p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(120, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoKeyType _mono_binding_get_notecard_line_func(MonoStringType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(217, retval, 2, args, 10.0, 0.1);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoStringType _mono_binding_get_notecard_line_sync_func(MonoStringType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(549, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoKeyType _mono_binding_get_number_of_notecard_lines_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(276, retval, 1, args, 10.0, 0.1);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static S32 _mono_binding_get_number_of_prims_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(275, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_get_number_of_sides_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(168, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoListType _mono_binding_get_object_animation_names_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(506, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoStringType _mono_binding_get_object_desc_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(270, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoListType _mono_binding_get_object_details_func(MonoKeyType p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(332, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoKeyType _mono_binding_get_object_link_key_func(MonoKeyType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(532, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static F32 _mono_binding_get_object_mass_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(295, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static MonoStringType _mono_binding_get_object_name_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(202, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static S32 _mono_binding_get_object_perm_mask_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(287, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_get_object_prim_count_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(323, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoVectorType _mono_binding_get_omega_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(79, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoKeyType _mono_binding_get_owner_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(117, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoKeyType _mono_binding_get_owner_key_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(182, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoListType _mono_binding_get_parcel_details_func(MonoVectorType p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(327, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static S32 _mono_binding_get_parcel_flags_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(317, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_get_parcel_max_prims_func(MonoVectorType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(326, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoStringType _mono_binding_get_parcel_music_url_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(396, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static S32 _mono_binding_get_parcel_prim_count_func(MonoVectorType p0, S32 p1, S32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(325, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoListType _mono_binding_get_parcel_prim_owners_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(324, retval, 1, args, 10.0, 2.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static S32 _mono_binding_get_permissions_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(138, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoKeyType _mono_binding_get_permissions_key_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(137, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoListType _mono_binding_get_physics_material_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(381, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoVectorType _mono_binding_get_pos_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(59, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoListType _mono_binding_get_prim_media_params_func(S32 p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(351, retval, 2, args, 10.0, 1.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoListType _mono_binding_get_primitive_params_func(MonoListType p0, S32 p0_length)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(279, retval, 1, args, 10.0, 0.2);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static S32 _mono_binding_get_region_agent_count_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(334, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoVectorType _mono_binding_get_region_corner_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(199, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static S32 _mono_binding_get_region_day_length_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(704, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_get_region_day_offset_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(706, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static F32 _mono_binding_get_region_fps_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(228, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static S32 _mono_binding_get_region_flags_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(318, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoVectorType _mono_binding_get_region_moon_direction_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(702, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoQuaternionType _mono_binding_get_region_moon_rotation_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_QUATERNION;
    call_lib_func(710, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoQuaternionType>::get(retval);
}

static MonoStringType _mono_binding_get_region_name_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(226, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoVectorType _mono_binding_get_region_sun_direction_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(700, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoQuaternionType _mono_binding_get_region_sun_rotation_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_QUATERNION;
    call_lib_func(708, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoQuaternionType>::get(retval);
}

static F32 _mono_binding_get_region_time_dilation_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(227, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static F32 _mono_binding_get_region_time_of_day_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(712, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static MonoStringType _mono_binding_get_render_material_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(760, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoVectorType _mono_binding_get_root_position_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(268, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoQuaternionType _mono_binding_get_root_rotation_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_QUATERNION;
    call_lib_func(269, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoQuaternionType>::get(retval);
}

static MonoQuaternionType _mono_binding_get_rot_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_QUATERNION;
    call_lib_func(62, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoQuaternionType>::get(retval);
}

static S32 _mono_binding_get_sp_max_memory_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(365, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoVectorType _mono_binding_get_scale_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(48, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoStringType _mono_binding_get_script_name_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(167, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static S32 _mono_binding_get_script_state_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(250, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static F32 _mono_binding_get_sim_stats_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(415, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static MonoStringType _mono_binding_get_simulator_hostname_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(283, retval, 0, args, 10.0, 10.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static S32 _mono_binding_get_start_parameter_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(134, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoStringType _mono_binding_get_start_string_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(556, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoListType _mono_binding_get_static_path_func(MonoVectorType p0, MonoVectorType p1, F32 p2, MonoListType p3, S32 p3_length)
{
    LLScriptLibData args[4];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibDataHelper<F32>::set(args[2], p2);
    LLScriptLibDataHelper<MonoListType>::set(args[3], p3, p3_length);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(413, retval, 4, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static S32 _mono_binding_get_status_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(46, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoStringType _mono_binding_get_sub_string_func(MonoStringType p0, S32 p1, S32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(94, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoVectorType _mono_binding_get_sun_direction_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(177, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoQuaternionType _mono_binding_get_sun_rotation_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_QUATERNION;
    call_lib_func(707, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoQuaternionType>::get(retval);
}

static MonoStringType _mono_binding_get_texture_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(57, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoVectorType _mono_binding_get_texture_offset_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(178, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static F32 _mono_binding_get_texture_rot_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(180, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static MonoVectorType _mono_binding_get_texture_scale_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(179, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static F32 _mono_binding_get_time_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(82, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static F32 _mono_binding_get_time_of_day_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(80, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static MonoStringType _mono_binding_get_timestamp_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(273, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoVectorType _mono_binding_get_torque_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(75, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static S32 _mono_binding_get_unix_time_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(316, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_get_used_memory_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(366, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoStringType _mono_binding_get_username_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(358, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoVectorType _mono_binding_get_vel_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(77, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoListType _mono_binding_get_visual_params_func(MonoKeyType p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(530, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static F32 _mono_binding_get_wallclock_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(81, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static S32 _mono_binding_give_agent_inventory_func(MonoKeyType p0, MonoStringType p1, MonoListType p2, S32 p2_length, MonoListType p3, S32 p3_length)
{
    LLScriptLibData args[4];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoListType>::set(args[2], p2, p2_length);
    LLScriptLibDataHelper<MonoListType>::set(args[3], p3, p3_length);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(517, retval, 4, args, 10.0, 3.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_give_inventory_func(MonoKeyType p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(150, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_give_inventory_list_func(MonoKeyType p0, MonoStringType p1, MonoListType p2, S32 p2_length)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoListType>::set(args[2], p2, p2_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(231, retval, 3, args, 10.0, 3.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_give_money_func(MonoKeyType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(99, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_god_like_rez_object_func(MonoKeyType p0, MonoVectorType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(135, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static F32 _mono_binding_ground_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(42, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static MonoVectorType _mono_binding_ground_contour_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(223, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoVectorType _mono_binding_ground_normal_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(222, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static void _mono_binding_ground_repel_func(F32 p0, S32 p1, F32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<F32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<F32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(230, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoVectorType _mono_binding_ground_slope_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(221, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoStringType _mono_binding_hmac_func(MonoStringType p0, MonoStringType p1, MonoStringType p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoStringType>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(538, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoKeyType _mono_binding_http_request_func(MonoStringType p0, MonoListType p1, S32 p1_length, MonoStringType p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibDataHelper<MonoStringType>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(320, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static void _mono_binding_http_response_func(MonoKeyType p0, S32 p1, MonoStringType p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<MonoStringType>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(348, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_hash_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(528, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoStringType _mono_binding_insert_string_func(MonoStringType p0, S32 p1, MonoStringType p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<MonoStringType>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(96, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static void _mono_binding_instant_message_func(MonoKeyType p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(118, retval, 2, args, 10.0, 2.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoStringType _mono_binding_integer_to_base64_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(280, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static S32 _mono_binding_is_friend_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(542, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_is_link_gltf_material_func(S32 p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(559, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoListType _mono_binding_json_to_list_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(513, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoStringType _mono_binding_json_get_value_func(MonoStringType p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(511, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoStringType _mono_binding_json_set_value_func(MonoStringType p0, MonoListType p1, S32 p1_length, MonoStringType p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibDataHelper<MonoStringType>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(510, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoStringType _mono_binding_json_value_type_func(MonoStringType p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(512, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoStringType _mono_binding_key_to_name_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(210, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoKeyType _mono_binding_key_count_key_value_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(601, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoKeyType _mono_binding_keys_key_value_func(S32 p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(602, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoVectorType _mono_binding_linear2s_rgb_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(715, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static void _mono_binding_link_adjust_sound_volume_func(S32 p0, F32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(535, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_link_particle_system_func(S32 p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(355, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_link_play_sound_func(S32 p0, MonoStringType p1, F32 p2, S32 p3)
{
    LLScriptLibData args[4];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<F32>::set(args[2], p2);
    LLScriptLibDataHelper<S32>::set(args[3], p3);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(533, retval, 4, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_link_set_sound_queueing_func(S32 p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(537, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_link_set_sound_radius_func(S32 p0, F32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(536, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_link_sit_target_func(S32 p0, MonoVectorType p1, MonoQuaternionType p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoQuaternionType>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(375, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_link_stop_sound_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(534, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_linkset_data_available_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(654, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_linkset_data_count_found_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(661, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_linkset_data_count_keys_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(653, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_linkset_data_delete_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(652, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoListType _mono_binding_linkset_data_delete_found_func(MonoStringType p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(662, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static S32 _mono_binding_linkset_data_delete_protected_func(MonoStringType p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(660, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoListType _mono_binding_linkset_data_find_keys_func(MonoStringType p0, S32 p1, S32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(657, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoListType _mono_binding_linkset_data_list_keys_func(S32 p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(656, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoStringType _mono_binding_linkset_data_read_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(651, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoStringType _mono_binding_linkset_data_read_protected_func(MonoStringType p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(659, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static void _mono_binding_linkset_data_reset_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(655, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_linkset_data_write_func(MonoStringType p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(650, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_linkset_data_write_protected_func(MonoStringType p0, MonoStringType p1, MonoStringType p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoStringType>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(658, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoStringType _mono_binding_list_to_csv_func(MonoListType p0, S32 p0_length)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(195, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoStringType _mono_binding_list_to_json_func(MonoStringType p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(514, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoListType _mono_binding_list_to_list_slice_func(MonoListType p0, S32 p0_length, S32 p1, S32 p2, S32 p3, S32 p4)
{
    LLScriptLibData args[5];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibDataHelper<S32>::set(args[3], p3);
    LLScriptLibDataHelper<S32>::set(args[4], p4);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(801, retval, 5, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoListType _mono_binding_list_to_list_strided_func(MonoListType p0, S32 p0_length, S32 p1, S32 p2, S32 p3)
{
    LLScriptLibData args[4];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibDataHelper<S32>::set(args[3], p3);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(198, retval, 4, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static S32 _mono_binding_list_find_list_func(MonoListType p0, S32 p0_length, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(201, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_list_find_list_next_func(MonoListType p0, S32 p0_length, MonoListType p1, S32 p1_length, S32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(803, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_list_find_strided_func(MonoListType p0, S32 p0_length, MonoListType p1, S32 p1_length, S32 p2, S32 p3, S32 p4)
{
    LLScriptLibData args[5];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibDataHelper<S32>::set(args[3], p3);
    LLScriptLibDataHelper<S32>::set(args[4], p4);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(800, retval, 5, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoListType _mono_binding_list_randomize_func(MonoListType p0, S32 p0_length, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(197, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoListType _mono_binding_list_sort_func(MonoListType p0, S32 p0_length, S32 p1, S32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(184, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoListType _mono_binding_list_sort_strided_func(MonoListType p0, S32 p0_length, S32 p1, S32 p2, S32 p3)
{
    LLScriptLibData args[4];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibDataHelper<S32>::set(args[3], p3);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(802, retval, 4, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static F32 _mono_binding_list_statistics_func(S32 p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(315, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static S32 _mono_binding_listen_func(S32 p0, MonoStringType p1, MonoKeyType p2, MonoStringType p3)
{
    LLScriptLibData args[4];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoKeyType>::set(args[2], p2);
    LLScriptLibDataHelper<MonoStringType>::set(args[3], p3);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(25, retval, 4, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_listen_control_func(S32 p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(26, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_listen_remove_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(27, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_load_url_func(MonoKeyType p0, MonoStringType p1, MonoStringType p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoStringType>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(297, retval, 3, args, 10.0, 0.1);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_look_at_func(MonoVectorType p0, F32 p1, F32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibDataHelper<F32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(105, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_loop_sound_func(MonoStringType p0, F32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(87, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_loop_sound_master_func(MonoStringType p0, F32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(88, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_loop_sound_slave_func(MonoStringType p0, F32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(89, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoStringType _mono_binding_md5_string_func(MonoStringType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(258, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static void _mono_binding_make_explosion_func(S32 p0, F32 p1, F32 p2, F32 p3, F32 p4, MonoStringType p5, MonoVectorType p6)
{
    LLScriptLibData args[7];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibDataHelper<F32>::set(args[2], p2);
    LLScriptLibDataHelper<F32>::set(args[3], p3);
    LLScriptLibDataHelper<F32>::set(args[4], p4);
    LLScriptLibDataHelper<MonoStringType>::set(args[5], p5);
    LLScriptLibDataHelper<MonoVectorType>::set(args[6], p6);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(100, retval, 7, args, 10.0, 0.1);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_make_fire_func(S32 p0, F32 p1, F32 p2, F32 p3, F32 p4, MonoStringType p5, MonoVectorType p6)
{
    LLScriptLibData args[7];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibDataHelper<F32>::set(args[2], p2);
    LLScriptLibDataHelper<F32>::set(args[3], p3);
    LLScriptLibDataHelper<F32>::set(args[4], p4);
    LLScriptLibDataHelper<MonoStringType>::set(args[5], p5);
    LLScriptLibDataHelper<MonoVectorType>::set(args[6], p6);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(103, retval, 7, args, 10.0, 0.1);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_make_fountain_func(S32 p0, F32 p1, F32 p2, F32 p3, F32 p4, S32 p5, MonoStringType p6, MonoVectorType p7, F32 p8)
{
    LLScriptLibData args[9];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibDataHelper<F32>::set(args[2], p2);
    LLScriptLibDataHelper<F32>::set(args[3], p3);
    LLScriptLibDataHelper<F32>::set(args[4], p4);
    LLScriptLibDataHelper<S32>::set(args[5], p5);
    LLScriptLibDataHelper<MonoStringType>::set(args[6], p6);
    LLScriptLibDataHelper<MonoVectorType>::set(args[7], p7);
    LLScriptLibDataHelper<F32>::set(args[8], p8);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(101, retval, 9, args, 10.0, 0.1);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_make_smoke_func(S32 p0, F32 p1, F32 p2, F32 p3, F32 p4, MonoStringType p5, MonoVectorType p6)
{
    LLScriptLibData args[7];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibDataHelper<F32>::set(args[2], p2);
    LLScriptLibDataHelper<F32>::set(args[3], p3);
    LLScriptLibDataHelper<F32>::set(args[4], p4);
    LLScriptLibDataHelper<MonoStringType>::set(args[5], p5);
    LLScriptLibDataHelper<MonoVectorType>::set(args[6], p6);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(102, retval, 7, args, 10.0, 0.1);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_manage_estate_access_func(S32 p0, MonoKeyType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoKeyType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(393, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_map_beacon_func(MonoStringType p0, MonoVectorType p1, MonoListType p2, S32 p2_length)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoListType>::set(args[2], p2, p2_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(516, retval, 3, args, 10.0, 1.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_map_destination_func(MonoStringType p0, MonoVectorType p1, MonoVectorType p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoVectorType>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(309, retval, 3, args, 10.0, 1.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_message_linked_func(S32 p0, S32 p1, MonoStringType p2, MonoKeyType p3)
{
    LLScriptLibData args[4];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<MonoStringType>::set(args[2], p2);
    LLScriptLibDataHelper<MonoKeyType>::set(args[3], p3);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(164, retval, 4, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_min_event_delay_func(F32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<F32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(125, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_mod_pow_func(S32 p0, S32 p1, S32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(300, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_modify_land_func(S32 p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(159, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_move_to_target_func(MonoVectorType p0, F32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(70, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoKeyType _mono_binding_name_to_key_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(524, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static void _mono_binding_navigate_to_func(MonoVectorType p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(398, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_offset_texture_func(F32 p0, F32 p1, S32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<F32>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(55, retval, 3, args, 10.0, 0.2);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_open_floater_func(MonoStringType p0, MonoStringType p1, MonoListType p2, S32 p2_length)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoListType>::set(args[2], p2, p2_length);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(604, retval, 3, args, 10.0, 0.2);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_open_remote_data_channel_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(254, retval, 0, args, 10.0, 1.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_ord_func(MonoStringType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(527, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_over_my_land_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(215, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_owner_say_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(292, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_parcel_media_command_list_func(MonoListType p0, S32 p0_length)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(298, retval, 1, args, 10.0, 2.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoListType _mono_binding_parcel_media_query_func(MonoListType p0, S32 p0_length)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(299, retval, 1, args, 10.0, 2.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoListType _mono_binding_parse_string_to_list_func(MonoStringType p0, MonoListType p1, S32 p1_length, MonoListType p2, S32 p2_length)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibDataHelper<MonoListType>::set(args[2], p2, p2_length);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(214, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static MonoListType _mono_binding_parse_string_keep_nulls_func(MonoStringType p0, MonoListType p1, S32 p1_length, MonoListType p2, S32 p2_length)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibDataHelper<MonoListType>::set(args[2], p2, p2_length);
    LLScriptLibData retval;
    retval.mType = LST_LIST;
    call_lib_func(285, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoListType>::get(retval);
}

static void _mono_binding_particle_system_func(MonoListType p0, S32 p0_length)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(229, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_pass_collisions_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(166, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_pass_touches_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(154, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_patrol_points_func(MonoListType p0, S32 p0_length, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(403, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_play_sound_func(MonoStringType p0, F32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(86, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_play_sound_slave_func(MonoStringType p0, F32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(90, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_point_at_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(131, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_preload_sound_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(93, retval, 1, args, 10.0, 1.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_pursue_func(MonoKeyType p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(400, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_push_object_func(MonoKeyType p0, MonoVectorType p1, MonoVectorType p2, S32 p3)
{
    LLScriptLibData args[4];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoVectorType>::set(args[2], p2);
    LLScriptLibDataHelper<S32>::set(args[3], p3);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(165, retval, 4, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoKeyType _mono_binding_read_key_value_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(388, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static void _mono_binding_refresh_prim_url_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(306, retval, 0, args, 10.0, 20.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_region_say_func(S32 p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(331, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_region_say_to_func(MonoKeyType p0, S32 p1, MonoStringType p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<MonoStringType>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(364, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_release_camera_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(116, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_release_controls_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(112, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_release_url_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(347, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_remote_data_reply_func(MonoKeyType p0, MonoKeyType p1, MonoStringType p2, S32 p3)
{
    LLScriptLibData args[4];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoKeyType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoStringType>::set(args[2], p2);
    LLScriptLibDataHelper<S32>::set(args[3], p3);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(256, retval, 4, args, 10.0, 3.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_remote_data_set_region_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(263, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_remote_load_script_func(MonoKeyType p0, MonoStringType p1, S32 p2, S32 p3)
{
    LLScriptLibData args[4];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibDataHelper<S32>::set(args[3], p3);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(251, retval, 4, args, 10.0, 3.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_remote_load_script_pin_func(MonoKeyType p0, MonoStringType p1, S32 p2, S32 p3, S32 p4)
{
    LLScriptLibData args[5];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibDataHelper<S32>::set(args[3], p3);
    LLScriptLibDataHelper<S32>::set(args[4], p4);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(253, retval, 5, args, 10.0, 3.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_remove_from_land_ban_list_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(312, retval, 1, args, 10.0, 0.1);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_remove_from_land_pass_list_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(311, retval, 1, args, 10.0, 0.1);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_remove_inventory_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(151, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_remove_vehicle_flags_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(237, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_replace_agent_environment_func(MonoKeyType p0, F32 p1, MonoStringType p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibDataHelper<MonoStringType>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(713, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_replace_environment_func(MonoVectorType p0, MonoStringType p1, S32 p2, S32 p3, S32 p4)
{
    LLScriptLibData args[5];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibDataHelper<S32>::set(args[3], p3);
    LLScriptLibDataHelper<S32>::set(args[4], p4);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(718, retval, 5, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoStringType _mono_binding_replace_sub_string_func(MonoStringType p0, MonoStringType p1, MonoStringType p2, S32 p3)
{
    LLScriptLibData args[4];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoStringType>::set(args[2], p2);
    LLScriptLibDataHelper<S32>::set(args[3], p3);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(541, retval, 4, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoKeyType _mono_binding_request_agent_data_func(MonoKeyType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(155, retval, 2, args, 10.0, 0.1);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoKeyType _mono_binding_request_display_name_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(361, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static void _mono_binding_request_experience_permissions_func(MonoKeyType p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(384, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoKeyType _mono_binding_request_inventory_data_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(156, retval, 1, args, 10.0, 1.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static void _mono_binding_request_permissions_func(MonoKeyType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(136, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoKeyType _mono_binding_request_secure_url_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(346, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoKeyType _mono_binding_request_simulator_data_func(MonoStringType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(293, retval, 2, args, 10.0, 1.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoKeyType _mono_binding_request_url_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(345, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoKeyType _mono_binding_request_user_key_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(525, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static MonoKeyType _mono_binding_request_username_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(359, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static void _mono_binding_reset_animation_override_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(502, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_reset_land_ban_list_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(321, retval, 0, args, 10.0, 0.1);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_reset_land_pass_list_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(322, retval, 0, args, 10.0, 0.1);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_reset_other_script_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(249, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_reset_script_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(163, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_reset_time_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(83, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_return_objects_by_id_func(MonoListType p0, S32 p0_length)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(520, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_return_objects_by_owner_func(MonoKeyType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(521, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_rez_at_root_func(MonoStringType p0, MonoVectorType p1, MonoVectorType p2, MonoQuaternionType p3, S32 p4)
{
    LLScriptLibData args[5];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoVectorType>::set(args[2], p2);
    LLScriptLibDataHelper<MonoQuaternionType>::set(args[3], p3);
    LLScriptLibDataHelper<S32>::set(args[4], p4);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(286, retval, 5, args, 200.0, 0.1);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_rez_object_func(MonoStringType p0, MonoVectorType p1, MonoVectorType p2, MonoQuaternionType p3, S32 p4)
{
    LLScriptLibData args[5];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoVectorType>::set(args[2], p2);
    LLScriptLibDataHelper<MonoQuaternionType>::set(args[3], p3);
    LLScriptLibDataHelper<S32>::set(args[4], p4);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(104, retval, 5, args, 200.0, 0.1);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoKeyType _mono_binding_rez_object_with_params_func(MonoStringType p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(544, retval, 2, args, 200.0, 0.1);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static F32 _mono_binding_rot_to_angle_func(MonoQuaternionType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoQuaternionType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(171, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static MonoVectorType _mono_binding_rot_to_axis_func(MonoQuaternionType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoQuaternionType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(170, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoVectorType _mono_binding_rot_to_euler_func(MonoQuaternionType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoQuaternionType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(15, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoVectorType _mono_binding_rot_to_fwd_func(MonoQuaternionType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoQuaternionType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(18, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoVectorType _mono_binding_rot_to_left_func(MonoQuaternionType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoQuaternionType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(19, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoVectorType _mono_binding_rot_to_up_func(MonoQuaternionType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoQuaternionType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(20, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoQuaternionType _mono_binding_rot_between_func(MonoVectorType p0, MonoVectorType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_QUATERNION;
    call_lib_func(21, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoQuaternionType>::get(retval);
}

static void _mono_binding_rot_look_at_func(MonoQuaternionType p0, F32 p1, F32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoQuaternionType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibDataHelper<F32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(127, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_rot_target_func(MonoQuaternionType p0, F32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoQuaternionType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(68, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_rot_target_remove_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(69, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_rotate_texture_func(F32 p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<F32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(56, retval, 2, args, 10.0, 0.2);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_round_func(F32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<F32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(11, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoStringType _mono_binding_sha1_string_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(343, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoStringType _mono_binding_sha256_string_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(531, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static S32 _mono_binding_same_group_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(219, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_say_func(S32 p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(23, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_scale_by_factor_func(F32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<F32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(592, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_scale_texture_func(F32 p0, F32 p1, S32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<F32>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(54, retval, 3, args, 10.0, 0.2);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_script_danger_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(246, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_script_profiler_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(367, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoKeyType _mono_binding_send_remote_data_func(MonoKeyType p0, MonoStringType p1, S32 p2, MonoStringType p3)
{
    LLScriptLibData args[4];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibDataHelper<MonoStringType>::set(args[3], p3);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(255, retval, 4, args, 10.0, 3.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static void _mono_binding_sensor_func(MonoStringType p0, MonoKeyType p1, S32 p2, F32 p3, F32 p4)
{
    LLScriptLibData args[5];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoKeyType>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibDataHelper<F32>::set(args[3], p3);
    LLScriptLibDataHelper<F32>::set(args[4], p4);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(28, retval, 5, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_sensor_remove_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(30, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_sensor_repeat_func(MonoStringType p0, MonoKeyType p1, S32 p2, F32 p3, F32 p4, F32 p5)
{
    LLScriptLibData args[6];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoKeyType>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibDataHelper<F32>::set(args[3], p3);
    LLScriptLibDataHelper<F32>::set(args[4], p4);
    LLScriptLibDataHelper<F32>::set(args[5], p5);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(29, retval, 6, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_set_agent_environment_func(MonoKeyType p0, F32 p1, MonoListType p2, S32 p2_length)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibDataHelper<MonoListType>::set(args[2], p2, p2_length);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(714, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_set_agent_rot_func(MonoQuaternionType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoQuaternionType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(515, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_alpha_func(F32 p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<F32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(51, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_angular_velocity_func(MonoVectorType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(379, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_animation_override_func(MonoStringType p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(501, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_buoyancy_func(F32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<F32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(122, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_camera_at_offset_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(244, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_camera_eye_offset_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(243, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_camera_params_func(MonoListType p0, S32 p0_length)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(313, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_click_action_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(333, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_color_func(MonoVectorType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(49, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_content_type_func(MonoKeyType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(374, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_damage_func(F32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<F32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(157, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_set_environment_func(MonoVectorType p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(717, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static S32 _mono_binding_set_experience_key_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(386, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_set_force_func(MonoVectorType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(64, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_force_and_torque_func(MonoVectorType p0, MonoVectorType p1, S32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(76, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_set_ground_texture_func(MonoListType p0, S32 p0_length)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(558, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_set_hover_height_func(F32 p0, S32 p1, F32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<F32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<F32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(123, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_inventory_perm_mask_func(MonoStringType p0, S32 p1, S32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(290, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_keyframed_motion_func(MonoListType p0, S32 p0_length, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(394, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_link_alpha_func(S32 p0, F32 p1, S32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(274, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_link_camera_func(S32 p0, MonoVectorType p1, MonoVectorType p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoVectorType>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(377, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_link_color_func(S32 p0, MonoVectorType p1, S32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(140, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_link_gltf_overrides_func(S32 p0, S32 p1, MonoListType p2, S32 p2_length)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<MonoListType>::set(args[2], p2, p2_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(560, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_set_link_media_func(S32 p0, S32 p1, MonoListType p2, S32 p2_length)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<MonoListType>::set(args[2], p2, p2_length);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(371, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_set_link_primitive_params_func(S32 p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(328, retval, 2, args, 10.0, 0.2);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_link_primitive_params_fast_func(S32 p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(353, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_link_render_material_func(S32 p0, MonoStringType p1, S32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(762, retval, 3, args, 10.0, 0.2);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_link_sit_flags_func(S32 p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(550, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_link_texture_func(S32 p0, MonoStringType p1, S32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(329, retval, 3, args, 10.0, 0.2);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_link_texture_anim_func(S32 p0, S32 p1, S32 p2, S32 p3, S32 p4, F32 p5, F32 p6, F32 p7)
{
    LLScriptLibData args[8];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibDataHelper<S32>::set(args[3], p3);
    LLScriptLibDataHelper<S32>::set(args[4], p4);
    LLScriptLibDataHelper<F32>::set(args[5], p5);
    LLScriptLibDataHelper<F32>::set(args[6], p6);
    LLScriptLibDataHelper<F32>::set(args[7], p7);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(356, retval, 8, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_local_rot_func(MonoQuaternionType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoQuaternionType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(284, retval, 1, args, 10.0, 0.2);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_set_memory_limit_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(369, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_set_object_desc_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(271, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_object_name_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(203, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_object_perm_mask_func(S32 p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(288, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_set_parcel_for_sale_func(S32 p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(561, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_set_parcel_music_url_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(267, retval, 1, args, 10.0, 2.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_pay_price_func(S32 p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(302, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_physics_material_func(S32 p0, F32 p1, F32 p2, F32 p3, F32 p4)
{
    LLScriptLibData args[5];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibDataHelper<F32>::set(args[2], p2);
    LLScriptLibDataHelper<F32>::set(args[3], p3);
    LLScriptLibDataHelper<F32>::set(args[4], p4);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(380, retval, 5, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_pos_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(58, retval, 1, args, 10.0, 0.2);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_set_prim_media_params_func(S32 p0, MonoListType p1, S32 p1_length)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoListType>::set(args[1], p1, p1_length);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(350, retval, 2, args, 10.0, 1.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_set_prim_url_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(305, retval, 1, args, 10.0, 20.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_primitive_params_func(MonoListType p0, S32 p0_length)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(259, retval, 1, args, 10.0, 0.2);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_set_region_pos_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(397, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_set_remote_script_access_pin_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(252, retval, 1, args, 10.0, 0.2);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_render_material_func(MonoStringType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(761, retval, 2, args, 10.0, 0.2);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_rot_func(MonoQuaternionType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoQuaternionType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(61, retval, 1, args, 10.0, 0.2);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_scale_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(47, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_script_state_func(MonoStringType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(148, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_sit_text_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(242, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_sound_queueing_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(208, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_sound_radius_func(F32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<F32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(209, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_status_func(S32 p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(45, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_text_func(MonoStringType p0, MonoVectorType p1, F32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibDataHelper<F32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(152, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_texture_func(MonoStringType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(53, retval, 2, args, 10.0, 0.2);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_texture_anim_func(S32 p0, S32 p1, S32 p2, S32 p3, F32 p4, F32 p5, F32 p6)
{
    LLScriptLibData args[7];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibDataHelper<S32>::set(args[3], p3);
    LLScriptLibDataHelper<F32>::set(args[4], p4);
    LLScriptLibDataHelper<F32>::set(args[5], p5);
    LLScriptLibDataHelper<F32>::set(args[6], p6);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(211, retval, 7, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_timer_event_func(F32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<F32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(107, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_torque_func(MonoVectorType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(74, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_touch_text_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(241, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_vehicle_flags_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(236, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_vehicle_float_param_func(S32 p0, F32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(233, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_vehicle_rotation_param_func(S32 p0, MonoQuaternionType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoQuaternionType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(235, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_vehicle_type_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(232, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_vehicle_vector_param_func(S32 p0, MonoVectorType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(234, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_set_velocity_func(MonoVectorType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(378, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_shout_func(S32 p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(24, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoStringType _mono_binding_sign_rsa_func(MonoStringType p0, MonoStringType p1, MonoStringType p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoStringType>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(539, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static S32 _mono_binding_sit_on_link_func(MonoKeyType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(503, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_sit_target_func(MonoVectorType p0, MonoQuaternionType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoQuaternionType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(238, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_sleep_func(F32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<F32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(108, retval, 1, args, 0.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_sound_func(MonoStringType p0, F32 p1, S32 p2, S32 p3)
{
    LLScriptLibData args[4];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibDataHelper<S32>::set(args[3], p3);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(85, retval, 4, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_sound_preload_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(126, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_start_animation_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(129, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_start_object_animation_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(504, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_stop_animation_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(130, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_stop_hover_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(124, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_stop_look_at_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(106, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_stop_move_to_target_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(71, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_stop_object_animation_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(505, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_stop_point_at_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(132, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_stop_sound_func()
{
    LLScriptLibData args[0];
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(92, retval, 0, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_string_length_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(128, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static MonoStringType _mono_binding_string_to_base64_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(260, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoStringType _mono_binding_string_trim_func(MonoStringType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(330, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static S32 _mono_binding_sub_string_index_func(MonoStringType p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(181, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_take_camera_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(115, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_take_controls_func(S32 p0, S32 p1, S32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(111, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static S32 _mono_binding_target_func(MonoVectorType p0, F32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(66, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_target_omega_func(MonoVectorType p0, F32 p1, F32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibDataHelper<F32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(133, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_target_remove_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(67, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_targeted_email_func(S32 p0, MonoStringType p1, MonoStringType p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoStringType>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(750, retval, 3, args, 10.0, 20.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_teleport_agent_func(MonoKeyType p0, MonoStringType p1, MonoVectorType p2, MonoVectorType p3)
{
    LLScriptLibData args[4];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoVectorType>::set(args[2], p2);
    LLScriptLibDataHelper<MonoVectorType>::set(args[3], p3);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(368, retval, 4, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_teleport_agent_global_coords_func(MonoKeyType p0, MonoVectorType p1, MonoVectorType p2, MonoVectorType p3)
{
    LLScriptLibData args[4];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoVectorType>::set(args[2], p2);
    LLScriptLibDataHelper<MonoVectorType>::set(args[3], p3);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(414, retval, 4, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_teleport_agent_home_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(158, retval, 1, args, 100.0, 5.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_text_box_func(MonoKeyType p0, MonoStringType p1, S32 p2)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(335, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoKeyType _mono_binding_transfer_linden_dollars_func(MonoKeyType p0, S32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(395, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static S32 _mono_binding_transfer_ownership_func(MonoKeyType p0, S32 p1, MonoListType p2, S32 p2_length)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibDataHelper<S32>::set(args[1], p1);
    LLScriptLibDataHelper<MonoListType>::set(args[2], p2, p2_length);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(519, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_trigger_sound_func(MonoStringType p0, F32 p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(91, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_trigger_sound_limited_func(MonoStringType p0, F32 p1, MonoVectorType p2, MonoVectorType p3)
{
    LLScriptLibData args[4];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<F32>::set(args[1], p1);
    LLScriptLibDataHelper<MonoVectorType>::set(args[2], p2);
    LLScriptLibDataHelper<MonoVectorType>::set(args[3], p3);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(212, retval, 4, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_un_sit_func(MonoKeyType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoKeyType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(220, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoStringType _mono_binding_unescape_url_func(MonoStringType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(308, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static void _mono_binding_update_character_func(MonoListType p0, S32 p0_length)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoListType>::set(args[0], p0, p0_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(406, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoKeyType _mono_binding_update_key_value_func(MonoStringType p0, MonoStringType p1, S32 p2, MonoStringType p3)
{
    LLScriptLibData args[4];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<S32>::set(args[2], p2);
    LLScriptLibDataHelper<MonoStringType>::set(args[3], p3);
    LLScriptLibData retval;
    retval.mType = LST_KEY;
    call_lib_func(389, retval, 4, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoKeyType>::get(retval);
}

static F32 _mono_binding_vec_dist_func(MonoVectorType p0, MonoVectorType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(14, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static F32 _mono_binding_vec_mag_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(12, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static MonoVectorType _mono_binding_vec_norm_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(13, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static S32 _mono_binding_verify_rsa_func(MonoStringType p0, MonoStringType p1, MonoStringType p2, MonoStringType p3)
{
    LLScriptLibData args[4];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoStringType>::set(args[2], p2);
    LLScriptLibDataHelper<MonoStringType>::set(args[3], p3);
    LLScriptLibData retval;
    retval.mType = LST_INTEGER;
    call_lib_func(540, retval, 4, args, 10.0, 0.0);
    return LLScriptLibDataHelper<S32>::get(retval);
}

static void _mono_binding_volume_detect_func(S32 p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(248, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static void _mono_binding_wander_within_func(MonoVectorType p0, MonoVectorType p1, MonoListType p2, S32 p2_length)
{
    LLScriptLibData args[3];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
    LLScriptLibDataHelper<MonoListType>::set(args[2], p2, p2_length);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(401, retval, 3, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static F32 _mono_binding_water_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_FLOATINGPOINT;
    call_lib_func(153, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<F32>::get(retval);
}

static void _mono_binding_whisper_func(S32 p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<S32>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_NULL;
    call_lib_func(22, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<void>::get(retval);
}

static MonoVectorType _mono_binding_wind_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(44, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoVectorType _mono_binding_world_pos_to_hud_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(547, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}

static MonoStringType _mono_binding_xor_base64_func(MonoStringType p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(522, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoStringType _mono_binding_xor_base64_strings_func(MonoStringType p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(262, retval, 2, args, 10.0, 0.3);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoStringType _mono_binding_xor_base64_strings_correct_func(MonoStringType p0, MonoStringType p1)
{
    LLScriptLibData args[2];
    LLScriptLibDataHelper<MonoStringType>::set(args[0], p0);
    LLScriptLibDataHelper<MonoStringType>::set(args[1], p1);
    LLScriptLibData retval;
    retval.mType = LST_STRING;
    call_lib_func(319, retval, 2, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoStringType>::get(retval);
}

static MonoVectorType _mono_binding_s_rgb_to_linear_func(MonoVectorType p0)
{
    LLScriptLibData args[1];
    LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
    LLScriptLibData retval;
    retval.mType = LST_VECTOR;
    call_lib_func(716, retval, 1, args, 10.0, 0.0);
    return LLScriptLibDataHelper<MonoVectorType>::get(retval);
}



void mono_internal_call_init_generated()
{
    mono_add_internal_call("LindenLab.SecondLife.Library::llAddToLandBanList", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_add_to_land_ban_list_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llAddToLandPassList", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_add_to_land_pass_list_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llAdjustDamage", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_adjust_damage_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llAdjustSoundVolume", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_adjust_sound_volume_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llAgentInExperience", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_agent_in_experience_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llAllowInventoryDrop", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_allow_inventory_drop_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llAngleBetween", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_angle_between_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llApplyImpulse", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_apply_impulse_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llApplyRotationalImpulse", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_apply_rotational_impulse_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llAttachToAvatar", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_attach_to_avatar_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llAttachToAvatarTemp", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_attach_to_avatar_temp_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llAvatarOnLinkSitTarget", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_avatar_on_link_sit_target_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llAvatarOnSitTarget", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_avatar_on_sit_target_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llAxes2Rot", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_axes_to_rot_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llAxisAngle2Rot", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_axis_angle_to_rot_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llBase64ToInteger", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_base64_to_integer_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llBase64ToString", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_base64_to_string_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llBreakAllLinks", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_break_all_links_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llBreakLink", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_break_link_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llCSV2ListInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_csv_to_list_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llCastRayInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_cast_ray_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llChar", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_char_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llClearCameraParams", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_clear_camera_params_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llClearExperience", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_clear_experience_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llClearExperiencePermissions", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_clear_experience_permissions_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llClearLinkMedia", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_clear_link_media_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llClearPrimMedia", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_clear_prim_media_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llCloseRemoteDataChannel", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_close_remote_data_channel_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llCloud", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_cloud_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llCollisionFilter", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_collision_filter_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llCollisionSound", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_collision_sound_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llCollisionSprite", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_collision_sprite_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llComputeHash", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_compute_hash_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llCreateCharacterInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_create_character_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llCreateKeyValue", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_create_key_value_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llCreateLink", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_create_link_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDamage", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_damage_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDataSizeKeyValue", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_data_size_key_value_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDeleteCharacter", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_delete_character_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDeleteKeyValue", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_delete_key_value_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDeleteSubString", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_delete_sub_string_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDerezObject", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_derez_object_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDetachFromAvatar", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_detach_from_avatar_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDetectedDamageInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_detected_damage_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDetectedGrab", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_detected_grab_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDetectedGroup", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_detected_group_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDetectedKey", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_detected_key_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDetectedLinkNumber", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_detected_link_number_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDetectedName", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_detected_name_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDetectedOwner", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_detected_owner_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDetectedPos", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_detected_pos_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDetectedRezzer", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_detected_rezzer_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDetectedRot", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_detected_rot_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDetectedTouchBinormal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_detected_touch_binormal_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDetectedTouchFace", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_detected_touch_face_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDetectedTouchNormal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_detected_touch_normal_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDetectedTouchPos", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_detected_touch_pos_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDetectedTouchST", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_detected_touch_st_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDetectedTouchUV", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_detected_touch_uv_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDetectedType", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_detected_type_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDetectedVel", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_detected_vel_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDialogInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_dialog_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llDie", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_die_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llEdgeOfWorld", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_edge_of_world_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llEjectFromLand", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_eject_from_land_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llEmail", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_email_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llEscapeURL", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_escape_url_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llEuler2Rot", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_euler_to_rot_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llEvadeInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_evade_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llExecCharacterCmdInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_exec_character_cmd_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llFindNotecardTextCountInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_find_notecard_text_count_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llFindNotecardTextSyncInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_find_notecard_text_sync_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llFleeFromInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_flee_from_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llForceMouselook", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_force_mouselook_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llFrand", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_frand_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGenerateKey", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_generate_key_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetAccel", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_accel_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetAgentInfo", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_agent_info_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetAgentLanguage", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_agent_language_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetAgentListInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_agent_list_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetAgentSize", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_agent_size_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetAlpha", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_alpha_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetAndResetTime", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_and_reset_time_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetAnimation", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_animation_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetAnimationListInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_animation_list_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetAnimationOverride", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_animation_override_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetAttached", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_attached_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetAttachedListInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_attached_list_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetAttachedListFilteredInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_attached_list_filtered_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetBoundingBoxInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_bounding_box_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetCameraAspect", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_camera_aspect_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetCameraFOV", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_camera_fov_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetCameraPos", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_camera_pos_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetCameraRot", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_camera_rot_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetCenterOfMass", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_center_of_mass_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetClosestNavPointInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_closest_nav_point_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetColor", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_color_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetCreator", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_creator_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetDate", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_date_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetDayLength", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_day_length_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetDayOffset", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_day_offset_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetDisplayName", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_display_name_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetEnergy", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_energy_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetEnv", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_env_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetEnvironmentInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_environment_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetExperienceDetailsInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_experience_details_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetExperienceErrorMessage", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_experience_error_message_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetExperienceListInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_experience_list_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetForce", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_force_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetFreeMemory", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_free_memory_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetFreeURLs", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_free_ur_ls_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetGMTclock", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_gm_tclock_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetGeometricCenter", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_geometric_center_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetHTTPHeader", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_http_header_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetHealth", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_health_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetInventoryAcquireTime", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_inventory_acquire_time_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetInventoryCreator", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_inventory_creator_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetInventoryDesc", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_inventory_desc_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetInventoryKey", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_inventory_key_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetInventoryName", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_inventory_name_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetInventoryNumber", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_inventory_number_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetInventoryPermMask", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_inventory_perm_mask_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetInventoryType", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_inventory_type_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetKey", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_key_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetLandOwnerAt", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_land_owner_at_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetLinkKey", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_link_key_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetLinkMediaInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_link_media_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetLinkName", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_link_name_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetLinkNumber", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_link_number_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetLinkNumberOfSides", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_link_number_of_sides_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetLinkPrimitiveParamsInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_link_primitive_params_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetLinkSitFlags", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_link_sit_flags_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetLocalPos", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_local_pos_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetLocalRot", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_local_rot_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetMass", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_mass_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetMassMKS", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_mass_mks_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetMaxScaleFactor", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_max_scale_factor_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetMemoryLimit", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_memory_limit_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetMinScaleFactor", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_min_scale_factor_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetMoonDirection", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_moon_direction_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetMoonRotation", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_moon_rotation_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetNextEmail", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_next_email_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetNotecardLine", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_notecard_line_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetNotecardLineSync", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_notecard_line_sync_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetNumberOfNotecardLines", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_number_of_notecard_lines_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetNumberOfPrims", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_number_of_prims_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetNumberOfSides", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_number_of_sides_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetObjectAnimationNamesInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_object_animation_names_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetObjectDesc", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_object_desc_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetObjectDetailsInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_object_details_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetObjectLinkKey", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_object_link_key_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetObjectMass", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_object_mass_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetObjectName", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_object_name_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetObjectPermMask", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_object_perm_mask_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetObjectPrimCount", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_object_prim_count_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetOmega", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_omega_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetOwner", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_owner_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetOwnerKey", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_owner_key_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetParcelDetailsInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_parcel_details_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetParcelFlags", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_parcel_flags_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetParcelMaxPrims", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_parcel_max_prims_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetParcelMusicURL", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_parcel_music_url_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetParcelPrimCount", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_parcel_prim_count_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetParcelPrimOwnersInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_parcel_prim_owners_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetPermissions", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_permissions_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetPermissionsKey", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_permissions_key_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetPhysicsMaterialInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_physics_material_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetPos", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_pos_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetPrimMediaParamsInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_prim_media_params_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetPrimitiveParamsInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_primitive_params_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetRegionAgentCount", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_region_agent_count_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetRegionCorner", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_region_corner_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetRegionDayLength", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_region_day_length_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetRegionDayOffset", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_region_day_offset_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetRegionFPS", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_region_fps_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetRegionFlags", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_region_flags_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetRegionMoonDirection", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_region_moon_direction_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetRegionMoonRotation", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_region_moon_rotation_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetRegionName", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_region_name_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetRegionSunDirection", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_region_sun_direction_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetRegionSunRotation", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_region_sun_rotation_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetRegionTimeDilation", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_region_time_dilation_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetRegionTimeOfDay", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_region_time_of_day_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetRenderMaterial", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_render_material_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetRootPosition", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_root_position_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetRootRotation", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_root_rotation_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetRot", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_rot_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetSPMaxMemory", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_sp_max_memory_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetScale", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_scale_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetScriptName", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_script_name_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetScriptState", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_script_state_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetSimStats", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_sim_stats_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetSimulatorHostname", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_simulator_hostname_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetStartParameter", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_start_parameter_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetStartString", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_start_string_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetStaticPathInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_static_path_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetStatus", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_status_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetSubString", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_sub_string_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetSunDirection", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_sun_direction_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetSunRotation", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_sun_rotation_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetTexture", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_texture_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetTextureOffset", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_texture_offset_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetTextureRot", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_texture_rot_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetTextureScale", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_texture_scale_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetTime", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_time_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetTimeOfDay", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_time_of_day_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetTimestamp", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_timestamp_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetTorque", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_torque_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetUnixTime", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_unix_time_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetUsedMemory", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_used_memory_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetUsername", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_username_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetVel", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_vel_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetVisualParamsInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_visual_params_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGetWallclock", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_get_wallclock_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGiveAgentInventoryInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_give_agent_inventory_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGiveInventory", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_give_inventory_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGiveInventoryListInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_give_inventory_list_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGiveMoney", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_give_money_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGodLikeRezObject", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_god_like_rez_object_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGround", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_ground_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGroundContour", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_ground_contour_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGroundNormal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_ground_normal_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGroundRepel", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_ground_repel_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llGroundSlope", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_ground_slope_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llHMAC", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_hmac_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llHTTPRequestInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_http_request_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llHTTPResponse", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_http_response_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llHash", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_hash_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llInsertString", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_insert_string_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llInstantMessage", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_instant_message_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llIntegerToBase64", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_integer_to_base64_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llIsFriend", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_is_friend_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llIsLinkGLTFMaterial", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_is_link_gltf_material_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llJson2ListInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_json_to_list_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llJsonGetValueInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_json_get_value_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llJsonSetValueInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_json_set_value_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llJsonValueTypeInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_json_value_type_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llKey2Name", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_key_to_name_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llKeyCountKeyValue", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_key_count_key_value_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llKeysKeyValue", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_keys_key_value_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinear2sRGB", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_linear2s_rgb_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinkAdjustSoundVolume", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_link_adjust_sound_volume_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinkParticleSystemInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_link_particle_system_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinkPlaySound", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_link_play_sound_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinkSetSoundQueueing", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_link_set_sound_queueing_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinkSetSoundRadius", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_link_set_sound_radius_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinkSitTarget", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_link_sit_target_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinkStopSound", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_link_stop_sound_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinksetDataAvailable", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_linkset_data_available_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinksetDataCountFound", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_linkset_data_count_found_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinksetDataCountKeys", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_linkset_data_count_keys_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinksetDataDelete", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_linkset_data_delete_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinksetDataDeleteFoundInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_linkset_data_delete_found_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinksetDataDeleteProtected", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_linkset_data_delete_protected_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinksetDataFindKeysInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_linkset_data_find_keys_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinksetDataListKeysInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_linkset_data_list_keys_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinksetDataRead", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_linkset_data_read_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinksetDataReadProtected", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_linkset_data_read_protected_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinksetDataReset", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_linkset_data_reset_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinksetDataWrite", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_linkset_data_write_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLinksetDataWriteProtected", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_linkset_data_write_protected_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llList2CSVInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_list_to_csv_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llList2JsonInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_list_to_json_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llList2ListSliceInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_list_to_list_slice_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llList2ListStridedInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_list_to_list_strided_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llListFindListInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_list_find_list_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llListFindListNextInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_list_find_list_next_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llListFindStridedInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_list_find_strided_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llListRandomizeInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_list_randomize_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llListSortInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_list_sort_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llListSortStridedInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_list_sort_strided_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llListStatisticsInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_list_statistics_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llListen", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_listen_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llListenControl", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_listen_control_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llListenRemove", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_listen_remove_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLoadURL", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_load_url_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLookAt", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_look_at_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLoopSound", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_loop_sound_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLoopSoundMaster", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_loop_sound_master_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llLoopSoundSlave", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_loop_sound_slave_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llMD5String", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_md5_string_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llMakeExplosion", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_make_explosion_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llMakeFire", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_make_fire_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llMakeFountain", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_make_fountain_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llMakeSmoke", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_make_smoke_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llManageEstateAccess", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_manage_estate_access_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llMapBeaconInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_map_beacon_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llMapDestination", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_map_destination_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llMessageLinked", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_message_linked_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llMinEventDelay", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_min_event_delay_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llModPow", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_mod_pow_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llModifyLand", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_modify_land_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llMoveToTarget", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_move_to_target_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llName2Key", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_name_to_key_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llNavigateToInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_navigate_to_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llOffsetTexture", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_offset_texture_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llOpenFloaterInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_open_floater_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llOpenRemoteDataChannel", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_open_remote_data_channel_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llOrd", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_ord_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llOverMyLand", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_over_my_land_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llOwnerSay", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_owner_say_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llParcelMediaCommandListInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_parcel_media_command_list_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llParcelMediaQueryInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_parcel_media_query_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llParseString2ListInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_parse_string_to_list_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llParseStringKeepNullsInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_parse_string_keep_nulls_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llParticleSystemInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_particle_system_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llPassCollisions", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_pass_collisions_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llPassTouches", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_pass_touches_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llPatrolPointsInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_patrol_points_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llPlaySound", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_play_sound_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llPlaySoundSlave", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_play_sound_slave_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llPointAt", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_point_at_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llPreloadSound", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_preload_sound_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llPursueInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_pursue_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llPushObject", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_push_object_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llReadKeyValue", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_read_key_value_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRefreshPrimURL", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_refresh_prim_url_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRegionSay", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_region_say_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRegionSayTo", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_region_say_to_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llReleaseCamera", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_release_camera_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llReleaseControls", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_release_controls_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llReleaseURL", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_release_url_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRemoteDataReply", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_remote_data_reply_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRemoteDataSetRegion", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_remote_data_set_region_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRemoteLoadScript", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_remote_load_script_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRemoteLoadScriptPin", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_remote_load_script_pin_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRemoveFromLandBanList", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_remove_from_land_ban_list_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRemoveFromLandPassList", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_remove_from_land_pass_list_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRemoveInventory", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_remove_inventory_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRemoveVehicleFlags", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_remove_vehicle_flags_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llReplaceAgentEnvironment", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_replace_agent_environment_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llReplaceEnvironment", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_replace_environment_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llReplaceSubString", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_replace_sub_string_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRequestAgentData", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_request_agent_data_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRequestDisplayName", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_request_display_name_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRequestExperiencePermissions", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_request_experience_permissions_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRequestInventoryData", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_request_inventory_data_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRequestPermissions", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_request_permissions_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRequestSecureURL", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_request_secure_url_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRequestSimulatorData", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_request_simulator_data_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRequestURL", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_request_url_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRequestUserKey", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_request_user_key_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRequestUsername", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_request_username_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llResetAnimationOverride", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_reset_animation_override_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llResetLandBanList", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_reset_land_ban_list_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llResetLandPassList", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_reset_land_pass_list_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llResetOtherScript", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_reset_other_script_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llResetScript", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_reset_script_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llResetTime", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_reset_time_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llReturnObjectsByIDInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_return_objects_by_id_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llReturnObjectsByOwner", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_return_objects_by_owner_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRezAtRoot", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_rez_at_root_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRezObject", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_rez_object_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRezObjectWithParamsInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_rez_object_with_params_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRot2Angle", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_rot_to_angle_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRot2Axis", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_rot_to_axis_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRot2Euler", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_rot_to_euler_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRot2Fwd", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_rot_to_fwd_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRot2Left", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_rot_to_left_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRot2Up", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_rot_to_up_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRotBetween", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_rot_between_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRotLookAt", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_rot_look_at_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRotTarget", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_rot_target_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRotTargetRemove", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_rot_target_remove_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRotateTexture", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_rotate_texture_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llRound", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_round_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSHA1String", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_sha1_string_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSHA256String", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_sha256_string_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSameGroup", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_same_group_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSay", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_say_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llScaleByFactor", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_scale_by_factor_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llScaleTexture", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_scale_texture_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llScriptDanger", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_script_danger_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llScriptProfiler", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_script_profiler_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSendRemoteData", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_send_remote_data_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSensor", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_sensor_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSensorRemove", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_sensor_remove_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSensorRepeat", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_sensor_repeat_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetAgentEnvironmentInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_agent_environment_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetAgentRot", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_agent_rot_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetAlpha", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_alpha_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetAngularVelocity", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_angular_velocity_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetAnimationOverride", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_animation_override_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetBuoyancy", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_buoyancy_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetCameraAtOffset", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_camera_at_offset_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetCameraEyeOffset", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_camera_eye_offset_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetCameraParamsInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_camera_params_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetClickAction", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_click_action_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetColor", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_color_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetContentType", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_content_type_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetDamage", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_damage_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetEnvironmentInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_environment_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetExperienceKey", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_experience_key_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetForce", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_force_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetForceAndTorque", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_force_and_torque_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetGroundTextureInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_ground_texture_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetHoverHeight", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_hover_height_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetInventoryPermMask", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_inventory_perm_mask_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetKeyframedMotionInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_keyframed_motion_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetLinkAlpha", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_link_alpha_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetLinkCamera", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_link_camera_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetLinkColor", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_link_color_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetLinkGLTFOverridesInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_link_gltf_overrides_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetLinkMediaInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_link_media_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetLinkPrimitiveParamsInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_link_primitive_params_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetLinkPrimitiveParamsFastInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_link_primitive_params_fast_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetLinkRenderMaterial", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_link_render_material_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetLinkSitFlags", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_link_sit_flags_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetLinkTexture", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_link_texture_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetLinkTextureAnim", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_link_texture_anim_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetLocalRot", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_local_rot_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetMemoryLimit", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_memory_limit_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetObjectDesc", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_object_desc_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetObjectName", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_object_name_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetObjectPermMask", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_object_perm_mask_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetParcelForSaleInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_parcel_for_sale_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetParcelMusicURL", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_parcel_music_url_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetPayPriceInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_pay_price_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetPhysicsMaterial", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_physics_material_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetPos", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_pos_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetPrimMediaParamsInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_prim_media_params_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetPrimURL", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_prim_url_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetPrimitiveParamsInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_primitive_params_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetRegionPos", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_region_pos_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetRemoteScriptAccessPin", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_remote_script_access_pin_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetRenderMaterial", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_render_material_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetRot", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_rot_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetScale", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_scale_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetScriptState", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_script_state_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetSitText", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_sit_text_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetSoundQueueing", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_sound_queueing_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetSoundRadius", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_sound_radius_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetStatus", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_status_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetText", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_text_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetTexture", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_texture_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetTextureAnim", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_texture_anim_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetTimerEvent", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_timer_event_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetTorque", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_torque_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetTouchText", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_touch_text_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetVehicleFlags", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_vehicle_flags_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetVehicleFloatParam", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_vehicle_float_param_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetVehicleRotationParam", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_vehicle_rotation_param_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetVehicleType", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_vehicle_type_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetVehicleVectorParam", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_vehicle_vector_param_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSetVelocity", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_set_velocity_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llShout", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_shout_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSignRSA", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_sign_rsa_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSitOnLink", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_sit_on_link_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSitTarget", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_sit_target_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSleep", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_sleep_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSound", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_sound_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSoundPreload", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_sound_preload_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llStartAnimation", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_start_animation_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llStartObjectAnimation", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_start_object_animation_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llStopAnimation", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_stop_animation_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llStopHover", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_stop_hover_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llStopLookAt", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_stop_look_at_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llStopMoveToTarget", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_stop_move_to_target_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llStopObjectAnimation", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_stop_object_animation_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llStopPointAt", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_stop_point_at_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llStopSound", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_stop_sound_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llStringLength", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_string_length_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llStringToBase64", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_string_to_base64_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llStringTrim", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_string_trim_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llSubStringIndex", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_sub_string_index_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llTakeCamera", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_take_camera_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llTakeControls", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_take_controls_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llTarget", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_target_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llTargetOmega", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_target_omega_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llTargetRemove", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_target_remove_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llTargetedEmail", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_targeted_email_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llTeleportAgent", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_teleport_agent_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llTeleportAgentGlobalCoords", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_teleport_agent_global_coords_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llTeleportAgentHome", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_teleport_agent_home_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llTextBox", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_text_box_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llTransferLindenDollars", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_transfer_linden_dollars_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llTransferOwnershipInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_transfer_ownership_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llTriggerSound", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_trigger_sound_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llTriggerSoundLimited", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_trigger_sound_limited_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llUnSit", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_un_sit_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llUnescapeURL", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_unescape_url_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llUpdateCharacterInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_update_character_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llUpdateKeyValue", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_update_key_value_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llVecDist", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_vec_dist_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llVecMag", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_vec_mag_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llVecNorm", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_vec_norm_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llVerifyRSA", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_verify_rsa_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llVolumeDetect", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_volume_detect_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llWanderWithinInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_wander_within_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llWater", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_water_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llWhisper", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_whisper_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llWind", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_wind_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llWorldPosToHUD", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_world_pos_to_hud_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llXorBase64", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_xor_base64_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llXorBase64Strings", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_xor_base64_strings_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llXorBase64StringsCorrect", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_xor_base64_strings_correct_func)));
    mono_add_internal_call("LindenLab.SecondLife.Library::llsRGB2Linear", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_s_rgb_to_linear_func)));

}
