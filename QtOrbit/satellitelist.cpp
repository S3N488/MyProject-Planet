#include "satellitelist.h"

#include "math.h"

SatelliteList::SatelliteList()
{
    list = new QList<Satellite*>() ;
    s = 1 ;
}

void SatelliteList::clear()
{
    list->clear() ;
}

void SatelliteList::addSatellite(double R, double D)
{
    Satellite * sat = new Satellite(R,(3.14-D)/2,(3.14+D)/2,(rand() % 100)/100.0f ) ;
    sat->setFCamera(F) ;
    list->append(sat);
}

void SatelliteList::speed(double muls)
{
    s*=muls ;
}

bool SatelliteLessThan(const Satellite * v1, const Satellite * v2) {
    return (v1->getY()<v2->getY()) ;
}

void SatelliteList::sortY()
{
    qSort(list->begin(),list->end(),SatelliteLessThan) ;
}

void SatelliteList::setCamera(double AF)
{
    F = AF ;
    for (int i=0; i<list->count(); i++)
        list->at(i)->setFCamera(F) ;
}

void SatelliteList::update(double dt)
{
    for (int i=0; i<list->count(); i++)
        list->at(i)->update(dt*s);
}

Satellite *SatelliteList::getSatellite(int i)
{
    return list->at(i) ;
}

int SatelliteList::getCount()
{
    return list->count() ;
}
