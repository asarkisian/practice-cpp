//-------------------------------------------------
// ArmorBonus.h

#ifndef ARMORBONUS_H
#define ARMORBONUS_H

#pragma warning(disable : 4512)

#include "Bonus.h"

class SpaceMarine;

class ArmorBonus : public Bonus
{
public:
	ArmorBonus(length_t inX, 
		       length_t inY);

	virtual ~ArmorBonus();

	virtual void pickedUpBy(SpaceMarine& sm);
};

#endif
//-------------------------------------------------