//-------------------------------------------------
// HealthBonus.cpp

#include "HealthBonus.h"
#include "SpaceMarine.h"

HealthBonus::HealthBonus(length_t inX, 
    	                 length_t inY)
:Bonus(inX, inY, 'H')
{
}

HealthBonus::~HealthBonus()
{
}

// Public Modifier Member Functions
void HealthBonus::pickedUpBy(SpaceMarine& sm)
{
	sm.adjustHealth(1);
	pickUp();
}
//-------------------------------------------------