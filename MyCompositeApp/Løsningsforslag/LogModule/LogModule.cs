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

namespace LogModule

{
    [ModuleExport(typeof(LogModule))]
    public class LogModule : IModule
    {
        //private readonly CompositionContainer container;
        private readonly IRegionManager regionManager;

        [ImportingConstructor]
        public LogModule(IRegionManager regionManager)
        {
            //this.container     = container;  CompositionContainer container, 
            this.regionManager = regionManager;
        }

        public void Initialize()
        {
            // Configures the MenuView to automatically appear in the Menu region (using View Discovery).
            //this.regionManager.RegisterViewWithRegion("MenuRegion", typeof(MenuView)); // Alternative syntax
            regionManager.RegisterViewWithRegion("MenuRegion", () => new MenuView());

        }
    }
}
