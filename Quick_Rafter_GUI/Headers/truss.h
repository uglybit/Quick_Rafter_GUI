#ifndef TRUSS_H
#define TRUSS_H

/*
    class Truss is base class for GableRoof
*/

#include "element.h"
#include "dimensions.h"
#include "purlin.h"
#include "wallplate.h"
#include "purlinprop.h"
#include "commonrafter.h"
#include <QDialog>
#include <QString>

enum class TrussType {
    Truss,
    GableRoof,
    HippedRoof
};

namespace Ui {
class Truss;
}

class Truss : public QDialog
{
    Q_OBJECT

public:
    explicit Truss(QWidget *parent, Dimensions* dimens);
    virtual ~Truss();
    virtual TrussType type() const;
    const Dimensions* getDimensions() const;
    int size();
    Element *getElement(unsigned position);
    const QString& getTrussType() const;
    void showTruss();
    void calcParam();

signals:
    void trussIsReady();
    void hippedRoofIsReady();
    void gableRoofIsReady();
    void trussIsRejected();

private slots:
    void wallPlateIsSet();
    void on_wallPlateReject();
    void commonRafterIsSet();
    void on_commonRafterReject();


protected:
    void addElementToTruss(Element* elem);
    void setTrussType(const QString& type);
    double calcArea();
    void getInitialDimensions() const;
    double calcCommonRaftersDistance();
    Dimensions* setDimensions();
    void removeLastElement();
    Element* getLastElement();

private:
    QString trussType;
    std::vector<Element*> elements;
    Dimensions* dimensions{};
};

#endif // TRUSS_H
