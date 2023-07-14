#ifndef MAIN_H
#define MAIN_H

#include "gba.h"
#include "cards.h"
#include "support.h"
#include "start_screen.h"
#include "play_screen.h"

void waitForInput(u32 currentButtons, u32 previousButtons, u16 button);

int state_decider(int state, struct DECK * deck, struct HAND * hand);
#endif
