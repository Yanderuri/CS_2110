#ifndef CARDS_H
#define CARDS_H

#include "images/cards_c/cards_white.h"
#include "gba.h"

#define CARD_HEIGHT 84
#define CARD_WIDTH 60

enum cards_values {
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
    KING = 12
};
enum cards_suits {
    CLUBS = 0,
    DIAMONDS = 1,
    HEARTS = 2,
    SPADES = 3
};
struct PLAY_CARD{
    const unsigned short* image; // pointer to the image of the card
    int suit; // 0 = clubs, 1 = diamonds, 2 = hearts, 3 = spades
    int value; // 0 = ace, 1 = 2, 2 = 3, ... 9 = 10, 10 = jack, 11 = queen, 12 = king
};
struct DECK{
    struct PLAY_CARD cards[52];
    int max_size;
    int remaining;
};
struct HAND{
    struct PLAY_CARD cards[5];
    int max_size;
    int count;
};

// Deck-related functions
void init_deck(struct DECK * deck);
void shuffle(struct DECK * deck);
int deal(struct DECK * deck, struct HAND * hand, int num_cards);

// Hand-related functions
void init_hand(struct HAND * hand);
int count_score(struct HAND * hand);
void sort_hand(struct HAND * hand);
void draw_hand(struct HAND * hand, int row, int col);
#endif