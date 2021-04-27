#include "../Headers/resultpurlinprop.h"
#include "ui_resultpurlinprop.h"

#include "QDebug"
#include "QMap"
#include "QPrinter"
#include "QPainter"
#include "QPrintDialog"

ResultPurlinProp::ResultPurlinProp(QWidget *parent, Element* elem) :
    ResultInterface(parent),
    ui(new Ui::ResultPurlinProp), purlinProp(elem)
{
    ui->setupUi(this);
    setFileName("Slup");
    setView();
}

ResultPurlinProp::~ResultPurlinProp()
{
    delete ui;
}

void ResultPurlinProp::setView()
{
    setFixedSize(954,640);
    QMap<QString, double> parameters = purlinProp->getParameters();
    ui->purlinPropHeight->setText(QString::number(parameters["Height"], 'f', 2));
    ui->purlinPropWidth->setText(QString::number(parameters["Width"], 'f', 2));
    ui->purlinPropLength->setText(QString::number(purlinProp->getDimensions()->getPurlinPropLength(), 'f', 2));
}

void ResultPurlinProp::setPrintGeometry()
{
    QLabel* printGeometry = getPrintLabel();
    printGeometry->setGeometry(ui->labelPrintPurlinProp->geometry());
}
