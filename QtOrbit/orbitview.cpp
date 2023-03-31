#include "orbitview.h"
#include <math.h>

double minz ;
double maxz ;

// Преобразование координат в проекцию
// Учитывается удаление камеры
// заход объекта "за спину" наблюдателя
// сдвиг камеры по вертикали
// Поворот камеры обрабатывается внутри расчета спутников

double OrbitView::mx(double x, double y)
{
    if (minz>y) minz=y ;
    if (maxz<y) maxz=y ;

    double nz = Z - y ;
    if (nz<1) nz=1 ;
    return XC+10*x/sqrt(nz) ;
}

double OrbitView::mz(double z, double y)
{
    double nz = Z - y ;
    if (nz<1) nz=1 ;

    double deltaV = V ;

    return YC+(10*z+deltaV)/sqrt(nz) ;
}

bool OrbitView::vis(double y)
{
    double nz = Z - y ;
    return (nz>=1);
}

double OrbitView::mr(double r, double y)
{
    double nz = Z - y ;
    if (nz<1) nz=1 ;
    double rr = r/sqrt(nz) ;
    if (rr<1) return 2 ; else return 10*rr ;
}

OrbitView::OrbitView(QWidget *parent):QGraphicsView(parent)
{
    SL = NULL ;
    Pl = NULL ;
    Z = 200.0f ;
    F = 0.0f ;
    V = 0 ;
}

void OrbitView::setSatelliteList(SatelliteList *ASL)
{
    SL = ASL ;
}

void OrbitView::setPlanet(Planet *APl)
{
    Pl = APl ;
}

void OrbitView::enableShowingOrbit(bool enable)
{
    showingorbit=enable ;
}

void OrbitView::refreshView()
{
    hide() ;
    show() ;
}

void OrbitView::zoom(double dz)
{
    Z+=dz ;
    if (Z<0) Z=0 ;
}

void OrbitView::camera(double dF) {
    F+=dF ;
}

void OrbitView::UpDown(double dV)
{
    V+=dV ;
}

void OrbitView::renderPlanet() {

    QPoint P(mx(Pl->getX(),0),mz(Pl->getZ(),0)) ;

    double R = Pl->getR() ;
    double Rz = mr(R,0) ;
    for (int r=Rz; r>3; r-=3) {
        int gr = 255*(cos(asin(r/Rz))) ;
        if (gr>255) gr = 255 ;
        QColor C(0,gr,0) ;
        p.setPen(QPen(C, 1, Qt::SolidLine, Qt::RoundCap));
        p.setBrush(QBrush(C)) ;
        p.drawEllipse(P,r,r);
    }
}

void OrbitView::paintEvent(QPaintEvent *event)
{
    p.begin(viewport());
    p.setRenderHint(QPainter::Antialiasing, true);

    SL->setCamera(F) ;

    // Вычисляем центр экрана
    XC = this->width()/2 ;
    YC = this->height()/2 ;

    p.setPen(QPen(Qt::blue, 1, Qt::SolidLine, Qt::RoundCap));

    p.drawLine(0,YC,this->width(),YC) ;
    p.drawLine(XC,0,XC,this->height()) ;

    // Если заданы планета и спутники
    if ((Pl!=NULL)&&(SL!=NULL)) {

        SL->sortY() ; // Сортируем по удаленности

        bool planetrender = false ;
        for (int i=0; i<SL->getCount(); i++) {
            Satellite * S = SL->getSatellite(i) ;

            // Выводим сначала дальние спутники, потому планету, потом остальные спутники
            if (!planetrender)
                if (S->getY()>Pl->getY()) {
                    planetrender=true ;
                    renderPlanet() ;
                }
            if (vis(S->getY())) {
            p.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::RoundCap));
            p.setBrush(QBrush(Qt::red)) ;
            const QPointF P(mx(S->getX(),S->getY()),mz(S->getZ(),S->getY())) ;
            p.drawEllipse(P,mr(3,S->getY()),mr(3,S->getY()));
            }
        }

        if (!planetrender) renderPlanet() ;

    }

    if (showingorbit)
    if (SL!=NULL) {
        // Отдельно рисуем все точки орбит
        for (int i=0; i<SL->getCount(); i++) {
            Satellite * S = SL->getSatellite(i) ;
            for (int j=0; j<S->ORBCNT-1; j++) {
                p.setPen(QPen(Qt::gray, 1, Qt::SolidLine, Qt::RoundCap));
                QPointF P1(mx(S->getOrbX(j),S->getOrbY(j)),mz(S->getOrbZ(j),S->getOrbY(j))) ;
                QPointF P2(mx(S->getOrbX(j+1),S->getOrbY(j+1)),mz(S->getOrbZ(j+1),S->getOrbY(j+1))) ;
                p.drawLine(P1,P2) ;
            }

        }

    }

    p.end();

}
