#include "cards.h"
#include <stdlib.h>

struct PLAY_CARD ace_clubs = {ace_clubs_white, CLUBS, ACE};
struct PLAY_CARD two_clubs = {two_clubs_white, CLUBS, TWO};
struct PLAY_CARD three_clubs = {three_clubs_white, CLUBS, THREE};
struct PLAY_CARD four_clubs = {four_clubs_white, CLUBS, FOUR};
struct PLAY_CARD five_clubs = {five_clubs_white, CLUBS, FIVE};
struct PLAY_CARD six_clubs = {six_clubs_white, CLUBS, SIX};
struct PLAY_CARD seven_clubs = {seven_clubs_white, CLUBS, SEVEN};
struct PLAY_CARD eight_clubs = {eight_clubs_white, CLUBS, EIGHT};
struct PLAY_CARD nine_clubs = {nine_clubs_white, CLUBS, NINE};
struct PLAY_CARD ten_clubs = {ten_clubs_white, CLUBS, TEN};
struct PLAY_CARD jack_clubs = {jack_clubs_white, CLUBS, JACK};
struct PLAY_CARD queen_clubs = {queen_clubs_white, CLUBS, QUEEN};
struct PLAY_CARD king_clubs = {king_clubs_white, CLUBS, KING};
struct PLAY_CARD ace_diamonds = {ace_diamonds_white, DIAMONDS, ACE};
struct PLAY_CARD two_diamonds = {two_diamonds_white, DIAMONDS, TWO};
struct PLAY_CARD three_diamonds = {three_diamonds_white, DIAMONDS, THREE};
struct PLAY_CARD four_diamonds = {four_diamonds_white, DIAMONDS, FOUR};
struct PLAY_CARD five_diamonds = {five_diamonds_white, DIAMONDS, FIVE};
struct PLAY_CARD six_diamonds = {six_diamonds_white, DIAMONDS, SIX};
struct PLAY_CARD seven_diamonds = {seven_diamonds_white, DIAMONDS, SEVEN};
struct PLAY_CARD eight_diamonds = {eight_diamonds_white, DIAMONDS, EIGHT};
struct PLAY_CARD nine_diamonds = {nine_diamonds_white, DIAMONDS, NINE};
struct PLAY_CARD ten_diamonds = {ten_diamonds_white, DIAMONDS, TEN};
struct PLAY_CARD jack_diamonds = {jack_diamonds_white, DIAMONDS, JACK};
struct PLAY_CARD queen_diamonds = {queen_diamonds_white, DIAMONDS, QUEEN};
struct PLAY_CARD king_diamonds = {king_diamonds_white, DIAMONDS, KING};
struct PLAY_CARD ace_hearts = {ace_hearts_white, HEARTS, ACE};
struct PLAY_CARD two_hearts = {two_hearts_white, HEARTS, TWO};
struct PLAY_CARD three_hearts = {three_hearts_white, HEARTS, THREE};
struct PLAY_CARD four_hearts = {four_hearts_white, HEARTS, FOUR};
struct PLAY_CARD five_hearts = {five_hearts_white, HEARTS, FIVE};
struct PLAY_CARD six_hearts = {six_hearts_white, HEARTS, SIX};
struct PLAY_CARD seven_hearts = {seven_hearts_white, HEARTS, SEVEN};
struct PLAY_CARD eight_hearts = {eight_hearts_white, HEARTS, EIGHT};
struct PLAY_CARD nine_hearts = {nine_hearts_white, HEARTS, NINE};
struct PLAY_CARD ten_hearts = {ten_hearts_white, HEARTS, TEN};
struct PLAY_CARD jack_hearts = {jack_hearts_white, HEARTS, JACK};
struct PLAY_CARD queen_hearts = {queen_hearts_white, HEARTS, QUEEN};
struct PLAY_CARD king_hearts = {king_hearts_white, HEARTS, KING};
struct PLAY_CARD ace_spades = {ace_spades_white, SPADES, ACE};
struct PLAY_CARD two_spades = {two_spades_white, SPADES, TWO};
struct PLAY_CARD three_spades = {three_spades_white, SPADES, THREE};
struct PLAY_CARD four_spades = {four_spades_white, SPADES, FOUR};
struct PLAY_CARD five_spades = {five_spades_white, SPADES, FIVE};
struct PLAY_CARD six_spades = {six_spades_white, SPADES, SIX};
struct PLAY_CARD seven_spades = {seven_spades_white, SPADES, SEVEN};
struct PLAY_CARD eight_spades = {eight_spades_white, SPADES, EIGHT};
struct PLAY_CARD nine_spades = {nine_spades_white, SPADES, NINE};
struct PLAY_CARD ten_spades = {ten_spades_white, SPADES, TEN};
struct PLAY_CARD jack_spades = {jack_spades_white, SPADES, JACK};
struct PLAY_CARD queen_spades = {queen_spades_white, SPADES, QUEEN};
struct PLAY_CARD king_spades = {king_spades_white, SPADES, KING};

