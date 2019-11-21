#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow2.h"
#include "converter.h"
#include <QtMath>
#include <QTextStream>
#include <QFile>
#include<QMessageBox>
#include "moneyconverter.h"
#include "calculationscreen.h"

MainWindow::MainWindow(QWidget * parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
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

    connect(ui->clear, SIGNAL(clicked()), this, SLOT(on_clear_clicked()));
    connect(ui->clear_all, SIGNAL(clicked()), this, SLOT(on_clear_all_clicked()));
    connect(ui->stepen, SIGNAL(clicked()), this, SLOT(power()));
    connect(ui->koren, SIGNAL(clicked()), this, SLOT(koren()));

    connect(ui->percent, SIGNAL(clicked()), this, SLOT(on_signproc_clicked()));
    connect(ui->percent_2, SIGNAL(clicked()), this, SLOT(on_signproc_clicked()));
    connect(ui->plus, SIGNAL(clicked()), this, SLOT(math_op()));
    connect(ui->minus, SIGNAL(clicked()), this, SLOT(math_op()));
    connect(ui->div, SIGNAL(clicked()), this, SLOT(math_op()));
    connect(ui->mul, SIGNAL(clicked()), this, SLOT(math_op()));
    connect(ui->plmin, SIGNAL(clicked()), this, SLOT(on_signproc_clicked()));
    connect(ui->ravno, SIGNAL(clicked()), this, SLOT(equalClicked()));
}

MainWindow::~MainWindow() {

    delete ui;
}

void MainWindow::on_actionexit_triggered() {

    QApplication::quit();
}

void MainWindow::abortOperation() {

    on_clear_all_clicked();
    ui->label->setText(tr("####"));
}

bool MainWindow::calculate(double rightOperand, const QString & pendingOperator) {

    if (pendingOperator == tr("+")) {
        sumSoFar += rightOperand;
    } else if (pendingOperator == tr("-")) {
        sumSoFar -= rightOperand;
    } else if (pendingOperator == tr("*")) {
        factorSoFar *= rightOperand;
    } else if (pendingOperator == tr("/")) {
        if (rightOperand == 0.0)
            return false;
        factorSoFar /= rightOperand;
    }
    return true;
}

void MainWindow::WriteToFile(QString info) {

    QFile file("C:\\Users\\Winston\\Documents\\S&C calculator\\mode 1.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append)){
        QMessageBox::warning(this, "WARNING!", "You are not perform any calculations");
        return;
    }

    QTextStream stream(&file);
    stream << info;

    file.flush();
    file.close();
}

void MainWindow::digits_numbers() {

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

void MainWindow::math_op() {

    QPushButton *button = qobject_cast<QPushButton *>(sender());

    num_f = ui->label->text().toDouble();
    ui->label->setText("");
    button->setChecked(true);
}

void MainWindow::on_dot_clicked() {

    if(!(ui->label->text().contains('.')))
        ui->label->setText(ui->label->text()+".");

    QString info = ui->dot->text();
    WriteToFile(info);
}

void MainWindow::power() {

    QPushButton *button = qobject_cast<QPushButton *>(sender());
    double operand = ui->label->text().toDouble();
    double result = 0.0;

    if (button->text() == "^") {
        if (operand < 0.0) {
            abortOperation();
            return;
        }
        result = std::pow(operand, 2.0);
    }
    ui->label->setText(QString::number(result, 'g', 15));
    waitingForOperand = true;

    QString info = ui->stepen->text();
    QString otv = QString::number(result, 'g', 15);
    WriteToFile(info+"="+otv);
}

void MainWindow::clearMemory() {

    sumInMemory = 0.0;
}

void MainWindow::readMemory() {

    ui->label->setText(QString::number(sumInMemory));
    waitingForOperand = true;
}

void MainWindow::setMemory() {

    equalClicked();
    sumInMemory = ui->label->text().toDouble();
}

void MainWindow::addToMemory() {

    equalClicked();
    sumInMemory += ui->label->text().toDouble();
}

void MainWindow::koren() {

    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    number = sqrt(number);
    new_label = QString::number(number, 'g', 15);
    ui->label->setText(new_label);

    QString info = ui->koren->text();
    QString otv = QString::number(number, 'g', 15);
    WriteToFile(info+"="+otv);
}

void MainWindow::equalClicked() {

    QString info;
    double operand = ui->label->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }
    if (!pendingAdditiveOperator.isEmpty()) {
        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        pendingAdditiveOperator.clear();
    } else {
        sumSoFar = operand;
        info = "=";
    }

    ui->label->setText(QString::number(sumSoFar));
    QString otv = QString::number(sumSoFar);
    sumSoFar = 0.0;
    waitingForOperand = true;

    WriteToFile(info+"="+otv+"\n");
}

