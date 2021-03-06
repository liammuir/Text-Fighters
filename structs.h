/*
structs.h

Liam Muir, 2019

include in all files that use player structs.

due to pointer problems, you have to access the player data with thr notation of match->p1.datafield
*/

#ifndef __STRUCTS__
#define __STRUCTS__

#define MAGE 1
#define KNIGHT 2
#define ARCHER 3

#define HEAL 1
#define MAGIC 2
#define GAUNT 3

struct player{
	int hp;
	int ac;
	int class;
	int perk;
	int healing_potions;
	int parry;
};

struct match{
	struct player p1;
	struct player p2;
	int distance;
};

#endif