#ifndef CONSTANTS_H
#define CONSTANTS_H

// Модуль констант общих

class Const {
public:
    // Число Пи
    constexpr const static double PI = 3.14 ;
    constexpr const static double PI2 = 6.28 ;
    // Минимальное отклонение от экваториальной орбиты
    constexpr const static int RMIN = 110 ;
    // Максимальное отклонение от экваториальной орбиты
    constexpr const static int RMAX = 150 ;
    // Радиус планеты
    constexpr const static int RPLANET = 100 ;
    // Шаг камеры по вертикали
    constexpr const static double DVERT = 100.0f ;
    // Шаг камеры по горизонтали
    constexpr const static double FPLUS = 3.14/10 ;
    // Шаг камеры по приближению-удалению
    constexpr const static double ZPLUS = 10.0f ;
};

#endif // CONSTANTS_H
