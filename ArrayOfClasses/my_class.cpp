#include "my_class.h"


MyClass::MyClass()
{
}


MyClass::MyClass(string n)
    :name(n)
{
}


MyClass::~MyClass()
{
}


string MyClass::return_name() const
{
    return(name);
}
