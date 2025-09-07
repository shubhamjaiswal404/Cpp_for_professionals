#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString myMsg = ui->lineEdit->text() + " ";
    ui->statusbar->clearMessage();

    if(ui->radioButton->isChecked())
    {
        myMsg.append(ui->radioButton->text() + " ");
    }
    if(ui->radioButton_2->isChecked())
    {
        myMsg.append(ui->radioButton_2->text() + " ");
    }
    if(ui->radioButton_3->isChecked())
    {
        myMsg.append(ui->radioButton_3->text() + " ");
    }
    if(ui->radioButton_4->isChecked())
    {
        myMsg.append(ui->radioButton_4->text() + " ");
    }

    if(ui->checkBox->isChecked())
    {
        myMsg.append(ui->checkBox->text() + " ");
    }
    if(ui->checkBox_2->isChecked())
    {
        myMsg.append(ui->checkBox_2->text() + " ");
    }
    if(ui->checkBox_3->isChecked())
    {
        myMsg.append(ui->checkBox_3->text() + " ");
    }
    if(ui->checkBox_4->isChecked())
    {
        myMsg.append(ui->checkBox_4->text() + " ");
    }
    ui->statusbar->showMessage(myMsg);


}

