
void task_lscript_init_generated()
{
    gScriptLibrary.assignExec("llAdjustDamage", adjust_damage_func);
    gScriptLibrary.assignExec("llAxisAngle2Rot", axis_angle_to_rot_func);
    gScriptLibrary.assignExec("llDerezObject", derez_object_func);
    gScriptLibrary.assignExec("llDetectedDamage", detected_damage_func);
    gScriptLibrary.assignExec("llFindNotecardTextCount", find_notecard_text_count_func);
    gScriptLibrary.assignExec("llFindNotecardTextSync", find_notecard_text_sync_func);
    gScriptLibrary.assignExec("llGetAttachedListFiltered", get_attached_list_filtered_func);
    gScriptLibrary.assignExec("llGetHealth", get_health_func);
    gScriptLibrary.assignExec("llGetStartString", get_start_string_func);
    gScriptLibrary.assignExec("llGiveAgentInventory", give_agent_inventory_func);
    gScriptLibrary.assignExec("llIsLinkGLTFMaterial", is_link_gltf_material_func);
    gScriptLibrary.assignExec("llListSortStrided", list_sort_strided_func);
    gScriptLibrary.assignExec("llMapBeacon", map_beacon_func);
    gScriptLibrary.assignExec("llSetAgentRot", set_agent_rot_func);
    gScriptLibrary.assignExec("llSetGroundTexture", set_ground_texture_func);
    gScriptLibrary.assignExec("llSetLinkGLTFOverrides", set_link_gltf_overrides_func);
    gScriptLibrary.assignExec("llSetParcelForSale", set_parcel_for_sale_func);
    gScriptLibrary.assignExec("llTransferOwnership", transfer_ownership_func);

}
