#include "poker.h"

void CPoker::quit()
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
