#include "../Headers/resultcommonrafter.h"
#include "ui_resultcommonrafter.h"

#include "QDebug"
#include "QMap"
#include "QPrinter"
#include "QPainter"
#include "QPrintDialog"

ResultCommonRafter::ResultCommonRafter(QWidget *parent, Element* elem) :
    ResultInterface(parent),
    ui(new Ui::ResultCommonRafter), commonRafter(elem)
{
    ui->setupUi(this);
    setView();
    setFileName("Krokiew_zwykla");
}

ResultCommonRafter::~ResultCommonRafter()
{
    delete ui;
}

void ResultCommonRafter::setView()
{
    setFixedSize(954,640);
    QMap<QString, double> parameters = commonRafter->getParameters();
    ui->verticalLine->setText(QString::number(parameters["Vertical line"]));
    ui->horizotalLine->setText(QString::number(parameters["Horizontal line"]));
    ui->verticalCut->setText(QString::number(parameters["Vertical cut"]));
    ui->horizontalCut->setText(QString::number(parameters["Horizontal cut"]));

    ui->eaveToWallPlate->setText(QString::number(parameters["Eave to wall plate"]));
    ui->wallPlateToPurlin->setText(QString::number(parameters["Wall plate to purlin"]));
    ui->purlinToTop->setText(QString::number(parameters["Purlin to top"]));
    ui->totalLength->setText(QString::number(parameters["Rafter total length"]));
    ui->betaAngle->setText(QString::number(parameters["Beta angle"]));
}

void ResultCommonRafter::setPrintGeometry()
{
    QLabel* printGeometry = getPrintLabel();
    printGeometry->setGeometry(ui->labelPrintCommon->geometry());
    qDebug() << "print geometry form common rafter " << printGeometry->geometry();
}
