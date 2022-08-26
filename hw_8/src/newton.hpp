#ifndef NEWTON_HPP_
#define NEWTON_HPP_

#include <stdlib.h>

template <typename T>
double findNearestRoot(T f, double startingPoint, double eps = 0.000001)
{
    // add your code here ...
    if (abs(f(startingPoint).first) < eps)
    {
        return startingPoint;
    }
    else
    {
        return findNearestRoot(f, startingPoint - f(startingPoint).first / f(startingPoint).second);
    }
}

#endif