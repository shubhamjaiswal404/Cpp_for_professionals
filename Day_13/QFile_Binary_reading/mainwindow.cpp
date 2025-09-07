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

void MainWindow::on_pushButton_3_clicked()
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


void MainWindow::on_pushButton_2_clicked()
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


void MainWindow::on_pushButton_clicked()
{
    ui->plainTextEdit->clear();
    ui->statusbar->clearMessage();

    char mBuffer[16];
    char hexStr[49];
    char hexTable[17] = "0123456789abcdef";

    QString fileName = ui->lineEdit->text();

    QFile mFile(fileName);
    if(mFile.exists())
    {
        if(mFile.open(QFile::ReadOnly)){
            while(!mFile.atEnd())
            {
                memset(mBuffer, '\0' , sizeof(mBuffer) + 1);
                memset(hexStr ,'\0' ,sizeof(hexStr) + 1);
                qint64 mPos = mFile.pos();
                qint64 mByte = mFile.read(mBuffer,sizeof(mBuffer));
                QString mLine = QString("%1").arg(mPos, 8, 16, QLatin1Char('0'));
                mLine.append(": ");

                for(int i=0 ; i< mByte ; i++)
                {

                    char mChar = mBuffer[i];
                    int mInt = int (mChar);
                    if(mInt < 0) mInt = 256 + int(mChar);
                    hexStr[i*3] = hexTable[int(mInt/16)];
                    hexStr[i*3 + 1] = hexTable[mInt % 16];
                    hexStr[i*3 + 2] = ' ';

                }
                mLine.append(QString(hexStr));
                ui->plainTextEdit->appendPlainText(mLine);
            }
        }        mFile.close();
    }
    else{
        ui->statusbar->showMessage("File does not exist");
    }
}














