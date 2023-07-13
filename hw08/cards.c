#include "cards.h"

void init_deck(struct DECK * deck){
    deck->cards[0] = ace_clubs;
    deck->cards[1] = two_clubs;
    deck->cards[2] = three_clubs;
    deck->cards[3] = four_clubs;
    deck->cards[4] = five_clubs;
    deck->cards[5] = six_clubs;
    deck->cards[6] = seven_clubs;
    deck->cards[7] = eight_clubs;
    deck->cards[8] = nine_clubs;
    deck->cards[9] = ten_clubs;
    deck->cards[10] = jack_clubs;
    deck->cards[11] = queen_clubs;
    deck->cards[12] = king_clubs;

    deck->cards[13] = ace_diamonds;
    deck->cards[14] = two_diamonds;
    deck->cards[15] = three_diamonds;
    deck->cards[16] = four_diamonds;
    deck->cards[17] = five_diamonds;
    deck->cards[18] = six_diamonds;
    deck->cards[19] = seven_diamonds;
    deck->cards[20] = eight_diamonds;
    deck->cards[21] = nine_diamonds;
    deck->cards[22] = ten_diamonds;
    deck->cards[23] = jack_diamonds;
    deck->cards[24] = queen_diamonds;
    deck->cards[25] = king_diamonds;

    deck->cards[26] = ace_hearts;
    deck->cards[27] = two_hearts;
    deck->cards[28] = three_hearts;
    deck->cards[29] = four_hearts;
    deck->cards[30] = five_hearts;
    deck->cards[31] = six_hearts;
    deck->cards[32] = seven_hearts;
    deck->cards[33] = eight_hearts;
    deck->cards[34] = nine_hearts;
    deck->cards[35] = ten_hearts;
    deck->cards[36] = jack_hearts;
    deck->cards[37] = queen_hearts;
    deck->cards[38] = king_hearts;

    deck->cards[39] = ace_spades;
    deck->cards[40] = two_spades;
    deck->cards[41] = three_spades;
    deck->cards[42] = four_spades;
    deck->cards[43] = five_spades;
    deck->cards[44] = six_spades;
    deck->cards[45] = seven_spades;
    deck->cards[46] = eight_spades;
    deck->cards[47] = nine_spades;
    deck->cards[48] = ten_spades;
    deck->cards[49] = jack_spades;
    deck->cards[50] = queen_spades;
    deck->cards[51] = king_spades;
}