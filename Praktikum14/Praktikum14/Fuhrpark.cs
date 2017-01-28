using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Praktikum14
{
    class Fuhrpark
    {
        LinkedList<Auto> list = new LinkedList<Auto>();

        public void Aufnehmen(Auto a)
        {
            list.Add(a);
        }

        public void Inventur()
        {
            Iterator<Auto> iter = list.iterator();

            while(iter.hasNext())
            {
                Auto a = iter.next();

                Console.WriteLine("Ein {0} aus dem Jahr {1}", a.hersteller, a.baujahr);
            }
        }

        public double BerechneFlottennalter()
        {
            int count = 0;
            int sum = 0;

            Iterator<Auto> iter = list.iterator();

            while (iter.hasNext())
            {
                Auto a = iter.next();

                sum += a.baujahr;

                count++;
            }

            return sum / count;
        }
    }
}
