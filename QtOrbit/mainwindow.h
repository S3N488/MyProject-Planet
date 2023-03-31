#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include "orbitview.h"
#include "satellitelist.h"
#include "planet.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void update() ;

    void on_butNew_clicked();

    void on_pushClear_clicked();

    void on_butZPlus_clicked();

    void on_butZMinus_clicked();

    void on_butSPlus_clicked();

    void on_butSMinus_clicked();

    void on_cbShowOrbit_clicked();

    void on_butFPlus_clicked();

    void on_butFMinus_clicked();

    void on_butUp_clicked();

    void on_butDown_clicked();

private:
    Ui::MainWindow *ui;
    // Представление системы на экране
    OrbitView * view ;
    // Список спутников
    SatelliteList * SL ;
    // Планета
    Planet * Pl ;
    // Таймер
    QTimer * timer ;
    // Счетчик времени
    QTime * time ;
    void updateSize() ;
};

#endif // MAINWINDOW_H
