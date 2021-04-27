#ifndef RESULTCOMMONRAFTER_H
#define RESULTCOMMONRAFTER_H

#include <QDialog>

#include "element.h"
#include "resultinterface.h"

namespace Ui {
class ResultCommonRafter;
}

class ResultCommonRafter final : public ResultInterface
{
    Q_OBJECT

public:
    explicit ResultCommonRafter(QWidget *parent, Element* elem);
    ~ResultCommonRafter();
    void setPrintGeometry() override final;

private:
    Ui::ResultCommonRafter *ui{};
    Element* commonRafter{};
    void setView();
};

#endif // RESULTCOMMONRAFTER_H
