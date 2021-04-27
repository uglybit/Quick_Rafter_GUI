#include "../Headers/resulthiprafter.h"
#include "ui_resulthiprafter.h"

#include "QMap"
#include "QDebug"
#include "QPrinter"
#include "QPainter"
#include "QPrintDialog"

ResultHipRafter::ResultHipRafter(QWidget *parent, Element* elem) :
    ResultInterface(parent),
    ui(new Ui::ResultHipRafter), hipRafter(elem)
{
    ui->setupUi(this);
    setFileName("Krokiew_narozna");
    QSize windowSize = size();
    setFixedSize(windowSize);
    setProfileView();
    setAxisView();
}

ResultHipRafter::~ResultHipRafter()
{
    delete ui;
}

void ResultHipRafter::setPrintGeometry()
{
    QLabel* printGeometry = getPrintLabel();
    printGeometry->setGeometry(ui->labelPrintHip->geometry());
    qDebug() << "print geometry form hip rafter " << printGeometry->geometry();
}

void ResultHipRafter::setProfileView()
{
    QMap<QString, double> params = hipRafter->getParameters();

    QMap<QString, double>::const_iterator i = params.constBegin();
    while (i != params.constEnd()) {
        qDebug() << i.key() << ": " << i.value() << Qt::endl;
        ++i;
    }

    ui->HipHeight->setText(QString::number(params["Height"], 'f', 2));
    ui->hipWidth->setText(QString::number(params["Width"]));

    ui->angleHorizontalCut->setText(QString::number(params["Angle cut to square"], 'f', 2));
    ui->horizontalCutInside->setText(QString::number(params["Horizontal cut to square"], 'f', 2));
    ui->horizontalCutOutside->setText(QString::number(params["Horizontal cut"], 'f', 2));
    ui->horizontalLine->setText(QString::number(params["Horizontal line"], 'f', 2));
    ui->verticalCutInside->setText(QString::number(params["Vertical cut to square"], 'f', 2));

    ui->verticalCutOutside->setText(QString::number(params["Vertical cut"], 'f', 2));
    ui->verticalLine->setText(QString::number(params["Vertical line"], 'f', 2));

}

void ResultHipRafter::setAxisView()
{
    QMap<QString, double> params = hipRafter->getParameters();
    ui->alphaAngle->setText(QString::number(params["Alpha angle"], 'f', 2));
    ui->betaAngle->setText(QString::number(params["Beta angle"], 'f', 2));
    ui->eaveLength->setText(QString::number(params["Horizontal eave length"], 'f', 2));
    ui->eaveToWallPlate->setText(QString::number(params["Eave to wall plate"], 'f', 2));
    ui->purlinToTop->setText(QString::number(params["Purlin to top"], 'f', 2));
    ui->totalLength->setText(QString::number(params["Rafter total length"], 'f', 2));
    ui->wallPlateToPurlin->setText(QString::number(params["Wall plate to purlin"], 'f', 2));
    ui->wallPlateToTop->setText(QString::number(params["Wall plate to top"], 'f', 2));
}

