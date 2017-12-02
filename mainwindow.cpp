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
int howlong (unsigned long long x) {
    int lengthCount = 0;
    for(; x != 0; x /= 10, lengthCount++);
    return lengthCount;
}
// 2 -> 10
int bintodec(unsigned long long whole) {
    unsigned long long dec = 0, base = 1;
    short rem;
    while (whole > 0)
    {
        rem = whole % 10; //
        dec += + rem * base;
        base *= 2;
        whole /= 10;
    }
        return dec;
}
// 8 -> 10
int octtodec(unsigned long long whole) {
    unsigned long long dec = 0, base = 1;
    short rem;
    while (whole > 0)
    {
        rem = whole % 10;
        dec += + rem * base;
        base *= 8;
        whole /= 10;
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

    }
    else if (basefrom==0&&baseto==2) { // 2 -> 10
        ui->answerbox->setText(QString::number(bintodec(number)));

    }
    else if (basefrom==0&&baseto==3) { // 2 -> 16

    }
    else if (basefrom==1&&baseto==0) { // 8 -> 2

    }
    else if (basefrom==1&&baseto==2) { // 8 -> 10
        ui->answerbox->setText(QString::number(octtodec(number)));
    }
    else if (basefrom==1&&baseto==3) { // 8 -> 16

    }
    else if (basefrom==2&&baseto==0) { // 10 -> 2

    }
    else if (basefrom==2&&baseto==1) { // 10 -> 8

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
