#include "../Headers/dimensionslength.h"
#include "ui_dimensionslength.h"

DimensionsLength::DimensionsLength(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DimensionsLength)
{
    ui->setupUi(this);
    QSize windowSize = size();
    setFixedSize(windowSize);
    setSpinPalette();
    setSpinFont();
    setSpinRange();
    setSpinValues();
    ui->buttonApprove->setDefault(true);
}

void DimensionsLength::setSpinPalette()
{
    QPalette palette(QColor(), QColor(), QColor(), QColor(), QColor(), QColor(220, 220, 220), QColor(33, 40, 48));
    ui->spinBuildingLength->setPalette(palette);
    ui->spinTrussLength->setPalette(palette);
}

void DimensionsLength::setSpinFont()
{
    QFont spinFont("MS Shell Dlg 2", 10, -1, false);
    ui->spinBuildingLength->setFont(spinFont);
    ui->spinTrussLength->setFont(spinFont);
}

void DimensionsLength::setSpinRange()
{
    ui->spinBuildingLength->setMaximum(1500);
    ui->spinTrussLength->setMaximum(1700);
}

void DimensionsLength::setSpinValues()
{
    ui->spinBuildingLength->setValue(1000);
    ui->spinTrussLength->setValue(1200);
}

DimensionsLength::~DimensionsLength()
{
    delete ui;
}

void DimensionsLength::on_buttonApprove_clicked()
{
    emit dimensionsLengthAreSet(ui->spinTrussLength->value(), ui->spinBuildingLength->value());
}

void DimensionsLength::on_buttonBack_clicked()
{
    emit dimensionsLengthReject();
}
