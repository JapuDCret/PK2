#include <iostream>
#include <chrono>
#include <thread>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <string.h>

#define dimension 7

uint8_t grid[dimension][dimension];

unsigned int sleepInterval = 250;

using namespace std;

struct point {
	int8_t x;
	int8_t y;
};

const uint8_t display_offset = 0;
const uint8_t display_mask = 0x1 << display_offset;
const uint8_t display_off = 0x0;
const uint8_t display_on = 0x1;

const uint8_t direction_offset = 1;
const uint8_t direction_mask = 0x3 << direction_offset;
const uint8_t direction_right = 0x0;
const uint8_t direction_left = 0x1;
const uint8_t direction_up = 0x2;
const uint8_t direction_down = 0x3;

const uint8_t food_offset = 3;
const uint8_t food_mask = 0x1 << food_offset;
const uint8_t food_off = 0x0;
const uint8_t food_on = 0x1;

void apply_direction(struct point* p, uint8_t direction);
void randomize_position(struct point* p);
struct point makeFood();
void keyboard_listener();

int keylistener_active = 42;

uint8_t direction = direction_right;
uint8_t next_direction = direction_right;


char c_head = '@';
char c_tail_u = 'v';
char c_tail_d = '^';
char c_tail_l = '>';
char c_tail_r = '<';
char c_body = '#';
char c_food = '*';
char c_space_v = '|';
char c_space_h = '=';
char c_empty = ' ';

int main(void)
{
	//clear grid.
	{
		int y;
		for(y=0; y < dimension; y++)
		{
			cout << c_space_v;
			int x;
			for(x=0; x < dimension; x++)
			{
				grid[y][x] = 0;
			}
		}
	}
	
	struct point head = { 3,1 };
	struct point tail = { 1,1 };
	makeFood();
	
	grid[1][1] = (direction_right << direction_offset) | (display_on << display_offset);
	grid[1][2] = (direction_right << direction_offset) | (display_on << display_offset);
	grid[1][3] = (direction_down << direction_offset);
	
	std::thread key_listener (keyboard_listener);
	
	char horizontal_spacer[dimension + 2];
	int i;
	for(i=0; i < dimension + 2; i++)
		horizontal_spacer[i] = c_space_h;
	
	
	uint8_t first = 1;
	uint8_t found_food = 0;
	uint8_t ded = 0;
	while(keylistener_active)
	{
		if(first)
			first = 0;
		else
			this_thread::sleep_for(chrono::milliseconds(sleepInterval));
		
		system("cls");
		
		fwrite( &horizontal_spacer, sizeof(char), dimension + 2, stderr );
		
		cout << endl;
		
		direction = next_direction;
		
		if(found_food)
		{
			makeFood();
		}
		
		found_food = 0;
		int y;
		for(y=0; y < dimension; y++)
		{
			fwrite( &c_space_v, sizeof(char), 1, stderr );
			int x;
			for(x=0; x < dimension; x++)
			{
				if((head.x == x) && (head.y == y))
				{
					fwrite( &c_head, sizeof(char), 1, stderr );
					
					if((grid[y][x] & food_mask) >> food_offset == food_on)
					{
						grid[y][x] = grid[y][x] & ~(food_on << food_offset);
						found_food = 1;
					}
					else if((grid[y][x] & display_mask) >> display_offset == display_on)
					{
						ded = 1;
						keylistener_active = 0;
					}
					
					grid[y][x] = grid[y][x] | (1 << display_offset);
				}
				else if((tail.x == x) && (tail.y == y))
				{
					uint8_t tail_direction = (grid[y][x] & direction_mask) >> direction_offset;
					switch(tail_direction)
					{
					case direction_right:
						fwrite( &c_tail_r, sizeof(char), 1, stderr );
						break;
					case direction_left:
						fwrite( &c_tail_l, sizeof(char), 1, stderr );
						break;
					case direction_up:
						fwrite( &c_tail_u, sizeof(char), 1, stderr );
						break;
					case direction_down:
						fwrite( & c_tail_d, sizeof(char), 1, stderr );
						break;
					}
					
					grid[y][x] = grid[y][x] & ~(display_on << display_offset);
				}
				else if((grid[y][x] & display_mask) >> display_offset == display_on)
				{
					if((grid[y][x] & food_mask) >> food_offset == food_on)
						fwrite( &c_food, sizeof(char), 1, stderr );
					else
						fwrite( &c_body, sizeof(char), 1, stderr );
				}
				else
				{
					fwrite( &c_empty, sizeof(char), 1, stderr );
				}
			}
			fwrite( &"|\n", sizeof(char), 2, stderr );
		}
		fwrite( &horizontal_spacer, sizeof(char), dimension + 2, stderr );
		
		//clear old direction and apply new one
		grid[head.y][head.x] = (grid[head.y][head.x] & ~direction_mask) | (direction << direction_offset);
		
		//apply directions
		apply_direction(&head, direction);
		
		if(!found_food)
		{
			uint8_t tail_direction = (grid[tail.y][tail.x] & direction_mask) >> direction_offset;
			apply_direction(&tail, tail_direction);
		}
	}
	
	if(ded)
	{
		cout << "du bist unnormal gestorben, schlecht" << endl;
	}
	
	cout << endl << "Press any key to terminate.";
	keylistener_active = 0;
	key_listener.join();
	
	return 0;
}

void check_overflow(struct point* p)
{
	if(p->x < 0)
		p->x = dimension - 1;
	else if(p->x >= dimension)
		p->x = 0;
	
	if(p->y < 0)
		p->y = dimension - 1;
	else if(p->y >= dimension)
		p->y = 0;
}

void apply_direction(struct point* p, uint8_t direction)
{
	switch(direction)
	{
	case direction_right:
		p->x++;
		break;
	case direction_left:
		p->x--;
		break;
	case direction_up:
		p->y--;
		break;
	case direction_down:
		p->y++;
		break;
	}
	check_overflow(p);
}

void randomize_position(struct point* p)
{
	p->x = rand() % dimension;
	p->y = rand() % dimension;
}

struct point makeFood()
{
	struct point food = { -1,-1 };
	
	do
	{
		randomize_position(&food);
	} while((grid[food.y][food.x] & display_mask) >> display_offset == display_on);
	grid[food.y][food.x] = (food_on << food_offset) | (display_on << display_offset);
	
	return food;
}

void keyboard_listener()
{
	while(keylistener_active)
	{
		char c = _getch();
		switch(c)
		{
		case 'W':
		case 'w':
			if(direction != direction_down)
				next_direction = direction_up;
			break;
		case 'S':
		case 's':
			if(direction != direction_up)
				next_direction = direction_down;
			break;
		case 'A':
		case 'a':
			if(direction != direction_right)
				next_direction = direction_left;
			break;
		case 'D':
		case 'd':
			if(direction != direction_left)
				next_direction = direction_right;
			break;
		case 'C':
		case 'c':
			keylistener_active = 0;
			return;
		}
	}
}