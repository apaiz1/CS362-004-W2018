/*
* Adam Paiz
* CS 362
* Winter term
* 4 Feb 2018
* ******************************************************
* Unit Test Function 3: getCost
* *******************************************************
* Every cost value will be checked here
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
    int temp_cost = 0;

    int deck[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag
    , tribute, smithy, council_room};    

    initializeGame (number_players, deck, seed, &reg_game);
    
    printf("***********************************************************\n");
    printf("Testing getCost function\n");
    printf("***********************************************************\n");
    printf("Cost of curse should be 0\n");
    temp_cost = getCost(curse);
    printf("expected 0, actual: %d\n",temp_cost);
    assert(temp_cost == 0);
    printf("***********************************************************\n");
    printf("Cost of estate should be 2\n");
    temp_cost = getCost(estate);
    printf("expected 2, actual: %d\n",temp_cost);
    assert(temp_cost == 2);
    printf("***********************************************************\n");
    printf("Cost of duchy should be 0\n");
    temp_cost = getCost(duchy);
    printf("expected 5, actual: %d\n",temp_cost);
    assert(temp_cost == 5);
    printf("***********************************************************\n");
    printf("Cost of province should be 8\n");
    temp_cost = getCost(province);
    printf("expected 8, actual: %d\n",temp_cost);
    assert(temp_cost == 8);
    printf("***********************************************************\n");
    printf("Cost of copper should be 0\n");
    temp_cost = getCost(copper);
    printf("expected 0, actual: %d\n",temp_cost);
    assert(temp_cost == 0);
    printf("***********************************************************\n");
    printf("Cost of silver should be 3\n");
    temp_cost = getCost(silver);
    printf("expected 3, actual: %d\n",temp_cost);
    assert(temp_cost == 3);
    printf("***********************************************************\n");
    printf("Cost of gold should be 6\n");
    temp_cost = getCost(gold);
    printf("expected 6, actual: %d\n",temp_cost);
    assert(temp_cost == 6);
    printf("***********************************************************\n");
    printf("Cost of adventurer should be 6\n");
    temp_cost = getCost(adventurer);
    printf("expected 6, actual: %d\n",temp_cost);
    assert(temp_cost == 6);
    printf("***********************************************************\n");
    printf("Cost of council_room should be 5\n");
    temp_cost = getCost(council_room);
    printf("expected 5, actual: %d\n",temp_cost);
    assert(temp_cost == 5);
    printf("***********************************************************\n");
    printf("Cost of feast should be 4\n");
    temp_cost = getCost(feast);
    printf("expected 4, actual: %d\n",temp_cost);
    assert(temp_cost == 4);
    printf("***********************************************************\n");
    printf("Cost of gardens should be 4\n");
    temp_cost = getCost(gardens);
    printf("expected 4, actual: %d\n",temp_cost);
    assert(temp_cost == 4);
    printf("***********************************************************\n");
    printf("Cost of mine should be 5\n");
    temp_cost = getCost(mine);
    printf("expected 5, actual: %d\n",mine);
    assert(temp_cost == 5);
    printf("***********************************************************\n");
    printf("Cost of remodel should be 4\n");
    temp_cost = getCost(remodel);
    printf("expected 4, actual: %d\n",temp_cost);
    assert(temp_cost == 4);
    printf("***********************************************************\n");
    printf("Cost of smithy should be 4\n");
    temp_cost = getCost(smithy);
    printf("expected 4, actual: %d\n",temp_cost);
    assert(temp_cost == 4);
    printf("***********************************************************\n");
    printf("Cost of village should be 3\n");
    temp_cost = getCost(village);
    printf("expected 3, actual: %d\n",temp_cost);
    assert(temp_cost == 3);
    printf("***********************************************************\n");
    printf("Cost of baron should be 4\n");
    temp_cost = getCost(baron);
    printf("expected 4, actual: %d\n",temp_cost);
    assert(temp_cost == 4);
    printf("***********************************************************\n");
    printf("Cost of great_hall should be 3\n");
    temp_cost = getCost(great_hall);
    printf("expected 3, actual: %d\n",temp_cost);
    assert(temp_cost == 3);
    printf("***********************************************************\n");
    printf("Cost of minion should be 3\n");
    temp_cost = getCost(minion);
    printf("expected 5, actual: %d\n",temp_cost);
    assert(temp_cost == 5);
    printf("***********************************************************\n");
    printf("Cost of steward should be 3\n");
    temp_cost = getCost(steward);
    printf("expected 3, actual: %d\n",temp_cost);
    assert(temp_cost == 3);
    printf("***********************************************************\n");
    printf("Cost of tribute should be 5\n");
    temp_cost = getCost(tribute);
    printf("expected 5, actual: %d\n",temp_cost);
    assert(temp_cost == 5);
    printf("***********************************************************\n");
    printf("***********************************************************\n");
    printf("Cost of cutpurse should be 4\n");
    temp_cost = getCost(cutpurse);
    printf("expected 4, actual: %d\n",temp_cost);
    assert(temp_cost == 4);
    printf("***********************************************************\n");
    printf("Cost of ambassador should be 3\n");
    temp_cost = getCost(ambassador);
    printf("expected 3, actual: %d\n",temp_cost);
    assert(temp_cost == 3);
    printf("***********************************************************\n");
    printf("Cost of embargo should be 2\n");
    temp_cost = getCost(embargo);
    printf("expected 2, actual: %d\n",temp_cost);
    assert(temp_cost == 2);
    printf("***********************************************************\n");
    printf("Cost of outpst should be 5\n");
    temp_cost = getCost(outpost);
    printf("expected 5, actual: %d\n",temp_cost);
    assert(temp_cost == 5);
    printf("***********************************************************\n");
    printf("Cost of salvager should be 4\n");
    temp_cost = getCost(salvager);
    printf("expected 4, actual: %d\n",temp_cost);
    assert(temp_cost == 4);
    printf("***********************************************************\n");
    printf("Cost of sea_hag should be 4\n");
    temp_cost = getCost(sea_hag);
    printf("expected 4, actual: %d\n",temp_cost);
    assert(temp_cost == 4);
    printf("***********************************************************\n");
    printf("Cost of treasure_map should be 4\n");
    temp_cost = getCost(treasure_map);
    printf("expected 4, actual: %d\n",temp_cost);
    assert(temp_cost == 4);
    printf("***********************************************************\n");
    printf("Passing Tests: 27 \n");
    printf("Failing Tests: 0 \n");
}