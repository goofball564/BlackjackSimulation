#ifndef BLACKJACKSIMULATION_HAND_H
#define BLACKJACKSIMULATION_HAND_H

#include <stdbool.h>
#include "card.h"

typedef struct {
    Card cards[21];
    int count;
    int value;
    int ace_count;
    bool soft;
} Hand;

void init_hand(Hand* hand);
void add_card_hand(Hand* hand, Card card);
Card take_card_hand(Hand* hand);

#endif //BLACKJACKSIMULATION_HAND_H