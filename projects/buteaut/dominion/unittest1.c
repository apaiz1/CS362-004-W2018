/***************************************************************************
** Author: Thomas Buteau
** Program: Dominion - Unit Test 1 (buyCard)
** Class: CS362-400
** Date: 2-4-18
** Description: This is a unit test for the buyCard function in dominion.c
***************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int main() {
	printf("Unit test for function buyCard beginning.\n");
	
	struct gameState* test1 = malloc(sizeof(struct gameState));
	test1->supplyCount[smithy] = 1;
	test1->whoseTurn = 1;
	test1->coins = 4;
	test1->numBuys = 0;
	test1->discardCount[1] = 0;
	int failure = 0;
	if(buyCard(smithy, test1) == -1) { //test should fail because 0 buys available
		printf("Passed - Correct for 0 buys available.\n");
	}
	else {
		printf("Failed - Incorrect for 0 buys available.\n");
		failure++;
	}

	test1->numBuys = 2;

	if (buyCard(smithy, test1) == 0) { //test should pass and buy the card
		printf("Passed - Correct for buying smithy card.\n");
	}
	else {
		printf("Failed - Incorrect for valid buy attempt.\n");
		failure++;
	}

	if (buyCard(smithy, test1) == -1) { //test should fail because of a lack of coin
		printf("Passed - Correct for 0 coin available.\n");
	}
	else {
		printf("Failed - Incorrect for 0 coin available.\n");
		failure++;
	}

	test1->coins = 4;

	if (buyCard(smithy, test1) == -1) { //test should fail due to lack of supply cards
		printf("Passed - Correct for 0 cards available.\n");
	}
	else {
		printf("Failed - Incorrect for 0 cards available.\n");
		failure++;
	}

	if (test1->discard[1][0] == smithy) {
		printf("Passed - Correct card in discard pile of player 1.\n");
	}
	else {
		printf("Failed - Test of discard pile failed.\n");
		failure++;
	}

	if (test1->discardCount[1] == 1) {
		printf("Passed - Correct number of cards in player 1 discard pile.\n");
	}
	else {
		printf("Failed - Incorrect number of cards in player 1 discard pile.\n");
		failure++;
	}

	if (test1->supplyCount[smithy] == 0) {
		printf("Passed - Correct number of supply card 'smithy' available.\n");
	}
	else {
		printf("Failed - Incorrect number of supply card 'smithy' available.\n");
		failure++;
	}

	if(failure == 0) printf("All tests successful.\n");
	else printf("%d tests failed.\n", failure);

	return 0;
}
