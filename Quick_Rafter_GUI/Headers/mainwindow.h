#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "truss.h"
#include "dimensions.h"
#include "hippedroof.h"
#include "result.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonApprove_clicked();
    void on_dimenionsSet();
    void on_trussIsSet();
    void on_resultClosed();
    void on_dimensionsReject();
    void on_trussIsNotSet();
    void on_buttonClose_clicked();

private:
    Ui::MainWindow *ui;
    QStringList options{"Dach dwuspadowy", "Dach czterospadowy"};
    Truss* truss{};
    Dimensions* dimensions{};
    Result* result{};
};
#endif // MAINWINDOW_H
