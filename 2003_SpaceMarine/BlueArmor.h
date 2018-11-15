//-----------------------------------------------
// BlueArmor.h

#ifndef BLUEARMOR_H
#define BLUEARMOR_H

#include "Bonus.h"

class SpaceMarine;

class BlueArmor : public Bonus
{
public:
	BlueArmor(length_t inX, 
		      length_t inY);

	virtual ~BlueArmor();

	virtual void pickedUpBy(SpaceMarine& sm);
};

#endif
//-----------------------------------------------