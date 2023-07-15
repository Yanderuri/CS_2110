#include "start_screen.h"
#include "gba.h"
#include "cards.h"

char *author = "Vy Mai";

void draw_start_screen(void)
{
    waitForVBlank();
    fillScreenDMA(BLACK);
    waitForVBlank();
    drawString(10, 10, "Welcome to Blackjack!", WHITE);
    waitForVBlank();
    drawString(30, 10, "Press Start to Play", WHITE);
    waitForVBlank();
    drawString(50, 10, author, YELLOW);
    waitForVBlank();
    drawImageDMA(HEIGHT / 2 + CARD_HEIGHT / 2, WIDTH / 2 - 0, CARD_WIDTH, CARD_HEIGHT, joker_white);
    waitForVBlank();
    drawImageDMA(HEIGHT / 2 + CARD_HEIGHT / 2, WIDTH / 2 - CARD_WIDTH / 2, CARD_WIDTH, CARD_HEIGHT, ace_clubs_white);
}