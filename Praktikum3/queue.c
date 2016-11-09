#define QUEUE_SIZE 2

int queue[QUEUE_SIZE];
int * start_elem = 0;
int * cur_elem = 0;

void enqueue(int i)
{
  int * next_elem = (cur_elem - start_elem + 1) % QUEUE_SIZE + cur_elem;
  if(next_elem != start_elem)
  {
    cur_elem = next_elem;
  }
  
  if(!start_elem)
  {
    start_elem = queue;
    cur_elem = start_elem;
  }

  *cur_elem = i;
}

int dequeue()
{
  if(start_elem)
  {
    int elem = *start_elem;
    
    if(cur_elem == start_elem)
    {
      start_elem = 0;
    }
    else
    {
      start_elem++;
    }
    
    return elem;
  }
  else
  {
    return -1;
  }
}
