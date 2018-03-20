using Menu.Views;
using Prism.Modularity;
using Prism.Regions;
using System;
using Microsoft.Practices.Unity;
using Prism.Unity;

namespace Menu
{
    public class MenuModule : IModule
    {
        private IRegionManager _regionManager;
        private IUnityContainer _container;

        public MenuModule(IUnityContainer container, IRegionManager regionManager)
        {
            _container = container;
            _regionManager = regionManager;
        }

        public void Initialize()
        {
            _container.RegisterTypeForNavigation<ViewA>();
            _regionManager.RegisterViewWithRegion("MenuRegion", typeof(ViewA));
        }
    }
}