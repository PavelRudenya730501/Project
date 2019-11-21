#include "converter.h"
#include "ui_converter.h"
#include "converter.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "moneyconverter.h"
#include "mainwindow.h"
#include "mainwindow2.h"
#include "calculationscreen.h"

Converter::Converter(QWidget * parent) : QMainWindow(parent), ui(new Ui::Converter)
{
    sumInMemory = 0.0;
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    waitingForOperand = true;

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

    connect(ui->yards, SIGNAL(clicked()), this, SLOT(fyards()));
    connect(ui->miles, SIGNAL(clicked()), this, SLOT(fmiles()));
    connect(ui->futs, SIGNAL(clicked()), this, SLOT(futs()));

    connect(ui->miligram, SIGNAL(clicked()), this, SLOT(mlgr()));
    connect(ui->gram, SIGNAL(clicked()), this, SLOT(gram()));
    connect(ui->kilogram, SIGNAL(clicked()), this, SLOT(kg()));
    connect(ui->tona, SIGNAL(clicked()), this, SLOT(tona()));

}

Converter::~Converter() {

    delete ui;
}

void Converter::WriteToFile(QString info) {

    QFile file("C:\\Users\\Winston\\Documents\\S&C calculator\\mode 1.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append)){
        QMessageBox::warning(this, "WARNING!", "You are not perform any calculations");
        return;
    }
    QTextStream stream(&file);
    stream << info << endl;

    file.flush();
    file.close();
}

void Converter::on_dot_clicked() {

    if(!(ui->label->text().contains('.')))
        ui->label->setText(ui->label->text()+".");
}

void Converter::digits_numbers() {

    QPushButton *button = qobject_cast<QPushButton *>(sender());
    double all_numbers;
    QString new_lable, info = button->text();

    if(ui->label->text().contains("." ) && button->text() == "0"){
        new_lable = ui->label->text() + button->text();
    } else{
        all_numbers = (ui->label->text() + button->text()).toDouble();
        new_lable = QString::number(all_numbers, 'g', 20);
    }

    ui->label->setText(new_lable);

    WriteToFile(info);
}

void Converter::on_actionExit_triggered() {

    QApplication::quit();
}

void Converter::on_actionStage_1_standart_2_triggered() {

    MainWindow *window = new MainWindow();
    window->show();
    this->close();
}

void Converter::on_actionStage_2_trigonometry_2_triggered() {

    MainWindow2 *sWindow = new MainWindow2();
    sWindow->show();
    this->close();
}

void Converter::on_actionStage_4_money_converter_triggered() {

    MoneyConverter *monc = new MoneyConverter();
    monc->show();
    this->close();
}

void Converter::on_clear_bar_clicked() {

    if (waitingForOperand)
        return;
    ui->label->setText("0");
    waitingForOperand = true;

    ui->mm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->sm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->met_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->km_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->yard_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->fut_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mile_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mgr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->funts_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->gr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->kg_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->ton_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
}

void Converter::on_clear_all_bar_clicked() {

    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator.clear();
    pendingMultiplicativeOperator.clear();
    ui->label->setText("0");
    waitingForOperand = true;
    pressedmmb = false;
    pressedsmb = false;
    pressedmtrb = false;
    pressedkmtrb = false;
    pressedyrdb = false;
    pressedftsb = false;
    pressedmlsb = false;

    pressedmgrb = false;
    pressedgrb = false;
    pressedkgrb = false;
    pressedtnb = false;
    pressedfuntb = false;

    ui->mm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->sm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->met_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->km_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->yard_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->fut_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mile_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mgr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->funts_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->gr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->kg_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->ton_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
}

//###########################################################

