#ifndef FLOATINGDIALOG_H
#define FLOATINGDIALOG_H

#include <QDialog>

namespace Ui {
class FloatingDialog;
}

class FloatingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FloatingDialog(QWidget *parent = nullptr);
    ~FloatingDialog();
    void setLabel(bool isSucceed,const QString &QString);
private slots:
    void on_pushButton_clicked();

private:
    Ui::FloatingDialog *ui;

signals:
    void addItem(const QString&);
};

#endif // FLOATINGDIALOG_H
