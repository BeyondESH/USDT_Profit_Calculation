#include "floatingdialog.h"
#include "ui_floatingdialog.h"

FloatingDialog::FloatingDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FloatingDialog)
{
    ui->setupUi(this);
}

FloatingDialog::~FloatingDialog()
{
    delete ui;
}

void FloatingDialog::setLabel(bool isSucceed,const QString &QString)
{
    if(isSucceed==false){
        ui->label->setStyleSheet("color:red");
    }else{
        ui->label->setStyleSheet("color:green");
    }
    ui->label->setText(QString);
}

void FloatingDialog::on_pushButton_clicked()
{
    ui->label->clear();
    if(ui->lineEdit->text()==nullptr){
        ui->label->setStyleSheet("color:red");
        ui->label->setText("不能为空!");
    }else{
        QString item=ui->lineEdit->text();
        //qDebug()<<item;
        emit addItem(item);
    }
}

