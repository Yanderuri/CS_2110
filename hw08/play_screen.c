#include "play_screen.h"

void init_play_screen(struct DECK *deck, struct HAND *hand, struct HAND *dealer_hand)
{
    fillScreenDMA(DARK_GREEN);
    deal(deck, hand, 2);
    deal(deck, dealer_hand, 2);
    waitForVBlank();
    draw_dealer_hand(dealer_hand, count_score(dealer_hand), 0);
    draw_player_hand(hand, count_score(hand));
    return;
}
void draw_player_hand(struct HAND *hand, int score)
{
    waitForVBlank();
    draw_hand(hand, PLAYER_HAND_ROW, (WIDTH * 3 / 4) - hand->count * (CARD_WIDTH / 2), 0);
    char *score_string;
    if ((score_string = malloc(3)) == NULL)
    {
        return;
    }
    itoa(score, score_string, 10);
    // Undraw the previous score location
    waitForVBlank();
    // drawString(HEIGHT / 2 + 10, WIDTH * 3 / 4, score_string, WHITE);


    // Undraw the previous score location
    waitForVBlank();
    drawRectDMA(SCORE_DRAW_HEIGHT, (WIDTH * 3 / 4) - (hand->count - 1) * (CARD_WIDTH / 2), 20, 10, DARK_GREEN);
    waitForVBlank();
    drawString(SCORE_DRAW_HEIGHT, (WIDTH * 3 / 4) - hand->count * (CARD_WIDTH / 2), score_string, WHITE);

    drawCenteredString(HEIGHT / 2 - 10, WIDTH / 4, 50, 10, "A: Hit, B: Fold", WHITE);
    free(score_string);
    return;
}
// Maybe needs fixing
void draw_dealer_hand(struct HAND *hand, int score, int revealed)
{
    // if revealed == 0, then draw the first card then the rest face down
    if (revealed == 0)
    {
        waitForVBlank();
        for (int i = 0; i < hand->count; i++)
        {
            if (i == 0)
            {
                // drawImageDMA(DEALER_HAND_ROW, DEALER_HAND_COL + (hand->count - 1 - i) * (CARD_WIDTH / 2), CARD_WIDTH, CARD_HEIGHT, hand->cards[i].image);
                drawImageDMA(DEALER_HAND_ROW, DEALER_HAND_COL, CARD_WIDTH, CARD_HEIGHT, hand->cards[i].image);

            }
            else
            {
                drawImageDMA(DEALER_HAND_ROW, DEALER_HAND_COL, CARD_WIDTH, CARD_HEIGHT, back_red_basic_white);
            }
        }
    }
    // if revealed == 1, then draw the whole hand
    if (revealed == 1)
    {
        waitForVBlank();
        for (int i = 0; i < hand->count; i++)
        {
            drawImageDMA(DEALER_HAND_ROW, DEALER_HAND_COL, CARD_WIDTH, CARD_HEIGHT, hand->cards[i].image);
        }
        // Draw score
        char *score_string;
        if ((score_string = malloc(3)) == NULL)
        {
            return;
        }
        itoa(score, score_string, 10);
        drawString(CARD_HEIGHT / 2, WIDTH * 3 / 4 + CARD_WIDTH / 2, score_string, WHITE);
        free(score_string);
        return;
    }
}