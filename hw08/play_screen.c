#include "play_screen.h"

void draw_play_screen(struct HAND * hand, int score){
    waitForVBlank();
    draw_hand(hand, HEIGHT - CARD_HEIGHT/2, (WIDTH * 3 / 4) - hand->count * (CARD_WIDTH/2));
    char * score_string;
    if ((score_string = malloc(3)) == NULL){
        return;
    }
    itoa(score, score_string, 10);
    waitForVBlank();
    drawString(HEIGHT - CARD_HEIGHT/2 - 10, (WIDTH * 3 / 4) - hand->count * (CARD_WIDTH/2), score_string, WHITE);
    free(score_string);
    return;
}
