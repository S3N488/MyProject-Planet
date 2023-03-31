#include "satellite.h"
#include <math.h>
#include "constants.h"

double Satellite::A() const
{
    // Угол изменяется линейно
    return Fcamera+Const::PI2*t/T ;
}

double Satellite::F() const
{
    // Угол изменяется гармонически
    return 0.5*(Fmin+Fmax) + 0.5*(Fmax-Fmin)*cos(Const::PI2*t/T) ;
}

void Satellite::rebuildOrbit() {
    double tsave = t ;
    t=0 ;
    // Отстройка всех точек, прогоняя спутник по переиоду
    const int cnt = ORBCNT ;
    Aorbit = new double[cnt] ;
    Forbit = new double[cnt] ;
    const double dt = T/(double)(ORBCNT-1) ;
    for (int i=0; i<ORBCNT; i++) {
        Aorbit[i]=A() ;
        Forbit[i]=F() ;
        t+=dt ;
    }
    t = tsave ;
}

Satellite::Satellite(double AR, double AFmin, double AFmax, double t0p)
{
    R=AR ;
    Fmin = AFmin ;
    Fmax = AFmax ;
    t =T*t0p ;

    rebuildOrbit() ;
}

void Satellite::update(double dt)
{
    t+=dt ;
}

// Преобразование стандартные - полярные в трехмерные
double Satellite::getX()
{
    return R*sin(F())*cos(A()) ;
}

double Satellite::getY() const
{
    return R*sin(F())*sin(A()) ;
}

double Satellite::getZ()
{
    return R*cos(F()) ;
}

double Satellite::getOrbX(int i)
{
    return R*sin(Forbit[i])*cos(Aorbit[i]) ;
}

double Satellite::getOrbY(int i)
{
    return R*sin(Forbit[i])*sin(Aorbit[i]) ;
}

double Satellite::getOrbZ(int i)
{
    return R*cos(Forbit[i]) ;
}

void Satellite::setFCamera(double F)
{
    Fcamera = F ;
    rebuildOrbit() ;
}
