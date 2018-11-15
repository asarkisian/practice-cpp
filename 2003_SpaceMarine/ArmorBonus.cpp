//-------------------------------------------------
// ArmorBonus.cpp

#include "ArmorBonus.h"
#include "SpaceMarine.h"

ArmorBonus::ArmorBonus(length_t inX, 
    	               length_t inY)
:Bonus(inX, inY, 'A')
{
}

ArmorBonus::~ArmorBonus()
{
}

// Public Modifier Member Functions
void ArmorBonus::pickedUpBy(SpaceMarine& sm)
{
	sm.adjustArmor(1);
	pickUp();
}
//-------------------------------------------------