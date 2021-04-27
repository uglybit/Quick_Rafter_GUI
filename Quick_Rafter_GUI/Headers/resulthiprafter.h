#ifndef RESULTHIPRAFTER_H
#define RESULTHIPRAFTER_H

#include <QDialog>

#include "element.h"
#include "resultinterface.h"

namespace Ui {
class ResultHipRafter;
}

class ResultHipRafter final : public ResultInterface
{
    Q_OBJECT

public:
    explicit ResultHipRafter(QWidget *parent, Element* elem);
    ~ResultHipRafter();

private:
    Ui::ResultHipRafter *ui{};
    Element* hipRafter{};
    void setPrintGeometry() override final;
    void setProfileView();
    void setAxisView();
};

#endif // RESULTHIPRAFTER_H
