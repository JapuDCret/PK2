using Fh.Pk2.Devices;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fh.Pk2.Commands
{
    class CdStart : Command
    {
        private CdPlayer player;

        public CdStart(CdPlayer player)
        {
            this.player = player;
        }

        public override void Execute()
        {
            player.Start();
        }
    }
}
