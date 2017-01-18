using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Praktikum14
{
    class Auto
    {
        public string hersteller;
        public int baujahr
        {
            get { return baujahr; }
            set { baujahr = value; }
        }

        public Auto(string hersteller, int baujahr)
        {
            this.hersteller = hersteller;
            this.baujahr = baujahr;
        }
    }
}
