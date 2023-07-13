#ifndef MAIN_H
#define MAIN_H

#include "gba.h"
#include "images/garbage.h"
#include "images/cards_c/cards_white.h"

// TODO: Create any necessary structs
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

/*
* For example, for a Snake game, one could be:
*
* struct snake {
*   int heading;
*   int length;
*   int row;
*   int col;
* };
*
* Example of a struct to hold state machine data:
*
* struct state {
*   int currentState;
*   int nextState;
* };
*
*/
struct PLAY_CARD{
    const unsigned short* image; // pointer to the image of the card
    int suit; // 0 = clubs, 1 = diamonds, 2 = hearts, 3 = spades
    int value; // 0 = ace, 1 = 2, 2 = 3, ... 9 = 10, 10 = jack, 11 = queen, 12 = king
};
struct DECK{
    struct PLAY_CARD cards[52];
    int size;
};
struct HAND{
    struct PLAY_CARD cards[5];
    int size;
};
struct DECK deck;
struct HAND hand;
struct PLAY_CARD card;

#endif
