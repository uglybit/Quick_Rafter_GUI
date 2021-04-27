#ifndef HIPPEDROOF_H
#define HIPPEDROOF_H

#include "gableroof.h"
#include "hiprafter.h"

class HippedRoof final: public GableRoof
{
public:
    explicit HippedRoof(QWidget *parent, Dimensions* dim);
    ~HippedRoof() override {};
    virtual TrussType type() const final override;

private slots:
    void on_hipRafterIsSet();
    void on_hipRafterReject();
    void on_gableRoofIsSet();

private:
    Dimensions* dimensions{};
};

#endif // HIPPEDROOF_H
