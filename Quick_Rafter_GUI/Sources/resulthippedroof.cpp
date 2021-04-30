#include "../Headers/resulthippedroof.h"
//#include "ui_resulthippedroof.h"

ResultHippedRoof::ResultHippedRoof(QWidget *parent, Truss* t) :
    ResultTruss(parent, t),
    truss(t)
{
    // don't need user interface
    QSize windowSize = size();
    setFixedSize(windowSize);
    setFrontView();
}

ResultHippedRoof::~ResultHippedRoof()
{

}

void ResultHippedRoof::setFrontView()
{
    double value = truss->getDimensions()->getBuildingLength();
    QLabel* labelBuilding = bulidingLengthLabel();
    labelBuilding->setText(QString::number(value, 'f', 2));
    int posY = labelBuilding->geometry().y();
    QRect rect = labelBuilding->geometry();
    rect.setY(posY - 13);
    labelBuilding->setGeometry(rect);

    value = truss->getDimensions()->getTrussLength();
    QLabel* labelTruss = trussLengthLabel();
    labelTruss->setText(QString::number(value, 'f', 2));
    posY = labelTruss->geometry().y();
    rect = labelTruss->geometry();
    rect.setY(posY + 8);
    labelTruss->setGeometry(rect);

    value = truss->getDimensions()->getCommonRaftersDistance();
    QLabel* labelRafter = rafterDistanceLabel();
    labelRafter->setText(QString::number(value, 'f', 2));
    labelRafter->setGeometry(300, 30, 81, 31);

    QLabel* labelPic = pictureLabel();
    QPixmap pixmap(":/res/ResultHippedFront.PNG");
    labelPic->setPixmap(pixmap);
    labelPic->setScaledContents(true);

    value = truss->getDimensions()->getRoofSurfaceArea();
    QLabel* labelSurfaceArea = roofSurfaceLabel();
    labelSurfaceArea->setText(QString::number(value, 'f', 2));

}
