#include "../Headers/result.h"
#include "ui_result.h"
#include "QDebug"
#include "QPrinter"
#include "QPainter"
#include "QPrintDialog"

Result::Result(QWidget *parent, Truss* t) :
    QDialog(parent),
    ui(new Ui::Result),  truss(t)
{
    ui->setupUi(this);
    QSize windowSize = size();
    setFixedSize(windowSize);
    setUpButtons();
    ui->buttonTruss->setDefault(true);
}

Result::~Result()
{
    delete ui;
}

void Result::setUpButtons()
{
    ui->buttonHipRafter->setEnabled(false);

    int size = truss->size();
    for (int i = 0; i < size; i++) {
        Element* currentElement;
        currentElement = truss->getElement(i);

        switch(currentElement->type())
        {
            case ElementType::CommonRafter:
                commonRafter = currentElement;
            break;
            case ElementType::HipRafter:
                hipRafter = currentElement;
                ui->buttonHipRafter->setEnabled(true);
            break;
            case ElementType::WallPlate:
                wallPlate = currentElement;
            break;
            case ElementType::Purlin:
                purlin = currentElement;
            break;
            case ElementType::PurlinProp:
                purlinProp = currentElement;
            break;
            default: break;
        }
    }
}

void Result::on_buttonTruss_clicked()
{
    switch(truss->type())
    {
        case TrussType::GableRoof:
            resultTruss = new ResultGableRoof(this, truss);
            resultTruss->show();
            break;
        case TrussType::HippedRoof:
            resultTruss = new ResultHippedRoof(this, truss);
            resultTruss->show();
            break;
        default: break;
    }
}

void Result::on_buttonCommonRafter_clicked()
{
    resCommRafter = new ResultCommonRafter(this, commonRafter);
    resCommRafter->show();
}

void Result::on_buttonWallPlate_clicked()
{
    resWallPlate = new ResultWallPlate(this, wallPlate);
    resWallPlate->show();
}

void Result::on_buttonHipRafter_clicked()
{
    resHipRafter = new ResultHipRafter(this, hipRafter);
    resHipRafter->show();
}

void Result::on_buttonPurlin_clicked()
{
    resPurlin = new ResultPurlin(this, purlin);
    resPurlin->show();
}

void Result::on_buttonPurlinProp_clicked()
{
    resPurlinprop = new ResultPurlinProp(this, purlinProp);
    resPurlinprop->show();
}

void Result::on_buttonClose_clicked()
{
    emit resultClosed();
}
