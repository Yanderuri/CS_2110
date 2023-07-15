#include "win_screen.h"

// TODO: Implement draw_win_screen()
void draw_win_screen(int score)
{
	waitForVBlank();
	fillScreenDMA(DARK_GREEN);
	waitForVBlank();
	drawString(10, 10, "You Win!", WHITE);
	waitForVBlank();
	drawString(30, 10, "Press Start to Play Again", WHITE);
	waitForVBlank();
	char * score_string;
	if ((score_string = malloc(11 * sizeof(char))) == NULL) {
		return;
	}
	score_string_maker(score_string, score);

	free(score_string);
	return;
}