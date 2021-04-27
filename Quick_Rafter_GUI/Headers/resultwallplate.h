#ifndef RESULTWALLPLATE_H
#define RESULTWALLPLATE_H

#include <QDialog>
#include "element.h"
#include "wallplate.h"
#include "resultinterface.h"

namespace Ui {
class ResultWallPlate;
}

class ResultWallPlate final : public ResultInterface
{
    Q_OBJECT

public:
    explicit ResultWallPlate(QWidget *parent, Element* elem);
    ~ResultWallPlate();

    void setPrintGeometry() override final;

private:
    Ui::ResultWallPlate *ui{};
    Element* wallPlate{};

    void setView();
};

#endif // RESULTWALLPLATE_H
