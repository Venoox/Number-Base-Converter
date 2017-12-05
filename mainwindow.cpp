#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   this->setFixedSize(QSize(396,336));
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    int basefrom=ui->from->currentIndex(); // From which base
    int baseto=ui->to->currentIndex(); // To which base
    /* 0=binary
     * 1=octal
     * 2=decimal
     * 3=hexadecimal */
    QString input = ui->inputbox->text(); // Input from user
    if (basefrom==baseto) {
       ui->answerbox->setText(input);
    }
    else if (basefrom==0&&baseto==1) { // 2 -> 8
        bool success;
        auto value = input.toInt(&success, 2);
        if (success) {
            ui->answerbox->setText(QString::number(value, 8));
        }
        else {
            ui->answerbox->setText("Error");
        }
    }
    else if (basefrom==0&&baseto==2) { // 2 -> 10
        bool success;
        auto value = input.toInt(&success, 2);
        if (success) {
            ui->answerbox->setText(QString::number(value));
        }
        else {
            ui->answerbox->setText("Error");
        }
    }
    else if (basefrom==0&&baseto==3) { // 2 -> 16
        bool success;
        auto value = input.toInt(&success, 2);
        if (success) {
            ui->answerbox->setText(QString::number(value, 16));
        }
        else {
            ui->answerbox->setText("Error");
        }
    }
    else if (basefrom==1&&baseto==0) { // 8 -> 2
        bool success;
        auto value = input.toInt(&success, 8);
        if (success) {
            ui->answerbox->setText(QString::number(value, 2));
        }
        else {
            ui->answerbox->setText("Error");
        }
    }
    else if (basefrom==1&&baseto==2) { // 8 -> 10
        bool success;
        auto value = input.toInt(&success, 8);
        if (success) {
            ui->answerbox->setText(QString::number(value));
        }
        else {
            ui->answerbox->setText("Error");
        }
    }
    else if (basefrom==1&&baseto==3) { // 8 -> 16
        bool success;
        auto value = input.toInt(&success, 8);
        if (success) {
            ui->answerbox->setText(QString::number(value, 16));
        }
        else {
            ui->answerbox->setText("Error");
        }
    }
    else if (basefrom==2&&baseto==0) { // 10 -> 2
        ui->answerbox->setText(QString::number(input.toInt(),2));
    }
    else if (basefrom==2&&baseto==1) { // 10 -> 8
        ui->answerbox->setText(QString::number(input.toInt(),8));
    }
    else if (basefrom==2&&baseto==3) { // 10 -> 16
        ui->answerbox->setText(QString::number(input.toInt(),16));
    }
    else if (basefrom==3&&baseto==0) { // 16 -> 2
        bool success;
        auto value = input.toInt(&success, 16);
        if (success) {
            ui->answerbox->setText(QString::number(value, 2));
        }
        else {
            ui->answerbox->setText("Error");
        }
    }
    else if (basefrom==3&&baseto==1) { // 16 -> 8
        bool success;
        auto value = input.toInt(&success, 16);
        if (success) {
            ui->answerbox->setText(QString::number(value, 8));
        }
        else {
            ui->answerbox->setText("Error");
        }
    }
    else if (basefrom==3&&baseto==2) { // 16 -> 10
        bool success;
        auto value = input.toInt(&success, 16);
        if (success) {
            ui->answerbox->setText(QString::number(value));
        }
        else {
            ui->answerbox->setText("Error");
        }
    }

}
