#ifndef PLAY_SCREEN_H
#define PLAY_SCREEN_H

#include "cards.h"
#include "gba.h"
#include "support.h"
#include <stdlib.h>



void init_play_screen(struct DECK * deck, struct HAND * hand, struct HAND * dealer_hand);
void draw_player_hand(struct HAND * hand, int score);
void draw_dealer_hand(struct HAND * hand, int score, int revealed);

#endif