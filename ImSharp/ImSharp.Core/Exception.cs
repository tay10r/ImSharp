using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ImSharp.Core
{
    public class Exception : System.Exception
    {
        public Exception(string message)
            : base(message) { }
    }
}
