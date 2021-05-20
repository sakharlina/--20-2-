#ifndef MYQTCLASS_H
#define MYQTCLASS_H

#include <QMainWindow>
#include <QtMath>
#include <QIntValidator>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MyQtClass; }
QT_END_NAMESPACE

class MyQtClass : public QMainWindow
{
    Q_OBJECT

public:
    MyQtClass(QWidget *parent = nullptr);
    ~MyQtClass();

private:
    Ui::MyQtClass *ui;
    QPalette palette;
    QIntValidator c_validator;
    QIntValidator ms_validator;

private slots:
    void on_delete1_clicked();
    void on_delete2_clicked();
    void variables();
    void change_sign();
    void math_operation();
    void trigonom_operation();
};
#endif // MYQTCLASS_H
