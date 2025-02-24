#include "dialog.h"
#include "ui_dialog.h"
#include "userinfo.h"
#include "tipsdialog.h"

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

    QIntValidator *validotor  = new QIntValidator(0,10000000,this);
    ui->numberLabelLineEdit->setValidator(validotor);
    QDoubleValidator *doubleValidotor  = new QDoubleValidator(0,10000000,5,this);
    ui->costLineEdit->setValidator(doubleValidotor);
    ui->marketLineEdit->setValidator(doubleValidotor);

    ui->serviceCostRateLabeldoubleSpinBox->setSuffix(" %");
    ui->serviceCostRateLabeldoubleSpinBox->setRange(0, 100000.00000);
    ui->serviceCostRateLabeldoubleSpinBox->setSingleStep(0.05);
    ui->serviceCostRateLabeldoubleSpinBox->setDecimals(5);
}

Dialog::~Dialog()
{
    delete ui;
}

bool Dialog::isQcomboBoxRepeat(QComboBox* comboBox,const QString &item)
{
    int count=comboBox->count();
    for (int i = 0; i < count; ++i) {
        if(comboBox->itemText(i)==item){
            _floatingDialog->setLabel(false,tr("已存在!"));
            return true;
        }
    }
    return false;
}


void Dialog::on_currenciescComboBox_textActivated(const QString &arg1)
{
    if(arg1!=nullptr){
        if(arg1=="更多"){
            _floatingDialog = new FloatingDialog(this);
            connect(_floatingDialog,&FloatingDialog::addItem,[&](const QString &item){
                //qDebug()<<item;
                if((isQcomboBoxRepeat(ui->currenciescComboBox,item))==false){
                    _floatingDialog->setLabel(true,tr("添加成功!"));
                    _floatingDialog->close();
                    int number=ui->currenciescComboBox->count();
                    ui->currenciescComboBox->insertItem(number-1,item);
                    ui->currenciescComboBox->setCurrentIndex(number-1);
                    userInfo::getInstance().setCurrencyKinds(item);
                }
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


void Dialog::on_unitComboBox_textActivated(const QString &arg1)
{
    if(arg1!=nullptr){
        if(arg1=="更多"){
            _floatingDialog = new FloatingDialog(this);
            connect(_floatingDialog,&FloatingDialog::addItem,[&](const QString &item){
                //qDebug()<<item;
                if((isQcomboBoxRepeat(ui->unitComboBox,item))==false){
                    _floatingDialog->setLabel(true,tr("添加成功!"));
                    _floatingDialog->close();
                    int number=ui->unitComboBox->count();
                    ui->unitComboBox->insertItem(number-1,item);
                    ui->unitComboBox->setCurrentIndex(number-1);
                    userInfo::getInstance().setUnit(item);
                    //qDebug()<<userInfo::getInstance().unit();
                }
            });
            _floatingDialog->setWindowModality(Qt::WindowModal);
            _floatingDialog->setWindowTitle(tr("新增单位"));
            _floatingDialog->exec();
        }else {
            userInfo::getInstance().setUnit(arg1);
            //qDebug()<<userInfo::getInstance().unit();
        }
    }
}


void Dialog::on_savePushButton_clicked()
{
    TipsDialog *tipsDialog = new TipsDialog(this);
    tipsDialog->setLabel(false,tr("用户参数不完整"));
    tipsDialog->setWindowModality(Qt::WindowModal);
    tipsDialog->exec();
}

