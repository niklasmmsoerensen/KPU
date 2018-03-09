using System;
using System.Collections.Generic;
using System.ComponentModel.Composition;
using System.ComponentModel.Composition.Hosting;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using Contracts;

namespace ExtensibleApp
{
    class Program
    {
        [Import(typeof(ICDLLclass))]
        private ICDLLclass Plugin { get; set; }

        [Import(typeof(ICappUtil))]
        private ICappUtil Util { get; set; }
        static void Main(string[] args)
        {
            Program app = new Program();
            app.Compose();
            app.Run();
        }
        public void Run()
        {
            
            Plugin.Init(Util);
            Plugin.Run();
            Plugin.TearDown();
        }
        public void Compose()
        {
            var catalog = new DirectoryCatalog(@".\Extensions");
            var container = new CompositionContainer(catalog, CompositionOptions.DisableSilentRejection);
            container.ComposeParts(this);
        }
    }
}
