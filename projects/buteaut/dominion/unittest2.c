/***************************************************************************
** Author: Thomas Buteau
** Program: Dominion - Unit Test 2 (fullDeckCount)
** Class: CS362-400
** Date: 2-4-18
** Description: This is a unit test for the fullDeckCount function in dominion.c
***************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int main() {
	printf("Unit test for function fullDeckCount beginning.\n");

	struct gameState* test2 = malloc(sizeof(struct gameState));
	int failure = 0;
	int start, returned, i;
	
	//no cards
	start = 0;
	test2->deckCount[0] = start;
	test2->handCount[0] = start;
	test2->discardCount[0] = start;
	returned = fullDeckCount(0, 1, test2);
	if (returned == start) {
		printf("Passed - %d of %d cards found (no cards).\n", returned, start);
	}
	else {
		printf("Failure - %d of %d cards found (no cards).\n", returned, start);
		failure++;
	}
	start = NULL;
	returned = NULL;

	//5 hand cards
	start = 5;
	test2->deckCount[0] = start;
	test2->handCount[0] = start;
	test2->discardCount[0] = start;
	for (i = 0; i < start; i++) {
		test2->hand[0][i] = 12; //12 is trivial magic number, just represents a card
	}
	returned = fullDeckCount(0, 12, test2);
	if (returned == start) {
		printf("Passed - %d of %d cards found (%d cards in hand).\n", returned, start, start);
	}
	else {
		printf("Failure - %d of %d cards found (%d cards in hand).\n", returned, start, start);
		failure++;
	}
	start = NULL;
	returned = NULL;

	//3 deck cards
	start = 3;
	test2->deckCount[0] = start;
	test2->handCount[0] = start;
	test2->discardCount[0] = start;
	for (i = 0; i < start; i++) {
		test2->deck[0][i] = 7; //7 is trivial magic number, just represents a card
	}
	returned = fullDeckCount(0, 7, test2);
	if (returned == start) {
		printf("Passed - %d of %d cards found (%d cards in deck).\n", returned, start, start);
	}
	else {
		printf("Failure - %d of %d cards found (%d cards in deck).\n", returned, start, start);
		failure++;
	}
	start = NULL;
	returned = NULL;

	//2 discard cards
	start = 2;
	test2->deckCount[0] = start;
	test2->handCount[0] = start;
	test2->discardCount[0] = start;
	for (i = 0; i < start; i++) {
		test2->discard[0][i] = 9; //9 is trivial magic number, just represents a card
	}
	returned = fullDeckCount(0, 9, test2);
	if (returned == start) {
		printf("Passed - %d of %d cards found (%d cards in discard).\n", returned, start, start);
	}
	else {
		printf("Failure - %d of %d cards found (%d cards in discard).\n", returned, start, start);
		failure++;
	}
	start = NULL;
	returned = NULL;

	//3 deck cards 4 hand card 2 discard cards
	int startDeck = 3;
	int startHand = 4;
	int startDiscard = 2;
	start = startDeck + startDiscard + startHand;
	test2->deckCount[0] = startDeck;
	test2->handCount[0] = startHand;
	test2->discardCount[0] = startDiscard;
	for (i = 0; i < startDeck; i++) {
		test2->deck[0][i] = 9; //9 is trivial magic number, just represents a card
	}
	for (i = 0; i < startHand; i++) {
		test2->hand[0][i] = 9; //9 is trivial magic number, just represents a card
	}
	for (i = 0; i < startDiscard; i++) {
		test2->discard[0][i] = 9; //9 is trivial magic number, just represents a card
	}
	returned = fullDeckCount(0, 9, test2);
	if (returned == start) {
		printf("Passed - %d of %d cards found (mixed from deck, hand, discard).\n", returned, start);
	}
	else {
		printf("Failure - %d of %d cards found (mixed from deck, hand, discard).\n", returned, start);
		failure++;
	}
	start = NULL;
	returned = NULL;

	if (failure == 0) printf("All tests successful.\n");
	else printf("%d tests failed.\n", failure);

	return 0;
}