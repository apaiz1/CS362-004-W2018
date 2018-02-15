/*
* Adam Paiz
* CS 362
* Winterterm
* 4 Feb 2018
* ******************************************************
* Unit Test Function 2: buyCard 
* *******************************************************
* First, the function will be make sure that with less than 1
numBuys it returns -1.
* Next, if it asks for a card that isn't availalble, it also
returns -1
* Next, if there is not enough money, it should return -1.
* If the card is allowed, check to make sure, the right number
of coins is deducted.
Also check that the number of buys goes down.
**********************************************************
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int main() {
    int new_cards = 0;
    int discarded_cards = 1;
    int extra_coins = 0;
    int shuffled_cards = 0;

    struct gameState reg_game;
    int seed = 900;

    int number_players = 2;
    int player = 0;
    int other_player = 1;
    int choice_1 = 0;
    int choice_2 = 0;
    int choice_3 = 0;
    int hand_pos = 0;
    int bonus = 0;

    int deck[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag
    , tribute, smithy, council_room};    

    initializeGame (number_players, deck, seed, &reg_game);
    printf("****************************************************\n");
    printf(" test buyCard function\n");
    printf("****************************************************\n");
    printf("Testing numBuys is less than 1\n");
    reg_game.numBuys = -1;
    int return_val = buyCard(village, &reg_game);
    printf("Should return -1, actual: %d\n", return_val);
    assert(return_val == -1);
    reg_game.numBuys = 1;
    printf("****************************************************\n");
    printf("test not enough coins\n");
    reg_game.coins = 0;
    return_val = buyCard(village, &reg_game);
    printf("Should return -1, actual: %d\n", return_val);
    assert(return_val == -1);
    reg_game.coins = 10;
    reg_game.numBuys = 10;
    printf("****************************************************\n");
    printf("Test not enough of a card available\n");
    reg_game.supplyCount[village] = 0;
    return_val = buyCard(village, &reg_game);
    printf("Should return -1, actual: %d\n", return_val);
    assert(return_val == -1);
    reg_game.supplyCount[village] = 10;
    printf("****************************************************\n");

    printf("Test for when the buy is successful");
    int beg_coins = reg_game.coins;
    reg_game.numBuys = 10;
    int beg_buys = reg_game.numBuys;
    buyCard(village, &reg_game);
    printf("Started with 10 coins; village cost 3 should be 7\n");
    printf("expected coins 7, actual: %d\n", reg_game.coins);
    assert(reg_game.coins == 7);
    printf("Started with 10 buys; village should use 1\n");
    printf("expected buys 9, actual: %d\n", reg_game.numBuys);
    assert(reg_game.numBuys == 9);
    printf("****************************************************\n");
    printf("Tests Completed\n");
    printf("Passing Tests: 5\n");
    printf("Failing Tests: 0\n");
}