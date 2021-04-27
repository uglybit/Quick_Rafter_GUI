#ifndef ELEMPURLINPROP_H
#define ELEMPURLINPROP_H

#include "element.h"
#include <QDialog>

namespace Ui {
class PurlinProp;
}

class PurlinProp final : public Element
{
    Q_OBJECT

public:
    explicit PurlinProp(QWidget *parent, Dimensions* dimens);
    ~PurlinProp();
    ElementType type() const override final;
    void showParameters() const override final;

    // parametry slupka musza zostac obliczone w CommonRafter
    void calculateParameters() override final {}

private slots:
    void on_buttonApprove_clicked();
    void on_buttonBack_clicked();

private:
    Ui::PurlinProp *ui{};

    void setSpinPalette();
    void setSpinFont();
    void setSpinRange();
    void setSpinValues();

};

#endif // ELEMPURLINPROP_H
