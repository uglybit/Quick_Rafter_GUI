#ifndef DIMENSIONS_H
#define DIMENSIONS_H

#include <QDialog>
#include "dimensionslength.h"

namespace Ui {
class Dimensions;
}

class Dimensions : public QDialog
{
    Q_OBJECT

public:
    explicit Dimensions(QWidget *parent = nullptr);
    ~Dimensions();

signals:
    void dimensionsAreSet();
    void dimensionsReject();

private slots:
    void on_buttonNext_clicked();
    void on_buttonBack_clicked();
    void on_lengthIsSet(double truss, double building);
    void on_dimensionsLengthReject();

public:
    // user input
    void setBuildingLength(double value);
    void setBuildingWidth(double value);
    void setTrussHeight(double value);
    void setTrussLength(double value);
    void setWallPlateHeight(double value);
    void setHorizontalEaveLength(double value);
    void setPurlin(bool pur);
    void setPurlinPropDistance(double value);
    void setCommonRafterHeight(double value);
    void setCommonRafterWidth(double value);
    void setCommonRafterDistance(double value);

    // calculations
    void setPurlinPropLength(double value);
    void setPurlinLevel(double value);
    void setPurlinDimensions(double value);
    void setCommRaftTotalLength(double value);
    void setHipWidth(double value);
    void setHipHeight(double value);
    void setHipRaftTotalLength(double len);
    void setRafterAboveWallPlat(double value);
    void setRoofSurfaceArea(double surfaceArea);

    double getPurlinPropLength() const;
    double getPurlinLevel() const;
    double getPurlinDimensions() const;
    double getCommRaftTotalLength() const;
    double getHipWidth() const;
    double getHipHeight() const;
    double getHipRaftTotalLength() const;
    double getRafterAboveWallPlat() const;
    double getBuildingLength() const;
    double getBuildingWidth() const;
    double getTrussHeight() const;
    double getTrussLength() const;
    double getWallPlateHeight() const;
    double getPurlinPropDistance() const;
    double getHorizontalEaveLength() const;
    double getCommonRafterHeight() const;
    double getCommonRafterWidth() const;
    double getCommonRaftersDistance() const;
    double getNumberOfCommRafters() const;
    double getRoofSurfaceArea() const;

private:
    Ui::Dimensions *ui;
    DimensionsLength* dimensionsLength;

    double buildingLength{ 0.0 };
    double buildingWidth{ 0.0 };
    double trussHeight{ 0.0 };
    double trussLength{ 0.0 };
    double wallPlateHeight{ 0.0 };
    double purlinPropDistance{ 0.0 };
    double horizontalEaveLength{ 0.0 };

    double commonRafterHeight{ 0.0 };
    double commonRafterWidth{ 0.0 };
    double commonRaftersDistance{ 0.0 };
    double commRaftTotalLength{ 0.0 };

    double hipRafterHeight{ 0.0 };
    double hipRafterWidth{ 0.0 };
    double hipRaftTotalLength{ 0.0 };

    double purlinDimensions{ 0.0 }; // assumption: square cross-section
    double purlinHeight{ 0.0 };
    double purlinLevel{ 0.0 };
    double purlinPropLength{ 0.0 }; // calculated by CommonRafter

    double rafterAboveWallPlat{ 0.0 };
    double alphaAngle{ 0 };
    double betaAngle{ 0 };

    double roofSurfaceArea{0};
    int numberOfRafters{ 0 };

    void setSpinPalette();
    void setSpinFont();
    void setSpinRange();
    void setSpinValues();
};

#endif // DIMENSIONS_H
