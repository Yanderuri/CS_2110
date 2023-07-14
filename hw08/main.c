#include "main.h"

#include <stdio.h>
#include <stdlib.h>


enum gba_state {
  START, // splash screen
  PLAY, // play the game
  WIN, // win screen
  LOSE, // lose screen
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

  u32 currentButtons = BUTTONS;
  UNUSED(currentButtons);
  u32 previousButtons = BUTTONS;
  UNUSED(previousButtons);


  // Initialize the deck
  struct DECK *deck;
  if ((deck = malloc(sizeof(struct DECK))) == NULL) {
    return 1;
  }
  init_deck(deck);
  // Initialize the hand
  struct HAND *hand;
  if ((hand = malloc(sizeof(struct HAND))) == NULL) {
    return 1;
  }
  init_hand(hand);

// Dealer hand
  struct HAND *dealer_hand;
  if ((dealer_hand = malloc(sizeof(struct HAND))) == NULL) {
    return 1;
  }
  init_hand(dealer_hand);
  // Shuffle the deck
  shuffle(deck);
  // Initialize the state
  enum gba_state state = START;
  UNUSED(hand);

  score = 0;

  draw_start_screen();
  // Game loop
  while(1) {
    currentButtons = BUTTONS;
    // State transitions
    switch(state) {
      case START:
        if (KEY_JUST_PRESSED(BUTTON_A, currentButtons, previousButtons)) {
          state = PLAY;
          fillScreenDMA(DARK_GREEN);
          waitForVBlank();
          draw_play_screen(hand, count_score(hand));
        }
        break;
      case PLAY:
        waitForVBlank();
        // Keep letting the players draw card, until they bust or fold
        if (KEY_JUST_PRESSED(BUTTON_A, currentButtons, previousButtons)) {
        }
        // Engage the dealer algorithm in determing whether to draw or not
        if (KEY_JUST_PRESSED(BUTTON_B, currentButtons, previousButtons)) {
        }
        break;
      case WIN:
        score += 1;
        if (KEY_JUST_PRESSED(BUTTON_A, currentButtons, previousButtons)) {
          state = START;
          init_hand(hand);
          init_deck(deck);
          shuffle(deck);
          init_hand(dealer_hand);
          draw_start_screen();
        }
        break;
      case LOSE:
        if (KEY_JUST_PRESSED(BUTTON_A, currentButtons, previousButtons)) {
          state = START;
          init_hand(hand);
          init_deck(deck);
          shuffle(deck);
          init_hand(dealer_hand);
          draw_start_screen();
        }
        break;
    }
    previousButtons = currentButtons;
  }
  // Letting pointers go
  free(&deck);
  free(&hand);
  free(&dealer_hand);
  return 0;
}
void waitForInput(u32 currentButtons, u32 previousButtons, u16 button){
  while (KEY_JUST_PRESSED(button, currentButtons, previousButtons) == 0){
    currentButtons = BUTTONS;
  }
  return;
}
int state_decider(int state, struct DECK * deck, struct HAND * hand){
  UNUSED(state);
  UNUSED(deck);
  UNUSED(hand);
  return 0;
}