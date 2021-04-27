#ifndef RESULTPURLINPROP_H
#define RESULTPURLINPROP_H

#include <QDialog>

#include "element.h"
#include "resultinterface.h"

namespace Ui {
class ResultPurlinProp;
}

class ResultPurlinProp final : public ResultInterface
{
    Q_OBJECT

public:
    explicit ResultPurlinProp(QWidget *parent, Element* elem);
    ~ResultPurlinProp();
    void setPrintGeometry() override final;

private:
    Ui::ResultPurlinProp *ui{};
    Element* purlinProp{};
    void setView();
};

#endif // RESULTPURLINPROP_H
