/*
* Adam Paiz
* CS 362
* Spring term
* 4 Feb 2018
* ******************************************************
* First Test of Dominion card: smithy 
* *******************************************************
*
*
*
*
*
*
*
* This file was inspired by the samples provided for homework.
**********************************************************
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <Stdlib.h>

#define TESTCARD "smithy"

int main() {
    int new_cards = 0;
    int discarded_cards = 1;
    int extra_coins = 0;
    int shuffled_cards = 0;

    struct gameState reg_game;
    struct gameState test_game;
    int seed = 900;

    int number_players = 2;
    int player = 0;
    int other_player = 1;
    /*
    * The smithy card does not have any options. So it will stay the same
    * for this game.
    */
    int choice_1 = 0;
    int choice_2 = 0;
    int choice_3 = 0;
    int hand_pos = 0;
    int bonus = 0;

    int deck[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag
    , tribute, smithy, council_room};    

    initializeGame (number_players, deck, seed, &reg_game);

    printf("************************Testing Card: %s ************\n", TESTCARD);
    
    /*
    * The player should receive three cards for smithy
    */
    printf("*********************Test One *********************\n");
    printf("Does the player with smithy get three cards?");

    memcpy(&test_game, & reg_game, sizeof(struct gameState));
    cardEffect( smithy, choice_1, choice_2, choice_3, &test_game,
       hand_pos, &bonus);
    new_cards = 3;
    extra_coins = 0;
    printf("hand count = %d, expected = %d\n", test_game.handCount[player], 
        reg_game.handCount[player] + new_cards - discarded_cards);
    printf("deck count = %d, expected = %d\n", test_game.deckCount[player],
        reg_game.deckCount[player] - new_cards + shuffled_cards);
    printf("coins = %d, expected coins = %d\n", test_game.coins, 
        reg_game.coins + extra_coins);
    assert(test_game.handCount[player] == reg_game.handCount[player] 
        + new_cards - discarded_cards);
    assert(test_game.handCount[player] == reg_game.handCount[player] 
        - new_cards + shuffled_cards);

    printf("******************************* Tests Done *****************\n");
}