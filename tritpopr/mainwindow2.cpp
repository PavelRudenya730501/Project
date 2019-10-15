#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "QtCore/qmath.h"
#include "iostream"
#include "converter.h"
#include "mainwindow.h"

using namespace std;

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));

    connect(ui->sin, SIGNAL(clicked()), this, SLOT(fsin()));
    connect(ui->cos, SIGNAL(clicked()), this, SLOT(fcos()));
    connect(ui->tg, SIGNAL(clicked()), this, SLOT(ftan()));
    connect(ui->ctg, SIGNAL(clicked()), this, SLOT(fctg()));
    connect(ui->Asin, SIGNAL(clicked()), this, SLOT(fAsin()));
    connect(ui->Acos, SIGNAL(clicked()), this, SLOT(fAcos()));
    connect(ui->Atan, SIGNAL(clicked()), this, SLOT(fAtan()));
    connect(ui->degr, SIGNAL(clicked()), this, SLOT(degree()));
    //connect(ui->Actg, SIGNAL(clicked()), this, SLOT(fActg()));
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::digits_numbers()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    double all_numbers;
    QString new_label;

    all_numbers = (ui->label->text() + button->text()).toDouble();
    new_label = QString::number(all_numbers, 'g', 15);
    ui->label->setText(new_label);
}

void MainWindow2::fsin(){
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    number = qSin(number);
    new_label = QString::number(number, 'g', 15);
    ui->label->setText(new_label);

}

void MainWindow2::fcos(){
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    number = qCos(number);
    new_label = QString::number(number, 'g', 15);
    ui->label->setText(new_label);
}

void MainWindow2::ftan(){
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    number = qTan(number);
    new_label = QString::number(number, 'g', 15);
    ui->label->setText(new_label);
}

void MainWindow2::fctg(){
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    number = 1/qTan(number);
    new_label = QString::number(number, 'g', 15);
    ui->label->setText(new_label);
}

void MainWindow2::fAsin(){
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    number = qSin(number);
    new_label = QString::number(number, 'g', 15);
    ui->label->setText(new_label);

}

void MainWindow2::fAcos(){
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    number = qCos(number);
    new_label = QString::number(number, 'g', 15);
    ui->label->setText(new_label);
}

void MainWindow2::fAtan(){
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    number = qTan(number);
    new_label = QString::number(number, 'g', 15);
    ui->label->setText(new_label);
}

void MainWindow2::degre(){
    double numb;
    QString new_label;
    numb = (ui->label->text()).toDouble();
    double pi = 3.14159265359, dr;
    numb = (180/pi)*numb;
    dr = numb - (int)numb;
    dr*=60;
    int min = int(dr);
    dr*=60;
    int sec = int(dr);
    cout<<"градусы: "<<numb<<"минуты: "<<min<<"секунды: "<<sec;
    new_label = QString::number(numb, 'g', 15);
    ui->label->setText(new_label);
}
void MainWindow2::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow2::on_actionStage1_triggered()
{
    MainWindow *window = new MainWindow();
    window->show();
    this->close();
}

void MainWindow2::on_pushButton_clear_clicked()
{
    ui->label->clear();
    ui->sin->setChecked(false);
    ui->cos->setChecked(false);
    ui->tg->setChecked(false);
    ui->ctg->setChecked(false);

    ui->label->setText("0");
}

void MainWindow2::on_pushButton_22_clicked()
{
    if(!(ui->label->text().contains('.')))
    ui->label->setText(ui->label->text()+".");
}

void MainWindow2::on_actionStage_3_converter_triggered()
{
    Converter *conv = new Converter();
    conv->show();
    this->close();
}
