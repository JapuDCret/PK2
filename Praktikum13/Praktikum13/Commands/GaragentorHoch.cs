using Fh.Pk2.Devices;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fh.Pk2.Commands
{
    class GaragentorHoch : Command
    {
        private Garagentor garagentor;

        public GaragentorHoch(Garagentor garagentor)
        {
            this.garagentor = garagentor;
        }

        public override void Execute()
        {
            garagentor.Hoch();
        }
    }
}
