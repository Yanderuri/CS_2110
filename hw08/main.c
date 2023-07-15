#include "main.h"

#include <stdio.h>
#include <stdlib.h>

enum gba_state
{
  START, // splash screen
  PLAY,  // play the game
  WIN,   // win screen
  LOSE,  // lose screen
};

// for intents and purposes, main() is simultaneously an init() function and a rendering function
int main(void)
{
  /* TODO: */
  // Manipulate REG_DISPCNT here to set Mode 3. //
  REG_DISPCNT = MODE3 | BG2_ENABLE;

  u32 currentButtons = BUTTONS;
  u32 previousButtons = BUTTONS;
  // Initialize the deck
  struct DECK *deck;
  if ((deck = malloc(sizeof(struct DECK))) == NULL)
  {
    return 1;
  }
  init_deck(deck);
  // Initialize the hand
  struct HAND *hand;
  if ((hand = malloc(sizeof(struct HAND))) == NULL)
  {
    return 1;
  }
  init_hand(hand);

  // Dealer hand
  struct HAND *dealer_hand;
  if ((dealer_hand = malloc(sizeof(struct HAND))) == NULL)
  {
    return 1;
  }
  init_hand(dealer_hand);
  // Shuffle the deck
  shuffle(deck);
  // Initialize the state
  enum gba_state state = START;
  // Draw the start screen
  draw_start_screen();
  // Initialize the score
  int score = 0;
  // Game loop
  while (1)
  {
    currentButtons = BUTTONS;
    // State transitions
    switch (state)
    {
    case START:
      if (KEY_JUST_PRESSED(BUTTON_START, currentButtons, previousButtons))
      {
        state = PLAY;
        init_play_screen(deck, hand, dealer_hand);
      }
      break;
    case PLAY:
      waitForVBlank();
      // Keep letting the players draw card, until they bust or fold
      if (KEY_JUST_PRESSED(BUTTON_A, currentButtons, previousButtons))
      {
        deal(deck, hand, 1);
        draw_player_hand(hand, count_score(hand));
        if (count_score(hand) > 21)
        {
          state = LOSE;
          delay(100);
          waitForVBlank();
          draw_lose_screen(score);
        }
      }
      // Engage the dealer in determing whether to draw or not
      if (KEY_JUST_PRESSED(BUTTON_B, currentButtons, previousButtons))
      {
        while (count_score(dealer_hand) < 17)
        {
          deal(deck, dealer_hand, 1);
          waitForVBlank();
          draw_dealer_hand(dealer_hand, count_score(dealer_hand), 0);
          delay(10);
        }
        draw_dealer_hand(dealer_hand, count_score(dealer_hand), 1);
        delay(100);
        if (count_score(dealer_hand) > 21)
        {
          state = WIN;
          score += 1;
          draw_win_screen(score);
        }
        else if (count_score(dealer_hand) > count_score(hand))
        {
          state = LOSE;
          waitForVBlank();
          draw_lose_screen(score);
        }
        else if (count_score(dealer_hand) < count_score(hand))
        {
          state = WIN;
          score += 1;
          draw_win_screen(score);
        }
        else
        {
          state = LOSE;
          waitForVBlank();
          draw_lose_screen(score);
        }
      }
      break;
    case WIN:
      // TODO: Create win_screen.h and win_screen.c
      if (KEY_JUST_PRESSED(BUTTON_START, currentButtons, previousButtons))
      {
        state = START;
        init_hand(hand);
        init_deck(deck);
        shuffle(deck);
        init_hand(dealer_hand);
        draw_start_screen();
      }
      break;
    case LOSE:
      if (KEY_JUST_PRESSED(BUTTON_START, currentButtons, previousButtons))
      {
        state = START;
        init_hand(hand);
        init_deck(deck);
        init_hand(dealer_hand);
        shuffle(deck);
        draw_start_screen();
      }
      break;
    }
    if (KEY_JUST_PRESSED(BUTTON_SELECT, currentButtons, previousButtons) && state != START)
    {
      score = 0;
      state = START;
      init_hand(hand);
      init_deck(deck);
      shuffle(deck);
      init_hand(dealer_hand);
      draw_start_screen();
    }
    previousButtons = currentButtons;
  }
  // Letting pointers go
  free(&deck);
  free(&hand);
  free(&dealer_hand);
  return 0;
}