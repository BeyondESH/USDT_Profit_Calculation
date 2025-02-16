#include "dialog.h"
#include "ui_dialog.h"
#include "userinfo.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    userInfo::getInstance();
    ui->setupUi(this);
    ui->minLineEdit->setEnabled(false);
    ui->grossProfitRateLineEdit->setEnabled(false);
    ui->profitRateLineEdit->setEnabled(false);
    ui->profitLineEdit->setEnabled(false);
    ui->serviceCostLineEdit->setEnabled(false);
    ui->currenciescComboBox->setCurrentIndex(-1);
    ui->unitComboBox->setCurrentIndex(-1);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_currenciescComboBox_currentTextChanged(const QString &arg1)
{
    if(arg1!=nullptr){
        if(arg1=="更多"){
            _floatingDialog = new FloatingDialog(this);
            connect(_floatingDialog,&FloatingDialog::addItem,[&](const QString &item){
                qDebug()<<item;
                ui->currenciescComboBox->addItem(item);
            });
            _floatingDialog->setWindowModality(Qt::WindowModal);
            _floatingDialog->setWindowTitle(tr("新增币种"));
            _floatingDialog->exec();
        }else {
            userInfo::getInstance().setCurrencyKinds(arg1);
            //qDebug()<<userInfo::getInstance().currencyKinds();
        }

    }
}


void Dialog::on_unitComboBox_currentTextChanged(const QString &arg1)
{
    if(arg1!=nullptr){
        if(arg1=="更多"){
            _floatingDialog = new FloatingDialog(this);
            connect(_floatingDialog,&FloatingDialog::addItem,[&](const QString &item){
                qDebug()<<item;
                ui->currenciescComboBox->addItem(item);
            });
            _floatingDialog->setWindowModality(Qt::WindowModal);
            _floatingDialog->setWindowTitle(tr("新增单位"));
            _floatingDialog->exec();
        }else {
            userInfo::getInstance().setCurrencyKinds(arg1);
            //qDebug()<<userInfo::getInstance().currencyKinds();
        }

    }
}

bool Dialog::isQcomboBoxRepeat(QComboBox &comboBox,QString &item)
{
    int count=comboBox.count();
    for (int i = 0; i < count-1; ++i) {
        if(comboBox.itemText(i)==item){
            _floatingDialog->setLabel(tr("已存在!"));
            return true;
        }
    }
    return false;
}

