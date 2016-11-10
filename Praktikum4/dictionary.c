#include "dictionary.h"

int hash(int a);

typedef struct node node_t;

struct node {
  int value;
  int flag;//0 means free
};

node_t dictionary[SIZE];

int insert(int a)
{
  int h = hash(a);
  
  int i=h;
  while(dictionary[i].flag)
  {
    i = hash(i + 1);
    //one full rotation...exit
    if(i == h)
      return -1;
  }
  dictionary[i].value = a;
  dictionary[i].flag = 1;//set taken
  
  return i;
}

int delete(int a)
{
  int h = hash(a);
  
  int i=h;
  while(dictionary[i].value != a)
  {
    //check if it's free, then there can't be other entries
    if(!dictionary[i].flag)
      break;
    
    i = hash(i + 1);
    //check for one full rotation...exit
    if(i == h)
      return -1;
  }
  
  if(!dictionary[i].flag)
  {
    return -1;//the entry found is already free
  }
  else
  {
    dictionary[i].flag = 0;//set free
    return i;
  }
}

int member(int a)
{
  int h = hash(a);
  
  int i=h;
  while(dictionary[i].value != a)
  {
    //check if it's free, then there can't be other entries
    if(!dictionary[i].flag)
      break;
    
    i = hash(i + 1);
    //check for one full rotation...exit
    if(i == h)
      return 0;
  }
  
  if(!dictionary[i].flag)
    return 0;//the entry found is free
  else
    return 1;
}

void visit_all(void (*work)(int value, int flag))
{
  int i;
  for(i=0; i < SIZE; i++)
  {
    work(dictionary[i].value, dictionary[i].flag);
  }
}

int get_size()
{
	return SIZE;
}

int hash(int a)
{
  return a % SIZE;
}