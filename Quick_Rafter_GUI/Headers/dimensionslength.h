#ifndef DIMENSIONSLENGTH_H
#define DIMENSIONSLENGTH_H

#include <QDialog>

namespace Ui {
class DimensionsLength;
}

class DimensionsLength final : public QDialog
{
    Q_OBJECT

public:
    explicit DimensionsLength(QWidget *parent = nullptr);
    ~DimensionsLength();

signals:
    void dimensionsLengthAreSet(double, double);
    void dimensionsLengthReject();

private slots:
    void on_buttonApprove_clicked();
    void on_buttonBack_clicked();

private:
    Ui::DimensionsLength *ui{};

    void setSpinPalette();
    void setSpinFont();
    void setSpinRange();
    void setSpinValues(); 
};

#endif // DIMENSIONSLENGTH_H
