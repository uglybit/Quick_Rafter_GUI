#include "../Headers/wallplate.h"
#include "ui_wallplate.h"

WallPlate::WallPlate(QWidget *parent, Dimensions* dim) :
     Element(parent, dim),
    ui(new Ui::WallPlate)
{
    ui->setupUi(this);
    setName("Wall plate");
    QSize windowSize = size();
    setFixedSize(windowSize);
    setSpinPalette();
    setSpinFont();
    setSpinRange();
    setSpinValues();
    ui->buttonApprove->setDefault(true);
}

WallPlate::~WallPlate()
{
    delete ui;
}

void WallPlate::setSpinPalette()
{
    ui->spinWidth->setPalette(getSpinPalette());
    ui->spinHeight->setPalette(getSpinPalette());
}

void WallPlate::setSpinFont()
{
    ui->spinWidth->setFont(getSpinFont());
    ui->spinHeight->setFont(getSpinFont());
}

void WallPlate::setSpinRange()
{

}

void WallPlate::setSpinValues()
{
    ui->spinWidth->setValue(12);
    ui->spinHeight->setValue(12);
}

ElementType WallPlate::type() const
{
    return ElementType::WallPlate;
}

void WallPlate::showParameters() const
{
    showDimensions();
}


void WallPlate::calculateParameters()
{
    setLength(getDimensions()->getTrussLength());
    // dla hipped roof wymiar bedzie inny
}

void WallPlate::on_buttonApprove_clicked()
{
    setWidth(ui->spinWidth->value());
    setHeight(ui->spinHeight->value());
    emit elementIsSet();
    this->close();
}

void WallPlate::on_buttonBack_clicked()
{
    emit elementRejected();
}
