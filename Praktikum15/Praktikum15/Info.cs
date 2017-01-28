using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Praktikum15
{
    class Info
    {
        public Info(Fuhrpark fuhrpark)
        {
            fuhrpark.FuhrparkEreignis += Informiere;
        }

        public void Informiere(object sender, FuhrparkEreignisArgs args)
        {
            Console.WriteLine("Ein neues Auto wurde hinzugefuegt! Ein {1} aus dem Jahr {0}", args.auto.baujahr, args.auto.hersteller);
        }
    }
}
