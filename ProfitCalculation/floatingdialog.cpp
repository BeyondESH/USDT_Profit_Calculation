#include "floatingdialog.h"
#include "ui_floatingdialog.h"

FloatingDialog::FloatingDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FloatingDialog)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("color:red");
}

FloatingDialog::~FloatingDialog()
{
    delete ui;
}

void FloatingDialog::setLabel(const QString &QString)
{
    ui->label->setText(QString);
}

void FloatingDialog::on_pushButton_clicked()
{
    ui->label->clear();
    if(ui->lineEdit->text()==nullptr){
        ui->label->setText("不能为空!");
    }else{
        QString item=ui->lineEdit->text();
        //qDebug()<<item;
        emit addItem(item);
    }
}

