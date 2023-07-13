#include "main.h"

#include <stdio.h>
#include <stdlib.h>


enum gba_state {
  START,
  PLAY,
  WIN,
  LOSE,
};

enum cards_state{
  card_1 = 0,
  card_2 = 1,
  card_3 = 2,
  card_4 = 3
};

// for intents and purposes, main() is simultaneously an init() function and a rendering function
int main(void) {
  /* TODO: */
  // Manipulate REG_DISPCNT here to set Mode 3. //
  REG_DISPCNT = MODE3 | BG2_ENABLE;
  // Save current and previous state of button input.
  u32 previousButtons = BUTTONS;
  u32 currentButtons = BUTTONS;
  struct DECK deck;
  init_deck(&deck);
  // Load initial application state
  // enum gba_state state = START;
  enum cards_state state = card_1;
  struct PLAY_CARD current_card = deck.cards[randint(0,52)];
  char * score_string = calloc(5, sizeof(char));
  int score = 0;
  score += current_card.value + 1;
  int add_score = 0;
  
  waitForVBlank();
  fillScreenDMA(BLACK);
  while (1) {
    currentButtons = BUTTONS; // Load the current state of the buttons
    itoa(score, score_string, 10);
    drawCenteredString(120, WIDTH/2, 10, 10, score_string, WHITE);
    switch(state){
      case card_1:
        waitForVBlank();
        drawImageDMA(0,0, CARD_WIDTH, CARD_HEIGHT, current_card.image);
        if (KEY_DOWN(BUTTON_RIGHT, currentButtons)){
          current_card = deck.cards[randint(0,52)];
          add_score = 1;
          state = card_2;
        }
        break;
      case card_2:
        waitForVBlank();
        drawImageDMA(0,30, CARD_WIDTH, CARD_HEIGHT, current_card.image);
        if (KEY_DOWN(BUTTON_RIGHT, currentButtons)){
          current_card = deck.cards[randint(0,52)];
          add_score = 1;
          state = card_3;
        }
        break;
      case card_3:
        waitForVBlank();
        drawImageDMA(0,60, CARD_WIDTH, CARD_HEIGHT, current_card.image);
        if (KEY_DOWN(BUTTON_RIGHT, currentButtons)){
          current_card = deck.cards[randint(0,52)];
          add_score = 1;
          state = card_4;
        }
        break;
      case card_4:
        waitForVBlank();
        drawImageDMA(0,90, CARD_WIDTH, CARD_HEIGHT, current_card.image);
        delay(50);
        if (KEY_DOWN(BUTTON_RIGHT, currentButtons)){
          current_card = deck.cards[randint(0,52)];
          add_score = 1;
          state = card_1;
          waitForVBlank();
          fillScreenDMA(BLACK);
        }
        break;
    }
    UNUSED(previousButtons);
    // score += current_card.value + 1; // because the values are 0-12, but we want 1-13
    if (add_score){
      score += current_card.value + 1;
      add_score = 0;
    }
    delay(25);
    waitForVBlank();
    drawRectDMA(120, WIDTH/2, 30, 10, BLACK);
    previousButtons = currentButtons; // Store the current state of the buttons
  }
  free(score_string);
  return 0;
}
// Add all of the cards to the deck
