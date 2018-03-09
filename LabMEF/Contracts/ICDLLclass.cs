using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Contracts
{
    public interface ICDLLclass
    {
        bool Init(ICappUtil pUtil);
        bool Run();
        void TearDown();
    }
}
