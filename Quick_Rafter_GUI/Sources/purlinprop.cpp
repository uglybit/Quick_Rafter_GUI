#include "../Headers/purlinprop.h"
#include "ui_purlinprop.h"

#include <QDebug>

PurlinProp::PurlinProp(QWidget *parent, Dimensions* dimens) :
    Element(parent, dimens),
    ui(new Ui::PurlinProp)
{
    ui->setupUi(this);
    setName("Purlin prop");
    QSize windowSize = size();
    setFixedSize(windowSize);
    setSpinPalette();
    setSpinFont();
    setSpinRange();
    setSpinValues();
    ui->buttonApprove->setDefault(true);
}

PurlinProp::~PurlinProp()
{
    delete ui;
}

void PurlinProp::setSpinPalette()
{
    ui->spinDimemsionA->setPalette(getSpinPalette());
    ui->spinDimesnionB->setPalette(getSpinPalette());
    ui->spinQuantity->setPalette(getSpinPalette());
}

void PurlinProp::setSpinFont()
{
    ui->spinDimemsionA->setFont(getSpinFont());
    ui->spinDimesnionB->setFont(getSpinFont());
    ui->spinQuantity->setFont(getSpinFont());
}

void PurlinProp::setSpinRange()
{

}

void PurlinProp::setSpinValues()
{
    ui->spinDimemsionA->setValue(10);
    ui->spinDimesnionB->setValue(10);
    ui->spinQuantity->setValue(8);
}

void PurlinProp::on_buttonApprove_clicked()
{
    setHeight(ui->spinDimemsionA->value());
    setWidth(ui->spinDimesnionB->value());
    setQuantity(ui->spinQuantity->value());
    setDimensions()->setPurlinDimensions(getHeight());
    setLength(getDimensions()->getPurlinPropLength());
    emit elementIsSet();
    this->close();
}

ElementType PurlinProp::type() const
{
    return ElementType::PurlinProp;
}

void PurlinProp::showParameters() const
{
    //setLength(getDimensions()->getPurlinPropLength());
    showDimensions();
    qDebug() << "\n\t\tquantity: " << getQuantity() ;
}

void PurlinProp::on_buttonBack_clicked()
{
    emit elementRejected();
}