void Converter::on_mm_bar_clicked() {

    ui->mm_bar->setStyleSheet("color: red; background-color: pink; border: 2px solid black;");
    ui->sm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->met_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->km_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->yard_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->fut_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mile_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mgr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->funts->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->gr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->kg_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->ton_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");

    pressedmmb = true;
    pressedsmb = false;
    pressedmtrb = false;
    pressedkmtrb = false;
    pressedyrdb = false;
    pressedftsb = false;
    pressedmlsb = false;

    QString info = ui->mm_bar->text()+" is chosen ";
    WriteToFile(info);
}

void Converter::on_sm_bar_clicked() {

    ui->mm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->sm_bar->setStyleSheet("color: red; background-color: pink; border: 2px solid black;");
    ui->met_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->km_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->yard_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->fut_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mile_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mgr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->funts->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->gr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->kg_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->ton_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");

    pressedsmb = true;
    pressedmmb = false;
    pressedmtrb = false;
    pressedkmtrb = false;
    pressedyrdb = false;
    pressedftsb = false;
    pressedmlsb = false;
    QString info = ui->sm_bar->text()+" is chosen ";
    WriteToFile(info);
}

void Converter::on_met_bar_clicked() {

    ui->mm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->sm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->met_bar->setStyleSheet("color: red; background-color: pink; border: 2px solid black;");
    ui->km_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->yard_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->fut_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mile_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mgr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->funts->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->gr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->kg_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->ton_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");

    pressedmtrb = true;
    pressedmmb = false;
    pressedsmb = false;
    pressedkmtrb = false;
    pressedyrdb = false;
    pressedftsb = false;
    pressedmlsb = false;
    QString info = ui->met_bar->text()+" is chosen ";
    WriteToFile(info);
}

void Converter::on_km_bar_clicked() {

    ui->mm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->sm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->met_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->km_bar->setStyleSheet("color: red; background-color: pink; border: 2px solid black;");
    ui->yard_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->fut_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mile_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mgr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->funts->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->gr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->kg_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->ton_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");

    pressedkmtrb = true;
    pressedmmb = false;
    pressedsmb = false;
    pressedmtrb = false;
    pressedyrdb = false;
    pressedftsb = false;
    pressedmlsb = false;
    QString info = ui->km_bar->text()+" is chosen ";
    WriteToFile(info);
}

void Converter::on_milimeters_clicked() {

    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    if(pressedmmb==true){
        new_label = QString::number(number, 'g', 20);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedsmb==true) {
        ui->label->setText("0");
        number = 10*number;
        new_label = QString::number(number, 'g', 20);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedmtrb==true) {
        ui->label->setText("0");
        number = 1000*number;
        new_label = QString::number(number, 'g', 20);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedkmtrb==true) {
        ui->label->setText("0");
        number = number*1000000;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedyrdb==true) {
        ui->label->setText("0");
        number = number*914.4;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedmlsb==true) {
        ui->label->setText("0");
        number = number*1609344;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedftsb==true) {
        ui->label->setText("0");
        number = number*304.8;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }
    else{
        ui->label->setText("Incorrect input!");
    }
}

void Converter::on_smeters_clicked() {

    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    if(pressedmmb==true){
        ui->label->setText("0");
        number = 0.1*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedsmb==true) {
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedmtrb==true) {
        ui->label->setText("0");
        number = 100*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedkmtrb==true) {
        ui->label->setText("0");
        number = 100000*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedyrdb==true) {
        ui->label->setText("0");
        number = number/0.010936132983377;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedftsb==true) {
        ui->label->setText("0");
        number = number/0.032808333333465;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedmlsb==true) {
        ui->label->setText("0");
        number = number/0.00000621371;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }
    else{
        ui->label->setText("Incorrect input!");
    }
    QString info = ui->smeters->text()+"=";
    WriteToFile(info);
}

