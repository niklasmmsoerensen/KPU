using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SimpleSuspectAssembly;

namespace SSAWrapper
{
    public class Wrapper : MarshalByRefObject
    {
        Utility utilityWrap;

        public Wrapper()
        {
            utilityWrap = new Utility();
        }

        public void Foo()
        {
            utilityWrap.Foo();
        }

        public void PrintDomain()
        {
            utilityWrap.PrintDomain();
        }
    }
}
