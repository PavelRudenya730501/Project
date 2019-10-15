#include "converter.h"
#include "ui_converter.h"
#include "mainwindow2.h"
#include "mainwindow.h"

Converter::Converter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Converter)
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

    connect(ui->milimeters, SIGNAL(clicked()), this, SLOT(fmlmtrs()));
    connect(ui->milimeters, SIGNAL(clicked()), this, SLOT(fsmtrs()));
    connect(ui->milimeters, SIGNAL(clicked()), this, SLOT(fdmtrs()));
    connect(ui->milimeters, SIGNAL(clicked()), this, SLOT(fmtrs()));
    connect(ui->milimeters, SIGNAL(clicked()), this, SLOT(fkmtrs()));
    connect(ui->milimeters, SIGNAL(clicked()), this, SLOT(fyards()));
    connect(ui->milimeters, SIGNAL(clicked()), this, SLOT(fmiles()));
    connect(ui->milimeters, SIGNAL(clicked()), this, SLOT(fut()));

    connect(ui->milimeters, SIGNAL(clicked()), this, SLOT(mlgr()));
    connect(ui->milimeters, SIGNAL(clicked()), this, SLOT(gram()));
    connect(ui->milimeters, SIGNAL(clicked()), this, SLOT(kg()));
    connect(ui->milimeters, SIGNAL(clicked()), this, SLOT(cntnr()));
    connect(ui->milimeters, SIGNAL(clicked()), this, SLOT(tona()));

}

Converter::~Converter()
{
    delete ui;
}

void Converter::on_dot_clicked()
{
    if(!(ui->label->text().contains('.')))
    ui->label->setText(ui->label->text()+".");
}

void Converter::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;
        all_numbers = (ui->label->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 15);
        ui->label->setText(new_label);
}

void Converter::on_actionExit_triggered()
{
    QApplication::quit();
}

void Converter::on_actionStage_2_trigonometry_triggered()
{
    MainWindow2 *sWindow = new MainWindow2();
    sWindow->show();
    this->close();
}

void Converter::on_actionStage_1_standart_triggered()
{
    MainWindow *window = new MainWindow();
    window->show();
    this->close();
}

void Converter::fmlmtrs(){
    //if(ui->pressedmm==true){

    //}
}
