#ifndef SATELLITE_H
#define SATELLITE_H

// Класс отдельного спутника
class Satellite
{
private:
    // Период обращения (условного времени)
    const double T = 5 ;
    // Точки орбиты
    double * Aorbit ;
    double * Forbit ;
    // Угол камеры (нужен для перестройки орбиты)
    double Fcamera ;
    // Радиус орбиты
    double R ;
    // Отклонения орбиты
    double Fmin ;
    double Fmax ;
    // Текущее время
    double t ;
    // Вычисление полярных координат
    double A() const ;
    double F() const ;
    // Перестройка орбиты
    void rebuildOrbit();
public:
    Satellite(double AR, double AFmin, double AFmax, double t0p);
    // Обновление состояния
    void update(double dt) ;
    // Получение трехмерных координат из полярных
    double getX() ;
    double getY() const ;
    double getZ() ;
    // То же для точек орбиты
    double getOrbX(int i) ;
    double getOrbY(int i) ;
    double getOrbZ(int i) ;
    // Установка угла камеры
    void setFCamera(double F) ;
    // Число точек орбиты
    const double ORBCNT=25 ;
};

#endif // SATELLITE_H
