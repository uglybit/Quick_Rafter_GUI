#include "../Headers/resultgableroof.h"
#include "ui_resultgableroof.h"

ResultGableRoof::ResultGableRoof(QWidget *parent, Truss* t) :
    ResultTruss(parent, t),
    ui(new Ui::ResultGableRoof), truss(t)
{
    ui->setupUi(this);
    QSize windowSize = size();
    setFixedSize(windowSize);
    setFrontView();
}

ResultGableRoof::~ResultGableRoof()
{
    delete ui;
}

void ResultGableRoof::setFrontView()
{
    double value;
    value = truss->getDimensions()->getBuildingLength();
    QLabel* labelBuilding = bulidingLengthLabel();
    labelBuilding->setText(QString::number(value, 'f', 2));

    value = truss->getDimensions()->getTrussLength();
    QLabel* labelTruss = trussLengthLabel();
    labelTruss->setText(QString::number(value, 'f', 2));

    value = truss->getDimensions()->getCommonRaftersDistance();
    QLabel* labelRafter = rafterDistanceLabel();
    labelRafter->setText(QString::number(value, 'f', 2));

    value = truss->getDimensions()->getRoofSurfaceArea();
    QLabel* labelSurfaceArea = roofSurfaceLabel();
    labelSurfaceArea->setText(QString::number(value, 'f', 2));
}
