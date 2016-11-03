#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

typedef struct node node_t;

struct node {
	int value;
	node_t * next;
};

node_t * dictionary[SIZE];

int insert(int d)
{
	int h = hash(d);
	
	node_t * elem = dictionary[h];
	
	node_t * new_elem = (node_t *) malloc(sizeof(node_t));
	if(new_elem)
	{
		new_elem->next = elem;
		new_elem->value = d;
		dictionary[h] = new_elem;
		return 1;
	}
	else
	{
		return 0;
	}
}

int delete(int d)
{
	int h = hash(d);
	
	node_t * elem = dictionary[h];
	node_t * elem_prev = NULL;
	
	while(elem)
	{
		if(elem->value == d)
		{
			if(elem_prev)
			{
				elem_prev->next = elem->next;
			}
			else//beginning of list
			{
				dictionary[h] = elem->next;
			}
			
			free(elem);
			
			return 1;
		}
		
		elem_prev = elem;
		elem = elem->next;
	}
	
	return 0;
}

int member(int d)
{
	int h = hash(d);
	
	node_t * elem = dictionary[h];
	
	while(elem)
	{
		if(elem->value == d)
		{
			return 1;
		}
		
		elem = elem->next;
	}
	
	return 0;
}

char * to_string()
{
	int i;
	for(i=0; i < SIZE; i++)
	{
		node_t * elem = dictionary[i];
		putch('[');
		short first = ~0;
		while(elem)
		{
			if(first)
			{
				first = 0;
			}
			else
			{
				putch(',');
			}
			int value = elem->value;
			putch(((value % 100) / 10) + '0');
			putch((value % 10) + '0');
			
			elem = elem->next;
		}
		putch(']');
		putch('\n');
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