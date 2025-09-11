#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<QComboBox>
#include<QFile>
#include<QIODevice>
#include<QTextStream>
#include<vector>
#include<QtXml>
#include<QDomProcessingInstruction>

struct Player
{
    QString name;
    QString memberType;
    QString gender;
    QString level;
    QString program;
};

std::vector<struct Player> mVec;

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
    struct Player myPlayer;
    QString myMsg = ui->lineEdit->text() + " , ";
    myPlayer.name = ui->lineEdit->text();

    ui->statusbar->clearMessage();
    if(ui->radioButton->isChecked())
    {
        myMsg.append(ui->radioButton->text() + " , ");
        myPlayer.memberType = ui->radioButton->text();
    }
    if(ui->radioButton_2->isChecked())
    {
        myMsg.append(ui->radioButton_2->text() + " , ");
        myPlayer.memberType = ui->radioButton_2->text();
    }
    if(ui->radioButton_3->isChecked())
    {
        myMsg.append(ui->radioButton_3->text() + " , ");
        myPlayer.memberType = ui->radioButton_3->text();
    }
    if(ui->radioButton_4->isChecked())
    {
        myMsg.append(ui->radioButton_4->text() + " , ");
        myPlayer.memberType = ui->radioButton_4->text();
    }

    myMsg.append(ui->comboBox->currentText() + " , ");
    myPlayer.gender = ui->comboBox->currentText();

    myMsg.append(ui->comboBox_2->currentText() + " , " );
    myPlayer.level = ui->comboBox_2->currentText();

    myPlayer.program.clear();

    if(ui->checkBox->isChecked())
    {
        myMsg.append(ui->checkBox->text() + " , ");
        myPlayer.program.append(ui->checkBox->text() + " , ");
    }
    if(ui->checkBox_2->isChecked())
    {
        myMsg.append(ui->checkBox_2->text() + " , ");
        myPlayer.program.append(ui->checkBox_2->text() + " , ");

    }
    if(ui->checkBox_3->isChecked())
    {
        myMsg.append(ui->checkBox_3->text() + " , ");
        myPlayer.program.append(ui->checkBox_3->text() + " , ");

    }
    if(ui->checkBox_4->isChecked())
    {
        myMsg.append(ui->checkBox_4->text() + " , ");
        myPlayer.program.append(ui->checkBox_4->text() + " , ");

    }

    mVec.push_back(myPlayer);
    ui->statusbar->showMessage(myMsg + " " + QString::number(mVec.size()));
}




void MainWindow::on_pushButton_2_clicked()
{
    QFile mFile("new_members.xml");
    if(!mVec.empty())
    {
        ui->statusbar->showMessage(QString::number(mVec.size()) + " Records is been saved " );

        // Create Document
        QDomDocument myDoc;
        QDomProcessingInstruction pi = myDoc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"utf-8\"");
        myDoc.appendChild(pi);

        //Add root node
        QDomElement root = myDoc.createElement("root");
        myDoc.appendChild(root);


        for(auto it = mVec.begin(); it != mVec.end() ; it++)
        {
            //Create player node
            QDomElement player = myDoc.createElement("player");

            //add name to player
            QDomElement name = myDoc.createElement("name");
            QDomText tName = myDoc.createTextNode(it->name);
            name.appendChild(tName);
            player.appendChild(name);


            //add membership Type to player

            QDomElement membership = myDoc.createElement("membership");
            QDomText tmembership = myDoc.createTextNode(it->memberType);
            membership.appendChild(tmembership);
            player.appendChild(membership);

            //add gender to player

            QDomElement gender = myDoc.createElement("gerder");
            QDomText tgender = myDoc.createTextNode(it->gender);
            gender.appendChild(tgender);
            player.appendChild(gender);

            //add level to player

            QDomElement level = myDoc.createElement("level");
            QDomText tlevel = myDoc.createTextNode(it->level);
            level.appendChild(tlevel);
            player.appendChild(level);

            //add  Program to player

            QDomElement program = myDoc.createElement("program");
            QDomText tProgram = myDoc.createTextNode(it->program);
            program.appendChild(tProgram);
            player.appendChild(program);

            //add player to root
            root.appendChild(player);
        }

        if(mFile.open(QIODevice::WriteOnly | QIODevice::Text ))
        {
            QTextStream out(&mFile);

            out << myDoc.toString();

            mVec.clear();
            mFile.flush();
            mFile.close();
        }
    }

}

