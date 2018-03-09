using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SSAWrapper;
using System.IO;
using System.Security;
using System.Security.Permissions;

namespace CautiousAppEx
{
    class Program
    {
        const string pathToUntrusted = "UntrustedComponents";
        const string wrapperAssembly = "SSAWrapper";

        static void Main(string[] args)
        {
            // Non-sandboxed use of Wrapper 
            Wrapper utility = new Wrapper();
            utility.PrintDomain();
            utility.Foo();

            //Setting the AppDomainSetup. It is very important to set the ApplicationBase to a folder 
            //other than the one in which the sandboxer resides.
            AppDomainSetup adSetup = new AppDomainSetup();
            adSetup.ApplicationBase = Path.GetFullPath(pathToUntrusted);

            //Setting the permissions for the AppDomain. We give the permission to execute and to 
            //read/discover the location where the untrusted code is loaded.
            PermissionSet permSet = new PermissionSet(PermissionState.None);
            permSet.AddPermission(new SecurityPermission(SecurityPermissionFlag.Execution));

            //Now we have everything we need to create the sandbox AppDomain, so let's create it.
            AppDomain sandbox = AppDomain.CreateDomain("Sandbox", null, adSetup, permSet);

            // Load the wrapper into the sandbox (the new application domain)
            var wrapperAsm = sandbox.Load(wrapperAssembly);

            // Uses CreateInstanceAndUnwrap to create an instance of the Utility class in the Sandbox
            Wrapper sandboxedWrapper = (Wrapper)sandbox.CreateInstanceAndUnwrap(wrapperAsm.FullName, "SSAWrapper.Wrapper");
            try
            {
                sandboxedWrapper.PrintDomain();
                sandboxedWrapper.Foo();
            }
            catch (SecurityException ex)
            {
                Console.WriteLine("The Utility class did something it was not allowed to,\n which caused a SecurityException to be thrown!");
                Console.WriteLine(ex.Message);
            }

            Console.ReadLine();
        }
    }
}
