#include "tipsdialog.h"
#include "ui_tipsdialog.h"

TipsDialog::TipsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TipsDialog)
{
    ui->setupUi(this);
}

TipsDialog::~TipsDialog()
{
    delete ui;
}

void TipsDialog::setLabel(bool isSucceed, const QString &QString)
{
    if(isSucceed==false){
        ui->label->setStyleSheet("color:red");
    }else{
        ui->label->setStyleSheet("color:green");
    }
    ui->label->setText(QString);
}
