﻿using Log.Views;
using Prism.Modularity;
using Prism.Regions;
using System;
using Microsoft.Practices.Unity;
using Prism.Unity;

namespace Log
{
    public class LogModule : IModule
    {
        private IRegionManager _regionManager;
        private IUnityContainer _container;

        public LogModule(IUnityContainer container, IRegionManager regionManager)
        {
            _container = container;
            _regionManager = regionManager;
        }

        public void Initialize()
        {
            _container.RegisterTypeForNavigation<ViewA>();
            _regionManager.RegisterViewWithRegion("LogRegion", typeof(ViewA));
        }
    }
}