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
#include <math.h>

int check_adventurer( int player, struct gameState * post) {
    struct gameState before;
    int number_treasure_before = 0;
    int number_treasure_after = 0;
    int hand_count_before = post->handCount[player];
    memcpy (&before, post, sizeof(struct gameState));
    /*
    * Make sure treasured should be at least two
    */
    printf("before card effect\n");
    cardEffect(adventurer,0,0,0,post,0,0);
    int card_drawn = 0;
    int hand_count_after = post->handCount[player];
    printf("after card effect\n");
    for (int i = 0; i< hand_count_before; i++) {
        printf("hand count %d, deckk handcout %d\n",i,before.handCount[player]);
        card_drawn = before.hand[player][i];
        if (card_drawn == copper) {
            number_treasure_before += 1;
        }
        else if (card_drawn == silver) {
            number_treasure_before += 1;
        }
        else if (card_drawn == gold) {
            number_treasure_before += 1;
        }
    }
    printf("here2\n");
    for (int i = 0; i< hand_count_after; i++) {
        card_drawn = post->hand[player][i];
        if (card_drawn == copper) {
            number_treasure_after += 1;
        }
        else if (card_drawn == silver) {
            number_treasure_after += 1;
        }
        else if (card_drawn == gold) {
            number_treasure_after += 1;
        }
    }
    printf("%d number treasure after, %d number treasure before\n",number_treasure_before, number_treasure_after);
    assert( number_treasure_after - number_treasure_before >= 0);
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
    printf( "Testing Adventuer.\n");
    printf( "Random Tests\n");

    SelectStream(2);
    PutSeed(3);

    for (number_tests=0; number_tests < 2000; number_tests++) {
        game.deckCount[0] = 0;
        for (i = 0; i < sizeof(struct gameState); i++) {
            int inner_random = (int) (floor(Random()*256));
            ((char*) &game)[i] = inner_random;
        }
        player = floor(Random() * 2 ) ;
        int random_1 = (int) (floor(Random() * MAX_HAND));
        int random_2 = (int) (floor(Random() * MAX_DECK));
        int random_3 = (int) (floor(Random() * MAX_HAND));
        game.handCount[player] = random_1;
        game.deckCount[player] = random_2;
        game.discardCount[player] = random_3;
        game.whoseTurn =  player;
        int lower = estate;
        int higher = treasure_map;
        printf("lower %d, higher %d\n",lower,higher);
        for (i=0; i< game.deckCount[player]; i++) {
            game.hand[player][i] = rand() %26 + 1;
        }
        printf("player %d, max_hand %d max_deck %d\n",player, MAX_HAND, MAX_DECK);
        printf("handcount %d, deckout %d, discardccount %d\n",game.handCount[player], game.deckCount[player], game.discardCount[player]);
        printf("number tests %d\n",number_tests);
        check_adventurer(player, &game);
    }
    printf("All Tests OK\n");

}