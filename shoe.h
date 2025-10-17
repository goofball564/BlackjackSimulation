#ifndef BLACKJACKSIMULATION_SHOE_H
#define BLACKJACKSIMULATION_SHOE_H

#include "card.h"

#define SUITS_PER_RANK 4
#define CARDS_PER_DECK 52
#define MAX_DECKS 8
#define VALUE_PER_DECK 340

typedef struct {
    Card cards[CARDS_PER_DECK * MAX_DECKS];
    int num_decks;
    int num_cards;
    int remaining_cards;
    int total_value;
    int remaining_value;
    int running_count;
} Shoe;

void init_shoe(Shoe* shoe, int num_decks);
void reset_shoe(Shoe* shoe);
Card take_card_shoe(Shoe* shoe);

#endif //BLACKJACKSIMULATION_SHOE_H