#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDir>
#include<QFont>
#include<QFileInfo>
#include<QFileInfoList>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setStyleSheet("QLineEdit{font-size : 12px;}");
    QFont mFont = ui->plainTextEdit->font();
    mFont.setPointSize(12);
    ui->plainTextEdit->setFont(mFont);
    ui->lineEdit->setText(QDir::homePath());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->plainTextEdit->clear();
    ui->statusbar->clearMessage();
    QString fileName = ui->lineEdit->text();
    QFile mFile(fileName);
    if(mFile.exists())
    {
        if(mFile.open(QFile::ReadOnly)){
            while(!mFile.atEnd())
            {
                QString mLine =mFile.readLine();
                ui->plainTextEdit->appendPlainText(mLine);
            }
        }        mFile.close();
    }
    else{
        ui->statusbar->showMessage("File does not exist");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->plainTextEdit->clear();
    ui->statusbar->clearMessage();
    QString currPath = ui->lineEdit->text();
    QDir myDir(currPath);
    if(myDir.exists())
    {
        QFileInfoList myList = myDir.entryInfoList();
        foreach (QFileInfo myItem, myList){
            QString myStr =myItem.absoluteFilePath();
            if(myItem.isDir()) myStr +="/";
            ui->plainTextEdit->appendPlainText(myStr);
        }
    }
    else{
        QMessageBox::warning(this,"My waring"," Directory does not exist !!!");
    }


}

