#include "../Headers/purlin.h"
#include "ui_purlin.h"

#include <QDebug>

Purlin::Purlin(QWidget *parent, Dimensions* dimens) :
    Element(parent, dimens),
    ui(new Ui::Purlin)
{
    ui->setupUi(this);
    setName("Purlin");
    QSize windowSize = size();
    setFixedSize(windowSize);
    setSpinPalette();
    setSpinFont();
    setSpinRange();
    setSpinValues();
    ui->buttonApprove->setDefault(true);
}

Purlin::~Purlin()
{
    delete ui;
}

void Purlin::setSpinPalette()
{
    ui->spinWidth->setPalette(getSpinPalette());
    ui->spinHieght->setPalette(getSpinPalette());
}

void Purlin::setSpinFont()
{
    ui->spinWidth->setFont(getSpinFont());
    ui->spinHieght->setFont(getSpinFont());
}

void Purlin::setSpinRange()
{

}

void Purlin::setSpinValues()
{
    ui->spinWidth->setValue(10);
    ui->spinHieght->setValue(10);
}

ElementType Purlin::type() const
{
    return ElementType::Purlin;
}


void Purlin::calculateParameters()
{
    setLength(getDimensions()->getBuildingLength());
}

void Purlin::showParameters() const
{
    showDimensions();
}

void Purlin::on_buttonApprove_clicked()
{
    setWidth(ui->spinWidth->value());
    setHeight((ui->spinHieght->value()));
    setDimensions()->setPurlinDimensions(getHeight());
    emit elementIsSet();
    this->close();
}

void Purlin::on_buttonBack_clicked()
{
    qDebug() << "Purlin reject clicked";
    emit elementRejected();
}
