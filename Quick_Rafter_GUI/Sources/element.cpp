#include "../Headers/element.h"

#include <QDebug>


Element::Element(QWidget *parent, Dimensions* dimens) :
    QDialog(parent), dimensions(dimens)
{

}

ElementType Element::type() const
{
    return ElementType::Element;
}


const Dimensions* Element::getDimensions() const
{
    return dimensions;
}


Dimensions* Element::setDimensions()
{
    return dimensions;
}


void Element::setName(const QString& n)
{
    name = n;
}

void Element::setWidth(const double value)
{
    width = value;
    addParameter("Width", value);
}

void Element::setHeight(const double value)
{
    height = value;
    addParameter("Height", value);
}


void Element::setLength(const double value)
{
    length = value;
    addParameter("Length", value);
}


void Element::setQuantity(const int value)
{
    quantity = value;
    addParameter("Quantity", value);
}


void Element::showDimensions() const
{
    qDebug() << '\n' << name <<  "\n\t(width/height/length): "
         << width << "/" << height << "/" << length;
}


double Element::radiansToDegrees(double value)
{
    return value *= convRadtoDeg;
}


double Element::degreesToRadians(double value)
{
    return value *= convDegToRad;
}


// calculates roof angles
void Element::calculateAngles(double vertical, double horizontal)
{
    double radians = atan(vertical/horizontal);
    alphaAngle = radiansToDegrees(radians);
    betaAngle = 90 - alphaAngle;
    addParameter("Alpha angle", alphaAngle);
    addParameter("Beta angle", betaAngle);
}


double Element::getWidth() const
{
    return width;
}


double Element::getHeight() const
{
    return height;
}


double Element::getAlphaAngle() const
{
    return alphaAngle;
}


double Element::getBetaAngle() const
{
    return betaAngle;
}


double Element::getQuantity() const
{
    return quantity;
}


const QString& Element::getName() const
{
    return name;
}


void Element::addParameter(const QString& name, const double value)
{
    parameters.insert(name, value);
}

const QMap<QString, double> &Element::getParameters() const
{
    return parameters;
}

const QPalette &Element::getSpinPalette() const
{
    return palette;
}

const QFont &Element::getSpinFont() const
{
    return spinFont;
}


