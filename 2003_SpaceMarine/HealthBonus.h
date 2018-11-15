//-------------------------------------------------
// ArmorBonus.h

#ifndef HEALTHBONUS_H
#define HEALTHBONUS_H

#pragma warning(disable : 4512)

#include "Bonus.h"

class SpaceMarine;
class HealthBonus : public Bonus
{
public:
	HealthBonus(length_t inX, 
		        length_t inY);

	virtual ~HealthBonus();

   virtual void pickedUpBy(SpaceMarine& sm);
};

#endif
//-------------------------------------------------