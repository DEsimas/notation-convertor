#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "convertor.h"

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
    void on_val_textChanged(const QString &arg1);

    void on_iss_textChanged(const QString &arg1);

    void on_oss_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    convertor conv;
    void cnv();
    number getData();
};
#endif // MAINWINDOW_H
