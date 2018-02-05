/*
* Adam Paiz
* CS 362
* winter term
* 4 Feb 2018
* ******************************************************
* Unit Test Function 1: initializeGame() 
* *******************************************************
* First, the numbers of curse cards and estate cards are tested for two players.
* Then, it is tested for three players.
* Finally, it is tested for four players. This covers all the possibilities.
* Then, the available resources are tested.
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
    struct gameState game_3;
    struct gameState game_4;
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
    initializeGame (3,deck, seed, &game_3);
    initializeGame (4, deck, seed, &game_4);
    //Check that the number of players is 2
    printf("****************************************************\n");
    printf("Testing initializeGame function\n");
    printf("****************************************************\n");
    printf("Checking values for when number of players is 2\n");
    printf("number of players is 2, actual: %d\n", reg_game.numPlayers);
    assert(reg_game.numPlayers == 2);
    printf("number of curse cards is 10, actual: %d\n", reg_game.supplyCount[curse]);
    assert(reg_game.supplyCount[curse] == 10);
    printf("number of estate cards is 8, actual: %d\n", reg_game.supplyCount[estate]);
    assert(reg_game.supplyCount[estate] == 8);
    printf("number of duchy cards is 8, actual: %d\n", reg_game.supplyCount[duchy]);
    assert(reg_game.supplyCount[duchy] == 8);
    printf("number of province cards is 8, actual: %d\n", reg_game.supplyCount[province]);
    assert(reg_game.supplyCount[province] == 8);
    printf("****************************************************\n");
    printf("Checking values for when number of players is 3\n");
    printf("number of players is 3, actual: %d\n", game_3.numPlayers);
    assert(game_3.numPlayers == 3);
    printf("number of curse cards is 20, actual: %d\n", game_3.supplyCount[curse]);
    assert(game_3.supplyCount[curse] == 20);
    printf("number of estate cards is 12, actual: %d\n", game_3.supplyCount[estate]);
    assert(game_3.supplyCount[estate] == 12);
    printf("number of duchy cards is 12, actual: %d\n", game_3.supplyCount[duchy]);
    assert(game_3.supplyCount[duchy] == 12);
    printf("number of province cards is 12, actual: %d\n", game_3.supplyCount[province]);
    assert(game_3.supplyCount[province] == 12);
    printf("****************************************************\n");
    printf("Checking values for when number of players is 4\n");
    printf("number of players is 4, actual: %d\n", game_4.numPlayers);
    assert(game_4.numPlayers == 4);
    printf("number of curse cards is 30, actual: %d\n", game_4.supplyCount[curse]);
    assert(game_4.supplyCount[curse] == 30);
    printf("number of estate cards is 12, actual: %d\n", game_4.supplyCount[estate]);
    assert(game_4.supplyCount[estate] == 12);
    printf("number of duchy cards is 12, actual: %d\n", game_4.supplyCount[duchy]);
    assert(game_4.supplyCount[duchy] == 12);
    printf("number of province cards is 12, actual: %d\n", game_4.supplyCount[province]);
    assert(game_4.supplyCount[province] == 12);
    printf("****************************************************\n");
    printf("checking numbers of resources\n");
    printf("number of silver in game should be 40, actual: %d\n" ,
        reg_game.supplyCount[silver] == 40);
    assert(reg_game.supplyCount[silver] == 40);
    printf("number of gold in game should be 30, actual: %d\n", 
        reg_game.supplyCount[gold] == 30);
    printf("for 2 players number of copper should be 46, actual %d\n", 
        reg_game.supplyCount[copper] );
    assert(reg_game.supplyCount[copper] == 46);
    printf("for 3 plays number of copper should be 39, actual %d\n",
        game_3.supplyCount[copper]);
    assert(game_3.supplyCount[copper] == 39);
    printf("for 3 players number of copper should be 32, actual %d\n", 
        game_4.supplyCount[copper]);
    printf("****************************************************\n");

    
}