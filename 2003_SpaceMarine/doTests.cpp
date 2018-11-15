//-------------------------------------------------
// doTests.cpp

#pragma warning(disable : 4800)

#include "ArmorBonus.h"
#include "BlueArmor.h"
#include "GreenArmor.h"
#include "HealthBonus.h"
#include "Monster.h"
#include "myAssert.h"
#include "PinkDemon.h"
#include "Screen.h"
#include "ShotgunGuy.h"
#include "SpaceMarine.h"
#include "Zombie.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::ofstream;
using std::string;
using std::vector;

void doTests()
{
	// MiniDoom Tests

	// Section 3.5
	cerr << "Begin unit tests:\n\n";
	cerr << "SpaceMarine 3.5 tests: ";
	{
		Screen theScreen(cout);
		const SpaceMarine csm(cin, 20, 10, "North", 100, 0);
		theScreen.setStatusBar(csm.createStatusBar());
		theScreen.display();
		csm.xPosition(); csm.yPosition(); csm.directionFacing();
		csm.health(); csm.armor(); csm.quitGame(); csm.isAlive();

		SpaceMarine sm(cin, 20, 10, "North", 100, 10);
		sm.adjustArmor(50);		debugAssert(sm.armor() == 60);
		sm.setArmor(70);		debugAssert(sm.armor() == 70);

		sm.adjustHealth(-20);	debugAssert(sm.health() == 80);
		sm.setHealth(170);		debugAssert(sm.health() == 170);

		sm.stepForward();		debugAssert(sm.yPosition() == 11);
		sm.stepBackward();		debugAssert(sm.yPosition() == 10);
		sm.stepLeft();			debugAssert(sm.xPosition() == 19);
		sm.stepRight();			debugAssert(sm.xPosition() == 20);
		sm.turnLeft();			debugAssert(sm.directionFacing() == "West");
		sm.turnRight();			debugAssert(sm.directionFacing() == "North");
		
		sm.turnLeft();			debugAssert(sm.directionFacing() == "West");
		sm.stepForward();		debugAssert(sm.xPosition() == 19);
		sm.stepBackward();		debugAssert(sm.xPosition() == 20);
		sm.stepLeft();			debugAssert(sm.yPosition() == 9);
		sm.stepRight();			debugAssert(sm.yPosition() == 10);
		sm.turnLeft();			debugAssert(sm.directionFacing() == "South");
		sm.turnRight();			debugAssert(sm.directionFacing() == "West");

		sm.turnLeft();			debugAssert(sm.directionFacing() == "South");
		sm.stepForward();		debugAssert(sm.yPosition() == 9);
		sm.stepBackward();		debugAssert(sm.yPosition() == 10);
		sm.stepLeft();			debugAssert(sm.xPosition() == 21);
		sm.stepRight();			debugAssert(sm.xPosition() == 20);
		sm.turnLeft();			debugAssert(sm.directionFacing() == "East");
		sm.turnRight();			debugAssert(sm.directionFacing() == "South");

		sm.turnLeft();			debugAssert(sm.directionFacing() == "East");
		sm.stepForward();		debugAssert(sm.xPosition() == 21);
		sm.stepBackward();		debugAssert(sm.xPosition() == 20);
		sm.stepLeft();			debugAssert(sm.yPosition() == 11);
		sm.stepRight();			debugAssert(sm.yPosition() == 10);
		sm.turnLeft();			debugAssert(sm.directionFacing() == "North");
		sm.turnRight();			debugAssert(sm.directionFacing() == "East");
	}
	cerr << "--OK\n";

	// Section 4.1
	cerr << "SpaceMarine 4.1 tests: ";
	{
		const SpaceMarine csm(cin, 20, 10, "North", 100, 0);
		csm.image();
	}
	cerr << "--OK\n";

	// Section 4.2
	cerr << "SpaceMarine 4.2 tests: ";
	{
		Screen theScreen(cout);
		const SpaceMarine csm(cin, 20, 10, "North", 100, 0);
		theScreen.setStatusBar(csm.createStatusBar());
		theScreen.display();
	}
	cerr << "--OK\n";
	cerr << "Screen 4.2 tests ";
	{
		const Screen cs(cout);
		cs.display();
	}
	cerr << "--OK\n";

	//Section 4.3
	cerr << "Zombie 4.3 tests: ";
	{
		const Zombie cz(20, 10, "North", 30);
		cz.xPosition(); cz.yPosition(); cz.directionFacing();
		cz.health(); cz.isAlive(); cz.image();

		Zombie zo(20, 10, "North", 30);

		zo.adjustHealth(-20);	debugAssert(zo.health() == 10);
		zo.setHealth(170);		debugAssert(zo.health() == 30);

		zo.stepForward();		debugAssert(zo.yPosition() == 11);
		zo.stepBackward();		debugAssert(zo.yPosition() == 10);
		zo.stepLeft();			debugAssert(zo.xPosition() == 19);
		zo.stepRight();			debugAssert(zo.xPosition() == 20);
		zo.turnLeft();			debugAssert(zo.directionFacing() == "West");
		zo.turnRight();			debugAssert(zo.directionFacing() == "North");
		
		zo.turnLeft();			debugAssert(zo.directionFacing() == "West");
		zo.stepForward();		debugAssert(zo.xPosition() == 19);
		zo.stepBackward();		debugAssert(zo.xPosition() == 20);
		zo.stepLeft();			debugAssert(zo.yPosition() == 9);
		zo.stepRight();			debugAssert(zo.yPosition() == 10);
		zo.turnLeft();			debugAssert(zo.directionFacing() == "South");
		zo.turnRight();			debugAssert(zo.directionFacing() == "West");

		zo.turnLeft();			debugAssert(zo.directionFacing() == "South");
		zo.stepForward();		debugAssert(zo.yPosition() == 9);
		zo.stepBackward();		debugAssert(zo.yPosition() == 10);
		zo.stepLeft();			debugAssert(zo.xPosition() == 21);
		zo.stepRight();			debugAssert(zo.xPosition() == 20);
		zo.turnLeft();			debugAssert(zo.directionFacing() == "East");
		zo.turnRight();			debugAssert(zo.directionFacing() == "South");

		zo.turnLeft();			debugAssert(zo.directionFacing() == "East");
		zo.stepForward();		debugAssert(zo.xPosition() == 21);
		zo.stepBackward();		debugAssert(zo.xPosition() == 20);		zo.stepLeft();			debugAssert(zo.yPosition() == 11);
		zo.stepRight();			debugAssert(zo.yPosition() == 10);
		zo.turnLeft();			debugAssert(zo.directionFacing() == "North");
		zo.turnRight();			debugAssert(zo.directionFacing() == "East");
	}
	cerr << "--OK\n";

	cerr << "SpaceMarine 4.3 tests: ";
	{
		const SpaceMarine csm(cin, 20, 10, "North", 100, 0);
		const Zombie cz(20, 10, "North", 30);
		Zombie z(20, 10, "North", 30);
		csm.isReadyToAttack(cz); csm.attack(z);

		SpaceMarine sm(cin, 20, 10, "North", 100, 0);

		Zombie zoN(20, 15, "North", 30);		debugAssert(sm.isReadyToAttack(zoN));
		sm.turnRight();							debugAssert(sm.directionFacing() == "East");
		Zombie zoE(25, 10, "North", 30);		debugAssert(sm.isReadyToAttack(zoE));
		sm.turnRight();							debugAssert(sm.directionFacing() == "South");
		Zombie zoS(20,  5, "North", 30);		debugAssert(sm.isReadyToAttack(zoS));
		sm.turnRight();							debugAssert(sm.directionFacing() == "West");
		Zombie zoW(15, 10, "North", 30);		debugAssert(sm.isReadyToAttack(zoW));

		sm.attack(zoW);							debugAssert(zoW.health() == 20);
		sm.attack(zoW);							debugAssert(zoW.health() == 10);
		sm.attack(zoW);							debugAssert(!zoW.isAlive() && !sm.isReadyToAttack(zoW));
	}
	cerr << "--OK\n";

	cerr << "Zombie 4.3 tests: ";
	{
		const Zombie cz(20, 10, "North", 30);
		const SpaceMarine csm(cin, 20, 10, "North", 30, 0);
		SpaceMarine sm(cin, 20, 10, "North", 30, 0);
		cz.isReadyToAttack(csm); cz.isReadyToAttack(csm);
		cz.turnMove(csm); cz.stepMove(csm);
		cz.attack(sm);

		Zombie zo(20, 10, "North", 30);

		SpaceMarine smN(cin, 20, 15, "North", 10, 10);
		SpaceMarine smE(cin, 25, 10, "North", 10, 10);
		SpaceMarine smS(cin, 20,  5, "North", 10, 10);
		SpaceMarine smW(cin, 15, 10, "North", 10, 10);

		debugAssert(zo.isReadyToAttack(smN));
		debugAssert(zo.isReadyToTurn(smE) && zo.turnMove(smE) == 'd');
		debugAssert(zo.isReadyToTurn(smS));
		debugAssert(zo.isReadyToTurn(smW) && zo.turnMove(smW) == 'a');

		zo.turnRight();							debugAssert(zo.directionFacing() == "East");
		debugAssert(zo.isReadyToTurn(smN) && zo.turnMove(smN) == 'a');
		debugAssert(zo.isReadyToAttack(smE));
		debugAssert(zo.isReadyToTurn(smS) && zo.turnMove(smS) == 'd');
		debugAssert(zo.isReadyToTurn(smW));

		zo.turnRight();							debugAssert(zo.directionFacing() == "South");
		debugAssert(zo.isReadyToTurn(smN));
		debugAssert(zo.isReadyToTurn(smE) && zo.turnMove(smE) == 'a');
		debugAssert(zo.isReadyToAttack(smS));
		debugAssert(zo.isReadyToTurn(smW) && zo.turnMove(smW) == 'd');

		zo.turnRight();							debugAssert(zo.directionFacing() == "West");
		debugAssert(zo.isReadyToTurn(smN) && zo.turnMove(smN) == 'd');
		debugAssert(zo.isReadyToTurn(smE));
		debugAssert(zo.isReadyToTurn(smS) && zo.turnMove(smS) == 'a');
		debugAssert(zo.isReadyToAttack(smW));

		zo.attack(smW);							debugAssert(smW.health() == 7 && smW.armor() == 4);
		zo.attack(smW);							debugAssert(smW.health() == 4 && smW.armor() == 0);
		zo.attack(smW);							debugAssert(!smW.isAlive() && !zo.isReadyToAttack(smW) &&
														    !zo.isReadyToAttack(smW));

		SpaceMarine sm0(cin, 20, 10, "North", 100, 0);
		debugAssert(!zo.isReadyToAttack(sm0) && !zo.isReadyToAttack(sm0));
		debugAssert(zo.stepMove(sm0) == 's');

		SpaceMarine sm1(cin, 21, 15, "North", 100, 0);
		SpaceMarine sm2(cin, 19, 15, "North", 100, 0);
		SpaceMarine sm3(cin, 15, 11, "North", 100, 0);
		SpaceMarine sm4(cin, 15,  9, "North", 100, 0);
		SpaceMarine sm5(cin, 19,  5, "North", 100, 0);
		SpaceMarine sm6(cin, 21,  5, "North", 100, 0);
		SpaceMarine sm7(cin, 25,  9, "North", 100, 0);
		SpaceMarine sm8(cin, 25, 11, "North", 100, 0);
		debugAssert(!zo.isReadyToAttack(sm1) && !zo.isReadyToAttack(sm1));
		debugAssert(!zo.isReadyToAttack(sm2) && !zo.isReadyToAttack(sm2));
		debugAssert(!zo.isReadyToAttack(sm3) && !zo.isReadyToAttack(sm3));
		debugAssert(!zo.isReadyToAttack(sm4) && !zo.isReadyToAttack(sm4));
		debugAssert(!zo.isReadyToAttack(sm5) && !zo.isReadyToAttack(sm5));
		debugAssert(!zo.isReadyToAttack(sm6) && !zo.isReadyToAttack(sm6));
		debugAssert(!zo.isReadyToAttack(sm7) && !zo.isReadyToAttack(sm7));
		debugAssert(!zo.isReadyToAttack(sm8) && !zo.isReadyToAttack(sm8));
	
		zo.turnRight();
		debugAssert(zo.directionFacing() == "North");
		debugAssert(zo.stepMove(sm1) == 'c');
		debugAssert(zo.stepMove(sm2) == 'z');
		debugAssert(zo.stepMove(sm3) == 'w');
		debugAssert(zo.stepMove(sm4) == 's');
		debugAssert(zo.stepMove(sm5) == 'z');
		debugAssert(zo.stepMove(sm6) == 'c');
		debugAssert(zo.stepMove(sm7) == 's');
		debugAssert(zo.stepMove(sm8) == 'w');

		zo.turnRight();
		debugAssert(zo.directionFacing() == "East");
		debugAssert(zo.stepMove(sm1) == 'w');
		debugAssert(zo.stepMove(sm2) == 's');
		debugAssert(zo.stepMove(sm3) == 'z');
		debugAssert(zo.stepMove(sm4) == 'c');
		debugAssert(zo.stepMove(sm5) == 's');
		debugAssert(zo.stepMove(sm6) == 'w');
		debugAssert(zo.stepMove(sm7) == 'c');
		debugAssert(zo.stepMove(sm8) == 'z');

		zo.turnRight();
		debugAssert(zo.directionFacing() == "South");
		debugAssert(zo.stepMove(sm1) == 'z');
		debugAssert(zo.stepMove(sm2) == 'c');
		debugAssert(zo.stepMove(sm3) == 's');
		debugAssert(zo.stepMove(sm4) == 'w');
		debugAssert(zo.stepMove(sm5) == 'c');
		debugAssert(zo.stepMove(sm6) == 'z');
		debugAssert(zo.stepMove(sm7) == 'w');
		debugAssert(zo.stepMove(sm8) == 's');

		zo.turnRight();
		debugAssert(zo.directionFacing() == "West");
		debugAssert(zo.stepMove(sm1) == 's');
		debugAssert(zo.stepMove(sm2) == 'w');
		debugAssert(zo.stepMove(sm3) == 'c');
		debugAssert(zo.stepMove(sm4) == 'z');
		debugAssert(zo.stepMove(sm5) == 'w');
		debugAssert(zo.stepMove(sm6) == 's');
		debugAssert(zo.stepMove(sm7) == 'z');
		debugAssert(zo.stepMove(sm8) == 'c');

		Zombie zo10(35, 11, "South", 30);
		SpaceMarine sm10(cin, 20, 10, "North", 10, 0);

		zo10.setMove(sm10);
		zo10.processMove(sm10);
		debugAssert(zo10.yPosition() == 10);
		zo10.setMove(sm10);
		zo10.processMove(sm10);
		debugAssert(zo10.directionFacing() == "West");
		zo10.setMove(sm10);
		zo10.processMove(sm10);
		debugAssert(!sm10.isAlive());
	}
	cerr << "--OK\n";

	cerr << "ArmorBonus 5.1 tests: ";
	{
		const ArmorBonus cab(10, 10);
		const SpaceMarine csm(cin, 10, 10, "North", 100, 0);
		cab.isStoodOnBy(csm); cab.xPosition(); cab.yPosition();
		cab.isPickedUp(); cab.image();

		SpaceMarine sm(cin, 20, 10, "North", 100, 10);

		ArmorBonus ab(20, 11);
		debugAssert(!ab.isStoodOnBy(sm));

		sm.stepForward();
		debugAssert(ab.isStoodOnBy(sm));

		debugAssert(sm.armor() == 10);
		debugAssert(!ab.isPickedUp());
		ab.pickedUpBy(sm);
		debugAssert(sm.armor() == 11);
		debugAssert(ab.isPickedUp());
		debugAssert(!ab.isStoodOnBy(sm));
	}
	cerr << "--OK\n";

	cerr << "Screen 5.2 tests: ";
	{
		ofstream screenFileOut("ScreenFile.txt");
		releaseAssert(screenFileOut);
		Screen theScreen(screenFileOut);
		SpaceMarine sm(cin, 20, 10, "North", 100, 0);
		
		theScreen.reset();
		theScreen.place(sm.xPosition(), sm.yPosition(), sm.image());
		theScreen.display();
		theScreen.setStatusBar(sm.createStatusBar());

		screenFileOut.close();

		ifstream screenFileIn("ScreenFile.txt");
		debugAssert(screenFileIn);

		ifstream screenFileTest("ScreenFileTest.txt");
		debugAssert(screenFileTest);
		string lineA, lineB;

		while(screenFileIn && screenFileTest)
		{
			getline(screenFileIn, lineA);
			getline(screenFileTest, lineB);
			debugAssert(lineA == lineB);
		}
	}
	cerr << "--OK\n";

    // Section 6.3
	cerr << "HealthBonus 6.3 tests: ";
	{
		const HealthBonus chb(10, 10);
		const SpaceMarine csm(cin, 10, 10, "North", 100, 0);
		chb.isStoodOnBy(csm); chb.xPosition(); chb.yPosition();
		chb.isPickedUp(); chb.image();

		SpaceMarine sm(cin, 20, 10, "North", 100, 10);

		HealthBonus hb(20, 11);
		debugAssert(!hb.isStoodOnBy(sm));

		sm.stepForward();
		debugAssert(hb.isStoodOnBy(sm));

		debugAssert(sm.health() == 100);
		debugAssert(!hb.isPickedUp());
		hb.pickedUpBy(sm);
		debugAssert(sm.health() == 101);
		debugAssert(hb.isPickedUp());
		debugAssert(!hb.isStoodOnBy(sm));
	}
	cerr << "--OK\n";

	//Section 6.4
	cerr << "PinkDemon 6.4 tests: ";
	{
		const PinkDemon cz(20, 10, "North", 30);
		cz.xPosition(); cz.yPosition(); cz.directionFacing();
		cz.health(); cz.isAlive(); cz.image();

		PinkDemon pd(20, 10, "North", 30);

		pd.adjustHealth(-20);	debugAssert(pd.health() == 10);
		pd.setHealth(170);		debugAssert(pd.health() == 70);  // max health is 70

		pd.stepForward();		debugAssert(pd.yPosition() == 11);
		pd.stepBackward();		debugAssert(pd.yPosition() == 10);
		pd.stepLeft();			debugAssert(pd.xPosition() == 19);
		pd.stepRight();			debugAssert(pd.xPosition() == 20);
		pd.turnLeft();			debugAssert(pd.directionFacing() == "West");
		pd.turnRight();			debugAssert(pd.directionFacing() == "North");
		
		pd.turnLeft();			debugAssert(pd.directionFacing() == "West");
		pd.stepForward();		debugAssert(pd.xPosition() == 19);
		pd.stepBackward();		debugAssert(pd.xPosition() == 20);
		pd.stepLeft();			debugAssert(pd.yPosition() == 9);
		pd.stepRight();			debugAssert(pd.yPosition() == 10);
		pd.turnLeft();			debugAssert(pd.directionFacing() == "South");
		pd.turnRight();			debugAssert(pd.directionFacing() == "West");

		pd.turnLeft();			debugAssert(pd.directionFacing() == "South");
		pd.stepForward();		debugAssert(pd.yPosition() == 9);
		pd.stepBackward();		debugAssert(pd.yPosition() == 10);
		pd.stepLeft();			debugAssert(pd.xPosition() == 21);
		pd.stepRight();			debugAssert(pd.xPosition() == 20);
		pd.turnLeft();			debugAssert(pd.directionFacing() == "East");
		pd.turnRight();			debugAssert(pd.directionFacing() == "South");

		pd.turnLeft();			debugAssert(pd.directionFacing() == "East");
		pd.stepForward();		debugAssert(pd.xPosition() == 21);
		pd.stepBackward();		debugAssert(pd.xPosition() == 20);		
		pd.stepLeft();			debugAssert(pd.yPosition() == 11);
		pd.stepRight();			debugAssert(pd.yPosition() == 10);
		pd.turnLeft();			debugAssert(pd.directionFacing() == "North");
		pd.turnRight();			debugAssert(pd.directionFacing() == "East");
	}
	cerr << "--OK\n";

	cerr << "PinkDemon 6.5 tests: ";
	{
		const PinkDemon cp(20, 10, "North", 30);
		const SpaceMarine csm(cin, 20, 10, "North", 30, 0);
		SpaceMarine sm(cin, 20, 10, "North", 30, 0);
		cp.isReadyToAttack(csm); cp.isReadyToTurn(csm);
		cp.turnMove(csm); cp.stepMove(csm);
		cp.attack(sm);

		PinkDemon pd(20, 10, "North", 30);

		SpaceMarine smNW(cin, 19, 11, "North", 20, 20);
		SpaceMarine smN(cin, 20, 11, "North", 20, 20);
		SpaceMarine smNE(cin, 21, 11, "North", 20, 20);
		SpaceMarine smE(cin, 21, 10, "North", 20, 20);
		SpaceMarine smSE(cin, 21, 9, "North", 20, 20);
		SpaceMarine smS(cin, 20, 9, "North", 20, 20);
		SpaceMarine smSW(cin, 19, 9, "North", 20, 20);
		SpaceMarine smW(cin, 19, 10, "North", 20, 20);

		debugAssert(pd.isReadyToAttack(smNW));
		debugAssert(pd.isReadyToAttack(smN));
		debugAssert(pd.isReadyToAttack(smNE));
		debugAssert(pd.isReadyToTurn(smE) && pd.turnMove(smE) == 'd');
		debugAssert(pd.isReadyToTurn(smSE) && pd.turnMove(smSE) == 'd');
		debugAssert(pd.isReadyToTurn(smS));
		debugAssert(pd.isReadyToTurn(smSW) && pd.turnMove(smSW) == 'a');
		debugAssert(pd.isReadyToTurn(smW) && pd.turnMove(smW) == 'a');

		pd.turnRight(); debugAssert(pd.directionFacing() == "East");
		debugAssert(pd.isReadyToTurn(smNW) && pd.turnMove(smNW) == 'a');
		debugAssert(pd.isReadyToTurn(smN) && pd.turnMove(smN) == 'a');
		debugAssert(pd.isReadyToAttack(smNE));
		debugAssert(pd.isReadyToAttack(smE));
		debugAssert(pd.isReadyToAttack(smSE));
		debugAssert(pd.isReadyToTurn(smS) && pd.turnMove(smS) == 'd');
		debugAssert(pd.isReadyToTurn(smSW) && pd.turnMove(smSW) == 'd');
		debugAssert(pd.isReadyToTurn(smW));

		pd.turnRight(); debugAssert(pd.directionFacing() == "South");
		debugAssert(pd.isReadyToTurn(smNW) && pd.turnMove(smNW) == 'd');
		debugAssert(pd.isReadyToTurn(smN));
		debugAssert(pd.isReadyToTurn(smNE) && pd.turnMove(smNE) == 'a');
		debugAssert(pd.isReadyToTurn(smE) && pd.turnMove(smE) == 'a');
		debugAssert(pd.isReadyToAttack(smSE));
		debugAssert(pd.isReadyToAttack(smSW));
		debugAssert(pd.isReadyToTurn(smW) && pd.turnMove(smW) == 'd');

		pd.turnRight(); debugAssert(pd.directionFacing() == "West");
		debugAssert(pd.isReadyToAttack(smNW));
		debugAssert(pd.isReadyToTurn(smN) && pd.turnMove(smN) == 'd');
		debugAssert(pd.isReadyToTurn(smNE) && pd.turnMove(smNE) == 'd');
		debugAssert(pd.isReadyToTurn(smE));
		debugAssert(pd.isReadyToTurn(smSE) && pd.turnMove(smSE) == 'a');
		debugAssert(pd.isReadyToTurn(smS) && pd.turnMove(smS) == 'a');
		debugAssert(pd.isReadyToAttack(smSW));
		debugAssert(pd.isReadyToAttack(smW));
		
		pd.attack(smW);		debugAssert(smW.health() == 14 && smW.armor() == 7);
		pd.attack(smW);		debugAssert(smW.health() == 8 && smW.armor() == 0);
		pd.attack(smW);		debugAssert(!smW.isAlive() && !pd.isReadyToAttack(smW) &&
			                            !pd.isReadyToTurn(smW));

		SpaceMarine sm0(cin, 20, 10, "North", 100, 0);
		debugAssert(!pd.isReadyToAttack(sm0) && !pd.isReadyToTurn(sm0));
		debugAssert(pd.stepMove(sm0) == 's');

		SpaceMarine sm1(cin, 21, 15, "North", 100, 0);		// above
		SpaceMarine sm2(cin, 19, 15, "North", 100, 0);
		SpaceMarine sm3(cin, 15, 11, "North", 100, 0);		// left
		SpaceMarine sm4(cin, 15,  9, "North", 100, 0);
		SpaceMarine sm5(cin, 19,  5, "North", 100, 0);		// below
		SpaceMarine sm6(cin, 21,  5, "North", 100, 0);
		SpaceMarine sm7(cin, 25,  9, "North", 100, 0);		// right
		SpaceMarine sm8(cin, 25, 11, "North", 100, 0);
		debugAssert(!pd.isReadyToAttack(sm1) && !pd.isReadyToTurn(sm1));
		debugAssert(!pd.isReadyToAttack(sm2) && !pd.isReadyToTurn(sm2));
		debugAssert(!pd.isReadyToAttack(sm3) && !pd.isReadyToTurn(sm3));
		debugAssert(!pd.isReadyToAttack(sm4) && !pd.isReadyToTurn(sm4));
		debugAssert(!pd.isReadyToAttack(sm5) && !pd.isReadyToTurn(sm5));
		debugAssert(!pd.isReadyToAttack(sm6) && !pd.isReadyToTurn(sm6));
		debugAssert(!pd.isReadyToAttack(sm7) && !pd.isReadyToTurn(sm7));
		debugAssert(!pd.isReadyToAttack(sm8) && !pd.isReadyToTurn(sm8));
	
		pd.turnRight();
		debugAssert(pd.directionFacing() == "North");
		debugAssert(pd.stepMove(sm1) == 'w');
		debugAssert(pd.stepMove(sm2) == 'w');
		debugAssert(pd.stepMove(sm3) == 'z');
		debugAssert(pd.stepMove(sm4) == 'z');
		debugAssert(pd.stepMove(sm5) == 's');
		debugAssert(pd.stepMove(sm6) == 's');
		debugAssert(pd.stepMove(sm7) == 'c');
		debugAssert(pd.stepMove(sm8) == 'c');
	
		pd.turnRight();
		debugAssert(pd.directionFacing() == "East");
		debugAssert(pd.stepMove(sm1) == 'z');
		debugAssert(pd.stepMove(sm2) == 'z');
		debugAssert(pd.stepMove(sm3) == 's');
		debugAssert(pd.stepMove(sm4) == 's');
		debugAssert(pd.stepMove(sm5) == 'c');
		debugAssert(pd.stepMove(sm6) == 'c');
		debugAssert(pd.stepMove(sm7) == 'w');
		debugAssert(pd.stepMove(sm8) == 'w');

		pd.turnRight();
		debugAssert(pd.directionFacing() == "South");
		debugAssert(pd.stepMove(sm1) == 's');
		debugAssert(pd.stepMove(sm2) == 's');
		debugAssert(pd.stepMove(sm3) == 'c');
		debugAssert(pd.stepMove(sm4) == 'c');
		debugAssert(pd.stepMove(sm5) == 'w');
		debugAssert(pd.stepMove(sm6) == 'w');
		debugAssert(pd.stepMove(sm7) == 'z');
		debugAssert(pd.stepMove(sm8) == 'z');
		
		pd.turnRight();
		debugAssert(pd.directionFacing() == "West");
		debugAssert(pd.stepMove(sm1) == 'c');
		debugAssert(pd.stepMove(sm2) == 'c');
		debugAssert(pd.stepMove(sm3) == 'w');
		debugAssert(pd.stepMove(sm4) == 'w');
		debugAssert(pd.stepMove(sm5) == 'z');
		debugAssert(pd.stepMove(sm6) == 'z');
		debugAssert(pd.stepMove(sm7) == 's');
		debugAssert(pd.stepMove(sm8) == 's');

		PinkDemon pd10(20, 12, "West", 30);
		SpaceMarine sm10(cin, 20, 10, "North", 10, 0);

		pd10.setMove(sm10);
		pd10.processMove(sm10);
		debugAssert(pd10.yPosition() == 11);
		pd10.setMove(sm10);
		pd10.processMove(sm10);
		debugAssert(pd10.directionFacing() == "South");
		pd10.setMove(sm10);
		pd10.processMove(sm10);
		debugAssert(!sm10.isAlive());
	}
	cerr << "--OK\n";

	cerr << "SpaceMarine 6.6 tests: ";
	{
		const SpaceMarine csm(cin, 20, 10, "North", 100, 0);
		const PinkDemon cp(20, 10, "North", 30);
		PinkDemon p(20, 10, "North", 30);
		csm.isReadyToAttack(cp); csm.attack(p);

		SpaceMarine sm(cin, 20, 10, "North", 100, 0);

		PinkDemon pdN(20, 15, "North", 30);		debugAssert(sm.isReadyToAttack(pdN));
		sm.turnRight();							debugAssert(sm.directionFacing() == "East");
		PinkDemon pdE(25, 10, "North", 30);		debugAssert(sm.isReadyToAttack(pdE));
		sm.turnRight();							debugAssert(sm.directionFacing() == "South");
		PinkDemon pdS(20,  5, "North", 30);		debugAssert(sm.isReadyToAttack(pdS));
		sm.turnRight();							debugAssert(sm.directionFacing() == "West");
		PinkDemon pdW(15, 10, "North", 30);		debugAssert(sm.isReadyToAttack(pdW));

		sm.attack(pdW);		debugAssert(pdW.health() == 20);
		sm.attack(pdW);		debugAssert(pdW.health() == 10);
		sm.attack(pdW);		debugAssert(!pdW.isAlive() && !sm.isReadyToAttack(pdW));
	}
	cerr << "--OK\n";

	cerr << "SpaceMarine 6.7 tests: ";
	{
		istringstream testInput("wwwwwzzzzsssccaddqfff");
		SpaceMarine sm(testInput, 20, 10, "North", 100, 0);

		Zombie zo(25, 12, "East", 20);
		ShotgunGuy sg(27, 12, "South", 30);
		PinkDemon pd(21, 12, "North", 10);

		vector<Monster*> mon;
		mon.push_back(&zo);
		mon.push_back(&sg);
		mon.push_back(&pd);

		do
		{
			sm.setMove();
			sm.processMove(mon);
		}while(!sm.quitGame());

		debugAssert(sm.xPosition() == 18);
		debugAssert(sm.yPosition() == 12);
		debugAssert(sm.directionFacing() == "East");

		sm.setMove();
		sm.processMove(mon);
		debugAssert(!pd.isAlive() && zo.health() == 10 && sg.health() == 20);
		sm.setMove();
		sm.processMove(mon);
		debugAssert(!pd.isAlive() && !zo.isAlive() && sg.health() == 10);
		sm.setMove();
		sm.processMove(mon);
		debugAssert(!pd.isAlive() && !zo.isAlive() && !sg.isAlive());
	}
	cerr << "--OK\n";

	// Section 7.3
	cerr << "GreenArmor 7.3 tests: ";
	{
		const GreenArmor cga(10, 10);
		const SpaceMarine csm(cin, 10, 10, "North", 100, 0);
		cga.isStoodOnBy(csm); cga.xPosition(); cga.yPosition();
		cga.isPickedUp(); cga.image();

		SpaceMarine sm(cin, 20, 10, "North", 100, 100);

		GreenArmor ga(20, 11);
		debugAssert(!ga.isStoodOnBy(sm));

		sm.stepForward();
		debugAssert(ga.isStoodOnBy(sm));

		debugAssert(sm.armor() == 100);
		debugAssert(!ga.isPickedUp());
		ga.pickedUpBy(sm);
		debugAssert(sm.armor() == 100);
		debugAssert(!ga.isPickedUp());
		debugAssert(ga.isStoodOnBy(sm));
		
		sm.adjustArmor(-1);
		debugAssert(sm.armor() == 99);
		ga.pickedUpBy(sm);
		debugAssert(sm.armor() == 100);
		debugAssert(ga.isPickedUp());
		debugAssert(!ga.isStoodOnBy(sm));
	}
	cerr << "--OK\n";

	// Section 8.2
	cerr << "BlueArmor 8.2 tests: ";
	{
		const BlueArmor cba(10, 10);
		const SpaceMarine csm(cin, 10, 10, "North", 100, 0);
		cba.isStoodOnBy(csm); cba.xPosition(); cba.yPosition();
		cba.isPickedUp(); cba.image();

		SpaceMarine sm(cin, 20, 10, "North", 100, 200);

		BlueArmor ba(20, 11);
		debugAssert(!ba.isStoodOnBy(sm));

		sm.stepForward();
		debugAssert(ba.isStoodOnBy(sm));

		debugAssert(sm.armor() == 200);
		debugAssert(!ba.isPickedUp());
		ba.pickedUpBy(sm);
		debugAssert(sm.armor() == 200);
		debugAssert(!ba.isPickedUp());
		debugAssert(ba.isStoodOnBy(sm));

		sm.adjustArmor(-1);
		debugAssert(sm.armor() == 199);
		ba.pickedUpBy(sm);
		debugAssert(sm.armor() == 200);
		debugAssert(ba.isPickedUp());
		debugAssert(!ba.isStoodOnBy(sm));
	}
	cerr << "--OK\n";

	
	// Section 8.3
	cerr << "SpacecMarine 8.3 tests: ";
	{
		istringstream testInput("wwwwwzzzzsssccaddqfff");
		SpaceMarine sm(testInput, 20, 10, "North", 100, 0);

		Zombie zo(25, 12, "East", 20);
		ShotgunGuy sg(27, 12, "South", 30);
		PinkDemon pd(21, 12, "North", 10);

		vector<Monster*> mon;
		mon.push_back(&zo);
		mon.push_back(&sg);
		mon.push_back(&pd);

		do
		{
			sm.setMove();
			sm.processMove(mon);
		}while(!sm.quitGame());

		debugAssert(sm.xPosition() == 18);
		debugAssert(sm.yPosition() == 12);
		debugAssert(sm.directionFacing() == "East");

		sm.setMove();
		sm.processMove(mon);
		debugAssert(!pd.isAlive() && zo.health() == 10 && sg.health() == 20);
		sm.setMove();
		sm.processMove(mon);
		debugAssert(!pd.isAlive() && !zo.isAlive() && sg.health() == 10);
		sm.setMove();
		sm.processMove(mon);
		debugAssert(!pd.isAlive() && !zo.isAlive() && !sg.isAlive());
	}
	cerr << "--OK\n";
	
	cerr << "\nAll unit tests passed" << flush;
	getchar();
}
//-------------------------------------------------