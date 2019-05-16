/*
initalize_players.c

Liam Muir, 2019

implementations of functions to initalize player data.

1 is healing potions, 2 is magic weapons, 3 is gauntlets
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "initalize_players.h"
#include "structs.h"
#include "combat_data.h"

#define MAGE 1
#define KNIGHT 2
#define ARCHER 3

const char* helpClass = "The character you choose determines the attacks you can use, the HP you have, and your AC.\nThe mage has fireball, staff, 30 HP and an AC of 11.\nThe knight has sword, lance, 40 HP and an AC of 14.\nThe archer has bow, dagger, 35 HP and an AC of 12";
const char* helpPerks = "The perk you choose determines the special actions you can take to give you an edge against your opponent\nYou get three healing potions that heal 4-8 HP each if you choose healing.\nThe magic weapons deal %20 percent more damage than normal.\nThe gauntlets allow you to punch your opponents, dealing 3-7 damage when hit.";

static int getBeginData(char* question,char* option_one, char* option_two, char* option_three, const char* help_text){//general logic for three choice question asking
	while(1){
		printf("\n%s\n\n", question);
		printf("1:%s, 2:%s, 3:%s, 4:help: ", option_one, option_two, option_three);
		int answer;
		scanf("%i", &answer);
			switch(answer){i
			case 1:
			return 1; 
			break;
			case 2:
			return 2;
			break;
			case 3:
			return 3;
			break;
			case 4:
			printf("\n%s\n", help_text);
			break;
		}
	}
	return 0;
}

static struct player* beginPlayer(){ //handles the begining text and gets players choice 
	int class = getBeginData("Choose Your Fighter!","mage","knight","archer",helpClass);
	int perk = getBeginData("Choose Your Special Perk!","healing potions","magic weapons","gauntlets",helpPerks);
	struct player newplayer = malloc(sizeof(struct player));
	newplayer->class = class;
	newplayer->perk = perk;
	newplayer->ac = actable[class];
	return newplayer;
}

static void printClassVs(struct match* game){ //prints versus message
	switch(game->p1->class){
		case MAGE:
		printf("\nMage");
		break;
		case ARCHER:
		printf("\nArcher");
		break;
		case KNIGHT:
		printf("\nKnight");
		break;
	}
	printf(" vs ");
	switch(game->p2->class){
		case MAGE:
		printf("Mage!\n");
		break;
		case ARCHER:
		printf("Archer!\n");
		break;
		case KNIGHT:
		printf("Knight!\n");
		break;
	}
}

struct match* initgame(){ //initalizes game
	struct match* game = malloc(sizeof(struct match));
	printf("\nWelcome to Text Fighters!\n");
	printf("\nPlayer one,\n");
	game->p1 = beginPlayer();
	printf("\nPlayer two,\n");
	game->p2 = beginPlayer();
	printClassVs(game);
	return game;
}













