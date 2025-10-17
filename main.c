#include <stdio.h>
#include "hand.h"
#include "shoe.h"

int main(void) {
    Hand hand;
    init_hand(&hand);

    int num_decks = 1;

    Shoe shoe;
    init_shoe(&shoe, num_decks);

    Card c;

    for (int i = 0; i < CARDS_PER_DECK * num_decks; i++) {
        c = take_card_shoe(&shoe);
        printf("Card: %d\n", c);
    }

    return 0;
}