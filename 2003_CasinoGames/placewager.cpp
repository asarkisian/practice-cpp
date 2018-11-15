#include "game.h"
using std::cout;
using std::endl;
using std::cin;

void CGame::placeWager()
{
    do
    {
	cout << "MAX BET = $500.00" << endl;
        cout << "MIN BET = $5.00" << endl;
	if(wagerAmount > playerMoney)
        {
            cout << "INSUFFICIENT FUNDS!" << endl;
        }
        cout << "Enter wager amount (Increments of five only!): ___\b\b\b";
	cin >> wagerAmount;

    }while(wagerAmount == 0 || wagerAmount > playerMoney);

	while(!(wagerAmount == 5 || wagerAmount == 10 || wagerAmount == 15
	|| wagerAmount == 20 || wagerAmount == 25 || wagerAmount == 30
	|| wagerAmount == 35 || wagerAmount == 40 || wagerAmount == 45
	|| wagerAmount == 50 || wagerAmount == 55 || wagerAmount == 60
	|| wagerAmount == 65 || wagerAmount == 70 || wagerAmount == 75
	|| wagerAmount == 80 || wagerAmount == 85 || wagerAmount == 90
	|| wagerAmount == 95 || wagerAmount == 100 || wagerAmount == 105
	|| wagerAmount == 110 || wagerAmount == 115 || wagerAmount == 120
	|| wagerAmount == 125 || wagerAmount == 130 || wagerAmount == 135
	|| wagerAmount == 140 || wagerAmount == 145 || wagerAmount == 150
	|| wagerAmount == 155 || wagerAmount == 160 || wagerAmount == 165
	|| wagerAmount == 170 || wagerAmount == 175 || wagerAmount == 180
	|| wagerAmount == 185 || wagerAmount == 190 || wagerAmount == 195
	|| wagerAmount == 200 || wagerAmount == 205 || wagerAmount == 210
	|| wagerAmount == 215 || wagerAmount == 220 || wagerAmount == 225
	|| wagerAmount == 230 || wagerAmount == 235 || wagerAmount == 240
	|| wagerAmount == 245 || wagerAmount == 250 || wagerAmount == 255
	|| wagerAmount == 260 || wagerAmount == 265 || wagerAmount == 270
	|| wagerAmount == 275 || wagerAmount == 280 || wagerAmount == 285
	|| wagerAmount == 290 || wagerAmount == 295 || wagerAmount == 300
	|| wagerAmount == 305 || wagerAmount == 310 || wagerAmount == 315
	|| wagerAmount == 320 || wagerAmount == 325 || wagerAmount == 330
	|| wagerAmount == 335 || wagerAmount == 340 || wagerAmount == 345
	|| wagerAmount == 350 || wagerAmount == 355 || wagerAmount == 360
	|| wagerAmount == 365 || wagerAmount == 370 || wagerAmount == 375
	|| wagerAmount == 380 || wagerAmount == 385 || wagerAmount == 390
	|| wagerAmount == 395 || wagerAmount == 400 || wagerAmount == 405
	|| wagerAmount == 410 || wagerAmount == 415 || wagerAmount == 420
	|| wagerAmount == 425 || wagerAmount == 430 || wagerAmount == 435
	|| wagerAmount == 440 || wagerAmount == 445 || wagerAmount == 450
	|| wagerAmount == 455 || wagerAmount == 460 || wagerAmount == 465
	|| wagerAmount == 470 || wagerAmount == 475 || wagerAmount == 480
	|| wagerAmount == 485 || wagerAmount == 490 || wagerAmount == 495
	|| wagerAmount == 500))
	{
		do
		{
                    cout << "\nMAX BET = $500.00" << endl;
		    cout << "MIN BET = $5.00" << endl;
		    if(wagerAmount > playerMoney)
                    {
                        cout << "INSUFFICIENT FUNDS!" << endl;
                    }
                    cout << "Enter wager amount (Increments of five only!): ___\b\b\b";
		    cin >> wagerAmount;

		}while(wagerAmount == 0 || wagerAmount > playerMoney);
	}
}
