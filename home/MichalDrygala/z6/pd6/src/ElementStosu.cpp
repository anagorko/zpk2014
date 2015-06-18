#include "ElementStosu.h"

//destruktor
ElementStosu::~ElementStosu() {}

//operatory
ostream& operator<<(ostream& os, ElementStosu& el)
{
    el.output(os);
    return os;
}
