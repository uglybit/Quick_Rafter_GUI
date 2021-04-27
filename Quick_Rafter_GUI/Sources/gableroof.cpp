#include "../Headers/gableroof.h"

#include <QDebug>

GableRoof::GableRoof(QWidget *parent, Dimensions* dim) : Truss(parent, dim), dimensions(dim)
{
    setTrussType("Gable roof");
    connect(this, &Truss::trussIsReady, this, &GableRoof::on_trussConstructed);
}

TrussType GableRoof::type() const
{
    return TrussType::GableRoof;
}

void GableRoof::on_trussConstructed()
{
    qDebug() << "Signal received: truss is ready ";
    Purlin* newElement = new Purlin(this, dimensions);
    addElementToTruss(newElement);
    connect(newElement, &Element::elementIsSet, this, &GableRoof::on_purlinIsSet);
    connect(newElement, &Element::elementRejected, this, &GableRoof::on_purlinReject);
    newElement->show();

}

void GableRoof::on_purlinReject()
{
    qDebug() << "Signal received: purlin reject";
    qDebug() << getLastElement();
    removeLastElement();
    getLastElement()->show();
}

void GableRoof::on_purlinIsSet()
{
    qDebug() << "Signal received: purlin is set ";
    PurlinProp* newElement = new PurlinProp(this, dimensions);
    addElementToTruss(newElement);
    connect(newElement, &Element::elementIsSet, this, &GableRoof::on_purlinPropIsSet);
    connect(newElement, &Element::elementRejected, this, &GableRoof::on_purlinPropReject);
    newElement->show();
}

void GableRoof::on_purlinPropIsSet()
{
    qDebug() << "Signal received: purlin prop is set ";
    emit gableRoofIsReady();
    this->close();
}

void GableRoof::on_purlinPropReject()
{
    qDebug() << "Signal received: purlin prop reject";
    qDebug() << getLastElement();
    removeLastElement();
    getLastElement()->show();
}




