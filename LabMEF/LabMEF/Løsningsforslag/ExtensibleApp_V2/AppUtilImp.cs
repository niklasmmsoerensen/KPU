using System;
using System.Collections.Generic;
using System.ComponentModel.Composition;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Contracts;

namespace ExtensibleApp_V2
{
    [Export (typeof(IAppUtil))]
    [PartCreationPolicy(CreationPolicy.Shared)]
    public class AppUtilImp : IAppUtil
    {
        public string GetName()
        {
            return Name;
        }

        public string MyAddString(string str1, string str2)
        {
            return str1 + str2;
        }

        public string Name { get; set; }
    }
}
