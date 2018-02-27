/***************************************************************************
** Author: Thomas Buteau
** Program: Dominion - Unit Test 4 (updateCoins)
** Class: CS362-400
** Date: 2-4-18
** Description: This is a unit test for the updateCoins function in dominion.c
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
	printf("Unit test for function updateCoins beginning.\n");

	struct gameState* test4 = malloc(sizeof(struct gameState));
	int bonus = 0;
	test4->handCount[0] = 10;
	
	updateCoins(0, test4, bonus);
	if (test4->coins == 0) {
		printf("Passed - 0 coins test. \n");
	}
	else {
		printf("Failed - 0 coins test.\n");
		failure++;
	}

	test4->hand[0][0] = copper;
	updateCoins(0, test4, bonus);
	if (test4->coins == 1) {
		printf("Passed - 1 copper test. \n");
	}
	else {
		printf("Failed - 1 copper test.\n");
		failure++;
	}

	test4->hand[0][1] = silver;
	updateCoins(0, test4, bonus);
	if (test4->coins == 3) {
		printf("Passed - 1 copper, 1 silver test. \n");
	}
	else {
		printf("Failed - 1 copper, 1 silver test.\n");
		failure++;
	}

	test4->hand[0][2] = gold;
	updateCoins(0, test4, bonus);
	if (test4->coins == 6) {
		printf("Passed - 1 copper, 1 silver, 1 gold test. \n");
	}
	else {
		printf("Failed - 1 copper, 1 silver, 1 gold test.\n");
		failure++;
	}

	bonus = 4;
	updateCoins(0, test4, bonus);
	if (test4->coins == 10) {
		printf("Passed - 1 copper, 1 silver, 1 gold, 4 bonus test. \n");
	}
	else {
		printf("Failed - 1 copper, 1 silver, 1 gold, 4 bonus test.\n");
		failure++;
	}

	if (failure == 0) printf("All tests successful.\n");
	else printf("%d tests failed.\n", failure);

	return 0;
}