// Minimal C# template for generated Mono bindings
// ONLY for testing, this will not compile!

using System;
using System.Collections;
using System.Runtime.CompilerServices;

namespace LindenLab.SecondLife
{
    public class Library
    {
        private static object[] ToArrayNoCopy(ArrayList list) { return list.ToArray(); }
        private static ArrayList ToArrayListNoCopy(object[] array) { return new ArrayList(array); }

        
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void llAdjustDamage(int number, float new_damage);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static Quaternion llAxisAngle2Rot(Vector axis, float angle);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static int llDerezObject(Key id, int flag);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static object[] llDetectedDamageInternal(int number);

        public static ArrayList llDetectedDamage(int number) {
            return ToArrayListNoCopy(llDetectedDamageInternal(number));
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static Key llFindNotecardTextCountInternal(string notecardname, string pattern, object[] options, int options_len);

        public static Key llFindNotecardTextCount(string notecardname, string pattern, ArrayList options) {
            return llFindNotecardTextCountInternal(notecardname, pattern, ToArrayNoCopy(options), options.Count);
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static object[] llFindNotecardTextSyncInternal(string name, string pattern, int start, int count, object[] options, int options_len);

        public static ArrayList llFindNotecardTextSync(string name, string pattern, int start, int count, ArrayList options) {
            return ToArrayListNoCopy(llFindNotecardTextSyncInternal(name, pattern, start, count, ToArrayNoCopy(options), options.Count));
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static object[] llGetAttachedListFilteredInternal(Key avatar, object[] options, int options_len);

        public static ArrayList llGetAttachedListFiltered(Key avatar, ArrayList options) {
            return ToArrayListNoCopy(llGetAttachedListFilteredInternal(avatar, ToArrayNoCopy(options), options.Count));
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static float llGetHealth(Key id);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static string llGetStartString();
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static int llGiveAgentInventoryInternal(Key agent, string folder, object[] inventory, int inventory_len, object[] options, int options_len);

        public static int llGiveAgentInventory(Key agent, string folder, ArrayList inventory, ArrayList options) {
            return llGiveAgentInventoryInternal(agent, folder, ToArrayNoCopy(inventory), inventory.Count, ToArrayNoCopy(options), options.Count);
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static int llIsLinkGLTFMaterial(int link, int face);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static object[] llListSortStridedInternal(object[] src, int src_len, int stride, int stride_index, int ascending);

        public static ArrayList llListSortStrided(ArrayList src, int stride, int stride_index, int ascending) {
            return ToArrayListNoCopy(llListSortStridedInternal(ToArrayNoCopy(src), src.Count, stride, stride_index, ascending));
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void llMapBeaconInternal(string region_name, Vector pos, object[] options, int options_len);

        public static void llMapBeacon(string region_name, Vector pos, ArrayList options) {
            llMapBeaconInternal(region_name, pos, ToArrayNoCopy(options), options.Count);
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void llSetAgentRot(Quaternion rot, int flags);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static int llSetGroundTextureInternal(object[] changes, int changes_len);

        public static int llSetGroundTexture(ArrayList changes) {
            return llSetGroundTextureInternal(ToArrayNoCopy(changes), changes.Count);
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void llSetLinkGLTFOverridesInternal(int link, int face, object[] @params, int params_len);

        public static void llSetLinkGLTFOverrides(int link, int face, ArrayList @params) {
            llSetLinkGLTFOverridesInternal(link, face, ToArrayNoCopy(@params), @params.Count);
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static int llSetParcelForSaleInternal(int ForSale, object[] Options, int Options_len);

        public static int llSetParcelForSale(int ForSale, ArrayList Options) {
            return llSetParcelForSaleInternal(ForSale, ToArrayNoCopy(Options), Options.Count);
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static int llTransferOwnershipInternal(Key agent_id, int flags, object[] options, int options_len);

        public static int llTransferOwnership(Key agent_id, int flags, ArrayList options) {
            return llTransferOwnershipInternal(agent_id, flags, ToArrayNoCopy(options), options.Count);
        }



    }
}
