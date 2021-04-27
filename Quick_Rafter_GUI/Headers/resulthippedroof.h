#ifndef RESULTHIPPEDROOF_H
#define RESULTHIPPEDROOF_H

#include <QDialog>

#include "resulttruss.h"

namespace Ui {
class ResultHippedRoof;
}

class ResultHippedRoof final : public ResultTruss
{
    Q_OBJECT

public:
    explicit ResultHippedRoof(QWidget *parent, Truss* t);
    ~ResultHippedRoof();

signals:
    void resultHippedRoofRejected();

private:
    Ui::ResultHippedRoof *ui{};
    Truss* truss{};
    void setFrontView();
};

#endif // RESULTHIPPEDROOF_H
