#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secondwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPalette palette;

private slots:
    void on_btn_graph_clicked();
    void on_exit_clicked();
    void on_light_clicked();
    void on_dark_clicked();
};

#endif // MAINWINDOW_H
