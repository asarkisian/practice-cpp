
#include <array>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct Horse {

	string name;
	int distance;
	int offset;
	int ID;

};

const int horseCount = 6;
const int trackLength = 100;


void getName(Horse& h) {
	cout << "Enter horses name: ";
	getline(cin, h.name);

	return;
}

int checkEvents(Horse& h) {

	srand(int(rand()));

	int randNum = (rand() % 16);

	switch (randNum)
	{
	case 0:
		h.offset = -(rand() % 2 + 1);
		break;
	case 1:
		h.offset = -(rand() % 2 + 1);
		break;
	case 2:
		h.offset = +(rand() % 2 + 1);
		break;
	case 3:
		h.offset = +(rand() % 2 + 1);
		break;
	case 4:
		h.offset = -(rand() % 3 + 4);
		break;
	case 5:
		h.offset = +(rand() % 3 + 4);
		break;

	}

	return h.offset;
}


int updatePos(Horse& h) {

	int randNum1 = (rand() % 6 + 1);
	int randNum2 = (rand() % 6 + 1);

	int sum = randNum1 + randNum2;

	sum += h.offset;

	if (sum <= 0) {
		h.offset = sum;
	}
	else {
		h.offset = 0;
		h.distance += sum;
	}

	if (h.distance >= 100) {
		h.distance = 100;
	}

	return h.distance;
}

void reportPos(array<Horse, horseCount> h) {

	for (int count = 0; count < h.size(); count++) {
		cout << h.at(count).ID << ')' << h.at(count).name << ' ' << h.at(count).distance << endl;
	}
	endl(cout);

	return;
}

void clearData(array<Horse, horseCount>& h) {

	for (int count = 0; count < h.size(); count++) {
		h.at(count).distance = h.at(count).offset = 0;
	}

	return;
}
	
int main(int argc, char** argv) {

	// seed random number generator
	srand(int(time(NULL)));

	// CREATE AND INITIALIZE VARIABLES
	array <Horse, horseCount> Horses;

	// using a range-based for loop, initialize data for each horse
	// have user name horses
	// get all the horses names
	for (int i = 0; i < horseCount; i++) {
		getName(Horses.at(i));
		Horses.at(i).ID = i;
	}

	// create ID. (you will probably want to create a index variable external to the loop to do this)
	int id = 0;

	// number of winning horse (init to 0)
	int winner = 0;

	// distance of leading horse (init to 0)
	int lead = 0;

	// bet
	int bet = 0;

	// user choice
	char playagain;

	// cash on hand (init to 100--or whatever value you chose)
	int cash = 100;

	// flag to indicate the race is active in race do-while loop (init to true)
	bool isRacing = true;
	
	// flag to indicate the game is active in game do-while loop (init to true)	
	bool isPlaying = true;
	
	// horse number bet on
	int hNum = 0;

	// START OF GAME LOOP
	do {

		// create ID. (you will probably want to create a index variable external to the loop to do this)
		id = 0;

		// number of winning horse (init to 0)
		winner = 0;

		// distance of leading horse (init to 0)
		lead = 0;

		// bet
		bet = 0;

		// flag to indicate the race is active in race do-while loop (init to true)
		isRacing = true;

		// flag to indicate the game is active in game do-while loop (init to true)	
		isPlaying = true;

		// horse number bet on
		hNum = 0;

		// clear distance and offset.
		clearData(Horses);

		// ask for bet amount and get the number of the horse being bet on
		cout << "Enter bet amount: ";
		cin >> bet;

		// if the bet is negative or $0, quit.
		if (bet <= 0) {
			exit(EXIT_SUCCESS);
		}

		cout << "Which horse are you betting on: ";
		cin >> hNum;

		// START OF RACE LOOP
		do{

			// for each horse--use range-based for
			for (int i = 0; i < Horses.size(); i++) {
				
				// check for events using a function and return horse's offset
				checkEvents(Horses.at(i));

				// roll dice and, using offset, adjust horse's distance using a function
				updatePos(Horses.at(i));

				// check for race over
				if (Horses.at(i).distance >= trackLength) {
					winner = Horses.at(i).ID;
					cout << "The winner is: " << winner << " - " << Horses.at(i).name << "!!" << endl;
					isRacing = false;

					// report horse position using function
					reportPos(Horses);
					
					break;
				}

				// report horse position using function
				reportPos(Horses);

				// check if this is leading horse and change lead and winner values if it is
				if (Horses.at(i).distance > lead) {
					lead = Horses.at(i).distance;
					cout << "Horse #: " << Horses.at(i).ID << " - " << Horses.at(i).name << " has taken the lead!" << endl;
				}

				//continue race loop until race is over;

			}
		} while (isRacing);
		// END OF RACE LOOP

		//report winner and settle bet
		if (hNum == winner) {
			cash += bet;
		}
		else {
			cash -= bet;
		}

		cout << "Bet Amount: " << bet << endl;
		cout << "Cash: " << cash << endl;

		if (cash > 0) {
			do {
				// if player wants to bet in another races
				cout << "\nPlay again? (y/n): ";
				cin >> playagain;

				playagain = toupper(playagain);

				if (playagain == 'Y') {
					isPlaying = true;

				}
				else if (playagain == 'N') {
					isPlaying = false;
					break;
				}
				else {
					cout << "Not a valid choice!";
				}
			} while (playagain != 'Y' && playagain != 'N');
		}
		else
		{
			cout << "You ran out of money!!!" << endl;
			exit(EXIT_SUCCESS);
		}

	}while (isPlaying);
	// END OF GAME LOOP

	// Wait for user input to close program when debugging.
	cin.get();

	return(EXIT_SUCCESS);
}
