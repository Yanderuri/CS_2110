#include "play_screen.h"

void draw_play_screen(struct HAND * hand, int score){
    waitForVBlank();
    draw_hand(hand, HEIGHT - CARD_HEIGHT/2, (WIDTH * 3 / 4) - hand->count * (CARD_WIDTH/2), 0);
    char * score_string;
    if ((score_string = malloc(3)) == NULL){
        return;
    }
    itoa(score, score_string, 10);
    waitForVBlank();
    drawString(HEIGHT - CARD_HEIGHT/2 - 10, (WIDTH * 3 / 4) - hand->count * (CARD_WIDTH/2), score_string, WHITE);
    if (score == 0){
        drawCenteredString(CARD_HEIGHT/2 + CARD_HEIGHT/4, WIDTH/4, 60, 30, "A: Hit, B: Fold", WHITE);
    }
    free(score_string);
    return;
}
void draw_dealer_hand(struct HAND * hand, int score){
    waitForVBlank();
    draw_hand(hand, 0 - CARD_HEIGHT/2, (WIDTH * 3 / 4) - hand->count * (CARD_WIDTH/2), 1);
    char * score_string;
    if ((score_string = malloc(3)) == NULL){
        return;
    }
    itoa(score, score_string, 10);
    waitForVBlank();
    drawString(0 - 10, (WIDTH * 3 / 4) - hand->count * (CARD_WIDTH/2), score_string, WHITE);
    free(score_string);
    return;
}