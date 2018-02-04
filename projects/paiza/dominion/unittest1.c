/*
* Adam Paiz
* CS 362
* Spring term
* 4 Feb 2018
* ******************************************************
* Unit Test Function 1: initializeGame() 
* *******************************************************
* The tests occur in 4 broad categories
* 1) Check the state of the first player to gain one card.
* 2) Check the state of the other player
* 3) Check the shared state of the two players.
* The number of actions should be increased by one.
* 4) Check the kingdom and victory cards.
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
#include <stdlib.h>


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
    int choice_1 = 0;
    int choice_2 = 0;
    int choice_3 = 0;
    int hand_pos = 0;
    int bonus = 0;

    int deck[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag
    , tribute, smithy, council_room};    

    initializeGame (number_players, deck, seed, &reg_game);
    //Check that the number of players is 2
    printf("number of players is 2, actual: %d", reg_game.numPlayers);
    assert(reg_game.numPlayers == 2);
    printf("number of curse cards is 10, actual: %d\n", reg_game.supplyCount[curse]);
    assert(reg_game.supplyCount[curse] == 10);
    printf("number of estate cards is 8, actual: %d\n", reg_game.supplyCount[estate]);
    assert(reg_game.supplyCount[estate] == 8);
    printf("number of duchy cards is 8, actual: %d\n", reg_game.supplyCount[duchy]);
    assert(reg_game.supplyCount[duchy] == 8);
    printf("number of province cards is 8, actual: %d\n", reg_game.supplyCount[province]);
    assert(reg_game.supplyCount[province] == 8);
    
}