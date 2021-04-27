#ifndef HIPRAFTER_H
#define HIPRAFTER_H

#include "commonrafter.h"
#include "dimensions.h"
#include <QDialog>

namespace Ui {
class HipRafter;
}

class HipRafter final : public CommonRafter
{
    Q_OBJECT

public:
    explicit HipRafter(QWidget *parent, Dimensions* dim);
    ~HipRafter();

    ElementType type() const override;
    void showParameters() const override final;
    void calculateParameters() override final;

private slots:
    void on_buttonApproveHip_clicked();
    void on_buttonBack_clicked();

protected:
    void calculateHipRafterDimensions();
    void setParameters();
    void cutToSquare();
    void addToEdges();
    void showHipParameters() const;
    void setAdditionToEgdes(const double addition);
    void setRafterTotalOnEdges(const double totalEgdes);
    double getAdditionToEgdes() const;
    double getRafterTotalOnEdges() const;

private:
    Ui::HipRafter *ui{};
    double additionToEgdes{ 0.0 }; // dodatek zalezny od szeokosci krokwi naroznej
    double rafterTotalOnEdges{ 0.0 }; // dlugosc krokwi z tym^ dodatkiem
    double verticalCutToSquare{ 0.0 }; // dlugosc pionowego zaciecia w osi krokwi - na naroze
    double horizontalCutToSquare{ 0.0 }; // dlugosc poziomego zaciecia w osi krokwi - na naroze
    double angleCutToSquare{ 0.0 }; // wymiar pod katem 45 stopni od zewnetrznej powierzchni krokwi do osi krokwi (linia pozioma)

    void setSpinPalette();
    void setSpinFont();
    void setSpinRange();
    void setSpinValues();
    void setProfileView();
};

#endif // HIPRAFTER_H
