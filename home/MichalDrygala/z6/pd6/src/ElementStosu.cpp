#include "ElementStosu.h"

//destruktor
    ElementStosu::~ElementStosu() {}

// operator
ostream& operator << (ostream& os, ElementStosu& el)
{
    el.output(os);
    return os;
}
