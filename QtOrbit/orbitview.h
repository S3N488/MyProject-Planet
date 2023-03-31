#ifndef ORBITVIEW_H
#define ORBITVIEW_H

#include <QGraphicsView>
#include "satellitelist.h"
#include "planet.h"

// Класс для рисования системы
class OrbitView : public QGraphicsView
{
private:
    // Ссылка на спутники и планету
    SatelliteList * SL ;
    Planet * Pl ;
    // Объект для рисования
    QPainter p;
    // Показывать ли орбиту?
    bool showingorbit ;
    // Позиция камеры - расстояние, угол и вертикаль
    double Z ;
    double F ;
    double V ;
    // Центр экрана в пикселях
    double XC ;
    double YC ;
    // Преобразование координат 3D в 2D
    double mx(double x, double y) ;
    double mz(double z, double y) ;
    double mr(double z, double y) ;
    // Проверка на выход объекта "за спину"
    bool vis(double y);
public:
    OrbitView(QWidget *parent);
    // Установка объектов и параемтров
    void setSatelliteList(SatelliteList * ASL) ;
    void setPlanet(Planet * APl) ;
    void enableShowingOrbit(bool enable) ;
    // Обновить графику
    void refreshView() ;
    // Приближение-удаление
    void zoom(double dz) ;
    // Отрисовка планеты
    void renderPlanet() ;
    // Камера влево-вправо
    void camera(double dF);
    // Вверх-вниз
    void UpDown(double dV) ;
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // ORBITVIEW_H
