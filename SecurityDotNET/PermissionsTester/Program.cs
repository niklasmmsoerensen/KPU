using Contracts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel.Composition;
using System.ComponentModel.Composition.Hosting;

namespace PermissionsTester
{
    class Program
    {
        static void Main(string[] args)
        {
            App app = new App();
            app.Compose();
            app.Run();
        }
    }

    class App
    {
        [Import(typeof(IFileReader))]
        private IFileReader reader { get; set; }

        public void Run()
        {
            //use reader
           
        }

        public void Compose()
        {
            var catalog = new DirectoryCatalog(@".\Extensions");
            var container = new CompositionContainer(catalog, CompositionOptions.DisableSilentRejection);
            container.ComposeParts(this);
        }
    }
}
