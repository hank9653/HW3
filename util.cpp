#include "util.h"

int areaSum(std::vector<Shape *> v) {
    int sum = 0;
    /*
    std::vector<Shape *>::iterator i;
    for (i=v.begin(); i != v.end(); ++i)
        sum += (*i)->area();
        */

    for(auto e : v)
        sum += e->area();
    return sum;
}

