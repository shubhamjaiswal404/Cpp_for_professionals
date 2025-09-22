 #include "dialog.h"
#include "ui_dialog.h"
#include<QDir>
#include<QFont>
#include<QFileInfo>
#include<QFileInfoList>
#include<QFile>
#include<QIODevice>
#include<QTextStream>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonDocument>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lineEdit->setStyleSheet("QLineEdit{font-size : 16px;}");
    QFont mFont = ui->plainTextEdit->font();
    mFont.setPointSize(12);
    ui->plainTextEdit->setFont(mFont);
    ui->lineEdit->setText(QDir::homePath());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    ui->plainTextEdit->clear();
    QString jsonStr;
    QString fileName = ui->lineEdit->text();
    QFile myFile(fileName);
    if(myFile.exists())
    {
        if(myFile.open(QIODevice::ReadOnly  | QIODevice::Text))
        {
            jsonStr = myFile.readAll();
            myFile.close();
            ui->plainTextEdit->appendPlainText(jsonStr);
            ui->plainTextEdit->appendPlainText("**** START PARSE JSON Data ****");

            QJsonDocument myDoc = QJsonDocument::fromJson(jsonStr.toUtf8());
            QJsonObject myObj = myDoc.object(); // 1st test for 1 json object

            if(myObj.isEmpty())
            {
                ui->plainTextEdit->appendPlainText("Object is Empty");
            }
            else
            {
                ui->plainTextEdit->appendPlainText("myObj size : " + QString::number(myObj.size()));
                for( auto it = myObj.begin() ; it!=myObj.end() ; it++)
                {
                    QString myStr = "Key-> "+ it.key().toUtf8() + " : Value-> ";
                    if(it->isArray())
                    {
                        QJsonArray myArr = it->toArray();
                        QString myStrArr = "[";
                        for(auto ita = myArr.begin(); ita != myArr.end() ; ita++)
                        {
                            myStrArr.append(ita->toString().toUtf8() + " ,");
                        }
                        myStrArr.append("]");
                        myStr.append(myStrArr);

                    }
                    else
                    {
                        myStr.append(it.value().toString());
                    }
                    ui->plainTextEdit->appendPlainText(myStr);
                }
            }
        }
    }
    else{
        ui->plainTextEdit->appendPlainText("File does not exist ");
    }
}

void Dialog::on_pushButton_2_clicked()
{
    ui->plainTextEdit->clear();
    QString currPath = ui->lineEdit->text();
    QDir mDir(currPath);
    if(mDir.exists())
    {
        QFileInfoList mList = mDir.entryInfoList();
        foreach (QFileInfo mItem , mList)
        {
            ui->plainTextEdit->appendPlainText(mItem.absoluteFilePath());
        }
    }
    else
    {
        ui->plainTextEdit->setPlainText("Directory not exist ");
    }
}

