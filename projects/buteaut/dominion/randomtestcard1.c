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
	int i; //, j;
	int failure = 0;
	int numRuns = 1000;
	struct gameState test1, original;
	int seed = 1000;
	printf("Beginning test of smithy card.\n");
	for (i = 0; i < numRuns; i++) {
		int players = rand() % MAX_PLAYERS + 1;
		int k[10] = { smithy, adventurer, village, great_hall, minion, mine, cutpurse,
			sea_hag, tribute, council_room };
		//int choice1, choice2, choice3 = 0;
		int failureLoop = 0;
		initializeGame(players, k, seed, &test1);
		int activePlayer = rand() % players + 1;
		test1.handCount[activePlayer] = rand() % MAX_HAND + 1;
		test1.deckCount[activePlayer] = rand() % MAX_DECK + 1;
		test1.discardCount[activePlayer] = test1.deckCount[activePlayer] - test1.handCount[activePlayer];
		memcpy(&original, &test1, sizeof(struct gameState));

		
		smithyPlay(&test1, activePlayer);

		//tests
		if (test1.handCount[activePlayer] == original.handCount[activePlayer] + 2) {
			printf("Passed - Player %d hand count is %d and should be %d.\n", activePlayer, test1.handCount[activePlayer], original.handCount[activePlayer] + 2);
		}
		else {
			printf("Failed - Player %d hand count is %d and should be %d.\n", activePlayer, test1.handCount[activePlayer], original.handCount[activePlayer] + 2);
			failure++;
			failureLoop++;
		}

		if (test1.deckCount[activePlayer] == original.deckCount[activePlayer] - 3) {
			printf("Passed - Player %d deck count is %d and should be %d.\n", activePlayer, test1.deckCount[activePlayer], original.deckCount[activePlayer] - 3);
		}
		else {
			printf("Failed - Player %d deck count is %d and should be %d.\n", activePlayer, test1.deckCount[activePlayer], original.deckCount[activePlayer] - 3);
			failure++;
			failureLoop++;
		}
		/*
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
		*/
		if (failureLoop == 0) printf("All tests successful.\n");
		else printf("%d tests failed.\n", failureLoop);
	}
	printf("%d total failures over %d tests.\n", failure, numRuns);
	return 0;
}