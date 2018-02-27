#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state, 
		int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);
int cardEffect(int card, int choice1, int choice2, int choice3, 
	       struct gameState *state, int handPos, int *bonus);
int adventureerPlay(struct gameState *state); //new function *bugged*
int minePlay(int choice1, int choice2, struct gameState *state, int handPos); //new function *bugged*
int remodelPlay(int choice1, int choice2, struct gameState *state, int handPos); //new function
int smithyPlay(struct gameState *state, int handPos); //new function *bugged*
int villagePlay(struct gameState *state, int handPos); //new function *bugged*
#endif
