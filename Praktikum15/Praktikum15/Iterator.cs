using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Praktikum15
{
    public interface Iterator<T>
    {
        Boolean hasNext();

        T next();
    }
}
