#ifndef RESULTGABLEROOF_H
#define RESULTGABLEROOF_H

#include <QDialog>
#include "resulttruss.h"

namespace Ui {
class ResultGableRoof;
}

class ResultGableRoof final : public ResultTruss
{
    Q_OBJECT

public:
    explicit ResultGableRoof(QWidget *parent, Truss* t);
    ~ResultGableRoof();

signals:
    void resultGableRoofRejected();

private:
    Ui::ResultGableRoof *ui{};
    Truss* truss{};
    void setFrontView();
};

#endif // RESULTGABLEROOF_H
