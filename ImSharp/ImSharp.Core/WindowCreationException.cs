using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ImSharp.Core
{
    public class WindowCreationException : Exception
    {
        public WindowCreationException(string message)
            : base(message) { }
    }
}
