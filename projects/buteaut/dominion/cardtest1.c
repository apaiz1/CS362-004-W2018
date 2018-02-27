/***************************************************************************
** Author: Thomas Buteau
** Program: Dominion - Card Test 1 (smithy)
** Class: CS362-400
** Date: 2-4-18
** Description: This is a card test for the smithy card in dominion.c
***************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int main() {
	int i, j;
	int failure = 0;
	/*
	struct gameState* test1 = malloc(sizeof(struct gameState));
	test1->handCount[0] = 1;
	test1->handCount[1] = 2;
	test1->hand[0][0] = 13;
	test1->hand[1][0] = 13;
	test1->hand[1][1] = 13;
	test1->deckCount[0] = 5;
	test1->deckCount[1] = 6;
	for (j = 0; j < 2; j++) {
		for (i = 0; i < test1->deckCount[0]; i++) {
			test1->deck[j][i] = 13;
		}
	}
	test1->discardCount[0] = 0;
	test1->discardCount[1] = 0;
	test1->whoseTurn = 0;

	struct gameState* original;
	memcpy(&original, &test1, sizeof(struct gameState));
	*/
	struct gameState test1, original;
	int seed = 1000;
	int players = 2;
	int k[10] = { smithy, adventurer, village, great_hall, minion, mine, cutpurse,
		sea_hag, tribute, council_room };
	int choice1, choice2, choice3 = 0;

	initializeGame(players, k, seed, &test1);
	memcpy(&original, &test1, sizeof(struct gameState));


	smithyPlay(&test1, 0);

	//tests
	if (test1.handCount[0] == original.handCount[0] + 2) {
		printf("Passed - Player 0 hand count is %d and should be %d.\n", test1.handCount[0], original.handCount[0] + 2);
	}
	else {
		printf("Failed - Player 0 hand count is %d and should be %d.\n", test1.handCount[0], original.handCount[0] + 2);
		failure++;
	}

	if (test1.deckCount[0] == original.deckCount[0] - 3) {
		printf("Passed - Player 0 deck count is %d and should be %d.\n", test1.deckCount[0], original.deckCount[0] - 3);
	}
	else {
		printf("Failed - Player 0 deck count is %d and should be %d.\n", test1.deckCount[0], original.deckCount[0] - 3);
		failure++;
	}

	if (test1.handCount[1] == original.handCount[1]) {
		printf("Passed - Player 1 hand count is %d and should be %d.\n", test1.handCount[1], original.handCount[1]);
	}
	else {
		printf("Failed - Player 1 hand count is %d and should be %d.\n", test1.handCount[1], original.handCount[1]);
		failure++;
	}

	if (test1.deckCount[1] == original.deckCount[1]) {
		printf("Passed - Player 1 deck count is %d and should be %d.\n", test1.deckCount[1], original.deckCount[1]);
	}
	else {
		printf("Failed - Player 1 deck count is %d and should be %d.\n", test1.deckCount[1], original.deckCount[1]);
		failure++;
	}

	if (failure == 0) printf("All tests successful.\n");
	else printf("%d tests failed.\n", failure);

	return 0;
}