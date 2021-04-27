#ifndef ELEMWALLPLATE_H
#define ELEMWALLPLATE_H

#include <QDialog>

#include "element.h"

namespace Ui {
class WallPlate;
}

class WallPlate final : public Element
{
    Q_OBJECT

public:
    explicit WallPlate(QWidget *parent, Dimensions* dim);
    ~WallPlate();

    ElementType type() const override final;
    void calculateParameters() override final;
    void showParameters() const override final;

private slots:
    void on_buttonApprove_clicked();
    void on_buttonBack_clicked();

private:
    Ui::WallPlate *ui{};

    void setParameters();
    void setSpinPalette();
    void setSpinFont();
    void setSpinRange();
    void setSpinValues();
};

#endif // ELEMWALLPLATE_H
