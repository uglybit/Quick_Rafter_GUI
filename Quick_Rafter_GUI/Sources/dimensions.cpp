#include "../Headers/dimensions.h"
#include "ui_dimensions.h"

#include <QMessageBox>
#include <QDebug>

Dimensions::Dimensions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dimensions)
{
    ui->setupUi(this);
    QSize windowSize = size();
    setFixedSize(windowSize);
    setSpinPalette();
    setSpinFont();
    setSpinRange();
    setSpinValues();
    ui->buttonNext->setDefault(true);
}

Dimensions::~Dimensions()
{
    delete ui;
}

void Dimensions::setSpinPalette()
{
    QPalette palette(QColor(0, 0, 0), QColor(0,0,0), QColor(0,0,0), QColor(0,0,0), QColor(0,0,0), QColor(220, 220, 220), QColor(33, 40, 48)  );
    ui->spinTrussHeight->setPalette(palette);
    ui->spinBuildingWidth->setPalette(palette);
    ui->spinWallPlateLevel->setPalette(palette);
    ui->spinEaveLength->setPalette(palette);
    ui->spinPropDistance->setPalette(palette);
}

void Dimensions::setSpinFont()
{
    QFont spinFont("MS Shell Dlg 2", 10, -1, false);
    ui->spinTrussHeight->setFont(spinFont);
    ui->spinBuildingWidth->setFont(spinFont);
    ui->spinWallPlateLevel->setFont(spinFont);
    ui->spinEaveLength->setFont(spinFont);
    ui->spinPropDistance->setFont(spinFont);
}

void Dimensions::setSpinRange()
{
    ui->spinTrussHeight->setMinimum(100);
    ui->spinTrussHeight->setMaximum(1000);
    ui->spinBuildingWidth->setMaximum(1000);
    ui->spinWallPlateLevel->setMaximum(100);
    ui->spinEaveLength->setMaximum(500);
    ui->spinPropDistance->setMinimum(50);
    ui->spinPropDistance->setMaximum(400);
}

void Dimensions::setSpinValues()
{
    ui->spinTrussHeight->setValue(350);
    ui->spinBuildingWidth->setValue(800);
    ui->spinWallPlateLevel->setValue(70);
    ui->spinEaveLength->setValue(110);
    ui->spinPropDistance->setValue(180);
    QSize windowSize(759, 417);
    this->setMinimumSize(windowSize);
    this->setMaximumSize(windowSize);
}

void Dimensions::on_lengthIsSet(double truss, double building)
{
    if (truss <= 0 || building <= 0) {
        QMessageBox::warning(this, "Bad value", "Length can not be <= 0!");
    }
    else {
        setTrussLength(truss);
        setBuildingLength(building);
        dimensionsLength->close();
        emit dimensionsAreSet();
        this->close();
    }
    qDebug() << "building length: " << getBuildingLength();
    qDebug() << "truss length: " << getTrussLength();
}

void Dimensions::on_buttonNext_clicked()
{
     setBuildingWidth( ui->spinBuildingWidth->value());
     setTrussHeight(ui->spinTrussHeight->value());
     setWallPlateHeight(ui->spinWallPlateLevel->value());
     setHorizontalEaveLength(ui->spinEaveLength->value());
     setPurlinPropDistance(ui->spinPropDistance->value());
     dimensionsLength = new DimensionsLength(this);

     qDebug() << "building width: " << getBuildingWidth();
     qDebug() << "Truss height: " << getTrussHeight();
     qDebug() << "wall plate hlevel: " << getWallPlateHeight();
     qDebug() << "horiz eave length: " << getHorizontalEaveLength();
     qDebug() << "prop dist: " << getPurlinPropDistance();

     connect(dimensionsLength, &DimensionsLength::dimensionsLengthAreSet, this, &Dimensions::on_lengthIsSet);
     connect(dimensionsLength, &DimensionsLength::dimensionsLengthReject,
             this, &Dimensions::on_dimensionsLengthReject);

     dimensionsLength->show();
     this->hide();
}

