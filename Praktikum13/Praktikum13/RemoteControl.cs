using Fh.Pk2.Commands;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Praktikum13
{
    class RemoteControl
    {
        private Command[][] buttons = {
            new Command[2],
            new Command[2],
            new Command[2],
            new Command[2]
        };

        public void SetCommand(int i, Command on, Command off)
        {
            if(i >= 4)
            {
                throw new IndexOutOfRangeException();
            }

            buttons[i] = new Command[] { on, off };
        }

        public void PressOn(int i)
        {
            buttons[i][0].Execute();
        }

        public void PressOff(int i)
        {
            buttons[i][1].Execute();
        }
    }
}
