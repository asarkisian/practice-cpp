//-------------------------------------------------
// BlueArmor.cpp

#include "BlueArmor.h"
#include "SpaceMarine.h"

BlueArmor::BlueArmor(length_t inX, 
    	             length_t inY)
:Bonus(inX, inY, 'B')
{
}

BlueArmor::~BlueArmor()
{
}

// Public Modifier Member Functions
void BlueArmor::pickedUpBy(SpaceMarine& sm)
{
	if(sm.armor() < 200)
	{
		sm.setArmor(200);
		pickUp();
	}
}
//-------------------------------------------------