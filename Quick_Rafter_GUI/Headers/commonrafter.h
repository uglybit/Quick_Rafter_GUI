#ifndef ELEMCOMMONRAFTER_H
#define ELEMCOMMONRAFTER_H


/*
    class CommonRafter is inherited by HipRafter
*/

#include "element.h"

namespace Ui {
class CommonRafter;
}

class CommonRafter : public Element
{
    Q_OBJECT

public:
    explicit CommonRafter(QWidget *parent, Dimensions* dim);
    explicit CommonRafter(Dimensions* dim, QWidget *parent = nullptr);
    ~CommonRafter();
    void setSpinPalette();
    void setSpinFont();
    void setSpinRange();
    void setSpinValues();
    ElementType type() const override;

    double getVerticalCut() const;
    double getHorizontalCut() const;
    double getRafterAboveWallPlate() const;
    double getAngleVerticalLine() const;
    double getAngleHorizontalLine() const;
    double getHorizontalEaveLength() const;
    double getEaveToWallPlate() const;
    double getWallPlateToPurlin() const;
    double getPurlinToTop() const;
    double getwallPlateToTop() const;
    double getRafterTotalLength() const;

private slots:
    void on_buttonApprove_clicked();
    void on_buttonBack_clicked();

protected:
    void setParameters();
    void calculateParameters() override;
    void calculateVerticalLine(double value);
    void calculateVerticalCut();
    void calculateProperVerticalCut();
    void calculateRafterAboveWallPlatt();
    void calculateHorizontalLine(double value);
    void calculateHorizontalCut();
    void calculatePurlinAndPropLength();
    void calculateCommonRafterDimensions();
    void showParameters() const override;

    void setVerticalCut(const double vCut);
    void setHorizontalCut(const double hCut);
    void setRafterAboveWallPlate(const double rafAbove);
    void setAngleVerticalLine(const double angVert);
    void setAngleHorizontalLine(const double angHor);
    void setHorizontalEaveLength(const double horEave);
    void setEaveToWallPlate(const double eaveWall);
    void setWallPlateToPurlin(const double wallPurl);
    void setPurlinToTop(const double purlTop);
    void setWallPlateToTop(const double wallTop);
    void setRafterTotalLength(const double rafterTotal);

private:
    Ui::CommonRafter *ui{};

    double verticalCut{ 0.0 };
    double horizontalCut{ 0.0 };

    double rafterAboveWallPlat{ 0.0 };
    double angleVerticalLine{ 0.0 };
    double angleHorizontalLine{ 0.0 };
    double horizontalEaveLength{ 0.0 };

    // rafter dimensions in axis
    double eaveToWallPlate{ 0.0 };
    double wallPlateToPurlin{ 0.0 };
    double purlinToTop{ 0.0 };
    double wallPlateToTop{ 0.0 };
    double rafterTotalLength{ 0.0 };

    static constexpr double CUTTING_RATIO = 0.25;
};

#endif // ELEMCOMMONRAFTER_H
