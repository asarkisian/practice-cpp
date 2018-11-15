//-------------------------------------------------
// GreenArmor.cpp

#include "GreenArmor.h"
#include "SpaceMarine.h"

GreenArmor::GreenArmor(length_t inX, 
    	               length_t inY)
:Bonus(inX, inY, 'G')
{
}

GreenArmor::~GreenArmor()
{
}

// Public Modifier Member Functions
void GreenArmor::pickedUpBy(SpaceMarine& sm)
{
	if(sm.armor() < 100)
	{
		sm.setArmor(100);
		pickUp();
	}
}
//-------------------------------------------------