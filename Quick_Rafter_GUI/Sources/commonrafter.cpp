#include "../Headers/commonrafter.h"
#include "ui_commonrafter.h"
#include <QDebug>

 CommonRafter:: CommonRafter(QWidget *parent, Dimensions* dim) :
     Element(parent, dim),
    ui(new Ui:: CommonRafter)
{
    ui->setupUi(this);
    setName("Common rafter");

    QSize windowSize = size();
    setFixedSize(windowSize);
    setSpinPalette();
    setSpinFont();
    setSpinRange();
    setSpinValues();
    ui->buttonApprove->setDefault(true);
}

 // this constructor is is working when cunstructs hip rafter
 CommonRafter:: CommonRafter(Dimensions* dim, QWidget *parent) :
     Element(parent, dim)
{
    horizontalEaveLength = getDimensions()->getHorizontalEaveLength() * sqrt(2);
    addParameter("Horizontal eave length", horizontalEaveLength);
}

 CommonRafter::~ CommonRafter()
{
    if (ui) {
        delete ui;
    }
}

 void CommonRafter::setSpinPalette()
 {
     ui->spinCommonWidth->setPalette(getSpinPalette());
     ui->spinCommonHeight->setPalette(getSpinPalette());
     ui->spinRafterDistance->setPalette(getSpinPalette());
 }

 void CommonRafter::setSpinFont()
 {
     ui->spinCommonWidth->setFont(getSpinFont());
     ui->spinCommonHeight->setFont(getSpinFont());
     ui->spinRafterDistance->setFont(getSpinFont());
 }

 void CommonRafter::setSpinRange()
 {

 }

 void CommonRafter::setSpinValues()
 {
     ui->spinCommonWidth->setValue(9);
     ui->spinCommonHeight->setValue(18);
     ui->spinRafterDistance->setValue(80);
 }

 void CommonRafter::on_buttonApprove_clicked()
 {
     setWidth(ui->spinCommonWidth->value());
     setHeight(ui->spinCommonHeight->value());
     setParameters();
     emit elementIsSet();
     this->close();
 }

 void CommonRafter::on_buttonBack_clicked()
 {
     emit elementRejected();
 }

ElementType CommonRafter::type() const {
    return ElementType::CommonRafter;
}


void CommonRafter::setParameters()
{
    setDimensions()->setCommonRafterWidth(getWidth());
    setDimensions()->setCommonRafterHeight(getHeight());
    setDimensions()->setCommonRafterDistance(ui->spinRafterDistance->value());
    horizontalEaveLength = getDimensions()->getHorizontalEaveLength();
    addParameter("Horizontal eave length", horizontalEaveLength);
}


void CommonRafter::calculateParameters()
{
    // calculating initial roof angles and dimensions
    double height = getDimensions()->getTrussHeight() - getDimensions()->getWallPlateHeight();
    double width = getDimensions()->getBuildingWidth()/2;
    calculateAngles(height, width);
    calculateVerticalLine(getDimensions()->getCommonRafterHeight()); // dlugosc pionowej kreski na krokwi
    calculateVerticalCut(); // dlugosc zaciecia

    // final calculations
    calculateRafterAboveWallPlatt();
    calculateAngles(height - rafterAboveWallPlat, width);
    calculateVerticalLine(getDimensions()->getCommonRafterHeight());
    calculateProperVerticalCut();
    calculateHorizontalLine(getDimensions()->getCommonRafterHeight());
    calculateHorizontalCut();
    calculatePurlinAndPropLength();
    calculateCommonRafterDimensions();
}


void CommonRafter::calculateVerticalLine(double value)
{
    angleVerticalLine = value/sin(degreesToRadians(getBetaAngle()));
    addParameter("Vertical line", angleVerticalLine);
}

void CommonRafter::calculateHorizontalLine(double value)
{
    angleHorizontalLine = value/sin(degreesToRadians(getAlphaAngle()));
    addParameter("Horizontal line", angleHorizontalLine);
}

// initial cut
void CommonRafter::calculateVerticalCut()
{
    verticalCut = angleVerticalLine * CUTTING_RATIO;
}

void CommonRafter::calculateRafterAboveWallPlatt()
{
    rafterAboveWallPlat = angleVerticalLine - verticalCut;
    setDimensions()->setRafterAboveWallPlat(rafterAboveWallPlat);
    addParameter("Rafter above wall plate", rafterAboveWallPlat);
}

// wlasciwa dlugosc zaciecia w pionie
void CommonRafter::calculateProperVerticalCut()
{
    verticalCut = angleVerticalLine - rafterAboveWallPlat;
    addParameter("Vertical cut", verticalCut);
}

void CommonRafter::calculatePurlinAndPropLength()
{
    double pPropDist = getDimensions()->getPurlinPropDistance();
    double tgAngle = tan(degreesToRadians(getAlphaAngle()));
    double wallPlateHeight = getDimensions()->getWallPlateHeight();
    double purlinDim = getDimensions()->getPurlinDimensions();
    double propLength = tgAngle* pPropDist + wallPlateHeight - purlinDim;
    setDimensions()->setPurlinPropLength(propLength);

    double purDim = getDimensions()->getPurlinDimensions();
    setDimensions()->setPurlinLevel(purDim + propLength);
}

