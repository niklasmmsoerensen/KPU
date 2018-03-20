using ModuleA.Views;
using Prism.Modularity;
using Prism.Regions;
using System;
using Microsoft.Practices.Unity;
using Prism.Unity;

namespace ModuleA
{
    public class ModuleAModule : IModule
    {
        private IRegionManager _regionManager;
        private IUnityContainer _container;

        public ModuleAModule(IUnityContainer container, IRegionManager regionManager)
        {
            _container = container;
            _regionManager = regionManager;
        }

        public void Initialize()
        {
            _container.RegisterTypeForNavigation<ViewA>();
            _regionManager.RegisterViewWithRegion("CenterRegion", typeof(Views.ViewA));
        }
    }
}