#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<QComboBox>
#include<QFile>
#include<QIODevice>
#include<QTextStream>
#include<vector>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonDocument>



struct Player
{
    QString name;
    QString memberType;
    QString gender;
    QString level;
    QString program;
};

std::vector<QJsonObject> mVec;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Male");
    ui->comboBox->addItem("Female");
    ui->comboBox_2->addItem("Beginner");
    ui->comboBox_2->addItem("Intermedia");
    ui->comboBox_2->addItem("Advance");
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QJsonObject myPlayer;
    QString myMsg = ui->lineEdit->text() + " , ";
    myPlayer["name"] = ui->lineEdit->text();

    ui->statusbar->clearMessage();
    if(ui->radioButton->isChecked())
    {
        myMsg.append(ui->radioButton->text() + " , ");
        myPlayer["memberType"] = ui->radioButton->text();
    }
    if(ui->radioButton_2->isChecked())
    {
        myMsg.append(ui->radioButton_2->text() + " , ");
        myPlayer["memberType"] = ui->radioButton_2->text();
    }
    if(ui->radioButton_3->isChecked())
    {
        myMsg.append(ui->radioButton_3->text() + " , ");
        myPlayer["memberType"] = ui->radioButton_3->text();
    }
    if(ui->radioButton_4->isChecked())
    {
        myMsg.append(ui->radioButton_4->text() + " , ");
        myPlayer["memberType"] = ui->radioButton_4->text();
    }

    myMsg.append(ui->comboBox->currentText() + " , ");
    myPlayer["gender"] = ui->comboBox->currentText();

    myMsg.append(ui->comboBox_2->currentText() + " , " );
    myPlayer["level"] = ui->comboBox_2->currentText();

    QJsonArray myProgram;

    if(ui->checkBox->isChecked())
    {
        myMsg.append(ui->checkBox->text() + " , ");
        myProgram.push_back(ui->checkBox->text());
    }
    if(ui->checkBox_2->isChecked())
    {
        myMsg.append(ui->checkBox_2->text() + " , ");
        myProgram.push_back(ui->checkBox_2->text());

    }
    if(ui->checkBox_3->isChecked())
    {
        myMsg.append(ui->checkBox_3->text() + " , ");
        myProgram.push_back(ui->checkBox_3->text());

    }
    if(ui->checkBox_4->isChecked())
    {
        myMsg.append(ui->checkBox_4->text() + " , ");
        myProgram.push_back(ui->checkBox_4->text());

    }

    myPlayer.insert("program" , myProgram);
    mVec.push_back(myPlayer);
    ui->statusbar->showMessage(myMsg + " " + QString::number(mVec.size()));
}


void MainWindow::on_pushButton_2_clicked()
{
    QFile mFile("new_members.json");
    if(!mVec.empty())
    {
        ui->statusbar->showMessage(QString::number(mVec.size()) + " Records is been saved " );


        if(mFile.open(QIODevice::WriteOnly | QIODevice::Text ))
        {
            QTextStream out(&mFile);

            for (auto it = mVec.begin(); it != mVec.end() ; it++)
            {
                out << QJsonDocument(*it).toJson()<<Qt::endl;
            }



            mVec.clear();
            mFile.flush();
            mFile.close();
        }
    }
}


