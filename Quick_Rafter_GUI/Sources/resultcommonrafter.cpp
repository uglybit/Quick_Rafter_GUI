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
    ui->verticalLine->setText(QString::number(parameters["Vertical line"], 'f', 2));
    ui->horizotalLine->setText(QString::number(parameters["Horizontal line"], 'f', 2));
    ui->verticalCut->setText(QString::number(parameters["Vertical cut"], 'f', 2));
    ui->horizontalCut->setText(QString::number(parameters["Horizontal cut"], 'f', 2));

    ui->eaveToWallPlate->setText(QString::number(parameters["Eave to wall plate"], 'f', 2));
    ui->wallPlateToPurlin->setText(QString::number(parameters["Wall plate to purlin"], 'f', 2));
    ui->purlinToTop->setText(QString::number(parameters["Purlin to top"], 'f', 2));
    ui->totalLength->setText(QString::number(parameters["Rafter total length"], 'f', 2));
    ui->betaAngle->setText(QString::number(parameters["Beta angle"], 'f', 2));
}

void ResultCommonRafter::setPrintGeometry()
{
    QLabel* printGeometry = getPrintLabel();
    printGeometry->setGeometry(ui->labelPrintCommon->geometry());
    qDebug() << "print geometry form common rafter " << printGeometry->geometry();
}
