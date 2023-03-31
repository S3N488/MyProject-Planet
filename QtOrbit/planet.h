#ifndef PLANET_H
#define PLANET_H

// Класс планеты
class Planet
{
private:
    // Радиус
    double R ;
public:
    Planet(double AR);
    // Координаты и радиус
    double getR() ;
    double getX() ;
    double getY() ;
    double getZ() ;
};

#endif // PLANET_H
