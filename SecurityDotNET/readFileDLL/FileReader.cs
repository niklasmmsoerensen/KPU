using Contracts;
using System;
using System.Collections.Generic;
using System.Composition;
using System.Linq;
using System.Security;
using System.Security.Permissions;
using System.Text;
using System.Threading.Tasks;

namespace readFileDLL
{
    [Export(typeof(IFileReader))]
    public class FileReader : IFileReader
    {
        public FileReader()
        {

        }

        public string readFile(string filePath)
        {
            IPermission permission;
            permission = new FileIOPermission(FileIOPermissionAccess.Write, filePath);
            permission.Demand();
            return System.IO.File.ReadAllText(filePath);
        }
    }
}
