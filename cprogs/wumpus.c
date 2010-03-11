
/* Hunt the Wumpus Game */
#include<stdio.h>
#include<stdlib.h>

/* Program Constants Defined here */
#define MAPWIDTH 7
#define MAPHEIGHT 7
#define NUM_PITS 4

/* Function Prototypes Defined here */

void initMap(char [MAPWIDTH][MAPHEIGHT]);
void printMap(char [MAPWIDTH][MAPHEIGHT]);
int move(int,int,int,int,char [MAPWIDTH][MAPHEIGHT]);
void smell(int,int,char [MAPWIDTH][MAPHEIGHT]);
int shoot(int,int,int,int,int,char [MAPWIDTH][MAPHEIGHT]);

int main(void)
{
	int num_arrows = 3;	/* Total Number of Arrows */
	char map[MAPWIDTH][MAPHEIGHT];	/* Map of Territory */
	int choice;			/* Users Input Command */
	int x,y;			/* Current Position of Player */
	int dx,dy;			/* Change in Direction */
	int flag;			/* Generic Error Flag */
	int action;			/* Action 1: -> Move */
					/* Action 2: -> Shoot */

	int debug = 1;

	/* Intialize Map */
	
	srand(time(NULL));
	initMap(map);
	
	/* Place Player at Random Location */
	/* Make sure you dont place a Player on Wumpus or a in a Pit! */

	flag = 1;
	while(flag == 1)
	{
		x = (rand() % 5) + 1;
		y = (rand() % 5) + 1;
	
		if(map[x][y] == '.')
		{
			map[x][y] = '@';
			flag = 0;
		}
	}

	printf("Welcome to 'Hunt the Wumpus' \n");
	
	if(debug)
		printMap(map);

	smell(x,y,map);

	/* Keep prompting for user input */
	do	
	{
		printf("Enter a Command: ");
		fflush(stdout);
		choice = getc(stdin);
		printf("\n");

		/* Clearing stdin manually */
		if(choice != '\n')
			while(getchar() != '\n')
				; /* empty statement */

		switch(choice)
		{
			/* Movement options */
			case 'n':
					dx = 0;
					dy = -1;
					action = 1;
					break;
			case 's':
					dx = 0;
					dy = +1;
					action =1;
					break;
			case 'e':
					dx = +1;
					dy = 0;
					action =1;
					break;
			case 'w':
					dx = -1;
					dy = 0;
					action =1;
					break;

			/* Shoot Options */
			
			case 'N':
					dx = 0;
					dy = -1;
					action = 2;
					break;
			case 'S':
					dx = 0;
					dy = +1;
					action = 2;
					break;
			case 'E':
					dx = +1;
					dy = 0;
					action = 2;
					break;
			case 'W':
					dx = -1;
					dy = 0;
					action = 2;
					break;

			default:
					printf("You cannot do that!\n");
					action = 0;
					break;

		}

	/* Move Player */

	if(action == 1)
	{
		flag = move(x,y,dx,dy,map);
		if(flag == 1)
		{
			map[x][y] ='.';
			x = x + dx;
			y = y + dy;
			map[x][y]='@';

		}
		else if(flag == -1)
			break;
	}

	/* Shoot */
	else if(action == 2)
	{
		flag = shoot(num_arrows--,x,y,dx,dy,map);
		if(flag == -1)
			break;
	}

	if(debug)
		printMap(map);
	smell(x,y,map);
}while(choice != 'Q' || choice !='q');

printf("Press any key to exit..");
getchar();

return 0;
}

/* Intialize Map with randomly placed Pits and Randomly placed Wumpus */

void initMap(char map[MAPWIDTH][MAPHEIGHT])
{
	int i,j;
	int x,y;

	/* First create a Clean Slate */
	
	for(j=0;j<MAPHEIGHT;j++)
		for(i=0;i<MAPWIDTH;i++)
			map[i][j]='.';

	/* Create walls around perimeter of map */
	
	for(i=0;i<MAPWIDTH;i++)
	{
		map[i][0]='#';
		map[i][MAPHEIGHT-1]='#';
	}
	
	for(j=1;j<MAPHEIGHT-1;j++)
	{
		map[0][j]='#';
		map[MAPWIDTH-1][j]='#';
	}

	/* Create Bottomless Pits at Random Locations */
	
	for(i=0;i<NUM_PITS;i++)
	{
		x = (rand() % 5) + 1;
		y = (rand() % 5) + 1;
		map[x][y] = 'P';
	}

	/* Create Wumpus at Random Location */

	x = (rand() % 5) + 1;
	y = (rand() % 5) + 1;
	
	map[x][y] = 'W';

}

/* This is a debug function that prints the entire map at any one time */

void printMap(char map[MAPWIDTH][MAPHEIGHT])
{
	int i,j;

	for(j=0;j<MAPHEIGHT;j++)
	{
		for(i=0;i<MAPWIDTH;i++)
			printf("%c",map[i][j]);
		printf("\n");
	}
}


/* Moves the Player to a new room */
/* This may Result in an untimely death */

int move(int x,int y,int dx,int dy,char map[MAPWIDTH][MAPHEIGHT])
{
	x = x + dx;
	y = y + dy;

	if(map[x][y] == '#')
	{
		printf("You try to move in that direction,");
		printf("but you bump into that wall.\n");
		return 0;
	}
	else if(map[x][y] == 'P')
	{
		printf("Yikes! You have fallen into a bottomless pit!");
		printf("Better Luck next time.\n");
		return -1;
	}
	else if(map[x][y] == 'W')
	{
		printf("Munch..Munch..\n");
		printf("The Wumpus has just had you for Lunch.\n");
		return -1;
	}
	else
		return 1;
}

/* This function provides the player with feedback about what might be in any of the adjoining rooms */

void smell(int x,int y,char map[MAPWIDTH][MAPHEIGHT])
{
	int pit_flag = 0;
	int wumpus_flag = 0;
	int i,j;

	/* First check West to East */
	for(i=x-1;i<=x+1;i++)
	{
		if(map[i][y]=='P')
			pit_flag = 1;
		else if(map[i][y]=='W')
			wumpus_flag =1;
	}
	
	/* Then check North to South */
	for(j=y-1;j<=y+1;j++)
	{
		if(map[x][j]=='P')
			pit_flag = 1;
		else if(map[x][j] == 'W')
			wumpus_flag = 1;
	}

	printf("You are in a dark room.\n");

	if(wumpus_flag == 1)
		printf("You smell the distinctive odor of a Wumpus.\n");
	if(pit_flag == 1)
		printf("You feel a cool breeze.\n");
}


/* Shoots an arrow in the indicated direction */

int shoot(int num_arrows,int x,int y,int dx,int dy,char map[MAPWIDTH][MAPHEIGHT])
{
	x = x + dx;	
	y = y + dy;

	if(num_arrows > 0)
	{
		printf("You shoot your arrow into the dark...\n");
		
		if(map[x][y] == 'W')
		{
			printf("\a You have slain a Wumpus!\n");
			return -1;
		}
		else
		{
			printf("And, you can hear it fall to the ground in the next room \n");
			return 0;
		}
	}
	else 
	{
		printf("You dont have any more arrows!\n");
		return 0;
	}
}
