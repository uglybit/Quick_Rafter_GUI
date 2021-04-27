#include "../Headers/resultpurlin.h"
#include "ui_resultpurlin.h"
#include "QDebug"
#include "QMap"
#include "QPrinter"
#include "QPainter"
#include "QPrintDialog"

ResultPurlin::ResultPurlin(QWidget *parent, Element* elem) :
    ResultInterface(parent),
    ui(new Ui::ResultPurlin), purlin(elem)
{
    ui->setupUi(this);
    setFileName("Platew");
    setView();
}

ResultPurlin::~ResultPurlin()
{
    delete ui;
}

void ResultPurlin::setView()
{
    setFixedSize(954,640);
    QMap<QString, double> parameters = purlin->getParameters();
    ui->purlinHeight->setText(QString::number(parameters["Height"], 'f', 2));
    ui->purlinWidth->setText(QString::number(parameters["Width"], 'f', 2));
    ui->purlinLength->setText(QString::number(purlin->getDimensions()->getTrussLength(), 'f', 2));
}

void ResultPurlin::setPrintGeometry()
{
    QLabel* printGeometry = getPrintLabel();
    printGeometry->setGeometry(ui->labelPrintPurlin->geometry());
}
