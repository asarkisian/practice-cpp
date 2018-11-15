#include "my_class.h"


MyClass::MyClass()
{
}


MyClass::MyClass(name_t n)
:my_name(n)
{
}


// destructor(s)
MyClass::~MyClass()
{
}


// modifier(s)
void MyClass::change_name(const name_t n)
{
    my_name = n;
}

// accessor(s)
name_t MyClass::get_name() const
{ 
    return(my_name);
}
