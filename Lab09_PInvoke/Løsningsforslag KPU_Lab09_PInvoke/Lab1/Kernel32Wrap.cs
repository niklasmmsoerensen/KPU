using System;
using System.Runtime.InteropServices;

namespace Lab1
{
    /// <summary>
    /// This static class provides wraps of some funktions found in Kernel32.dll (Part of Windows API)
    /// </summary>
    public static class Kernel32Wrap
    {
        // http://msdn.microsoft.com/en-us/library/windows/desktop/ms679277(v=vs.85).aspx
        [DllImport("Kernel32", SetLastError = true)]
        public static extern int Beep(uint freq, uint duration);
    }
}
