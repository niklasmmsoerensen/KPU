using Microsoft.Win32.Interop;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Lab1
{
    class Program
    {
        static void Main(string[] args)
        {
            int errorResult;
            int errorInfo;

            Console.WriteLine("Test of Beep");
            errorResult = Kernel32Wrap.Beep(2000, 500);
            if (errorResult == 0)		// In case of an error
                Console.WriteLine("Call of Beep returned an error.");

            Console.WriteLine("Will now try to provoke an error - does not work on Windows 7 or 8 (no error here).");
            errorResult = Kernel32Wrap.Beep(10, 1000);  // Herz must above 36
            if (errorResult == 0)		// In case of an error
            {
                Console.WriteLine("Call of Beep returned an error.");
                errorInfo = Marshal.GetLastWin32Error();    
                Console.WriteLine("  Last Win32 error: {0}", errorInfo);
                Console.WriteLine("        Error name: {0}", ResultWin32.GetErrorName(errorInfo));
            }

            Console.ReadLine();
            BeepMusic.Play();
        }
    }
}
