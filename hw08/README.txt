I made a short tutorial on how to play blacjack, but this game is much simplified compared to the version in the casinos.
Shuffle a deck, and deal 2 cards face down to the player and 2 cards to the dealer.
The player can always see their hand, and they can see one face of the dealer's hand.

The goal is to reach a card value of 21 without going over.
The best hand possible is an Ace and one of the face cards.
Cards values: Numbers -> Numbers. Face cards are 10 points each. and Aces can be 1 or 11 (depends on which one is more advantageous to the player).
The player can hit until they fold, aka draw cards. If they bust (going over 21), they lose the game.
The dealer, according to the rules, must draw whenever their hand is less than 16 and stop when 17 or greater.
In the case the hand is equal, the house wins.

The game keeps track of how many times the player has won, displayed as the score in the win/lose screen.
Although the requirements specify that hitting backspace must reset the game state to the original state, due to the nature of randInt() built into gba.c, the starting hand will always be fixed. I guess, this follows a deterministic machine, the same input will always make the same output.

Anyways, have fun. This has been a good semester. 
-Vy.