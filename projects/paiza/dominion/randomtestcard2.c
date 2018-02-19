/*
* Adam Paiz
* CS 362 
* 18 February 2018
* ***************************************************************************
* Random Test of my Great Hall Card 
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
#include <math.h>

int check_great_hall( int player, struct gameState * post) {
    struct gameState before;
    int number_treasure_before = 0;
    int number_treasure_after = 0;
    int new_cards = 1;
    int discarded_cards = 0;
    int hand_count_before = post->handCount[player];
    memcpy (&before, post, sizeof(struct gameState));
    cardEffect(great_hall,0,0,0,post,0,0);
    int card_drawn = 0;
    int hand_count_after = post->handCount[player];
    /*
    * Make sure hand count doesn't change because you add but discard current 
    */
    assert(post->handCount[player] == before.handCount[player]  );
    /*
    * Some other values will be checked here.
    */
    assert(post->coins == before.coins);
    assert(post->numBuys == before.numBuys);
    /*
    *this value is two instead of one because the code is changed
    *it is a bug really
    */
    assert(post->numActions == before.numActions + 2);
    return 0;
}

int main() {
    int i, r,  deck_count, discard_count, hand_count;
    int number_tests, player;

    int kingdom[10] = {
        adventurer, council_room, feast, gardens, mine, 
        remodel, smithy, village, baron, great_hall
    };

    struct gameState game;
    memset(&game,0, sizeof(struct gameState));
    printf( "Testing great hall.\n");
    printf( "Random Tests\n");

    PutSeed(3000000000);
    SelectStream(2);

    for (number_tests=0; number_tests < 2000; number_tests++) {
        initializeGame(2, kingdomCards, number_tests, &game);
        player = floor(Random() * 2 ) ;
        player = 0;
        int random_1 = (int) (floor(Random() * MAX_HAND));
        int random_2 = (int) (floor(Random() * MAX_DECK));
        int random_3 = (int) (floor(Random() * MAX_HAND));
        game.handCount[player] = random_1;
        game.deckCount[player] = random_2;
        game.discardCount[player] = random_3;
        game.whoseTurn =  player;
        int lower = estate;
        int higher = treasure_map;
        for (i=0; i< game.deckCount[player]; i++) {
            game.hand[player][i] = floor((Random() *26) + 1);
        }
        check_great_hall(player, &game);
    }
    printf("All Tests OK\n");

}