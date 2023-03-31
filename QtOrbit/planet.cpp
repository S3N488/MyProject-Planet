#include "planet.h"

Planet::Planet(double AR)
{
    R=AR ;
}

double Planet::getR()
{
    return R ;
}

// Ставим планету в центр координат
double Planet::getX()
{
    return 0 ;
}

double Planet::getY()
{
    return 0 ;
}

double Planet::getZ()
{
    return 0 ;
}
