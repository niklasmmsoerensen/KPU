using Contracts;
using System;
using System.Collections.Generic;
using System.ComponentModel.Composition;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PlugInn1_v2
{
    [Export(typeof(IDLLcontract))]
    public class PlugInn1 : IDLLcontract
    {
        [Import (typeof(IAppUtil))]
        IAppUtil appUtil {get; set;}

        public void Init(IAppUtil util)
        {
            //appUtil = util;
        }

        public bool Run()
        {
            Console.WriteLine(appUtil.MyAddString("Hello ", "World"));
            Console.WriteLine("Your name is: " + appUtil.GetName());
            return true;
        }

        public void TearDown()
        {
            appUtil = null;
        }
    }
}
