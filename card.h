#ifndef BLACKJACKSIMULATION_CARD_H
#define BLACKJACKSIMULATION_CARD_H

extern const int card_values[13];

typedef enum {
    ACE = 0,
    TWO = 1,
    THREE = 2,
    FOUR = 3,
    FIVE = 4,
    SIX = 5,
    SEVEN = 6,
    EIGHT = 7,
    NINE = 8,
    TEN = 9,
    JACK = 10,
    QUEEN = 11,
    KING = 12,
} Card;

#endif //BLACKJACKSIMULATION_CARD_H