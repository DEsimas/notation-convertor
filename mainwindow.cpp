#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

number MainWindow::getData() {
    number n;

    QString iss = ui->iss->text();
    n.iss = iss.toInt();

    QString val = ui->val->text();
    n.val = val.toStdString();

    QString oss = ui->oss->text();
    n.oss = oss.toInt();

    return n;
}

void MainWindow::on_val_textChanged(const QString &arg1)
{
    cnv();
}

void MainWindow::cnv()
{
    number n = getData();
    try {
        QString val = QString::fromStdString(conv.convert(n));
        ui->output->setText(val);
    }  catch (...) {
        ui->output->setText("Input Error");
    }
}

void MainWindow::on_iss_textChanged(const QString &arg1)
{
    cnv();
}

void MainWindow::on_oss_textChanged(const QString &arg1)
{
    cnv();
}
