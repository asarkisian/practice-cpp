//-------------------------------------------------
// GreenArmor.h

#ifndef GREENARMOR_H
#define GREENARMOR_H

#pragma warning(disable : 4512)

#include "Bonus.h"

class SpaceMarine;

class GreenArmor : public Bonus
{
public:
	GreenArmor(length_t inX, 
		       length_t inY);

	virtual ~GreenArmor();

	virtual void pickedUpBy(SpaceMarine& sm);
};

#endif
//-------------------------------------------------