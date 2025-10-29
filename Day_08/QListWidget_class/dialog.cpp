//#include<QListWidgetItem>
#include "dialog.h"  // Note I have added  header file #include<QListWidgetItem> in #include "dialog.h" header file
#include "ui_dialog.h"
#include<QDir>
#include<QFont>
#include<QFileInfo>
#include<QFileInfoList>
#include<QFileInfo>
#include<QListWidget>
#include<QListWidgetItem>
#include<QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lineEdit->setStyleSheet("QLineEdit{font-size: 12px;}");
    QFont mFont = ui->listWidget->font();
    mFont.setPointSize(12);
    ui->listWidget->setFont(mFont);
    ui->lineEdit->setText(QDir::homePath());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    ui->listWidget->clear();
    QString currPath = ui->lineEdit->text();
    QDir mDir(currPath);
    if(mDir.exists())
    {
        QFileInfoList mList = mDir.entryInfoList();
        foreach(QFileInfo mItem, mList)
        {
            QString mQStr = mItem.absoluteFilePath();
            if(mItem.isDir()) mQStr += "/";
            ui->listWidget->addItem(mQStr);
        }
    }
    else
    {
        QMessageBox::warning(this,"My Warning","Directory does not exist");

    }
}


void Dialog::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ui->lineEdit->setText(item->text());
    this->on_pushButton_clicked();
}

