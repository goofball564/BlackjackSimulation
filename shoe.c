#define _CRT_RAND_S

#include <stdio.h>
#include <stdlib.h>
#include "shoe.h"

errno_t random_in_range_inclusive(unsigned int max, unsigned int* random_result) {
    errno_t error_result = rand_s(random_result);

    if (error_result == 0) {
        *random_result = *random_result % (max + 1);
    }

    return error_result;
}

void init_shoe(Shoe* shoe, int num_decks) {
    shoe->num_decks = num_decks;
    shoe->num_cards = CARDS_PER_DECK * num_decks;
    shoe->total_value = VALUE_PER_DECK * num_decks;

    int index = 0;
    for (int i = 0; i < num_decks; i++) {
        for (int j = 0; j < SUITS_PER_RANK; j++) {
            for (Card c = ACE; c <= KING; c++) {
                shoe->cards[index] = c;
                index++;
            }
        }
    }

    reset_shoe(shoe);
}

void reset_shoe(Shoe* shoe) {
    shoe->remaining_cards = CARDS_PER_DECK * shoe->num_decks;
    shoe->remaining_value = shoe->total_value;
    shoe->running_count = 0;
}

Card take_card_shoe(Shoe* shoe) {
    int i = --shoe->remaining_cards;
    unsigned int j;
    errno_t error = random_in_range_inclusive(i, &j);

    while (error != 0) {
        printf("ERROR\n");
        error = random_in_range_inclusive(i, &j);
    }

    Card return_card = shoe->cards[j];
    shoe->cards[j] = shoe->cards[i];
    shoe->cards[i] = return_card;

    if (return_card >= TEN) {
        shoe->running_count--;
    } else if (return_card <= SIX) {
        shoe->running_count++;
    }

    return shoe->cards[i];
}