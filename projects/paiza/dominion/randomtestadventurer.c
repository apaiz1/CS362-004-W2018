/*
* Adam Paiz
* CS 362 
* 18 February 2018
* ***************************************************************************
* Random Test of my Adventurer Function
* ***************************************************************************
* At the start, this file was inspired by betterTestDrawCard.c from the 
* lectures.
* 
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int check_adventurer( int number_players, struct gameState * post) {
    struct gameState before;
    memcpy (&before, post, sizeof(struct gameState));
    cardEffect(adventurer,0,0,0,post,0,0);
    return 0;
}

int main() {
    int i, r,  deck_count, discard_count, hand_count;
    int number_tests, number_players;

    int kingdom[10] = {
        adventurer, council_room, feast, gardens, mine, 
        remodel, smithy, village, baron, great_hall
    };

    struct gameState game;

    printf( "Testing Adventuer.\n");
    printf( "Random Tests\n");

    SelectStream(2);
    PutSeed(3);

    for (number_tests=0; number_tests < 2000; number_tests++) {
        number_players = floor(Random() * 2 ) ;
        check_adventurer(number_players, &game);
    }
    printf("All Tests OK\n");

}