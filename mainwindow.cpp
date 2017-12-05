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
// Check how long is a number
unsigned long long howlong (unsigned long long x) {
    int lengthCount = 0;
    for(; x != 0; x /= 10, lengthCount++);
    return lengthCount;
}
unsigned long long value;
unsigned long long DecToBin(unsigned long long n)
{
    std::string r;
    while(n!=0) {
        r=(n%2==0 ?"0":"1")+r;
        n/=2;
    }
    value = atoi(r.c_str());
    return value;
}
unsigned long long DecToOct(unsigned long long n)
{
    std::string r;
    while(n!=0) {
        r=(n%8==0 ? "0": n%8==1 ? "1": n%8==2 ? "2":n%8==3 ? "3":n%8==3 ? "3":n%8==5 ? "5":n%8==6 ? "6":n%8==7 ? "7": "error")+r;
        n/=8;
    }
    value = atoi(r.c_str());
    return value;
}
// 2 -> 10
unsigned long long BinToDec(unsigned long long n) {
    unsigned long long dec = 0, base = 1;
    short rem;
    while (n > 0)
    {
        rem = n % 10; //
        dec += + rem * base;
        base *= 2;
        n /= 10;
    }
        return dec;
}
// 8 -> 10
unsigned long long OctToDec(unsigned long long n) {
    unsigned long long dec = 0, base = 1;
    short rem;
    while (n > 0)
    {
        rem = n % 10;
        dec += + rem * base;
        base *= 8;
        n /= 10;
    }
        return dec;
}
void MainWindow::on_pushButton_clicked()
{
    unsigned long long number;
    int basefrom=ui->from->currentIndex(); // From which base
    int baseto=ui->to->currentIndex(); // To which base
    /* 0=binary
     * 1=octal
     * 2=decimal
     * 3=hexadecimal */
    QString input = ui->inputbox->text(); // Input from user
    number = input.toInt(); // Convert the string to int
    // Check all possible scenarios
    if (basefrom==baseto) {
       ui->answerbox->setText(input);
    }
    else if (basefrom==0&&baseto==1) { // 2 -> 8
        ui->answerbox->setText(QString::number(DecToOct(BinToDec(number))));
    }
    else if (basefrom==0&&baseto==2) { // 2 -> 10
        //if (input.contains("0")&&input.contains("1")) {
            ui->answerbox->setText(QString::number(BinToDec(number)));
        //}
        //else {
        //    ui->answerbox->setText("Error");
        //}
    }
    else if (basefrom==0&&baseto==3) { // 2 -> 16

    }
    else if (basefrom==1&&baseto==0) { // 8 -> 2
        ui->answerbox->setText(QString::number(DecToBin(OctToDec(number))));
    }
    else if (basefrom==1&&baseto==2) { // 8 -> 10
        ui->answerbox->setText(QString::number(OctToDec(number)));
    }
    else if (basefrom==1&&baseto==3) { // 8 -> 16

    }
    else if (basefrom==2&&baseto==0) { // 10 -> 2
        ui->answerbox->setText(QString::number(DecToBin(number)));
    }
    else if (basefrom==2&&baseto==1) { // 10 -> 8
        ui->answerbox->setText(QString::number(DecToOct(number)));
    }
    else if (basefrom==2&&baseto==3) { // 10 -> 16

    }
    else if (basefrom==3&&baseto==0) { // 16 -> 2

    }
    else if (basefrom==3&&baseto==1) { // 16 -> 8

    }
    else if (basefrom==3&&baseto==2) { // 16 -> 10

    }

}
