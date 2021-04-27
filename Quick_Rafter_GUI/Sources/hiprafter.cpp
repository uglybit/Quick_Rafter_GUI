#include "../Headers/hiprafter.h"
#include "ui_hiprafter.h"
#include <QDebug>

HipRafter::HipRafter(QWidget *parent, Dimensions* dimens) :
    CommonRafter(dimens, parent),
    ui(new Ui::HipRafter)
{
    ui->setupUi(this);
    setName("Hip rafter");
    QSize windowSize = size();
    setFixedSize(windowSize);
    setSpinPalette();
    setSpinFont();
    setSpinRange();
    setSpinValues();
    ui->buttonApproveHip->setDefault(true);
}

HipRafter::~HipRafter()
{
    delete ui;
}

void HipRafter::setSpinPalette()
{
    ui->spinHieght->setPalette(getSpinPalette());
    ui->spinWidth->setPalette(getSpinPalette());
}

void HipRafter::setSpinFont()
{
    ui->spinHieght->setFont(getSpinFont());
    ui->spinWidth->setFont(getSpinFont());
}

void HipRafter::setSpinRange()
{

}

void HipRafter::setSpinValues()
{
    ui->spinHieght->setValue(22);
    ui->spinWidth->setValue(14);
}

void HipRafter::on_buttonApproveHip_clicked()
{
    setHeight(ui->spinHieght->value());
    setWidth(ui->spinWidth->value());
    setDimensions()->setHipWidth(getWidth());
    setDimensions()->setHipHeight(getHeight());
    emit elementIsSet();
    qDebug() << "Emiting signal: hiprafter approved";
    this->close();
}


void HipRafter::on_buttonBack_clicked()
{
    emit elementRejected();
}


ElementType HipRafter::type() const
{
    return  ElementType::HipRafter;
}

void HipRafter::calculateHipRafterDimensions() {

    double eave = getDimensions()->getHorizontalEaveLength();
    double propDistance = getDimensions()->getPurlinPropDistance();
    double buildWidth = getDimensions()->getBuildingWidth() / 2;

    eave *= sqrt(2);
    propDistance *= sqrt(2);
    buildWidth *= sqrt(2);

    double cosValue = cos(degreesToRadians(getAlphaAngle()));
    setEaveToWallPlate(eave/cosValue);
    addParameter("Eave to wall plate", getEaveToWallPlate());

    setWallPlateToPurlin(propDistance/cosValue);
    addParameter("Wall plate to purlin", getWallPlateToPurlin());

    double dist = buildWidth - propDistance;
    setPurlinToTop(dist/cosValue);
    addParameter("Purlin to top", getPurlinToTop());

    setWallPlateToTop(buildWidth/cosValue);
    addParameter("Wall plate to top", getwallPlateToTop());

    setRafterTotalLength((buildWidth + eave)/cosValue);
    addParameter("Rafter total length", getRafterTotalLength());
 
    setDimensions()->setHipRaftTotalLength(getRafterTotalLength());
}

void HipRafter::calculateParameters()
{
    double horizontal = sqrt(2) * (getDimensions()->getBuildingWidth() / 2);
    double vertical =
        getDimensions()->getTrussHeight() -
        getDimensions()->getWallPlateHeight() -
        getDimensions()->getRafterAboveWallPlat();

    calculateAngles(vertical, horizontal);
    calculateVerticalLine(getDimensions()->getHipHeight());
    double vertCut = getAngleVerticalLine() - getDimensions()->getRafterAboveWallPlat();
    setVerticalCut(vertCut);
    addParameter("Vertical cut", vertCut); 
    calculateHorizontalLine(getDimensions()->getHipHeight());
    calculateHorizontalCut();

    cutToSquare();
    calculateHipRafterDimensions(); 
    addToEdges();
}

// second cut - square in axis
void HipRafter::cutToSquare()
{
    double hipWidth = getDimensions()->getHipWidth();
    double correction = tan(degreesToRadians(getAlphaAngle())) * (0.5 * hipWidth);

    verticalCutToSquare = getVerticalCut() + correction;
    addParameter("Vertical cut to square", verticalCutToSquare);

    horizontalCutToSquare = verticalCutToSquare / tan(degreesToRadians(getAlphaAngle()));
    addParameter("Horizontal cut to square", horizontalCutToSquare);

    setRafterAboveWallPlate(getDimensions()->getRafterAboveWallPlat());
    angleCutToSquare = (0.5 * getDimensions()->getHipWidth()) * sqrt(2);
    addParameter("Angle cut to square", angleCutToSquare);
}

void HipRafter::addToEdges()
{
    double cosValue = cos(degreesToRadians(getAlphaAngle()));
    double rafterWidth = getDimensions()->getHipWidth();

    setAdditionToEgdes((rafterWidth * 0.5) / cosValue);
    setRafterTotalOnEdges(getRafterTotalLength() + getAdditionToEgdes());
}

void HipRafter::showParameters() const
{
    CommonRafter::showParameters();
    showHipParameters();
}


void HipRafter::showHipParameters() const
{
    qDebug() << "\n\t-vertical Cut To Square: " << verticalCutToSquare << "\n";
    qDebug() << "\t-horizontal Cut To Square: " << horizontalCutToSquare << "\n";
    qDebug() << "\t-angle Cut To Square: " << angleCutToSquare ;
}


void HipRafter::setAdditionToEgdes(const double addition)
{
    additionToEgdes = addition;
    addParameter("Additon to edges", getAdditionToEgdes());
}


void HipRafter::setRafterTotalOnEdges(const double totalEgdes)
{
    rafterTotalOnEdges = totalEgdes;
    addParameter("Total on edges", getRafterTotalOnEdges());
}


double HipRafter::getAdditionToEgdes() const
{
    return additionToEgdes;
}


double HipRafter::getRafterTotalOnEdges() const
{
    return rafterTotalOnEdges;
}
