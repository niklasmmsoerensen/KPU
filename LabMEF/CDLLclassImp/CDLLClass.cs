using Contracts;
using System;
using System.Collections.Generic;
using System.ComponentModel.Composition;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CDLLclassImp
{
    [Export(typeof(ICDLLclass))]
    public class CDLLClass : ICDLLclass
    {
        private ICappUtil _pUtil;
        
        public bool Init(ICappUtil pUtil)
        {
            if(pUtil != null)
            {
                _pUtil = pUtil;
                Console.WriteLine("CDLLclass imp initialised!");
                return true;
            }
            else
            {
                Console.WriteLine("Error! pUtil was null");
                return false;
            }
        }
        
        public bool Run()
        {
            string str1 = "Hello ";
            string str2 = "World";
            Console.WriteLine("Adding two strings: Hello + World with pUtil");
            string result = _pUtil.MyAddstring(str1, str2);
            Console.WriteLine("Result was: " + result);
            Console.WriteLine("getName: " + _pUtil.GetName());
            return true;
        }
        
        public void TearDown()
        {
            Console.WriteLine("CDLLClass teardown");
        }
    }
}
