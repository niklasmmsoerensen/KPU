using System;
using System.Runtime.InteropServices;

namespace Lab3
{
    class Program
    {
        // extern "C" LAB3_DLL_API void SomeUnmanagedFunctionUsingCallback(double x, FafX pF);
        [DllImport("Lab3_Dll.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void SomeUnmanagedFunctionUsingCallback(double x, CallBackDelegate callback);

        // Definition of delegate used for callback function
        public delegate double CallBackDelegate(double x);

        static void Main(string[] args)
        {
            CallBackDelegate theFunctionDelegate = new CallBackDelegate(Math.Sin);
            Console.WriteLine("Calling \"SomeUnmanagedFunctionUsingCallback\" with F=sin(pi/2) ------ \n");
            SomeUnmanagedFunctionUsingCallback(Math.PI / 2.0, theFunctionDelegate);

            Console.WriteLine("\n---------------------------------------\n");
            Console.WriteLine("Calling \"SomeUnmanagedFunctionUsingCallback\" with F=MySqr(2) ------ \n");
            theFunctionDelegate = new CallBackDelegate(MySqr);
            SomeUnmanagedFunctionUsingCallback(2.0, theFunctionDelegate);

            Console.WriteLine("\n---------------------------------------\n");
            Console.WriteLine("Calling \"SomeUnmanagedFunctionUsingCallback\" with F=MyPower(x) ------ \n");
            // Need an object because use of non-static function
            Program anObject = new Program();
            theFunctionDelegate = new CallBackDelegate(anObject.MyPower);
            anObject.power = 3.0;
            SomeUnmanagedFunctionUsingCallback(2.0, theFunctionDelegate);
            Console.Write("Pres enter to continue");
            Console.ReadLine();
        }

        public static double MySqr(double x)
        {
            return x * x;
        }

        // Private data member power
        private double power;

        public double MyPower(double x)
        {
            return Math.Pow(x, power);
        }
    }
}
