#include "secondwindow.h"
#include "ui_secondwindow.h"

extern bool tema;
int index = 1, first, last, a = 0, b = 1, s = 0, minimum, distance = 0;
int visited[6] { 0, 0, 0, 0, 0, 0 };
int minway[6] { -1, -1, -1, -1, -1, -1}, w[6] { -1, -1, -1, -1, -1, -1 };
QString st;
struct Node {
    int way[6];
    bool take = 0;
    int from = 1000;
};
Node node[6];
bool kway;

SecondWindow::SecondWindow(QWidget *parent) : QWidget(parent),
    ui(new Ui::SecondWindow), int_validator(0, 100, this)
{
    ui->setupUi(this);
    if (tema) {
        QPixmap pan("C:/Users/kcentr.ru/OneDrive/CreativeWork/MyTravelingSalesmanTask/bg1.jpg");
        pan = pan.scaled(this->size(), Qt::IgnoreAspectRatio);
        palette.setBrush(QPalette::Background, pan);
        this->setPalette(palette);
        ui->header->setStyleSheet("QLabel{ font: 15pt; color: rgb(110, 103, 91); }");
        ui->input->setStyleSheet("QPushButton{ border-radius: 6px; font: 15pt; color: rgb(110, 103, 91); background-color: rgb(218, 215, 204); }");
        ui->newgraph->setStyleSheet("QPushButton{ border-radius: 6px; font: 15pt; color: rgb(110, 103, 91); background-color: rgb(218, 215, 204); }");
        ui->exit->setStyleSheet("QPushButton{ border-radius: 6px; font: 15pt; color: rgb(110, 103, 91); background-color: rgb(218, 215, 204); }");
    }
    else {
        QPixmap pan("C:/Users/kcentr.ru/OneDrive/CreativeWork/MyTravelingSalesmanTask/bg2.jpg");
        pan = pan.scaled(this->size(), Qt::IgnoreAspectRatio);
        palette.setBrush(QPalette::Background, pan);
        this->setPalette(palette);
        ui->header->setStyleSheet("QLabel{ font: 15pt; color: rgb(255, 255, 255); }");
        ui->input->setStyleSheet("QPushButton{ border-radius: 6px; font: 15pt; color: rgb(255, 255, 255); background-color: rgb(91, 130, 153); }");
        ui->newgraph->setStyleSheet("QPushButton{ border-radius: 6px; font: 15pt; color: rgb(255, 255, 255); background-color: rgb(91, 130, 153); }");
        ui->exit->setStyleSheet("QPushButton{ border-radius: 6px; font: 15pt; color: rgb(255, 255, 255); background-color: rgb(91, 130, 153); }");
    }

    ui->window->setValidator(&int_validator);
    ui->input->hide();
    ui->window->hide();
    ui->newgraph->hide();
    for (int i = 0; i < 6; i++) node[i].from = 1000;
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_exit_clicked()
{
    QWidget::close();
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            node[i].way[j] = 0;
        }
        minway[i] = -1;
        node[i].from = 1000;
        node[i].take = false;
    }
    index=1;
    a=0; b=1;
    kway = 0;
}

void SecondWindow::on_newgraph_clicked()
{
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            node[i].way[j] = 0;
        }
        minway[i] = -1;
        node[i].from = 1000;
        node[i].take = false;
    }
    index=1;
    a=0; b=1;
    kway = 0;
    ui->header->setText("Сделайте выбор начального города.");
    ui->newgraph->hide();
    this->repaint();
}

void SecondWindow::paintEvent(QPaintEvent*)
{
    QPushButton *button1, *button2;
    QString s;
    QPen pen;
    QPainter painter;
    painter.begin(this);
    pen.setColor(Qt::black);
    pen.setWidth(3);
    painter.setPen(pen);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (node[i].way[j])
            {
                s = "node" + QString::number(i+1);
                button1 = this->findChild<QPushButton*>(s);
                s = "node" + QString::number(j+1);
                button2 = this->findChild<QPushButton*>(s);
                painter.drawLine(button1->x()+51, button1->y()+51, button2->x()+51, button2->y()+51);
            }
        }
    }
    if (kway)
    {
        pen.setColor(Qt::yellow);
        pen.setWidth(3);
        painter.setPen(pen);
        for (int i = 0; i < 5; i++)
        {
            if (minway[i] > -1)
            {
                s = "node" + QString::number(minway[i]+1);
                button1 = this->findChild<QPushButton*>(s);
                if (minway[i+1] > -1)
                {
                    s = "node" + QString::number(minway[i+1]+1);
                    button2 = this->findChild<QPushButton*>(s);
                    painter.drawLine(button1->x()+51, button1->y()+51, button2->x()+51, button2->y()+51);
                }
            }
        }
    }
    painter.end();
}

