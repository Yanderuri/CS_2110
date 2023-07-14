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
    drawRectDMA(SCORE_DRAW_HEIGHT, (WIDTH * 3 / 4) - (hand->count - 1) * (CARD_WIDTH/2), 15, 10, DARK_GREEN);
    waitForVBlank();
    drawString(SCORE_DRAW_HEIGHT, (WIDTH * 3 / 4) - hand->count * (CARD_WIDTH/2), score_string, WHITE);
    if (score == 0){
        drawCenteredString(CARD_HEIGHT/2 + CARD_HEIGHT/4, WIDTH/4, 60, 30, "A: Hit, B: Fold", WHITE);
    }
    free(score_string);
    return;
}
void draw_dealer_hand(struct HAND * hand, int score){
    waitForVBlank();
    // Draw the first card then draw the back of the cards for the rest.
    int row = 0 - CARD_HEIGHT/2;
    int col = (WIDTH * 3 / 4) - hand->count * (CARD_WIDTH/2);
    
    for (int i = hand->count - 1; i >= 0; i--){
        waitForVBlank();
        if (i == hand->count - 1){
            drawImageDMA(row, col + i * (CARD_WIDTH/2) , CARD_WIDTH, CARD_HEIGHT, hand->cards[0].image);
        }
        else{
            drawImageDMA(row, col + i * (CARD_WIDTH/2) , CARD_WIDTH, CARD_HEIGHT, back_red_basic_white);
        }
    }
    char * score_string;
    if ((score_string = malloc(3)) == NULL){
        return;
    }
    itoa(score, score_string, 10);
    waitForVBlank();
    free(score_string);
    return;
}