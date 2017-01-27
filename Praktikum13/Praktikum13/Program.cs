using Fh.Pk2.Commands;
using Fh.Pk2.Devices;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Praktikum13
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Starte Program..");

            RemoteControl remote = new RemoteControl();

            CdPlayer player = new CdPlayer();
            Command cdOn = new CdStart(player);
            Command cdOff = new CdStopp(player);

            remote.SetCommand(0, cdOn, cdOff);

            Garagentor garagentor = new Garagentor();
            Command garageOn = new GaragentorHoch(garagentor);
            Command garageOff = new GaragentorRunter(garagentor);

            remote.SetCommand(1, garageOn, garageOff);

            remote.PressOn(0);
            remote.PressOn(1);

            remote.PressOff(0);
            remote.PressOff(1);

            Console.WriteLine("Stoppe Program..");
            Console.ReadLine();
        }
    }
}
