#include <stdio.h>
#include "hand.h"
#include "shoe.h"

const char card_chars[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

int main(void) {
    const int num_decks = 1;

    Shoe shoe;
    init_shoe(&shoe, num_decks);

    Hand player_hand;
    init_hand(&player_hand);

    Hand dealer_hand;
    init_hand(&dealer_hand);

    for (int i = 0; i < 2; i++) {
        const Card player_card = take_card_shoe(&shoe);
        add_card_hand(&player_hand, player_card);

        const Card dealer_card = take_card_shoe(&shoe);
        add_card_hand(&dealer_hand, dealer_card);
    }

    const Card dealer_face_up_card = dealer_hand.cards[0];


    // if dealer has blackjack -- lose or push if player has blackjack
    // else if player has blackjack -- win 3:2



    // simulated player
    // places bet based on betting strategy
    // then plays game based on play strategy (basic, cd exceptions, counting exceptions)
    // simulate outcome
    // repeat until player is broke or N hands have been played

    return 0;
}