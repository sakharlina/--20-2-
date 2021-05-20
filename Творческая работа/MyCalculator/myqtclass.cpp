#include "myqtclass.h"
#include "ui_myqtclass.h"

int c1, c2, m1, m2, s1, s2;
double vc, vm, vs, value, value1, value2, value3;
double ipart, dpart;

MyQtClass::MyQtClass(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MyQtClass), c_validator(-361, 361, this), ms_validator(-61, 61, this)
{
    ui->setupUi(this);

    QPixmap pan("C:/Users/kcentr.ru/OneDrive/CreativeWork/MyCalculator/picture.jpg");
    pan = pan.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, pan);
    this->setPalette(palette);

    ui->celsius1->setValidator(&c_validator); ui->celsius2->setValidator(&c_validator);
    ui->minute1->setValidator(&ms_validator); ui->minute2->setValidator(&ms_validator);
    ui->second1->setValidator(&ms_validator); ui->second2->setValidator(&ms_validator);
    connect(ui->bott_sign,SIGNAL(clicked()),this,SLOT(change_sign()));
    connect(ui->bott_plus,SIGNAL(clicked()),this,SLOT(math_operation()));
    connect(ui->bott_minus,SIGNAL(clicked()),this,SLOT(math_operation()));
    connect(ui->bott_mult,SIGNAL(clicked()),this,SLOT(math_operation()));
    connect(ui->bott_del,SIGNAL(clicked()),this,SLOT(math_operation()));
    connect(ui->bott_sin,SIGNAL(clicked()),this,SLOT(trigonom_operation()));
    connect(ui->bott_cos,SIGNAL(clicked()),this,SLOT(trigonom_operation()));
    connect(ui->bott_tan,SIGNAL(clicked()),this,SLOT(trigonom_operation()));
    connect(ui->bott_cot,SIGNAL(clicked()),this,SLOT(trigonom_operation()));
    connect(ui->bott_asin,SIGNAL(clicked()),this,SLOT(trigonom_operation()));
    connect(ui->bott_acos,SIGNAL(clicked()),this,SLOT(trigonom_operation()));
    connect(ui->bott_atan,SIGNAL(clicked()),this,SLOT(trigonom_operation()));
    connect(ui->bott_acot,SIGNAL(clicked()),this,SLOT(trigonom_operation()));
}

MyQtClass::~MyQtClass()
{
    delete ui;
}

void MyQtClass::on_delete1_clicked()
{
    ui->celsius1->setText("0");
    ui->minute1->setText("0");
    ui->second1->setText("0");
}

void MyQtClass::on_delete2_clicked()
{
    ui->celsius2->setText("0");
    ui->minute2->setText("0");
    ui->second2->setText("0");
}

void MyQtClass::variables()
{
    c1 = ui->celsius1->text().toInt(); c2 = ui->celsius2->text().toInt();
    m1 = ui->minute1->text().toInt(); m2 = ui->minute2->text().toInt();
    s1 = ui->second1->text().toInt(); s2 = ui->second2->text().toInt();
}

void MyQtClass::change_sign()
{
    QPushButton *bot = (QPushButton *)sender();
    QString new_result;
    variables();

    if (c2 != 0 || m2 != 0 || s2 != 0)
        QMessageBox::warning(this, "Ошибка", "Для выбранной операции необходимо в верхнюю строку ввести единственное значение угла.");
    else if ((c1 < 0 && (m1 > 0 || s1 > 0)) || (c1 > 0 && (m1 < 0 || s1 < 0)))
        QMessageBox::warning(this, "Ошибка", "Значения угла введены некорректно.");
    else if (bot->text() == "+/-")
    {
        if (c1 < 0)
        {
            value = (c1 + m1 / 60.0 + s1 / 3600.0) + 360;
            vc = (int)value;
            dpart = (value - vc) * 60;
            vm = (int)dpart;
            vs = (dpart - vm) * 60;
        }
        else
        {
            value = (c1 + m1 / 60.0 + s1 / 3600.0) - 360;
            vc = (int)value;
            dpart = (value - vc) * 60;
            vm = (int)dpart;
            vs = (dpart - vm) * 60;
        }

        new_result = QString::number(vc) + "°" + QString::number(vm) + "'" + QString::number(vs) + "''";

        ui->result->setText(new_result);
    }
}

