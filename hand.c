#include "hand.h"

void init_hand(Hand* hand) {
    hand->count = 0;
    hand->value = 0;
    hand->ace_count = 0;
    hand->soft = false;
}

void add_card_hand(Hand* hand, const Card card) {
    hand->cards[hand->count++] = card;
    hand->value += card_values[card];

    if (card == ACE) {
        hand->ace_count++;
    }

    if (hand->ace_count > 0 && hand->value <= 11 && hand->soft == false) {
        hand->value += 10;
        hand->soft = true;
    }
    else if (hand->value > 21 && hand->soft) {
        hand->value -= 10;
        hand->soft = false;
    }
}

Card take_card_hand(Hand* hand) {
    const Card card = hand->cards[hand->count-- - 1];
    hand->value -= card_values[card];

    if (card == ACE) {
        hand->ace_count--;
    }

    if (hand->ace_count > 0 && hand->value <= 11 && hand->soft == false) {
        hand->value += 10;
        hand->soft = true;
    }
    else if (hand->soft && hand->ace_count == 0) {
        hand->soft = false;
        hand->value -= 10;
    }

    return card;
}