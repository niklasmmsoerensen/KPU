﻿using MenuModule.Views;
using Prism.Modularity;
using Prism.Regions;
using System;
using Microsoft.Practices.Unity;
using Prism.Unity;

namespace MenuModule
{
    public class MenuModuleModule : IModule
    {
        private IRegionManager _regionManager;
        private IUnityContainer _container;

        public MenuModuleModule(IUnityContainer container, IRegionManager regionManager)
        {
            _container = container;
            _regionManager = regionManager;
        }

        public void Initialize()
        {
            _container.RegisterTypeForNavigation<ViewA>();
        }
    }
}