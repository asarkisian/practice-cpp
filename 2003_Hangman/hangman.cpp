//**************************************
//     
// Name: Hangman (Simple)
// Description:Very simple game of hangman using classes.
// By: Armond_Sarkisian
//
// This code is copyrighted and has
// limited warranties. Please see http:
//     www.Planet-Source-Code.com/vb/scripts/Sh
//     owCode.asp?txtCodeId=6476&lngWId=3//for details.
//**************************************

//--------------------------------------
// Hangman.cpp
//#pragma warning(disable : 4244)

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::transform;

char my_move;

class Hangman
{
public:
	Hangman();
	~Hangman();

	void playerOne(); 
	void setMove();
	void processMove();
	void initialize();
	void displayGrid() const;

	bool quitSession() const;
	bool isPlayAgain() const;
	bool isWin() const;
	bool isLose() const;

	string secretWord() const;

private:

	string my_body;
	string my_secretWord;
	string my_secretX;
	string my_category;
	string my_hint;

	char my_quit;
	char my_isPlayAgain;
	char my_choice;
	string my_missed;
	bool my_isWin;
	bool my_isLose;
};

char update(char secretWord, char secretX)
{
	if(my_move == secretWord)
		return secretWord;
	else
		return secretX;
}

Hangman::Hangman()
:my_body("       "),
my_secretWord(""),
my_secretX(""),
my_category(""),
my_hint(""),
my_quit('Q'),
my_isPlayAgain('N'),
my_choice(' '),
my_missed(""),
my_isWin(false),
my_isLose(false)
{}

Hangman::~Hangman()
{}

void Hangman::playerOne()
{
	cout << "\nEnter category:";
	cin >> my_category;

	transform(my_category.begin(), my_category.end(), my_category.begin(), toupper);

	cout << "Enter any hints:";
	cin >> my_hint;

	transform(my_hint.begin(), my_hint.end(), my_hint.begin(), toupper);

	cout << "Enter secret word: ";
	cin >> my_secretWord;

	transform(my_secretWord.begin(), my_secretWord.end(), my_secretWord.begin(), toupper);

	my_secretX = string(my_secretWord.size(), '*');
}

void Hangman::setMove()
{
	cout << "Category: " << my_category << '\n';
	cout << "Hint: " << my_hint << '\n';
	cout << "Missed:" << my_missed << '\n';

	cout << "Enter a letter [" << my_secretX << "]: ";
	cin >> my_move;
	my_move = toupper(my_move);
}

void Hangman::processMove()
{
	string old = my_secretX;

	transform(my_secretWord.begin(), my_secretWord.end(), my_secretX.begin(), my_secretX.begin(), update);

	if(old == my_secretX)
	{
		my_missed += my_move;
		my_missed += ", ";
		if(my_body[0] == ' ')
		{
			my_body[0] = 'O';
		}
		else if(my_body[1] == ' ')
		{
			my_body[1] = '\\';
		}
		else if(my_body[2] == ' ')
		{
			my_body[2] = '/';
		}
		else if(my_body[3] == ' ')
		{
			my_body[3] = '|';
		}
		else if(my_body[4] == ' ')
		{
			my_body[4] = '|';
		}
		else if(my_body[5] == ' ')
		{
			my_body[5] = '/';
		}
		else if(my_body[6] == ' ')
		{
			my_body[6] = '\\';
			my_isLose = true;
		}
	}

	if(my_secretWord == my_secretX)
	{
		my_isWin = true;
		return;
	}
}

void Hangman::initialize()
{
	my_body = ("       ");
	my_secretWord = ("");
	my_secretX = ("");
	my_category = ("");
	my_hint = ("");
	my_quit = ('Q');
	my_isPlayAgain = ('N');
	my_choice = (' ');
	my_missed = ("");
	my_isWin = (false);
	my_isLose = (false);
}

void Hangman::displayGrid() const
{
	system("cls");

	cout << "    ------\n"
	     << "    |    |\n"
	     << "   " << my_body[1] << my_body[0] << my_body[2] << "   |\n"
	     << "    " << my_body[3] << "    |\n"
	     << "    " << my_body[4] << "    |\n"
	     << "   " << my_body[5] << ' ' << my_body[6] << "   |\n"
  	     << "         |\n"
	     << "    -----\n" << std::flush;
}

bool Hangman::quitSession() const
{
	if(isWin() || isLose())
		return true;
	
	return false;
}

bool Hangman::isPlayAgain() const
{
	if(my_move == my_isPlayAgain)
		return true;

	return false;
}

bool Hangman::isWin() const
{
	if(my_isWin)
		return true;
	
	return false;
}

bool Hangman::isLose() const
{
	if(my_isLose)
		return true;
	
	return false;
}

string Hangman::secretWord() const
{
	return my_secretWord;
}

int main()
{
	Hangman hm;

	do
	{
		system("cls");
		hm.initialize();
		hm.playerOne();
		do
		{
			if(!hm.isWin())
			{
				hm.displayGrid();
				hm.setMove();
				hm.processMove();
			}
		}while(!hm.quitSession());
		
		if(hm.isWin())
		{
			system("cls");

			cout << "    -------\n"
				 << "          |\n"
				 << "    \\O/   |\n"
				 << "     |    |\n" 
				 << "     |    |\n"
				 << "    / \\   |\n"
				 << "    -------\n";
			
			cout << "\nCongratulations! You win!\n";
			cout << "Secret word is " << hm.secretWord() << endl;
		}
		else if(hm.isLose())
		{
			hm.displayGrid();
			cout << "\nSorry you lose!\n";
			cout << "Secret word was " << hm.secretWord() << endl;
		}
	
		cout << "Do you want to play again: ";
		cin >> my_move;
		my_move = toupper(my_move);
	
	}while(!hm.isPlayAgain());
	
	return 0;
}