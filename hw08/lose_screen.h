#ifndef LOSE_SCREEN_H
#define LOSE_SCREEN_H

#include <stdlib.h>
#include <math.h>
#include "gba.h"
#include "cards.h"
#include "support.h"


void draw_lose_screen(int score);
void draw_card_bounce(const unsigned short *image, int row, int col, int width, int height, int direction);

#endif