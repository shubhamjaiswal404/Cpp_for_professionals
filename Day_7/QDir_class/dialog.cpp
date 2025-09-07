#include "dialog.h"
#include "ui_dialog.h"
#include<QDir>
#include<QFont>
#include<QFileInfo>
#include<QFileInfoList>


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lineEdit->setStyleSheet("QLineEdit{font-size : 12px;}");
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
    QString currPath = ui->lineEdit->text();
    QDir mDir(currPath);
    if(mDir.exists())
    {
        // do something
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

