using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Praktikum15
{
    class LinkedList<T>
    {
        Element start;
        Element current_pos;

        public void Add(T value)
        {
            Element elem = new Element(value, null);

            if(start == null)
            {
                start = current_pos = elem;
            }
            else
            {
                //link the previous end with the new element
                current_pos.next = elem;

                //elem is the new end
                current_pos = elem;
            }
        }

        public T Remove(int pos)
        {
            Element current = start;
            Element previous = null;

            if (current != null)
            {
                int i = 0;
                while ((i < pos) && (current.next != null))
                {
                    previous = current;
                    current = current.next;
                    i++;
                }

                if (previous == null)
                {
                    //deleted last element in list
                    start = current_pos = null;
                }
                else
                {
                    previous.next = current.next;
                }

                return current.value;
            }

            return default(T);
        }

        public Iterator<T> iterator()
        {
            return new ListIterator(this);
        }


        class Element
        {
            public T value;
            public Element next;

            public Element(T value, Element next)
            {
                this.value = value;
                this.next = next;
            }
        }


        class ListIterator : Iterator<T>
        {
            private LinkedList<T> list;
            private int pos = 0;

            public ListIterator(LinkedList<T> list)
            {
                this.list = list;
            }

            public Boolean hasNext()
            {
                Element current = list.start;

                int i = 0;
                while ((i++ < pos))
                {
                    if (current.next == null)
                    {
                        return false;
                    }

                    current = current.next;
                }

                return true;
            }

            public T next()
            {
                Element current = list.start;

                int i = 0;
                while ((i++ < pos))
                {
                    if (current.next == null)
                    {
                        return default(T);
                    }

                    current = current.next;
                }

                pos++;
                return current.value;
            }
        }
    }
}
