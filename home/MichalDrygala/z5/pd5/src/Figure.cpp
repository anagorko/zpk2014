#include "Figure.h"

ostream& operator << (ostream& os, const Figure& f)
{
    return f.output(os);
}
