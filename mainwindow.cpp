#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    int basefrom=ui->from->currentIndex();
    int baseto=ui->to->currentIndex();
    /* 0=binary
     * 1=octal
     * 2=decimal
     * 3=hexadecimal */
    QString input = ui->inputbox->text();
    if (basefrom==baseto) {
       ui->answerbox->setText(input);
    }
    else if (basefrom==0&&baseto==1) {

    }
    else if (basefrom==0&&baseto==2) {

    }
    else if (basefrom==0&&baseto==3) {

    }
    else if (basefrom==1&&baseto==0) {

    }
    else if (basefrom==1&&baseto==2) {

    }
    else if (basefrom==1&&baseto==3) {

    }
    else if (basefrom==2&&baseto==0) {

    }
    else if (basefrom==2&&baseto==1) {

    }
    else if (basefrom==2&&baseto==3) {

    }
    else if (basefrom==3&&baseto==0) {

    }
    else if (basefrom==3&&baseto==1) {

    }
    else if (basefrom==3&&baseto==2) {

    }

}
