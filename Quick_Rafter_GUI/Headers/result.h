#ifndef RESULT_H
#define RESULT_H

#include "truss.h"
#include "resulttruss.h"
#include "resultgableroof.h"
#include "resulthippedroof.h"
#include "resultcommonrafter.h"
#include "resultwallplate.h"
#include "resulthiprafter.h"
#include "resultpurlin.h"
#include "resultpurlinprop.h"
#include "resultinterface.h"
#include <QDialog>

namespace Ui {
class Result;
}

class Result : public QDialog
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent, Truss* truss);
    ~Result();
    void setUpButtons();

signals:
    void resultClosed();

private slots:
    void on_buttonTruss_clicked();
    void on_buttonCommonRafter_clicked();
    void on_buttonWallPlate_clicked();
    void on_buttonHipRafter_clicked();
    void on_buttonPurlin_clicked();
    void on_buttonPurlinProp_clicked();
    void on_buttonClose_clicked();

private:
    Ui::Result *ui{};
    Truss* truss{};
    ResultTruss* resultTruss{};
    Element* wallPlate{};
    Element* commonRafter{};
    Element* hipRafter{};
    Element* purlin{};
    Element* purlinProp{};

    ResultCommonRafter* resCommRafter{};
    ResultWallPlate* resWallPlate{};
    ResultHipRafter* resHipRafter{};
    ResultPurlin* resPurlin{};
    ResultPurlinProp* resPurlinprop{};
    ResultInterface* resultInterface;

};

#endif // RESULT_H
