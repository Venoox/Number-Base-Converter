#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <string>
#include <vector>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
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

std::string FindinDecimal(int n, int x) //n is n-bit Gray code array, x is index of the array we need to return
{
    if (n <= 0)
        return "Cannot be negative!";
    else if (x >= pow(2,n) || x < 0)
        return "Out of range!";

    std::vector<std::string> arr;
    // start with one-bit pattern
    arr.push_back("0");
    arr.push_back("1");

    // Every iteration of this loop generates 2*i codes from previously
    // generated i codes.
    int i, j;
    for (i = 2; i < (1<<n); i = i<<1)
    {
        // Enter the prviously generated codes again in arr[] in reverse
        // order. Nor arr[] has double number of codes.
        for (j = i-1 ; j >= 0 ; j--)
            arr.push_back(arr[j]);

        // append 0 to the first half
        for (j = 0 ; j < i ; j++)
            arr[j] = "0" + arr[j];

        // append 1 to the second half
        for (j = i ; j < 2*i ; j++)
            arr[j] = "1" + arr[j];
    }
    return arr[x];
}
int FindinGray(int n, std::string input)
{
    if (n <= 0)
        return -2;

    std::vector<std::string> arr;
    // start with one-bit pattern
    arr.push_back("0");
    arr.push_back("1");

    // Every iteration of this loop generates 2*i codes from previously
    // generated i codes.
    int i, j;
    for (i = 2; i < (1<<n); i = i<<1)
    {
        // Enter the prviously generated codes again in arr[] in reverse
        // order. Nor arr[] has double number of codes.
        for (j = i-1 ; j >= 0 ; j--)
            arr.push_back(arr[j]);

        // append 0 to the first half
        for (j = 0 ; j < i ; j++)
            arr[j] = "0" + arr[j];

        // append 1 to the second half
        for (j = i ; j < 2*i ; j++)
            arr[j] = "1" + arr[j];
    }
    //Search the array with input
    int index;
    for (index=0;arr[index]!=input;index++) {
        if(index==pow(2,n)-1) return -1;
    }
    return index;
}
void MainWindow::on_pushButton_2_clicked()
{
    QString bits = ui->lineEdit->text();
    QString number = ui->lineEdit_2->text();
    int x = number.toInt();
    int y = bits.toInt();
    if (bits.isEmpty()&&number.isEmpty()) {
        ui->lineEdit_3->setText("No input!");
    }
    else if (ui->comboBox->currentIndex()==0) {
        ui->lineEdit_3->setText(QString::fromStdString(FindinDecimal(y,x)));
    }
    else if (ui->comboBox->currentIndex()==1) {
        int index = FindinGray(y,number.toStdString());
        if (index==-1) {
            ui->lineEdit_3->setText("Out of range!");
        }
        else if (index==-2) {
            ui->lineEdit_3->setText("Cannot be negative!");
        }
        else {
        ui->lineEdit_3->setText(QString::number(index));
        }
    }
}
