#ifndef GABLEROOF_H
#define GABLEROOF_H

/*
    class Truss is inherited by HippedRoof
*/

#include "truss.h"
#include "purlin.h"
#include "purlinprop.h"

class GableRoof : public Truss
{
public:
    explicit GableRoof(QWidget *parent, Dimensions* dim);
    virtual TrussType type() const override;

private slots:
    void on_purlinIsSet();
    void on_purlinReject();
    void on_purlinPropIsSet();
    void on_purlinPropReject();
    void on_trussConstructed();

private:
    Dimensions* dimensions{};
};
#endif // GABLEROOF_H
