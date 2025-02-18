#ifndef DIALOG_H
#define DIALOG_H

#include <QComboBox>
#include <QDialog>
#include "floatingdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_currenciescComboBox_textActivated(const QString &arg1);

    void on_unitComboBox_textActivated(const QString &arg1);

private:
    Ui::Dialog *ui;
    bool isQcomboBoxRepeat(QComboBox* comboBox,const QString & item);
    FloatingDialog* _floatingDialog;
};
#endif // DIALOG_H