void Search(int dist, int a)
{
    distance += dist;
    visited[a] = 1;
    w[s] = a;
    s++;
    if (a == last && distance == minimum)
        for (int z = 0; z < 6; z++) minway[z] = w[z];
    else
    {
        for (int b = 0; b < 6; b++)
        {
            if (!visited[b] && node[a].way[b])
            {
                Search(node[a].way[b], b);
            }
        }
    }
    s--;
    w[s] = -1;
    distance -= dist;
    visited[a] = 0;
}

void Process(Node &cur)
{
    int min = 1000;
    for (int i = 0; i < 6; i++)
    {
        if (cur.way[i] != 0 && cur.way[i] + cur.from < node[i].from) node[i].from=cur.way[i] + cur.from;
        if (cur.way[i] != 0 && !node[i].take && cur.way[i] < min) min = cur.way[i];
    }
    cur.take = 1;
    for (int i = 0; i < 6; i++) if (cur.way[i] == min && !node[i].take) Process(node[i]);
}

void SecondWindow::on_input_clicked()
{
    QString string;
    if (a < 5)
    {
        if (b < 6)
        {
            node[a].way[b] = ui->window->text().toInt();
            node[b].way[a] =node[a].way[b];
            this->repaint();
            b++;
            if (b != 6)
            {
                string = "Введите расстояние между городами " + QString::number(a+1) + " и " + QString::number(b+1);
                ui->header->setText(string);
            }
            ui->window->setText("");
        }
        if (b == 6)
        {
            a++;
            b = a + 1;
            if (a != 5)
            {
                string = "Введите расстояние между городами " + QString::number(a+1) + " и " + QString::number(b+1);
                ui->header->setText(string);
                ui->window->setText("");
            }
            else
            {
                node[first].from = 0;
                Process(node[first]);
                minimum = node[last].from;
                Search(0, first);
                st = QString::number(first+1);
                for (int i = 1; i < 6; i++)
                {
                    if (minway[i] != -1) st += "->" + QString::number(minway[i]+1);
                }
                string = "Кратчайшее расстояние между выбранными городами равно " + QString::number(node[last].from) + "\nКратчайший путь: " + st;
                ui->header->setText(string);
                ui->input->hide();
                kway = true;
                this->repaint();
                ui->window->hide();
                ui->newgraph->show();
            }
        }
    }
}

void SecondWindow::on_node1_clicked()
{
    if (index == 1)
    {
        index++;
        first = 0;
        ui->header->setText("Теперь конечного.");
    }
    else if (index == 2)
    {
        ui->window->show();
        ui->input->show();
        ui->header->setText("Введите расстояние между городами 1 и 2.");
        last = 0;
        index = 0;
    }
}

void SecondWindow::on_node2_clicked()
{
    if (index == 1)
    {
        index++;
        first = 1;
        ui->header->setText("Теперь конечного.");
    }
    else if (index == 2)
    {
        index = 0;
        ui->window->show();
        ui->input->show();
        ui->header->setText("Введите расстояние между городами 1 и 2.");
        last = 1;
    }
}

void SecondWindow::on_node3_clicked()
{
    if (index == 1)
    {
        index++;
        first = 2;
        ui->header->setText("Теперь конечного.");
    }
    else if (index == 2)
    {
        index = 0;
        ui->window->show();
        ui->input->show();
        ui->header->setText("Введите расстояние между городами 1 и 2.");
        last = 2;
    }
}

void SecondWindow::on_node4_clicked()
{
    if (index == 1)
    {
        index++;
        first = 3;
        ui->header->setText("Теперь конечного.");
    }
    else if (index == 2)
    {
        index = 0;
        ui->window->show();
        ui->input->show();
        ui->header->setText("Введите расстояние между городами 1 и 2.");
        last = 3;
    }
}

void SecondWindow::on_node5_clicked()
{
    if (index == 1)
    {
        index++;
        first = 4;
        ui->header->setText("Теперь конечного.");
    }
    else if (index == 2)
    {
        index = 0;
        ui->window->show();
        ui->input->show();
        ui->header->setText("Введите расстояние между городами 1 и 2.");
        last = 4;
    }
}

void SecondWindow::on_node6_clicked()
{
    if (index == 1)
    {
        index++;
        first = 5;
        ui->header->setText("Теперь конечного.");
    }
    else if (index == 2)
    {
        index = 0;
        ui->window->show();
        ui->input->show();
        ui->header->setText("Введите расстояние между городами 1 и 2.");
        last = 5;
    }
}
