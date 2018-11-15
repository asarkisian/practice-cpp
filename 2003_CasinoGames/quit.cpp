#include "game.h"

void CGame::quit()
{
    isComputerWin = false;
    isHumanWin = false;
    isHumanStay = false;
    isHumanHit = false;
    isComputerStay = false;
    isComputerHit = false;
    isDraw = false;
    isFirstDeal = false;
    isPlayAgain = false;
    isQuit = true;
}