void MainWindow::on_mul_clicked() {

    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = ui->label->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        ui->label->setText(QString::number(factorSoFar));
    } else {
        factorSoFar = operand;
    }

    pendingMultiplicativeOperator = clickedOperator;
    waitingForOperand = true;

    ui->mul->setChecked(true);

    QString info = ui->mul->text();
    WriteToFile(info);
}

void MainWindow::on_plus_clicked() {

    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = ui->label->text().toDouble();
    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        ui->label->setText(QString::number(factorSoFar));
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }
    if (!pendingAdditiveOperator.isEmpty()) {
        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        ui->label->setText(QString::number(sumSoFar));
    } else {
        sumSoFar = operand;
    }
    pendingAdditiveOperator = clickedOperator;
    waitingForOperand = true;
    ui->plus->setChecked(true);

    QString info = ui->plus->text();
    WriteToFile(info);
}

void MainWindow::on_clear_clicked() {

    ui->div->setChecked(false);
    ui->plus->setChecked(false);
    ui->minus->setChecked(false);
    ui->mul->setChecked(false);

    ui->label->setText("0");
    waitingForOperand = true;
}

void MainWindow::on_signproc_clicked() {

    QPushButton *button = qobject_cast<QPushButton *>(sender());
    double all_numbers;
    QString new_label, info;

    if(button->text()== "+/-"){
        all_numbers = (ui->label->text()).toDouble();
        all_numbers = all_numbers*-1;
        new_label = QString::number(all_numbers, 'g', 15);
        ui->label->setText(new_label);
        info = ui->plmin->text();
    }else if(button->text()== "→%"){
        all_numbers = (ui->label->text()).toDouble();
        all_numbers = all_numbers*0.01;
        new_label = QString::number(all_numbers, 'g', 15);
        ui->label->setText(new_label);
        info = ui->percent->text();
    }else if(button->text()== "%→"){
        all_numbers = (ui->label->text()).toDouble();
        all_numbers = all_numbers*100;
        new_label = QString::number(all_numbers, 'g', 15);
        ui->label->setText(new_label);
        info = ui->percent_2->text();
    }

    WriteToFile(info);
}

void MainWindow::on_clear_all_clicked() {

    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator.clear();
    pendingMultiplicativeOperator.clear();
    ui->label->setText("0");
    waitingForOperand = true;
}

void MainWindow::on_minus_clicked() {

    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = ui->label->text().toDouble();
    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        ui->label->setText(QString::number(factorSoFar));
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }
    if (!pendingAdditiveOperator.isEmpty()) {
        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        ui->label->setText(QString::number(sumSoFar));
    } else {
        sumSoFar = operand;
    }
    pendingAdditiveOperator = clickedOperator;
    waitingForOperand = true;
    ui->minus->setChecked(true);

    QString info = ui->minus->text();
    WriteToFile(info);
}

void MainWindow::on_div_clicked() {

    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = ui->label->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        ui->label->setText(QString::number(factorSoFar));
    } else {
        factorSoFar = operand;
    }

    pendingMultiplicativeOperator = clickedOperator;
    waitingForOperand = true;

    QString info = ui->div->text();
    WriteToFile(info);
}

void MainWindow::on_actionStage_2_trigonometry_triggered() {

    MainWindow2 *sWindow = new MainWindow2();
    sWindow->show();
    this->close();
}

void MainWindow::on_actionStage_3_converter_2_triggered() {

    Converter *conv = new Converter();
    conv->show();
    this->close();
}

void MainWindow::on_actionStage_4_money_converter_triggered() {

    MoneyConverter *monc = new MoneyConverter();
    monc->show();
    this->close();
}

void MainWindow::on_actionFull_screen_triggered() {

    showFullScreen();
}

void MainWindow::on_actionStandart_screen_triggered() {

    showNormal();
}

void MainWindow::on_backspace_clicked() {

    QString text = ui->label->text();
    text.chop(1);
    if (text.isEmpty()) {
        text = "0";
        waitingForOperand = true;
    }
    ui->label->setText(text);
}

void MainWindow::on_actionCalculation_list_triggered() {

    CalculationScreen *calc = new CalculationScreen;
    calc->show();
}