void Converter::on_kilometers_clicked() {

    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    if(pressedmmb==true){
        ui->label->setText("0");
        number = number*0.000001;
        new_label = QString::number(number, 'r', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedsmb==true) {
        ui->label->setText("0");
        number = number*0.00001;
        new_label = QString::number(number, 'e', 10);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedmtrb==true) {
        ui->label->setText("0");
        number = 0.001*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedkmtrb==true) {
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedyrdb==true) {
        ui->label->setText("0");
        number = number*0.0009144;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedftsb==true) {
        ui->label->setText("0");
        number = number*0.00030408;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedmlsb==true) {
        ui->label->setText("0");
        number = number*1.609344;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }
    else{
        ui->label->setText("Incorrect input!");
    }
    QString info = ui->kilometers->text()+"=";
    WriteToFile(info);
}

void Converter::on_meters_clicked() {

    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    if(pressedmmb==true){
        ui->label->setText("0");
        number = 0.001*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedsmb==true) {
        ui->label->setText("0");
        number = 0.01*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedmtrb==true) {
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedkmtrb==true) {
        ui->label->setText("0");
        number = 1000*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedyrdb==true) {
        ui->label->setText("0");
        number = number*0.9144;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedftsb==true) {
        ui->label->setText("0");
        number = number/3.2808333333465;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedmlsb==true) {
        ui->label->setText("0");
        number = number/0.000621371;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }
    else{
        ui->label->setText("Incorrect input!");
    }
    QString info = ui->meters->text()+"=";
    WriteToFile(info);
}

void Converter::on_yard_bar_clicked() {

    ui->mm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->sm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->met_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->km_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->yard_bar->setStyleSheet("color: red; background-color: pink; border: 2px solid black;");
    ui->fut_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mile_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mgr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->funts->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->gr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->kg_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->ton_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");

    pressedkmtrb = false;
    pressedmmb = false;
    pressedsmb = false;
    pressedmtrb = false;
    pressedyrdb = true;
    pressedftsb = false;
    pressedmlsb = false;
    QString info = ui->yard_bar->text()+" is chosen ";
    WriteToFile(info);
}

void Converter::on_mile_bar_clicked() {

    ui->mm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->sm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->met_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->km_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->yard_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->fut_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mile_bar->setStyleSheet("color: red; background-color: pink; border: 2px solid black;");
    ui->mgr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->funts->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->gr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->kg_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->ton_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");


    pressedkmtrb = false;
    pressedmmb = false;
    pressedsmb = false;
    pressedmtrb = false;
    pressedyrdb = false;
    pressedftsb = false;
    pressedmlsb = true;
    QString info = ui->mile_bar->text()+" is chosen ";
    WriteToFile(info);
}

void Converter::on_fut_bar_clicked() {

    ui->mm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->sm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->met_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->km_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->yard_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->fut_bar->setStyleSheet("color: red; background-color: pink; border: 2px solid black;");
    ui->mile_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mgr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->funts->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->gr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->kg_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->ton_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");


    pressedkmtrb = false;
    pressedmmb = false;
    pressedsmb = false;
    pressedmtrb = false;
    pressedyrdb = false;
    pressedftsb = true;
    pressedmlsb = false;
    QString info = ui->fut_bar->text()+" is chosen ";
    WriteToFile(info);
}

//####################################################

void Converter::on_yards_clicked() {

    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    if(pressedmmb==true){
        number = 0.000001*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedsmb==true) {
        number = 0.00001*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedmtrb==true) {
        number = 0.001*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedkmtrb==true) {
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedyrdb==true) {
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedftsb==true) {
        number = number*0.333333;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedmlsb==true) {
        number = number*0.000189394;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }
    else{
        ui->label->setText("Incorrect input!");
    }
    QString info = ui->yards->text()+"=";
    WriteToFile(info);
}

void Converter::on_miles_clicked() {

    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    if(pressedmmb==true){
        number = 0.000001*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedsmb==true) {
        number = 0.00001*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedmtrb==true) {
        number = 0.001*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedkmtrb==true) {
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedyrdb==true) {
        number = number*0.000568182;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedftsb==true) {
        number = number*0.000189394;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedmlsb==true) {
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }
    else{
        ui->label->setText("Incorrect input!");
    }
    QString info = ui->miles->text()+"=";
    WriteToFile(info);
}

void Converter::on_futs_clicked() {

    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    if(pressedmmb==true){
        number = 0.000001*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedsmb==true) {
        number = 0.00001*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedmtrb==true) {
        number = 0.001*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedkmtrb==true) {
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedyrdb==true) {
        number = number*3;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedftsb==true) {
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if (pressedmlsb==true) {
        number = number*5280;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }
    else{
        ui->label->setText("Incorrect input!");
    }
    QString info = ui->futs->text()+"=";
    WriteToFile(info);
}

//########################################################

void Converter::on_mgr_bar_clicked() {

    ui->mm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->sm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->met_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->km_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->yard_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->fut_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mile_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mgr_bar->setStyleSheet("color: red; background-color: pink; border: 2px solid black;");
    ui->funts_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->gr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->kg_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->ton_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");

    pressedmmb = false;
    pressedsmb = false;
    pressedmtrb = false;
    pressedkmtrb = false;
    pressedyrdb = false;
    pressedftsb = false;
    pressedmlsb = false;

    pressedmgrb = true;
    pressedgrb = false;
    pressedkgrb = false;
    pressedtnb = false;
    pressedfuntb = false;
    QString info = ui->mgr_bar->text()+" is chosen ";
    WriteToFile(info);
}

void Converter::on_gr_bar_clicked() {

    ui->mm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->sm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->met_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->km_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->yard_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->fut_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mile_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mgr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->funts_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->gr_bar->setStyleSheet("color: red; background-color: pink; border: 2px solid black;");
    ui->kg_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->ton_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");

    pressedmmb = false;
    pressedsmb = false;
    pressedmtrb = false;
    pressedkmtrb = false;
    pressedyrdb = false;
    pressedftsb = false;
    pressedmlsb = false;

    pressedmgrb = false;
    pressedgrb = true;
    pressedkgrb = false;
    pressedtnb = false;
    pressedfuntb = false;
    QString info = ui->gr_bar->text()+" is chosen ";
    WriteToFile(info);
}

void Converter::on_kg_bar_clicked() {

    ui->mm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->sm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->met_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->km_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->yard_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->fut_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mile_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mgr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->funts_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->gr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->kg_bar->setStyleSheet("color: red; background-color: pink; border: 2px solid black;");
    ui->ton_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");

    pressedmmb = false;
    pressedsmb = false;
    pressedmtrb = false;
    pressedkmtrb = false;
    pressedyrdb = false;
    pressedftsb = false;
    pressedmlsb = false;

    pressedmgrb = false;
    pressedgrb = false;
    pressedkgrb = true;
    pressedtnb = false;
    pressedfuntb = false;
    QString info = ui->kg_bar->text()+" is chosen ";
    WriteToFile(info);
}

void Converter::on_cnt_bar_clicked() {

    ui->mm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->sm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->met_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->km_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->yard_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->fut_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mile_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mgr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->funts_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->gr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->kg_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->ton_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");

    pressedmmb = false;
    pressedsmb = false;
    pressedmtrb = false;
    pressedkmtrb = false;
    pressedyrdb = false;
    pressedftsb = false;
    pressedmlsb = false;

    pressedmgrb = false;
    pressedgrb = false;
    pressedkgrb = false;
    pressedtnb = false;
    pressedfuntb = false;
}

void Converter::on_ton_bar_clicked() {

    ui->mm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->sm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->met_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->km_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->yard_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->fut_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mile_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mgr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->funts_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->gr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->kg_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->ton_bar->setStyleSheet("color: red; background-color: pink; border: 2px solid black;");

    pressedmmb = false;
    pressedsmb = false;
    pressedmtrb = false;
    pressedkmtrb = false;
    pressedyrdb = false;
    pressedftsb = false;
    pressedmlsb = false;

    pressedmgrb = false;
    pressedgrb = false;
    pressedkgrb = false;
    pressedtnb = true;
    pressedfuntb = false;
    QString info = ui->ton_bar->text()+" is chosen ";
    WriteToFile(info);
}

void Converter::on_funts_bar_clicked() {

    ui->mm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->sm_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->met_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->km_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->yard_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->fut_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mile_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->mgr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->funts_bar->setStyleSheet("color: red; background-color: pink; border: 2px solid black;");
    ui->gr_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->kg_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");
    ui->ton_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");

    pressedmmb = false;
    pressedsmb = false;
    pressedmtrb = false;
    pressedkmtrb = false;
    pressedyrdb = false;
    pressedftsb = false;
    pressedmlsb = false;

    pressedmgrb = false;
    pressedgrb = false;
    pressedkgrb = false;
    pressedtnb = false;
    pressedfuntb = true;
    QString info = ui->funts_bar->text()+" is chosen ";
    WriteToFile(info);
}

void Converter::on_miligram_clicked() {

    double number;
    number = (ui->label->text()).toDouble();
    QString new_label;
    if(pressedmgrb == true){
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedgrb == true){
        number = number*1000;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedkgrb == true){
        number = number*1000000;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedtnb == true){
        number = number*1000000000;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedfuntb ==true){
        number = number*453592.4;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }
    else{
        ui->label->setText("Incorrect input!");
    }
    QString info = ui->futs->text()+"=";
    WriteToFile(info);
}

void Converter::on_gram_clicked() {

    double number;
    number = (ui->label->text()).toDouble();
    QString new_label;
    if(pressedmgrb == true){
        number = number*0.001;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedgrb == true){
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedkgrb == true){
        number = number*1000;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedtnb == true){
        number = number*1000000;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedfuntb ==true){
        number = number*453.5924;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }
    else{
        ui->label->setText("Incorrect input!");
    }
    QString info = ui->futs->text()+"=";
    WriteToFile(info);
}

void Converter::on_kilogram_clicked() {

    double number;
    number = (ui->label->text()).toDouble();
    QString new_label;
    if(pressedmgrb == true){
        number = number*0.000001;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedgrb == true){
        number = number*0.001;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedkgrb == true){
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedtnb == true){
        number = number*1000;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedfuntb ==true){
        number = number*0.4535924;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }
    else{
        ui->label->setText("Incorrect input!");
    }
    QString info = ui->futs->text()+"=";
    WriteToFile(info);
}

void Converter::on_tona_clicked() {

    double number;
    number = (ui->label->text()).toDouble();
    QString new_label;
    if(pressedmgrb == true){
        number = number*0.000000001;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedgrb == true){
        number = number*0.000001;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedkgrb == true){
        number = number*0.001;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedtnb == true){
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedfuntb ==true){
        number = number*0.0004535924;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }
    else{
        ui->label->setText("Incorrect input!");
    }
    QString info = ui->futs->text()+"=";
    WriteToFile(info);
}

void Converter::on_funts_clicked() {

    double number;
    number = (ui->label->text()).toDouble();
    QString new_label;
    if(pressedmgrb == true){
        number = number*0.00000220462;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedgrb == true){
        number = number*0.00220462;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedkgrb == true){
        number = number*2.204623;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedtnb == true){
        number = number*2204.623;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }else if(pressedfuntb ==true){
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
        QString info = ui->milimeters->text()+"="+new_label;
        WriteToFile(info);
    }
    else{
        ui->label->setText("Incorrect input!");
    }
    QString info = ui->futs->text()+"=";
    WriteToFile(info);
}

void Converter::on_backspace_clicked() {

    QString text = ui->label->text();
    text.chop(1);
    if (text.isEmpty()) {
        text = "0";
        waitingForOperand = true;
    }
    ui->label->setText(text);
}

void Converter::on_actionCalculation_list_triggered() {

    CalculationScreen *calc = new CalculationScreen();
    calc->show();
}

