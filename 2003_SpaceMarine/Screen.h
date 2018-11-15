//-------------------------------------------------
// Screen.h

#ifndef SCREEN_H
#define SCREEN_H

#pragma warning(disable : 4512)

#include "Typedefs.h"
#include <iosfwd>
#include <string>
#include <vector>

class Screen
{
public:
	Screen(std::ostream& inOS);

	void place(const length_t inX, 
		       const length_t inY, 
			   const image_t inI);
	void reset();
	void setStatusBar(const std::string& inS);
	
	void display() const;
	void displayStatusBar() const;

private:
	std::ostream& my_output;
	std::vector<std::string> my_image;

	std::string my_statusBar;
};

#endif
//-------------------------------------------------