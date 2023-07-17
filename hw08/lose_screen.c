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
    
    draw_card_bounce(joker_white, PLAYER_HAND_ROW, 0, CARD_WIDTH, CARD_HEIGHT, 0);
    draw_card_bounce(ace_clubs_white, PLAYER_HAND_ROW, 240 - CARD_WIDTH, CARD_WIDTH, CARD_HEIGHT, 1);
    free(score_string);
    return;
}
// Draw an card bouncing back and forth on the lower half of the screen
void draw_card_bounce(const unsigned short *image, int row, int col, int width, int height, int direction){
    for(int i = 0; i < 240; i++){
        waitForVBlank();
        if(direction == 0){
            drawImageDMA(row, col + i, width, height, image);
        } else {
            drawImageDMA(row, col - i, width, height, image);
        }
        waitForVBlank();
        if(direction == 0){
            undrawImageDMA(row, col - i, width, height, BLACK);
        } else {
            undrawImageDMA(row, col + i, width, height, BLACK);
        }
    }
}