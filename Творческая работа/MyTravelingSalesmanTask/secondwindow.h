#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QIntValidator>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private:
    Ui::SecondWindow *ui;
    QIntValidator int_validator;
    QPalette palette;

protected:
    void paintEvent(QPaintEvent*) override;

private slots:
    void on_exit_clicked();
    void on_input_clicked();
    void on_node1_clicked();
    void on_node2_clicked();
    void on_node3_clicked();
    void on_node4_clicked();
    void on_node5_clicked();
    void on_node6_clicked();
    void on_newgraph_clicked();
};

#endif // SECONDWINDOW_H
