#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создание всех объектов
    SL = new SatelliteList() ;

    Pl = new Planet(Const::RPLANET) ;

    view = new OrbitView(this) ;
    view->setSatelliteList(SL);
    view->setPlanet(Pl) ;
    view->enableShowingOrbit(ui->cbShowOrbit->checkState()==Qt::Checked);
    updateSize() ;

    time = new QTime() ;
    time->start() ;

    // Таймер и его сигнал
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    timer->start(10) ;

}

MainWindow::~MainWindow()
{
    // Очистка объектов
    delete view ;
    delete time ;
    delete timer ;
    delete SL ;
    delete ui;
}

void MainWindow::update()
{
    // Получаем время, прошедшее
    double dt = time->elapsed() ;
    time->start() ;

    dt /= 1000 ;

    // Обновляем систему и графику
    SL->update(dt) ;
    view->refreshView();
}

void MainWindow::updateSize()
{
    // Позиционирование графики
    const int LEFTPANEL=200 ;
    view->setGeometry(QRect(LEFTPANEL, 20, this->width()-LEFTPANEL-10, this->height()-20-10));
    view->refreshView();
}

void MainWindow::on_butNew_clicked()
{
    SL->addSatellite(Const::RMIN+(rand() % (Const::RMAX-Const::RMIN)),0+(rand() % 50)/50.0f);
}

void MainWindow::on_pushClear_clicked()
{
    SL->clear();
}

void MainWindow::on_butZPlus_clicked()
{
    view->zoom(-Const::ZPLUS) ;
}

void MainWindow::on_butZMinus_clicked()
{
    view->zoom(+Const::ZPLUS) ;
}

void MainWindow::on_butSPlus_clicked()
{
    SL->speed(2.0f) ;
}

void MainWindow::on_butSMinus_clicked()
{
    SL->speed(0.5f) ;
}

void MainWindow::on_cbShowOrbit_clicked()
{
    view->enableShowingOrbit(ui->cbShowOrbit->checkState()==Qt::Checked);
}

void MainWindow::on_butFPlus_clicked()
{
    view->camera(+Const::FPLUS) ;
}

void MainWindow::on_butFMinus_clicked()
{
    view->camera(-Const::FPLUS) ;
}

void MainWindow::on_butUp_clicked()
{
    view->UpDown(Const::DVERT) ;
}

void MainWindow::on_butDown_clicked()
{
    view->UpDown(-Const::DVERT) ;
}
