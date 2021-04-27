#include "../Headers/resulttruss.h"
#include "ui_resulttruss.h"

ResultTruss::ResultTruss(QWidget *parent, Truss* t) :
    ResultInterface(parent),
    ui(new Ui::ResultTruss), truss(t)
{
    ui->setupUi(this);
    QSize windowSize = size();
    setFileName("Wiezba");
    setFixedSize(windowSize);
    setProfileView();
}

ResultTruss::~ResultTruss()
{
    delete ui;
}

void ResultTruss::setPrintGeometry()
{
    QLabel* printGeometry = getPrintLabel();
    printGeometry->setGeometry(ui->labelPrintTruss->geometry());
    qDebug() << "print geometry from truss " << printGeometry->geometry();
}

void ResultTruss::setProfileView()
{
    double value;
    value = truss->getDimensions()->getBuildingWidth();
    ui->profileBuildingWidth->setText(QString::number(value, 'f', 2));

    value = truss->getDimensions()->getHorizontalEaveLength();
    ui->profileEaveLength->setText(QString::number(value));

    value = truss->getDimensions()->getPurlinPropDistance();
    ui->profilePropDistance->setText(QString::number(value));

    value = truss->getDimensions()->getPurlinLevel();
    ui->profilePurlinLevel->setText(QString::number(value, 'f', 2));

    value = truss->getDimensions()->getCommonRafterHeight();
    ui->profileRafterHeight->setText(QString::number(value));

    value = truss->getDimensions()->getCommRaftTotalLength();
    ui->profileRafterLength->setText(QString::number(value));

    value = truss->getDimensions()->getTrussHeight();
    ui->profileTrussHeight->setText(QString::number(value));

    value = truss->getDimensions()->getWallPlateHeight();
    ui->profileWallPlate->setText(QString::number(value));
}

QLabel *ResultTruss::trussLengthLabel()
{
    return ui->frontTrussWidth;
}

QLabel *ResultTruss::rafterDistanceLabel()
{
    return ui->frontRafterDistance;
}

QLabel *ResultTruss::roofSurfaceLabel()
{
    return ui->frontSurfaceArea;
}

QLabel *ResultTruss::pictureLabel()
{
    return ui->frontLabelPicture;
}

QLabel* ResultTruss::bulidingLengthLabel()
{
    return ui->frontBuildingLength;
}

