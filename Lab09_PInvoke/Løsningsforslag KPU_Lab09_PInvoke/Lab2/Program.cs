using System;
using System.Runtime.InteropServices;
using System.Text;

namespace Lab2
{
    class Program
    {
        // Listing of functions to import from my custom DLL

        // extern "C" LAB1_1_API int myAdd(int number1, int number2)
        [DllImport("Lab1_1.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int myAdd(int number1, int number2);

        //extern "C" LAB1_1_API char* myAddStr(char* str1, char* str2)
        [DllImport("Lab1_1.dll", CallingConvention = CallingConvention.Cdecl, CharSet=CharSet.Ansi)]
        public static extern IntPtr myAddStr(string str1, string str2);

        //extern "C" LAB1_1_API string myAddString(string str1, string str2) <-- PInvoke kender ikkt til string-klassen i C++, så dette fejler!!!
        [DllImport("Lab1_1.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr myAddString(string str1, string str2);


        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main(string[] args)
        {
            Console.WriteLine("Calling navetive C++ myAdd from C#:");
            int a = 2;
            int b = 3;
            int res;
            res = myAdd(a, b);
            Console.WriteLine("  myAdd says: {0} + {1} is {2}.", a, b, res);

            Console.WriteLine("Calling navetive C++ myAddStr from C#:");
            string str1 = "Hello";
            string str2 = " World";
            IntPtr ptr = myAddStr(str1, str2);  // In order to get the correct semantics here I must return an IntPtr.
            string strRes = Marshal.PtrToStringAnsi(ptr);
            Console.WriteLine("  myAddStr says: {0}", strRes);
            //Marshal.FreeHGlobal(ptr); // Can't free memory allocated by C++'s new --> memory leak!

            //Console.WriteLine("calling navetive c++ myaddstring from c#:");
            //string str3 = "hello";
            //string str4 = " mars";
            //ptr = myAddString(str3, str4);  // dette burde ikke virke, og det gør det heller ikke!
            //string strres2 = Marshal.PtrToStringAuto(ptr);
            //Console.WriteLine("  myaddstr says: {0}", strres2);

            Console.ReadKey();
        }
    }
}
