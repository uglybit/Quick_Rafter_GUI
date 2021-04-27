#include "../Headers/resultinterface.h"
#include "ui_resultinterface.h"

ResultInterface::ResultInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultInterface)
{
    ui->setupUi(this);
     connect(ui->buttonEksportPDF, SIGNAL(clicked()), SLOT(on_ButtonPrintClick()));
}

ResultInterface::~ResultInterface()
{
    delete ui;
}

void ResultInterface::setView()
{
    this->setFixedSize(this->size());
}

void ResultInterface::setExportPDF()
{
    QDir dir;
    dir.setPath(QDir::homePath() + "/" + fileName + ".pdf");
    fileName = QFileDialog::getSaveFileName(this, "Zapisz jako...", dir.absolutePath() );
    qDebug() << fileName;
    printer.setOutputFileName(fileName);

    pixmap = this->grab();
    setPrintGeometry();
    source = this->ui->labelPrint->geometry();

    double printWidth = source.width();
    double printHeight = source.height();

    if (printWidth > PRINT_MAX_WIDTH) {
        double scaleRatio = PRINT_MAX_WIDTH / printWidth;
        printWidth *= scaleRatio;
        printHeight *= scaleRatio;
    }
    target.setRect(0, 0, printWidth, printHeight);
}

QLabel *ResultInterface::getPrintLabel()
{
    return ui->labelPrint;
}

void ResultInterface::setFileName(const QString &fName)
{
    fileName = fName;
}

const QString &ResultInterface::getFileName() const
{
    return fileName;
}

void ResultInterface::on_ButtonPrintClick()
{
    qDebug() << "---> Export clicked";

    setExportPDF();
    qDebug() << getFileName();

    if (!painter.begin(&printer)) {
        qDebug() << "failed open file";
    }

    painter.drawPixmap(target, pixmap, source);
    painter.end();
}
