//-------------------------------------------------
// Screen.cpp

#include "Globals.h"
#include "Room.h"
#include "Screen.h"
#include <algorithm>
#include <iostream>
using std::copy;
using std::domain_error;
using std::flush;
using std::for_each;
using std::ostream;
using std::ostream_iterator;
using std::replace_if;
using std::string;

void clearScreen()
{
	system("cls");
}

// Predicate Function for use only with reset()
bool notSpace(const char c)
{
    return (c != ' ');
}

// Function for use only with the constructor using for_each()
void placeWallChar(string& row)
{
	row.at(0) = row[row.size() - 1] = theRoom.eastWall();
}

// Function for use only with the reset function using for_each()
void appendNewLine(string& row)
{
	row.push_back('\n');
}

// Function for use only with the constructor using for_each()
void resetScreen(string& image)
{
	replace_if(image.begin() + 1, image.end() - 2, notSpace, ' ');
}

// Public Modifier Member Functions
Screen::Screen(ostream& inOS)
:my_output(inOS),
 my_image(theRoom.nrows(), string(theRoom.ncols(), theRoom.floor())),
 my_statusBar("")
{
	// Side Walls
	const string horizontalWall(theRoom.ncols(), theRoom.northWall());
	for_each(my_image.begin() + 1, my_image.end() - 1, placeWallChar);
	my_image.front() = my_image.back() = horizontalWall;

	// Corners
	my_image.at(0).at(0) = theRoom.northWestCorner();
	my_image.at(0)[theRoom.ncols() - 1] = theRoom.northEastCorner();
	my_image[my_image.size() - 1].at(0) = theRoom.southWestCorner();
	my_image[my_image.size() - 1][theRoom.ncols() - 1] = theRoom.southEastCorner();

	// Adding the new line character at the end of each string
	for_each(my_image.begin(), my_image.end(), appendNewLine);
}

void Screen::place(const length_t inX, const length_t inY, const image_t inI)
{
	// Translate physical coordinates to screen coordinates
	const int col(inX);
	const int row(my_image.size() - 1 - inY);
	my_image.at(row).at(col) = inI;
}

void Screen::reset()
{
	for_each(my_image.begin() + 1, my_image.end() - 1, resetScreen);
}

void Screen::setStatusBar(const string& inS)
{
	my_statusBar = inS;
}

// Public Accessor Member Functions
void Screen::display() const
{
	clearScreen();
	copy(my_image.begin(), my_image.end(), ostream_iterator<string>(my_output));
	my_output << flush;
	displayStatusBar();
}

void Screen::displayStatusBar() const
{
    my_output << my_statusBar << flush;
}
//-------------------------------------------------