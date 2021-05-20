#include "mainwindow.h"
#include "ui_mainwindow.h"

bool tema;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (ui->light->isChecked()) on_light_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_graph_clicked()
{
    SecondWindow *window = new SecondWindow();
    window->show();
}

void MainWindow::on_exit_clicked()
{
    QWidget::close();
}

void MainWindow::on_light_clicked()
{
    tema = 1;
    QPixmap pan("C:/Users/kcentr.ru/OneDrive/CreativeWork/MyTravelingSalesmanTask/background1.jpg");
    pan = pan.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, pan);
    this->setPalette(palette);
    ui->btn_graph->setStyleSheet("QPushButton{ border-radius: 6px; font: 15pt; color: rgb(110, 103, 91); background-color: rgb(218, 215, 204); }");
    ui->exit->setStyleSheet("QPushButton{ border-radius: 6px; font: 15pt; color: rgb(110, 103, 91); background-color: rgb(218, 215, 204); }");
    ui->label->setStyleSheet("QLabel{ font: 15pt; color: rgb(110, 103, 91); }");
    ui->light->setStyleSheet("QRadioButton{ font: 10pt; color: rgb(110, 103, 91); }");
    ui->dark->setStyleSheet("QRadioButton{ font: 10pt; color: rgb(110, 103, 91); }");
}

void MainWindow::on_dark_clicked()
{
    tema = 0;
    QPixmap pan("C:/Users/kcentr.ru/OneDrive/CreativeWork/MyTravelingSalesmanTask/background2.jpg");
    pan = pan.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, pan);
    this->setPalette(palette);
    ui->btn_graph->setStyleSheet("QPushButton{ border-radius: 6px; font: 15pt; color: rgb(225, 255, 255); background-color: rgb(91, 130, 153); }");
    ui->exit->setStyleSheet("QPushButton{ border-radius: 6px; font: 15pt; color: rgb(255, 255, 255); background-color: rgb(91, 130, 153); }");
    ui->label->setStyleSheet("QLabel{ font: 15pt; color: rgb(255, 255, 255); }");
    ui->light->setStyleSheet("QRadioButton{ font: 10pt; color: rgb(255, 255, 255); }");
    ui->dark->setStyleSheet("QRadioButton{ font: 10pt; color: rgb(255, 255, 255); }");
}
