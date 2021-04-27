#include "../Headers/truss.h"
#include "ui_truss.h"

#include <QDebug>

Truss::Truss(QWidget *parent, Dimensions* dimens) :
    QDialog(parent), dimensions(dimens)
{
    WallPlate* newElement = new WallPlate(this, dimens);
    addElementToTruss(newElement);
    connect(newElement, &Element::elementIsSet, this, &Truss::wallPlateIsSet);
    connect(newElement, &Element::elementRejected, this, &Truss::on_wallPlateReject);
    newElement->show();
}

Truss::~Truss()
{
    for (auto a : elements) {
        if (a != nullptr) {
            delete a;
        }
    }
}

TrussType Truss::type() const
{
    return TrussType::Truss;
}

void Truss::wallPlateIsSet()
{
    qDebug() << "Received signal: wall plate is set";
    qDebug() << "wall plate level: " << getDimensions()->getWallPlateHeight();
    qDebug() << "width: " << elements[0]->getWidth();
    qDebug() << "height: " << elements[0]->getHeight();
    CommonRafter* newElement = new CommonRafter(this, dimensions);
    addElementToTruss(newElement);
    connect(newElement, &Element::elementIsSet, this, &Truss::commonRafterIsSet);
    connect(newElement, &Element::elementRejected, this, &Truss::on_commonRafterReject);
    newElement->show();
}

void Truss::commonRafterIsSet()
{
    qDebug() << "Received signal: common rafter is set: ";
    qDebug() << getDimensions()->getCommonRafterHeight();
    qDebug() << getDimensions()->getCommonRafterWidth();
    qDebug() << getDimensions()->getCommonRaftersDistance();
    calcCommonRaftersDistance();
    emit trussIsReady();
}

void Truss::on_commonRafterReject()
{
    qDebug() << "Received signal: common reject";
    qDebug() << elements.back();
    removeLastElement();
    elements.back()->show();
}

void Truss::on_wallPlateReject()
{
    qDebug() << "Received signal: wall plate reject";
    removeLastElement();
    emit trussIsRejected();
}

void Truss::addElementToTruss(Element *elem)
{
    elements.push_back(elem);
}

Element* Truss::getLastElement()
{
    if(elements.size() > 0) {
        return elements.back();
    }
    else {
        return nullptr;
    }

}

Element* Truss::getElement(unsigned position)
{
    if (position < elements.size()) {
         return elements.at(position);
    }
    else {
        return nullptr;
    }
}

int Truss::size()
{
    return elements.size();
}

const Dimensions* Truss::getDimensions() const
{
    return dimensions;
}


Dimensions* Truss::setDimensions()
{
    return dimensions;
}

void Truss::removeLastElement()
{
    elements.back()->close();
    delete elements.back();
    elements.erase(elements.end()-1);
}

// wywoluje funkcje obliczajca dla kazdego elementu
void Truss::calcParam()
{
    for (auto a : elements) {
        a->calculateParameters();
    }
}

// shows all elements in the truss
void Truss::showTruss()
{
    getInitialDimensions();

    for (auto a : elements ) {
        a->showParameters();
    }

    qDebug() << "\nCommon rafters distance: "
       << getDimensions()->getCommonRaftersDistance();

    qDebug() << "\nRoof surface area: "
         << calcArea() << " m2" ;
}

void Truss::getInitialDimensions() const
{
    qDebug() << "Initial dimensions: \n";
    qDebug() << "\n\tBuliding length: " << getDimensions()->getBuildingLength();
    qDebug() << "\n\tBuliding width: " << getDimensions()->getBuildingWidth();
    qDebug() << "\n\tTruss height: " << getDimensions()->getTrussHeight();
    qDebug() << "\n\tTruss length: " << getDimensions()->getTrussLength();
    qDebug() << "\n\tWall plate level: " << getDimensions()->getWallPlateHeight();
    qDebug() << "\n\tPurlin prop distance: " << getDimensions()->getPurlinPropDistance();
    qDebug() << "\n\tHorizontal eave length: " << getDimensions()->getHorizontalEaveLength();
    qDebug() << "\n\tCommon rafter height: " << getDimensions()->getCommonRafterHeight();
    qDebug() << "\n\tCommon rafter width: " << getDimensions()->getCommonRafterWidth();
    qDebug() << "\n\tHip rafter height: " << getDimensions()->getHipHeight();
    qDebug() << "\n\tHip rafter width: " << getDimensions()->getHipWidth() ;
}

double Truss::calcCommonRaftersDistance()
{
    double trussLength = getDimensions()->getTrussLength();
    int numberOfRafters = trussLength /
        (getDimensions()->getCommonRafterWidth() +
            getDimensions()->getCommonRaftersDistance());
    numberOfRafters += 1;
    double rafterDistance = (trussLength / numberOfRafters);
    setDimensions()->setCommonRafterDistance(rafterDistance);
    return rafterDistance;
}

// calculates roof surface area
double Truss::calcArea()
{
    double height = getDimensions()->getCommRaftTotalLength();
    double width = getDimensions()->getTrussLength();
    double surfaceArea = height * width * 2;
    surfaceArea /= 10000; // przeliczenie na m^2
    setDimensions()->setRoofSurfaceArea(surfaceArea);
    return surfaceArea;
}

void Truss::setTrussType(const QString& type)
{
    trussType = type;
}

const QString& Truss::getTrussType() const
{
    return trussType;
}
