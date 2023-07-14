#ifndef PLAY_SCREEN_H
#define PLAY_SCREEN_H

#include "cards.h"
#include "gba.h"
#include "support.h"
#include <stdlib.h>


#define SCORE_DRAW_HEIGHT (HEIGHT - CARD_HEIGHT/2 - 10)
#define PLAYER_HAND_ROW (HEIGHT - CARD_HEIGHT/2)
#define PLAYER_HAND_COL ((WIDTH * 3 / 4) - hand->count * (CARD_WIDTH/2))
#define DEALER_HAND_ROW (0 - CARD_HEIGHT/2)
#define DEALER_HAND_COL ((WIDTH * 3 / 4) - hand->count * (CARD_WIDTH/2))


void draw_play_screen(struct HAND * hand, int score);
void draw_dealer_hand(struct HAND * hand, int score);

#endif