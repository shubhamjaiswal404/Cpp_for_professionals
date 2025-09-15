#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtCore>
#include<QtXml>
#include<QFile>
#include<QDir>
#include<QFileInfoList>
#include<QFileInfo>
#include<QIODevice>
#include<QMessageBox>
#include<QDomDocument>
#include<QDomElement>
#include<QDomNode>
#include<QDomNodeList>
//#include<QXmlSimpleReader>
//#include<QXmlStreamReader>
//#include<QXmlInputSource>


void MainWindow :: listNodeChld(QDomElement inElem , int lv)
{
    QDomNode node = inElem.firstChild();
    int level = lv;
    int mPos = level * 4;
    while(!node.isNull())
    {
        QDomElement myElem = node.toElement();
        if(!myElem.isNull())
        {
            ui->plainTextEdit->appendPlainText(QString("%1").arg(' ',mPos, QLatin1Char(' ')) + myElem.tagName() + " : " + myElem.text());
        }
        if(myElem.hasChildNodes())
        {
            int chLevel  = lv++;
            this->listNodeChld(myElem, chLevel);
        }
        node = node.nextSibling();
    }
}

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
        if(mFile.open(QFile::ReadOnly))
        {
            while(!mFile.atEnd())
            {
                QString mLine =mFile.readLine();
                ui->plainTextEdit->appendPlainText(mLine);
            }
        }        mFile.close();
    }
    else
    {
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
    else
    {
        QMessageBox::warning(this,"My waring"," Directory does not exist !!!");
    }


}

void MainWindow::on_pushButton_3_clicked()
{
    QString fileName =ui->lineEdit->text();
    ui->plainTextEdit->clear();
    ui->statusbar->clearMessage();
    QFile mFile(fileName);
    if(mFile.exists())
    {
        if(mFile.open(QIODevice::ReadOnly | QIODevice::Text)){

            QDomDocument    myDoc;
            myDoc.setContent(&mFile);
            QDomElement myDocElem = myDoc.documentElement();
            QDomNode myNode = myDocElem.firstChild();

            while (!myNode.isNull())
            {
                QDomElement nodeElem = myNode.toElement();
                ui->plainTextEdit->appendPlainText(nodeElem.tagName());
                if(myNode.hasChildNodes())
                {
                    this->listNodeChld(nodeElem, 1);
                }
                myNode = myNode.nextSibling();
            }
        }
        else
        {
            ui->statusbar->showMessage("File can not open for read ");
        }

    }
    else
    {
        ui->statusbar->showMessage("File does not exist");
    }

}





