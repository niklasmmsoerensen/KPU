using System;
using System.Collections.Generic;
using System.ComponentModel.Composition;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Contracts;

namespace CAppUtilImp
{
    [Export(typeof(ICappUtil))]
    public class CAppUtil : ICappUtil
    {
        private string Name { get; set; }
        public CAppUtil()
        {

        }
        [ImportingConstructor]
        public CAppUtil(string name)
        {
            Name = name;
        }
        public string GetName()
        {
            return Name;
        }
        
        public string MyAddstring(string str1, string str2)
        {
            return str1 + str2;
        }
    }
}
