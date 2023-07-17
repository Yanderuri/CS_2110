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

    waitForVBlank();
    waitForVBlank();

    int currentVBlank = vBlankCounter;

    while (vBlankCounter - currentVBlank < 960){
        waitForVBlank();
        draw_card_bounce(joker_white, HEIGHT - CARD_HEIGHT, 0, CARD_WIDTH, CARD_HEIGHT, 1);
        waitForVBlank();
        draw_card_bounce(joker_white, HEIGHT - CARD_HEIGHT, WIDTH - CARD_WIDTH, CARD_WIDTH, CARD_HEIGHT, -1);
    }
    free(score_string);
    return;
}
// Direction is either 1 or -1
void draw_card_bounce(const unsigned short *image, int row, int col, int width, int height, int direction){
    int i = 0;
    double sine_val = 0;
    if (direction == 1){
        i = 0;
        while (i <= WIDTH - CARD_WIDTH){
            sine_val = 20 * sine_taylor(i/10);
            drawImageDMA(row + (int) (sine_val), col + i, width, height, image);
            waitForVBlank();
            drawRectDMA(row + (int) (sine_val), col + i, width, height, BLACK);
            i++;
        }
        drawRectDMA(row, WIDTH - CARD_WIDTH, CARD_WIDTH, CARD_HEIGHT, BLACK);
    }
    else if (direction == -1){
        i = 0;
        while (i <= WIDTH - CARD_WIDTH){
            sine_val = 20 * sine_taylor(i/10);
            drawImageDMA(row + (int) (sine_val), col - i, width, height, image);
            waitForVBlank();
            drawRectDMA(row + (int) (sine_val), col - i, width, height, BLACK);
            i++;
        }
        drawRectDMA(row, 0, CARD_WIDTH, CARD_HEIGHT, BLACK);
    }
    return;
}