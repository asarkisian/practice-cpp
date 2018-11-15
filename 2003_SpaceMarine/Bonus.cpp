//-------------------------------------------------
// Bonus.cpp

#include "Bonus.h"
#include "SpaceMarine.h"

Bonus::Bonus(length_t inX, 
	         length_t inY,
	         image_t  inI)
:my_xPosition(inX),
 my_yPosition(inY),
 my_isPickedUp(false),
 my_image(inI),
 my_space(' ')
{
}

Bonus::~Bonus()
{
}

void Bonus::pickUp()
{
	my_isPickedUp = (true);
}

bool Bonus::isStoodOnBy(const SpaceMarine& csm) const
{
    if(my_xPosition == csm.xPosition() && my_yPosition == csm.yPosition()
		&& my_isPickedUp == false)
	{
	    return(true);
	}
	return(false);
}

length_t Bonus::xPosition()const
{
	return(my_xPosition);
}

length_t Bonus::yPosition() const
{
	return(my_yPosition);
}

bool Bonus::isPickedUp() const
{
	return(my_isPickedUp);
}

image_t Bonus::image() const
{
	if(my_isPickedUp == false)
	{
		return(my_image);
	}
	return(my_space);
}
//-------------------------------------------------