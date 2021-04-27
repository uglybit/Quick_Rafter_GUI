#ifndef ELEMELEMENT_H
#define ELEMELEMENT_H


/*
    class Element is base class for all roof elements. Is inherited by:
    CommonRafter, HipRafter, WallPlate, Purlin, PurlinProp
*/

#include <QDialog>
#include <QString>
#include "QMap"
#include "dimensions.h"
#include <cmath>
#include <iostream>

enum class ElementType {
    Element,
    CommonRafter,
    HipRafter,
    Purlin,
    PurlinProp,
    WallPlate
    };


namespace Ui {
class Element;
}

class Element : public QDialog
{
    Q_OBJECT

public:
    explicit Element(QWidget *parent, Dimensions* dim);
    ~Element() {}

    virtual ElementType type() const;
    virtual void calculateParameters() = 0;
    virtual void showParameters() const = 0;
    const Dimensions* getDimensions() const;
    Dimensions* setDimensions();
    const QMap<QString, double> &getParameters() const;
    double getWidth() const;
    double getHeight() const;

signals:
    void elementIsSet();
    void elementRejected();

protected:
    void addParameter(const QString& name, const double value);
    void setName(const QString& n);
    void setHeight(const double value);
    void setWidth(const double value);
    void setLength(const double value);
    void setQuantity(const int value);
    void setElementParameters();

    double radiansToDegrees(double value);
    double degreesToRadians(double value);
    void calculateAngles(double vertical, double horizontal);
    void showDimensions() const;

    double getAlphaAngle() const;
    double getBetaAngle() const;
    double getQuantity() const;
    const QString& getName() const;
    const QPalette &getSpinPalette() const;
    const QFont& getSpinFont() const;

private:
     Dimensions* dimensions;
     QMap<QString, double> parameters;
     QPalette palette{QColor(), QColor(), QColor(), QColor(), QColor(), QColor(220, 220, 220), QColor(33, 40, 48)};
     QFont spinFont{"MS Shell Dlg 2", 10, -1, false};
     QString name;
     double length{ 0.0 };
     double width{ 0.0 };
     double height{ 0.0 };
     int quantity{ 0 };
     // roof angles
     double alphaAngle{ 0.0 };
     double betaAngle{ 0.0 };

    // conversion radians <--> degrees
    static constexpr  double convRadtoDeg = 180 / 3.141592653589;
    static constexpr  double convDegToRad = 3.141592653589 / 180;
};

#endif // ELEMELEMENT_H
