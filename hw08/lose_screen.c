#include "lose_screen.h"

void draw_lose_screen(int score){
    waitForVBlank();
    fillScreenDMA(BLACK);
    drawString(10, 10, "You Lose!", RED);
    drawString(30, 10, "Press Start to Play Again", RED);

    char *score_string;
    if ((score_string = malloc(11 * sizeof(char))) == NULL) {
        return;
    }
    score_string_maker(score_string, score);

    drawString(50, 10, score_string, YELLOW);
    // waitForVBlank();
    // drawImageDMA(HEIGHT / 2 + CARD_HEIGHT / 2, WIDTH / 2 - 0, CARD_WIDTH, CARD_HEIGHT, joker_white);
    // drawImageDMA(HEIGHT / 2 + CARD_HEIGHT / 2, WIDTH / 2 - CARD_WIDTH / 2, CARD_WIDTH, CARD_HEIGHT, ace_clubs_white);
    free(score_string);
    return;
}
