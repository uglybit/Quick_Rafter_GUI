#ifndef ELEMPURLIN_H
#define ELEMPURLIN_H

#include "element.h"
#include <QDialog>

namespace Ui {
class Purlin;
}

class Purlin final : public Element
{
    Q_OBJECT

public:
    explicit Purlin(QWidget *parent, Dimensions* dim);
    ~Purlin();

    ElementType type() const override final;
    void calculateParameters() override final;
    void setParameters();
    void showParameters() const override final;

private slots:
    void on_buttonApprove_clicked();
    void on_buttonBack_clicked();

private:
    Ui::Purlin *ui{};

    void setSpinPalette();
    void setSpinFont();
    void setSpinRange();
    void setSpinValues();
};

#endif // ELEMPURLIN_H
