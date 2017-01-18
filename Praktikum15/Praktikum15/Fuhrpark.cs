using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Praktikum15
{
    class FuhrparkEreignisArgs : EventArgs
    {
        public Auto auto { get; set; }

        public FuhrparkEreignisArgs(Auto auto)
        {
            this.auto = auto;
        }
    }

    class Fuhrpark
    {
        public delegate void FuhrparkEreignisHandler(object sender, FuhrparkEreignisArgs args);

        public event FuhrparkEreignisHandler FuhrparkEreignis;

        LinkedList<Auto> list = new LinkedList<Auto>();

        public void Aufnehmen(Auto auto)
        {
            list.Add(auto);
            FuhrparkEreignis(this, new FuhrparkEreignisArgs(auto));
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
