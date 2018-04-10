using MyCompositeApp.Views;
using System.Windows;
using Prism.Modularity;
using Microsoft.Practices.Unity;
using Prism.Unity;
using ModuleA.Views;
using ModuleA;
using Status;
using Log;
using Menu;

namespace MyCompositeApp
{
    class Bootstrapper : UnityBootstrapper
    {
        protected override DependencyObject CreateShell()
        {
            return Container.Resolve<MainWindow>();
        }

        protected override void InitializeShell()
        {
            Application.Current.MainWindow.Show();
        }

        protected override void ConfigureModuleCatalog()
        {
            var moduleCatalog = (ModuleCatalog)ModuleCatalog;
            //Add module to modulecatalog so prism can discover it and call its Initialize()
            moduleCatalog.AddModule(typeof(ModuleAModule));
            moduleCatalog.AddModule(typeof(StatusModule));
            moduleCatalog.AddModule(typeof(MenuModule));
        }
        protected override IModuleCatalog CreateModuleCatalog()
        {
            var catalog = new ConfigurationModuleCatalog();
            return catalog;
        }
    }
}
