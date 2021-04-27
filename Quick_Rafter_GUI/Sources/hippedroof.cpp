#include "../Headers/hippedroof.h"

#include <QDebug>

// dach kopertowy
HippedRoof::HippedRoof(QWidget *parent, Dimensions* dim) : GableRoof(parent, dim), dimensions(dim)
{
    setTrussType("Hipped roof");
    connect(this, &GableRoof::gableRoofIsReady, this, &HippedRoof::on_gableRoofIsSet);
}

TrussType HippedRoof::type() const
{
    return TrussType::HippedRoof;
}

void HippedRoof::on_gableRoofIsSet()
{
    qDebug() << "Signal received: gable roof is set ";
    HipRafter* newElement = new HipRafter(this, dimensions);
    addElementToTruss(newElement);
    connect(newElement, &Element::elementIsSet, this, &HippedRoof::on_hipRafterIsSet);
    connect(newElement, &Element::elementRejected, this, &HippedRoof::on_hipRafterReject);
    newElement->show();
}

void HippedRoof::on_hipRafterIsSet()
{
    emit hippedRoofIsReady();
}

void HippedRoof::on_hipRafterReject()
{
    qDebug() << "Signal received: hip rafter reject";
    qDebug() << getLastElement();
    removeLastElement();
    getLastElement()->show();
}
