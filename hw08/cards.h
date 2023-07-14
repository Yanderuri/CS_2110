#ifndef CARDS_H
#define CARDS_H

#include "images/cards_c/cards_white.h"

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
    int size;
    int remaining;  
};
struct HAND{
    struct PLAY_CARD cards[5];
    int size;
};

void init_deck(struct DECK * deck);

// List of every possible card in the deck
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

#endif