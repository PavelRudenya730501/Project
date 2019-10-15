#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow2.h"
#include "converter.h"
#include "cmath"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    sumInMemory = 0.0;
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    waitingForOperand = true;

    ui->setupUi(this);
    //ui->back->hide();
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
    connect(ui->ravno, SIGNAL(clicked()), this, SLOT(equalClicked()));
    connect(ui->stepen, SIGNAL(clicked()), this, SLOT(power()));
    connect(ui->koren, SIGNAL(clicked()), this, SLOT(koren()));
    connect(ui->back, SIGNAL(clicked()), this, SLOT(on_back_clicked()));
    connect(ui->percent, SIGNAL(clicked()), this, SLOT(on_signproc_clicked()));

    /*
    connect(ui->pushButton_dec, SIGNAL(clicked), this, SLOT(operations()));
    connect(ui->pushButton_skl, SIGNAL(clicked), this, SLOT(operations()));
    connect(ui->pushButton_skr, SIGNAL(clicked), this, SLOT(operations()));

    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionexit_triggered()
{
    QApplication::quit();
}
void MainWindow::on_action2_stage_triggered()
{
    MainWindow2 *sWindow = new MainWindow2();
    sWindow->show();
    this->close();
}
void MainWindow::on_actionStage_3_converter_triggered()
{
    Converter *conv = new Converter();
    conv->show();
    this->close();
}

void MainWindow::digits_numbers()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
        int digitValue = clickedButton->text().toInt();
        if (ui->label->text() == "0" && digitValue == 0.0)
            return;

        if (waitingForOperand) {
            ui->label->clear();
            waitingForOperand = false;
        }
        ui->label->setText(ui->label->text() + QString::number(digitValue));
}

void MainWindow::power()
{
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
    ui->label->setText(QString::number(result));
    waitingForOperand = true;
}

void MainWindow::koren()
{
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    number = sqrt(number);
    new_label = QString::number(number, 'g', 15);
    ui->label->setText(new_label);
}

void MainWindow::on_plus_clicked()
{
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
}

void MainWindow::on_minus_clicked()
{
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

}

void MainWindow::on_mul_clicked()
{
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
}

void MainWindow::equalClicked()
{
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
    }

    ui->label->setText(QString::number(sumSoFar));
    sumSoFar = 0.0;
    waitingForOperand = true;
}

void MainWindow::on_dot_clicked()
{
    if(!(ui->label->text().contains('.')))
    ui->label->setText(ui->label->text()+".");
}

void MainWindow::on_signproc_clicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    double all_numbers;
    QString new_label;

    if(button->text()== "+/-"){
        all_numbers = (ui->label->text()).toDouble();
        all_numbers = all_numbers*-1;
        new_label = QString::number(all_numbers, 'g', 15);
        ui->label->setText(new_label);
    }else if(button->text()== "%"){
        all_numbers = (ui->label->text()).toDouble();
        all_numbers = all_numbers*00.1;
        new_label = QString::number(all_numbers, 'g', 15);
        ui->label->setText(new_label);
    }
    /*QString text = ui->label->text();
    double value = text.toDouble();

    if (value > 0.0) {
        text.prepend(tr("-"));
    } else if (value < 0.0) {
        text.remove(0, 1);
    }
    ui->label->setText(text);*/
}

void MainWindow::on_back_clicked()
{
    if (waitingForOperand)
        return;

    QString text = ui->label->text();
    text.chop(1);
    if (text.isEmpty()) {
        text = "0";
        waitingForOperand = true;
    }
    ui->label->setText(text);
}

void MainWindow::on_clear_clicked()
{
    ui->back->show();
    if (waitingForOperand)
        return;

    ui->label->setText("0");
    waitingForOperand = true;
}

void MainWindow::on_clear_all_clicked()
{
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator.clear();
    pendingMultiplicativeOperator.clear();
    ui->label->setText("0");
    waitingForOperand = true;
}

void MainWindow::clearMemory()
{
    sumInMemory = 0.0;
}
void MainWindow::readMemory()
{
    ui->label->setText(QString::number(sumInMemory));
    waitingForOperand = true;
}
void MainWindow::setMemory()
{
    equalClicked();
    sumInMemory = ui->label->text().toDouble();
}
void MainWindow::addToMemory()
{
    equalClicked();
    sumInMemory += ui->label->text().toDouble();
}

void MainWindow::abortOperation()
{
    on_clear_all_clicked();
    ui->label->setText(tr("####"));
}

bool MainWindow::calculate(double rightOperand, const QString &pendingOperator)
{
    if (pendingOperator == tr("+")) {
        sumSoFar += rightOperand;
    } else if (pendingOperator == tr("-")) {
        sumSoFar -= rightOperand;
    } else if (pendingOperator == tr("\303\227")) {
        factorSoFar *= rightOperand;
    } else if (pendingOperator == tr("/")) {
        if (rightOperand == 0.0)
            return false;
        factorSoFar /= rightOperand;
    }
    return true;
}
