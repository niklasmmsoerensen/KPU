using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Lab09_PInvoke
{
    class Program
    {
        static void Main(string[] args)
        {

            IntPtr result = Win32API.AddStrings("Hello ", "World");
            string str = Marshal.PtrToStringAnsi(result);
            Console.WriteLine("Result is: " + str);
        }
    }
    public class Win32API
    {
        [DllImport("user32.dll")]
        [return: MarshalAs(UnmanagedType.Bool)]
        public static extern bool MessageBeep(UInt32 beepType);


        [DllImport("Lab1_1test.dll", CharSet = CharSet.Auto, EntryPoint = "myAddStr")]
        public static extern IntPtr AddStrings([MarshalAs(UnmanagedType.LPStr)] string str1, [MarshalAs(UnmanagedType.LPStr)] string str2);

    }
}
