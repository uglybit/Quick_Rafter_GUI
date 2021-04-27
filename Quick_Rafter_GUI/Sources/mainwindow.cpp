#include "../Headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "../Headers/gableroof.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboTrussType->addItems(options);

    QSize windowSize = size();
    setFixedSize(windowSize);
    this->statusBar()->setSizeGripEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonApprove_clicked()
{
    dimensions = new Dimensions(this);
    connect(dimensions, &Dimensions::dimensionsAreSet, this, &MainWindow::on_dimenionsSet);
    connect(dimensions, &Dimensions::dimensionsReject, this, &MainWindow::on_dimensionsReject);
    dimensions->show();
    ui->buttonApprove->setEnabled(false);
    ui->comboTrussType->setEnabled(false);
}

void MainWindow::on_dimensionsReject()
{

    if (dimensions) {
        delete dimensions;
        dimensions = nullptr;
    }

    ui->buttonApprove->setEnabled(true);
    ui->comboTrussType->setEnabled(true);
}


void MainWindow::on_dimenionsSet()
{
    qDebug() << "Signal received: dimensions are set";

    int index = ui->comboTrussType->currentIndex();
    switch(index)
    {
       case 0: truss = new GableRoof(this, dimensions);
        break;
       case 1: truss = new HippedRoof(this, dimensions);
        break;
    }

    connect(truss, &GableRoof::trussIsRejected, this, &MainWindow::on_trussIsNotSet);

    if (index > 1) return;

    if (index == 0) {
        connect(truss, &GableRoof::gableRoofIsReady, this, &MainWindow::on_trussIsSet);
    }
    else {
        connect(truss, &HippedRoof::hippedRoofIsReady, this, &MainWindow::on_trussIsSet);
    }
}

void MainWindow::on_trussIsSet()
{
    qDebug() << "Signal received: gable or hipped roof is ready";
    qDebug() << truss->getTrussType();
    truss->calcParam();
    truss->showTruss();

    result = new Result(this, truss);
    connect(result, &Result::resultClosed, this, &MainWindow::on_resultClosed);
            result->show();
}

void MainWindow::on_trussIsNotSet()
{
    qDebug() << "Signal received: truss is not set!";
    if (truss) {
        delete truss;
        truss = nullptr;
    }
    dimensions->show();
}

void MainWindow::on_resultClosed()
{
    if (dimensions) {
        delete dimensions;
        dimensions = nullptr;
    }
    if (truss) {
        delete truss;
        truss = nullptr;
    }
    if (result) {
        delete result;
        result = nullptr;
    }
    ui->buttonApprove->setEnabled(true);
    ui->comboTrussType->setEnabled(true);

}

void MainWindow::on_buttonClose_clicked()
{
    this->close();
}
