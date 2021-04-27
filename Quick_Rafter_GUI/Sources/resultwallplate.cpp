#include "../Headers/resultwallplate.h"
#include "ui_resultwallplate.h"

#include "QDebug"
#include "QMap"
#include "QPrinter"
#include "QPainter"
#include "QPrintDialog"

ResultWallPlate::ResultWallPlate(QWidget *parent, Element* elem) :
    ResultInterface(parent),
    ui(new Ui::ResultWallPlate), wallPlate(elem)
{
    ui->setupUi(this);
    setFileName("Murlata");
    setView();
}

ResultWallPlate::~ResultWallPlate()
{
    delete ui;
}

void ResultWallPlate::setPrintGeometry()
{
    QLabel* printGeometry = getPrintLabel();
    printGeometry->setGeometry(ui->labelPrintWallPlate->geometry());
}

void ResultWallPlate::setView()
{
    setFixedSize(954,640);
    QMap<QString, double> parameters = wallPlate->getParameters();
    ui->wallPlateHeight->setText(QString::number(parameters["Height"], 'f', 2));
    ui->wallPlateWidth->setText(QString::number(parameters["Width"], 'f', 2));
    ui->wallPlateLength->setText(QString::number(wallPlate->getDimensions()->getTrussLength(), 'f', 2));
}

