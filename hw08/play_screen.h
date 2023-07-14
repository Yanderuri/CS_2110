#ifndef PLAY_SCREEN_H
#define PLAY_SCREEN_H

#include "cards.h"
#include "gba.h"
#include "support.h"
#include <stdlib.h>

void draw_play_screen(struct HAND * hand, int score);
void draw_dealer_hand(struct HAND * hand, int score);

#endif