void CommonRafter::calculateHorizontalCut()
{
    horizontalCut = verticalCut/tan(degreesToRadians(getAlphaAngle()));
    addParameter("Horizontal cut", horizontalCut);
}

void CommonRafter::calculateCommonRafterDimensions()
{
    // DIMENSION EAVE - WALL PLATE
    double eave = getDimensions()->getHorizontalEaveLength();
    double propDistance = getDimensions()->getPurlinPropDistance();
    double buildWidth = getDimensions()->getBuildingWidth() / 2;

    double cosValue = cos(degreesToRadians(getAlphaAngle()));
    eaveToWallPlate = eave/cosValue;
    addParameter("Eave to wall plate", eaveToWallPlate);

    wallPlateToPurlin = propDistance/cosValue;
    addParameter("Wall plate to purlin", wallPlateToPurlin);

    double dist = buildWidth - propDistance;
    purlinToTop = dist/cosValue;
    addParameter("Purlin to top", purlinToTop);

    wallPlateToTop = buildWidth/cosValue;
    addParameter("Wall plate to top", wallPlateToTop);

    rafterTotalLength = (buildWidth + eave)/cosValue;
    setDimensions()->setCommRaftTotalLength(rafterTotalLength);
    addParameter("Rafter total length", rafterTotalLength);
}

void CommonRafter::showParameters() const
{
    qDebug() << "\n\n" << getName() << " parameters:"  << "\n";
    qDebug() << "\t-rafter Above WallPlat: " << rafterAboveWallPlat << "\n";
    qDebug() << "\t-angle Vertical Line: " << angleVerticalLine << "\n";
    qDebug() << "\t-angle Horizontal Line: " << angleHorizontalLine << "\n";
    qDebug() << "\t-horizontal Eave Length: " << horizontalEaveLength << "\n";
    qDebug() << "\t-alpha angle: " << getAlphaAngle() << "\n";
    qDebug() << "\t-beta angle " << getBetaAngle() << "\n";
    qDebug() << "\t-vertical Cut: " << verticalCut << "\n";
    qDebug() << "\t-horizontal Cut: " << horizontalCut << "\n";

    qDebug() << '\n' << getName() << " dimensions:" << "\n";
    qDebug() << "\t-eave To Wall Plate: " << eaveToWallPlate << "\n";

    qDebug() << "\t-wall Plate To Purlin: " << wallPlateToPurlin << "\n";
    qDebug() << "\t-purlin To Top: " << purlinToTop << "\n";

    qDebug() << "\t-wall Plate To Top: " << wallPlateToTop << "\n";
    qDebug() << "\t-rafter Total Length: " << rafterTotalLength ;

}

void CommonRafter::setVerticalCut(const double vCut)
{
    verticalCut = vCut;
}


void CommonRafter::setHorizontalCut(const double hCut)
{
    horizontalCut = hCut;
}


void CommonRafter::setRafterAboveWallPlate(const double rafAbove)
{
    rafterAboveWallPlat = rafAbove;
}


void CommonRafter::setAngleVerticalLine(const double angVert)
{
    angleVerticalLine = angVert;
}


void CommonRafter::setAngleHorizontalLine(const double angHor)
{
    angleHorizontalLine = angHor;
}


void CommonRafter::setHorizontalEaveLength(const double horEave)
{
    horizontalEaveLength = horEave;
}


void CommonRafter::setEaveToWallPlate(const double eaveWall)
{
    eaveToWallPlate = eaveWall;
}


void CommonRafter::setWallPlateToPurlin(const double wallPurl)
{
    wallPlateToPurlin = wallPurl;
}


void CommonRafter::setPurlinToTop(const double purlTop)
{
    purlinToTop = purlTop;
}


void CommonRafter::setWallPlateToTop(const double wallTop)
{
    wallPlateToTop = wallTop;
}


void CommonRafter::setRafterTotalLength(const double rafterTotal)
{
    rafterTotalLength = rafterTotal;
}

// get
double CommonRafter::getVerticalCut() const
{
    return verticalCut;
}


double CommonRafter::getHorizontalCut() const
{
    return  horizontalCut;
}


double CommonRafter::getRafterAboveWallPlate() const
{
    return rafterAboveWallPlat;
}


double CommonRafter::getAngleVerticalLine() const
{
    return angleVerticalLine;
}


double CommonRafter::getAngleHorizontalLine() const
{
    return angleHorizontalLine;
}


double CommonRafter::getHorizontalEaveLength() const
{
    return horizontalEaveLength;
}


double CommonRafter::getEaveToWallPlate() const
{
    return eaveToWallPlate;
}


double CommonRafter::getWallPlateToPurlin() const
{
    return wallPlateToPurlin;
}


double CommonRafter::getPurlinToTop() const
{
    return purlinToTop;
}


double CommonRafter::getwallPlateToTop() const
{
    return wallPlateToTop;
}


double CommonRafter::getRafterTotalLength() const
{
    return rafterTotalLength;
}


