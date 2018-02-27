/***************************************************************************
** Author: Thomas Buteau
** Program: Dominion - Unit Test 3 (isGameOver)
** Class: CS362-400
** Date: 2-4-18
** Description: This is a unit test for the isGameOver function in dominion.c
***************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int main() {
	printf("Unit test for function isGameOver beginning.\n");

	struct gameState* test3 = malloc(sizeof(struct gameState));
	int failure = 0;
	int i;

	//normal operation should continue
	for (i = 0; i < 25; i++) {
		test3->supplyCount[i] = 5;
	}
	test3->supplyCount[province] = 5;
	test3->supplyCount[curse] = 5;
	test3->supplyCount[adventurer] = 5;
	test3->supplyCount[smithy] = 5;
	test3->supplyCount[baron] = 5;

	if (isGameOver(test3) == 0) {
		printf("Passed - Game continues. \n");
	}
	else {
		printf("Failure - Game stopped when it should have continued.\n");
		failure++;
	}
	for (i = 0; i < 25; i++) {
		test3->supplyCount[i] = 0;
	}

	//no more provinces remaining
	for (i = 0; i < 25; i++) {
		test3->supplyCount[i] = 5;
	}
	test3->supplyCount[province] = 0;
	if (isGameOver(test3) == 1) {
		printf("Passed - Province end. \n");
	}
	else {
		printf("Failure - Game continued when it should have stopped.\n");
		failure++;
	}
	for (i = 0; i < 25; i++) {
		test3->supplyCount[i] = 0;
	}

	//Normal operation 2 supplies empty
	for (i = 0; i < 25; i++) {
		test3->supplyCount[i] = 5;
	}
	test3->supplyCount[smithy] = 0;
	test3->supplyCount[baron] = 0;

	if (isGameOver(test3) == 0) {
		printf("Passed - Game continues. \n");
	}
	else {
		printf("Failure - Game stopped when it should have continued.\n");
		failure++;
	}
	for (i = 0; i < 25; i++) {
		test3->supplyCount[i] = 0;
	}

	//End game operation 3 supplies empty
	test3->supplyCount[adventurer] = 0;
	test3->supplyCount[smithy] = 0;
	test3->supplyCount[baron] = 0;

	if (isGameOver(test3) == 1) {
		printf("Passed - 3 supplies empty end. \n");
	}
	else {
		printf("Failure - Game continued when it should have stopped.\n");
		failure++;
	}
	for (i = 0; i < 25; i++) {
		test3->supplyCount[i] = 0;
	}

	//End game operation 4 supplies empty
	test3->supplyCount[curse] = 0;
	test3->supplyCount[adventurer] = 0;
	test3->supplyCount[smithy] = 0;
	test3->supplyCount[baron] = 0;

	if (isGameOver(test3) == 1) {
		printf("Passed - 4 supplies empty end. \n");
	}
	else {
		printf("Failure - Game continued when it should have stopped.\n");
		failure++;
	}
	for (i = 0; i < 25; i++) {
		test3->supplyCount[i] = 0;
	}

	if (failure == 0) printf("All tests successful.\n");
	else printf("%d tests failed.\n", failure);

	return 0;
}