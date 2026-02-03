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
        public extern static void llAdjustDamage(int Number, float Damage);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static Quaternion llAxisAngle2Rot(Vector Axis, float Angle);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static int llDerezObject(Key ID, int flags);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static object[] llDetectedDamageInternal(int Number);

        public static ArrayList llDetectedDamage(int Number) {
            return ToArrayListNoCopy(llDetectedDamageInternal(Number));
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static Key llFindNotecardTextCountInternal(string NotecardName, string Pattern, object[] Options, int Options_len);

        public static Key llFindNotecardTextCount(string NotecardName, string Pattern, ArrayList Options) {
            return llFindNotecardTextCountInternal(NotecardName, Pattern, ToArrayNoCopy(Options), Options.Count);
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static object[] llFindNotecardTextSyncInternal(string NotecardName, string Pattern, int StartMatch, int Count, object[] Options, int Options_len);

        public static ArrayList llFindNotecardTextSync(string NotecardName, string Pattern, int StartMatch, int Count, ArrayList Options) {
            return ToArrayListNoCopy(llFindNotecardTextSyncInternal(NotecardName, Pattern, StartMatch, Count, ToArrayNoCopy(Options), Options.Count));
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static object[] llGetAttachedListFilteredInternal(Key AgentID, object[] Options, int Options_len);

        public static ArrayList llGetAttachedListFiltered(Key AgentID, ArrayList Options) {
            return ToArrayListNoCopy(llGetAttachedListFilteredInternal(AgentID, ToArrayNoCopy(Options), Options.Count));
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static float llGetHealth(Key ID);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static string llGetStartString();
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static int llGiveAgentInventoryInternal(Key AgentID, string FolderName, object[] InventoryItems, int InventoryItems_len, object[] Options, int Options_len);

        public static int llGiveAgentInventory(Key AgentID, string FolderName, ArrayList InventoryItems, ArrayList Options) {
            return llGiveAgentInventoryInternal(AgentID, FolderName, ToArrayNoCopy(InventoryItems), InventoryItems.Count, ToArrayNoCopy(Options), Options.Count);
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static int llIsLinkGLTFMaterial(int link, int face);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static object[] llListSortStridedInternal(object[] ListVariable, int ListVariable_len, int Stride, int Sortkey, int Ascending);

        public static ArrayList llListSortStrided(ArrayList ListVariable, int Stride, int Sortkey, int Ascending) {
            return ToArrayListNoCopy(llListSortStridedInternal(ToArrayNoCopy(ListVariable), ListVariable.Count, Stride, Sortkey, Ascending));
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void llMapBeaconInternal(string RegionName, Vector Position, object[] Options, int Options_len);

        public static void llMapBeacon(string RegionName, Vector Position, ArrayList Options) {
            llMapBeaconInternal(RegionName, Position, ToArrayNoCopy(Options), Options.Count);
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void llSetAgentRot(Quaternion rot, int flags);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static int llSetGroundTextureInternal(object[] Changes, int Changes_len);

        public static int llSetGroundTexture(ArrayList Changes) {
            return llSetGroundTextureInternal(ToArrayNoCopy(Changes), Changes.Count);
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void llSetLinkGLTFOverridesInternal(int link, int face, object[] options, int options_len);

        public static void llSetLinkGLTFOverrides(int link, int face, ArrayList options) {
            llSetLinkGLTFOverridesInternal(link, face, ToArrayNoCopy(options), options.Count);
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static int llSetParcelForSaleInternal(int ForSale, object[] Options, int Options_len);

        public static int llSetParcelForSale(int ForSale, ArrayList Options) {
            return llSetParcelForSaleInternal(ForSale, ToArrayNoCopy(Options), Options.Count);
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static int llTransferOwnershipInternal(Key AgentID, int Flags, object[] Params, int Params_len);

        public static int llTransferOwnership(Key AgentID, int Flags, ArrayList Params) {
            return llTransferOwnershipInternal(AgentID, Flags, ToArrayNoCopy(Params), Params.Count);
        }



    }
}
