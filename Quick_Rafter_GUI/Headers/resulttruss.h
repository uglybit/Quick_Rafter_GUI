#ifndef RESULTTRUSS_H
#define RESULTTRUSS_H

#include "truss.h"
#include <QDialog>
#include "QLabel"
#include "resultinterface.h"

namespace Ui {
class ResultTruss;
}

class ResultTruss : public ResultInterface
{
    Q_OBJECT

public:
    explicit ResultTruss(QWidget *parent, Truss* t);
    ~ResultTruss();
    void setPrintGeometry() override final;

signals:
    void resultTrussRejected();

protected:
    QLabel* bulidingLengthLabel();
    QLabel* trussLengthLabel();
    QLabel* rafterDistanceLabel();
    QLabel* roofSurfaceLabel();
    QLabel* pictureLabel();

private:
    Ui::ResultTruss *ui{};
    Truss* truss{};

    void setFrontView();
    void setProfileView();
};

#endif // RESULTTRUSS_H
