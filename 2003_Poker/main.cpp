//--------------------------------------------------
//main.cpp

#include "poker.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
    CPoker pk;
    pk.getPlayersName();

    while(pk.isPlayAgain == true)
    {
        pk.doMain();
    }

    return 0;
}

//--------------------------------------------------
