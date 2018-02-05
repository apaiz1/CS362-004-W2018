/*
* Adam Paiz
* CS 362
* Winter term
* 4 Feb 2018
* ******************************************************
* Unit Test Function 4: buyCard 
* *******************************************************
* First, it will make sure it doesn't work if phase is not 0.
* Then, it will make sure it doesn't work if the actions are less than 1.
* If an action card is chosen it also fails.
* after the card is chosen make sure it returns negative 1.
( check that the number of cards goes down)
* check that coins are updated
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
    int return_val = 0;

    int deck[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag
    , tribute, smithy, council_room};    

    initializeGame (number_players, deck, seed, &reg_game);
    printf("****************************************************\n");
    printf("Testing playCard\n");
    printf("****************************************************\n");
    printf("if phase is not zero should be negative 1");
    reg_game.phase = 1;
    return_val = playCard(0,choice_1,choice_2,choice_3,&reg_game);
    printf("expected -1, actual: %d\n", return_val);
    assert( return_val == -1);
    reg_game.phase = 0;
    printf("****************************************************\n");
    printf("if actions are less than one should return -1\n");
    reg_game.numActions = -1;
    return_val = playCard(0,choice_1,choice_2,choice_3,&reg_game);
    printf("expected -1, actual: %d\n", return_val);
    assert(return_val == -1);
    reg_game.numActions = 10;
    printf("****************************************************\n");
    reg_game.whoseTurn = 0;
    printf(" if card is not an action should be -1\n");
    reg_game.hand[0][hand_pos] = gold;
    return_val = playCard(hand_pos,choice_1,choice_2,choice_3, &reg_game);
    printf("expected: -1, actual: %d\n",return_val);
    assert(return_val == -1);
    printf("****************************************************\n");
    hand_pos = 1;
    reg_game.hand[0][hand_pos] = smithy;
    int beg_actions = reg_game.numActions;
    playCard(hand_pos, choice_1, choice_2, choice_3, &reg_game);
    printf("Number of actions should be decreased by one for successful card\n");
    printf("beg: %d, after %d\n", beg_actions, reg_game.numActions);
    assert(beg_actions == reg_game.numActions + 1);
    printf("****************************************************\n");
    printf("Tests passed: 4\n");
    printf("Tests Failed: 0\n");

}