void Dimensions::on_dimensionsLengthReject()
{
    qDebug() << "Odebralem sygnal reject od dimensionsLength";
    if (dimensionsLength) {
        delete dimensionsLength;
        dimensionsLength = nullptr;
    }
    this->show();
}

// this function is used by CommonRafter
void Dimensions::setPurlinPropLength(double value)
{
    purlinPropLength = value;
}

// user input
void Dimensions::setBuildingLength(double value)
{
    buildingLength = value;
}


void Dimensions::setBuildingWidth(double value)
{
    buildingWidth = value;
}


void Dimensions::setTrussHeight(double value)
{
    trussHeight = value;
}


void Dimensions::setTrussLength(double value)
{
    trussLength = value;
}


void Dimensions::setWallPlateHeight(double value)
{
    wallPlateHeight = value;
}


void Dimensions::setPurlinPropDistance(double value)
{
    purlinPropDistance = value;
}


void Dimensions::setHorizontalEaveLength(double value)
{
    horizontalEaveLength = value;
}


void Dimensions::setCommonRafterHeight(double value)
{
    commonRafterHeight = value;
}


void Dimensions::setCommonRafterWidth(double value)
{
    commonRafterWidth = value;
}


void Dimensions::setCommonRafterDistance(double value)
{
    commonRaftersDistance = value;
}


void Dimensions::setPurlinDimensions(double value)
{
    purlinHeight = value;
}


void Dimensions::setCommRaftTotalLength(double value)
{
    commRaftTotalLength = value;
}


void Dimensions::setPurlinLevel(double value)
{
    purlinLevel = value;
}


void Dimensions::setHipWidth(double value)
{
    hipRafterWidth = value;
}


void Dimensions::setHipHeight(double value)
{
    hipRafterHeight = value;
}


void Dimensions::setHipRaftTotalLength(double len)
{
    hipRaftTotalLength = len;
}


void Dimensions::setRafterAboveWallPlat(double value)
{
    rafterAboveWallPlat = value;
}

void Dimensions::setRoofSurfaceArea(double surfaceArea)
{
    roofSurfaceArea = surfaceArea;
}


// get
double Dimensions::getPurlinPropLength() const
{
    return purlinPropLength;
}


double Dimensions::getPurlinDimensions()  const
{
    return purlinHeight;
}


double Dimensions::getCommRaftTotalLength() const
{
    return commRaftTotalLength;
}


double Dimensions::getPurlinLevel() const
{
    return purlinLevel;
}


double Dimensions::getHipWidth() const
{
    return hipRafterWidth;
}


double Dimensions::getHipRaftTotalLength() const
{
    return hipRaftTotalLength;
}


double Dimensions::getRafterAboveWallPlat() const
{
    return rafterAboveWallPlat;
}


double Dimensions::getHipHeight() const
{
    return hipRafterHeight;
}


double Dimensions::getBuildingLength() const
{
    return  buildingLength;
}


double Dimensions::getBuildingWidth() const
{
    return  buildingWidth;
}


double Dimensions::getTrussHeight() const
{
    return  trussHeight;
}


double Dimensions::getTrussLength() const
{
    return  trussLength;
}


double Dimensions::getWallPlateHeight() const
{
    return  wallPlateHeight;
}


double Dimensions::getPurlinPropDistance() const
{
    return  purlinPropDistance;
}


double Dimensions::getHorizontalEaveLength() const
{
    return  horizontalEaveLength;
}


double Dimensions::getCommonRafterHeight() const
{
    return  commonRafterHeight;
}


double Dimensions::getCommonRafterWidth() const
{
    return  commonRafterWidth;
}


double Dimensions::getCommonRaftersDistance() const
{
    return  commonRaftersDistance;
}


double Dimensions::getNumberOfCommRafters() const
{
    return  numberOfRafters;
}

double Dimensions::getRoofSurfaceArea() const
{
    return roofSurfaceArea;
}



void Dimensions::on_buttonBack_clicked()
{
    emit dimensionsReject();
}

