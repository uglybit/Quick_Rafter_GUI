#ifndef RESULTPURLIN_H
#define RESULTPURLIN_H

#include <QDialog>

#include "element.h"
#include "resultinterface.h"

namespace Ui {
class ResultPurlin;
}

class ResultPurlin final : public ResultInterface
{
    Q_OBJECT

public:
    explicit ResultPurlin(QWidget *parent, Element* elem);
    ~ResultPurlin();

    void setPrintGeometry() override final;

private:
    Ui::ResultPurlin *ui{};
    Element* purlin{};

    void setView();
};

#endif // RESULTPURLIN_H
