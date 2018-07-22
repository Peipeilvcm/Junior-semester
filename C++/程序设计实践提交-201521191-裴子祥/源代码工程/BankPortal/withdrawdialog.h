#ifndef WITHDRAWDIALOG_H
#define WITHDRAWDIALOG_H

#include <QDialog>

namespace Ui {
class WithdrawDialog;
}

class WithdrawDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WithdrawDialog(QWidget *parent = 0);
    ~WithdrawDialog();

private:
    Ui::WithdrawDialog *ui;

private slots:
    void withdrawButton_clicked();
    void cancelButton_clicked();
};

#endif // WITHDRAWDIALOG_H
