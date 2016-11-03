#include <stdio.h>
#include "dictionary.h"

int main()
{
	printf("SIZE: %d\n", get_size());
	
	int i;
	for(i = 1; i <= 2 * SIZE; i++){
		printf("%d", insert(i));
	}
	
	printf("\n");
	to_string();
	
	printf("\n");
	for(i = 1; i <= SIZE; i++){
		printf("%d", member(i));
	}
	
	printf("\n");
	for(i = SIZE+1; i <= 2*SIZE; i++){
		printf("%d", delete(i));
	}
	
	printf("\n");
	to_string();
	
	printf("\n");
	for(i = 1; i <= 2*SIZE; i++){
		printf("%d", member(i));
	}
	printf("\n");
}