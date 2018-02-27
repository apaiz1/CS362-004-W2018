/***************************************************************************
** Author: Thomas Buteau
** Program: Dominion - Card Test 4 (great hall)
** Class: CS362-400
** Date: 2-4-18
** Description: This is a card test for the great hall card in dominion.c
***************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int main() {
	int failure = 0;

	struct gameState test1, original;
	int seed = 1000;
	int players = 2;
	int k[10] = { smithy, adventurer, village, great_hall, minion, mine, cutpurse,
		sea_hag, tribute, council_room };
	int choice1 = 0, choice2 = 0, choice3 = 0;

	initializeGame(players, k, seed, &test1);
	test1.hand[0][0] = great_hall;
	memcpy(&original, &test1, sizeof(struct gameState));

	cardEffect(great_hall, choice1, choice2, choice3, &test1, 0, 0);

	//tests
	if (test1.handCount[0] == original.handCount[0]) {
		printf("Passed - Player 0 hand count is %d and should be %d.\n", test1.handCount[0], original.handCount[0]);
	}
	else {
		printf("Failed - Player 0 hand count is %d and should be %d.\n", test1.handCount[0], original.handCount[0]);
		failure++;
	}

	if (test1.handCount[1] == original.handCount[1]) {
		printf("Passed - Player 1 hand count is %d and should be %d.\n", test1.handCount[1], original.handCount[1]);
	}
	else {
		printf("Failed - Player 1 hand count is %d and should be %d.\n", test1.handCount[1], original.handCount[1]);
		failure++;
	}

	if (test1.deckCount[0] == original.deckCount[0] - 1) {
		printf("Passed - Player 0 deck count is %d and should be %d.\n", test1.deckCount[0], original.deckCount[0] - 1);
	}
	else {
		printf("Failed - Player 0 deck count is %d and should be %d.\n", test1.deckCount[0], original.deckCount[0] - 1);
		failure++;
	}

	if (test1.deckCount[1] == original.deckCount[1]) {
		printf("Passed - Player 1 deck count is %d and should be %d.\n", test1.deckCount[1], original.deckCount[1]);
	}
	else {
		printf("Failed - Player 1 deck count is %d and should be %d.\n", test1.deckCount[1], original.deckCount[1]);
		failure++;
	}

	if (test1.numActions == original.numActions + 1) {
		printf("Passed - %d actions available, %d actions expected.\n", test1.numActions, original.numActions + 1);
	}
	else {
		printf("Failed - %d actions available, %d actions expected.\n", test1.numActions, original.numActions + 1);
		failure++;
	}

	if (failure == 0) printf("All tests successful.\n");
	else printf("%d tests failed.\n", failure);

	return 0;
}