void MyQtClass::math_operation()
{
    QPushButton *bot = (QPushButton *)sender();
    QString new_result;
    variables();

    if ((c1 < 0 && (m1 > 0 || s1 > 0)) || (c1 > 0 && (m1 < 0 || s1 < 0)))
        QMessageBox::warning(this, "Ошибка", "Значения угла введены некорректно.");
    else if (bot->text() == "+")
    {
        if (c1 < 0) value1 = (c1 + m1 / 60.0 + s1 / 3600.0) - 360;
        else value1 = c1 + m1 / 60.0 + s1 / 3600.0;
        if (c2 < 0) value2 = (c2 + m2 / 60.0 + s2 / 3600.0) - 360;
        else value2 = c2 + m2 / 60.0 + s2 / 3600.0;
        value3 = value1 + value2;

        vc = (int)value3;
        dpart = (value3 - vc) * 60;
        vm = (int)dpart;
        vs = (dpart - vm) * 60;
        new_result = QString::number(vc) + "°" + QString::number(vm) + "'" + QString::number(vs) + "''";

        ui->result->setText(new_result);
    }
    else if (bot->text() == "-")
    {
        if (c1 < 0) value1 = (c1 + m1 / 60.0 + s1 / 3600.0) - 360;
        else value1 = c1 + m1 / 60.0 + s1 / 3600.0;
        if (c2 < 0) value2 = (c2 + m2 / 60.0 + s2 / 3600.0) - 360;
        else value2 = c2 + m2 / 60.0 + s2 / 3600.0;
        value3 = value1 - value2;

        vc = (int)value3;
        dpart = (value3 - vc) * 60;
        vm = (int)dpart;
        vs = (dpart - vm) * 60;
        new_result = QString::number(vc) + "°" + QString::number(vm) + "'" + QString::number(vs) + "''";

        ui->result->setText(new_result);
    }
    else if (bot->text() == "x")
    {
        if (c1 < 0) value1 = (c1 + m1 / 60.0 + s1 / 3600.0) - 360;
        else value1 = c1 + m1 / 60.0 + s1 / 3600.0;
        if (c2 < 0) value2 = (c2 + m2 / 60.0 + s2 / 3600.0) - 360;
        else value2 = c2 + m2 / 60.0 + s2 / 3600.0;
        value3 = value1 * value2;

        vc = (int)value3;
        dpart = (value3 - vc) * 60;
        vm = (int)dpart;
        vs = (dpart - vm) * 60;
        new_result = QString::number(vc) + "°" + QString::number(vm) + "'" + QString::number(vs) + "''";

        ui->result->setText(new_result);
    }
    else if (bot->text() == "÷")
    {
        if (c1 < 0) value1 = (c1 + m1 / 60.0 + s1 / 3600.0) - 360;
        else value1 = c1 + m1 / 60.0 + s1 / 3600.0;
        if (c2 < 0) value2 = (c2 + m2 / 60.0 + s2 / 3600.0) - 360;
        else value2 = c2 + m2 / 60.0 + s2 / 3600.0;
        value3 = value1 / value2;

        vc = (int)value3;
        dpart = (value3 - vc) * 60;
        vm = (int)dpart;
        vs = (dpart - vm) * 60;
        new_result = QString::number(vc) + "°" + QString::number(vm) + "'" + QString::number(vs) + "''";

        ui->result->setText(new_result);
    }
}

void MyQtClass::trigonom_operation()
{
    QPushButton *bot = (QPushButton *)sender();
    QString new_result;
    variables();

    if (c2 != 0 || m2 != 0 || s2 != 0)
        QMessageBox::warning(this, "Ошибка", "Для выбранной операции необходимо в верхнюю строку ввести единственное значение угла.");
    else if ((c1 < 0 && (m1 > 0 || s1 > 0)) || (c1 > 0 && (m1 < 0 || s1 < 0)))
        QMessageBox::warning(this, "Ошибка", "Значения угла введены некорректно.");
    else if (bot->text() == "sin")
    {
        if (c1 < 0) value1 = (c1 + m1 / 60.0 + s1 / 3600.0) + 360;
        else value1 = c1 + m1 / 60.0 + s1 / 3600.0;
        value = sin(value1);

        new_result = QString::number(value);

        ui->result->setText(new_result);
    }
    else if (bot->text() == "cos")
    {
        if (c1 < 0) value1 = (c1 + m1 / 60.0 + s1 / 3600.0) + 360;
        else value1 = c1 + m1 / 60.0 + s1 / 3600.0;
        value = cos(value1);

        new_result = QString::number(value);

        ui->result->setText(new_result);
    }
    else if (bot->text() == "tan")
    {
        if (c1 < 0) value1 = (c1 + m1 / 60.0 + s1 / 3600.0) + 360;
        else value1 = c1 + m1 / 60.0 + s1 / 3600.0;
        value = tan(value1);

        new_result = QString::number(value);

        ui->result->setText(new_result);
    }
    else if (bot->text() == "cot")
    {
        if (c1 < 0) value1 = (c1 + m1 / 60.0 + s1 / 3600.0) + 360;
        else value1 = c1 + m1 / 60.0 + s1 / 3600.0;
        value = 1 / tan(value1);

        new_result = QString::number(value);

        ui->result->setText(new_result);
    }
    else if (bot->text() == "asin")
    {
        if (c1 < 0) value1 = (c1 + m1 / 60.0 + s1 / 3600.0) + 360;
        else value1 = c1 + m1 / 60.0 + s1 / 3600.0;
        value = asin(value1);

        new_result = QString::number(value);

        ui->result->setText(new_result);
    }
    else if (bot->text() == "acos")
    {
        if (c1 < 0) value1 = (c1 + m1 / 60.0 + s1 / 3600.0) + 360;
        else value1 = c1 + m1 / 60.0 + s1 / 3600.0;
        value = acos(value1);

        new_result = QString::number(value);

        ui->result->setText(new_result);
    }
    else if (bot->text() == "atan")
    {
        if (c1 < 0) value1 = (c1 + m1 / 60.0 + s1 / 3600.0) + 360;
        else value1 = c1 + m1 / 60.0 + s1 / 3600.0;
        value = atan(value1);

        new_result = QString::number(value);

        ui->result->setText(new_result);
    }
    else if (bot->text() == "acot")
    {
        if (c1 < 0) value1 = (c1 + m1 / 60.0 + s1 / 3600.0) + 360;
        else value1 = c1 + m1 / 60.0 + s1 / 3600.0;
        value = 1.0 / atan(value1);

        new_result = QString::number(value);

        ui->result->setText(new_result);
    }
}
