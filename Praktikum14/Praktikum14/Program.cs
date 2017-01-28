using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Praktikum14
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Starte Programm..");


            LinkedList<string> list1 = new LinkedList<string>();

            list1.Add("hallo");
            list1.Add("_");
            list1.Add("Welt");


            Iterator<string> iter = list1.iterator();

            while(iter.hasNext())
            {
                Console.WriteLine("Element: {0}", iter.next() );
            }


            Console.WriteLine("Removing Element at Position 1");
            list1.Remove(1);

            Iterator<string> iter2 = list1.iterator();

            while (iter2.hasNext())
            {
                Console.WriteLine("Element: {0}", iter2.next());
            }
            

            Fuhrpark fuhrpark = new Fuhrpark();

            Auto a1 = new Auto("Tesla", 2010);
            fuhrpark.Aufnehmen(a1);
            Auto a2 = new Auto("Mitsubishi", 1999);
            fuhrpark.Aufnehmen(a2);
            Auto a3 = new Auto("Honda", 2000);
            fuhrpark.Aufnehmen(a3);
            Auto a4 = new Auto("Toyota", 1997);
            fuhrpark.Aufnehmen(a4);

            fuhrpark.Inventur();

            //Console.WriteLine("Flottennalter = {0}", fuhrpark.BerechneFlottennalter());


            Console.WriteLine("Stoppe Programm..");

            Console.ReadLine();
        }
    }
}
