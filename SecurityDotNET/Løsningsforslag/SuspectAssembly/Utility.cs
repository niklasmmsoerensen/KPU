using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SuspectAssembly
{
    public class Utility : MarshalByRefObject
    {
        public void Foo()
        {
            StreamReader sr = new StreamReader("ImportantFile.txt");
            while (!sr.EndOfStream)
            {
                string secret = sr.ReadLine();
            }
            Console.WriteLine("Sending secret info to super hacker");
        }

        public void PrintDomain()
        {
            Console.WriteLine("Object is executing in AppDomain \"{0}\"",
                AppDomain.CurrentDomain.FriendlyName);
        }

    }
}
