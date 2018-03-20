using Status.Views;
using Prism.Modularity;
using Prism.Regions;
using System;
using Microsoft.Practices.Unity;
using Prism.Unity;

namespace Status
{
    public class StatusModule : IModule
    {
        private IRegionManager _regionManager;
        private IUnityContainer _container;

        public StatusModule(IUnityContainer container, IRegionManager regionManager)
        {
            _container = container;
            _regionManager = regionManager;
        }

        public void Initialize()
        {
            _container.RegisterTypeForNavigation<ViewA>();
            _regionManager.RegisterViewWithRegion("StatusRegion", typeof(ViewA));
        }
    }
}