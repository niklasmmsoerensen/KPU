using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel.Composition;
using Microsoft.Practices.Prism.Logging;
using Microsoft.Practices.Prism.MefExtensions;
using Microsoft.Practices.Prism.Modularity;
using Microsoft.Practices.Prism.Regions;
using Microsoft.Practices.Prism.MefExtensions.Modularity;

namespace StatusModule
{
    [ModuleExport("StatusModule", typeof(StatusModule))]
    public class StatusModule : IModule
    {

        public StatusModule()
        {
            
        }

        public void Initialize()
        {
            
        }
    }
}
