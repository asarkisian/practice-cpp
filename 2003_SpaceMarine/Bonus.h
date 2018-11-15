//-------------------------------------------------
// Bonus.h

#pragma warning(disable : 4512)

#ifndef BONUS_H
#define BONUS_H

#include "Typedefs.h"

class SpaceMarine;

class Bonus
{
public:
	Bonus(length_t inX, 
		  length_t inY,
		  image_t  inI);

	virtual ~Bonus();

	virtual void pickedUpBy(SpaceMarine& sm) = 0;

	bool isStoodOnBy(const SpaceMarine& csm) const;
	length_t xPosition()const;
	length_t yPosition() const;
	bool isPickedUp() const;
	image_t image() const;

protected:
	void pickUp();

private:
	const length_t my_xPosition;
	const length_t my_yPosition;

	bool my_isPickedUp;

	const image_t my_image;
	const image_t my_space;
};

#endif
//-------------------------------------------------