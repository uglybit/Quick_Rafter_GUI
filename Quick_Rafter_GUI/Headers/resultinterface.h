#ifndef RESULTINTERFACE_H
#define RESULTINTERFACE_H

/*
    ResultInterface is base class for the calculation results of each element.
    Is inherited by: ResultCommonRafter, RasultHipRafter, ResultWallPlate, ResultPurlin, ResultPurlinProp
*/

#include <QDialog>
#include "QPrinter"
#include "QPainter"
#include "QLabel"
#include <QDebug>
#include <QFileDialog>
#include <QDir>

namespace Ui {
class ResultInterface;
}

class ResultInterface : public QDialog
{
    Q_OBJECT

public:
    explicit ResultInterface(QWidget *parent = nullptr);
    virtual ~ResultInterface();

private slots:
    void on_ButtonPrintClick();

protected:
    void setView();
    void setExportPDF();
    QLabel *getPrintLabel();
    void setFileName(const QString& fName);
    const QString &getFileName() const;
    virtual void setPrintGeometry() = 0;

private:
    static constexpr int PRINT_MAX_WIDTH = 761;
    Ui::ResultInterface *ui;
    QString fileName{"Interface.pdf"};
    QPrinter printer;
    QPainter painter;
    QPixmap pixmap;
    QRect source;
    QRect target;

};

#endif // RESULTINTERFACE_H