void init_deck(struct DECK * deck){
    deck->size = 52;
    deck->remaining = 52;

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
void shuffle(struct DECK * deck){
    int i;
    struct PLAY_CARD *temp ;
    if ((temp = malloc(sizeof(struct PLAY_CARD)))  == NULL){
        return;
    }
    for (i = 0; i < deck->remaining; i++){
        int j = randint(0, 51);
        if (i != j){
            *temp = deck->cards[i];
            deck->cards[i] = deck->cards[j];
            deck->cards[j] = *temp;
        }
    }
    free(temp);
}
/* Deal num_cards from the deck to the hand.
    * If the hand is full or no cards left, return 1.
    * Otherwise, remove num_cards from the deck and add them to the hand.
    * Shift PLAY_CARD over when removing from the deck, keeping the array contiguous.
*/
int deal(struct DECK * deck, struct HAND * hand, int num_cards){
    if (hand->count == hand->max_size || deck->remaining <= num_cards){
        return 1;
    }
    int i;
    for (i = 0; i < num_cards; i++){
        hand->cards[hand->count] = deck->cards[deck->remaining - 1];
        hand->count++;
        deck->remaining--;
    }
    return 0;
}
// Hand-related functions
void init_hand(struct HAND * hand){
    hand->count = 0;
    hand->max_size = 5;
    for (int i = 0; i < hand->max_size; i++){
        hand->cards[i].image = NULL;
        hand->cards[i].suit = 0;
        hand->cards[i].value = 0;
    }
}
int count_score(struct HAND * hand){
    int score = 0;
    int aces = 0;
    int i = 0;
    for (i = 0; i < hand->count; i++){
        if (hand->cards[i].value == ACE){
            aces++;
        } else if (hand->cards[i].value >= JACK){
            score += 10;
        } else {
            score += hand->cards[i].value + 1;
        }
    }
    for (i = 0; i < aces; i++){
        if (score + 11 <= 21){
            score += 11;
        } else {
            score += 1;
        }
    }
    return score;
}
// Insertion sort the hand based on the card.value field
void sort_hand(struct HAND * hand){
    int i, j;
    struct PLAY_CARD* temp;
    if ((temp = malloc(sizeof(struct PLAY_CARD))) == NULL){
        return;
    }
    for (i = 1; i < hand->count; i++){
        *temp = hand->cards[i];
        j = i - 1;
        while (j >= 0 && hand->cards[j].value > temp->value){
            hand->cards[j + 1] = hand->cards[j];
            j--;
        }
        hand->cards[j + 1] = *temp;
    }
    free(temp);
}
void draw_hand(struct HAND * hand, int row, int col, int direction){
    int i;
    if (direction == 0){
        for (i = 0; i < hand->count; i++){
            waitForVBlank();
            drawImageDMA(row, col + i * (CARD_WIDTH/2) , CARD_WIDTH, CARD_HEIGHT, hand->cards[i].image);
        }
    }
    // tbh, unused direction.
    else if (direction == 1){
        for (i = hand->count - 1; i >= 0; i--){
            waitForVBlank();
            drawImageDMA(row, i * (CARD_WIDTH/2) + col, CARD_WIDTH, CARD_HEIGHT, hand->cards[i].image);
        }
    }
}