#ifndef TIPSDIALOG_H
#define TIPSDIALOG_H

#include <QDialog>

namespace Ui {
class TipsDialog;
}

class TipsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TipsDialog(QWidget *parent = nullptr);
    ~TipsDialog();
    void setLabel(bool isSucceed,const QString &QString);
private:
    Ui::TipsDialog *ui;
};

#endif // TIPSDIALOG_H
