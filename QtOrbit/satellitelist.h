#ifndef SATELLITELIST_H
#define SATELLITELIST_H

#include <QList>
#include "satellite.h"

// Список спутников
class SatelliteList
{
private:
    // Скорость изменения времени
    double s ;
    // Угол камеры
    double F ;
    // Список стандартным классом
    QList<Satellite*> * list ;
public:
    SatelliteList();
    // Очистка
    void clear() ;
    // Добавление спутника
    void addSatellite(double R,double D) ;
    // Обновление спутников
    void update(double dt) ;
    // Получение спутника и количества
    Satellite * getSatellite(int i) ;
    int getCount() ;
    // Установка скорости изменения времени
    void speed(double muls) ;
    // Сортировка спутников по удаленности от камеры
    void sortY() ;
    // Установка угла камеры
    void setCamera(double AF) ;
};

#endif // SATELLITELIST_H
