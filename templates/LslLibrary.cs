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

        /* GENERATED FUNCTION BINDINGS */
    }
}
