#ifndef DEPOSITDIALOG_H
#define DEPOSITDIALOG_H

#include <QDialog>

namespace Ui {
class DepositDialog;
}

class DepositDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DepositDialog(QWidget *parent = 0);
    ~DepositDialog();

private:
    Ui::DepositDialog *ui;

private slots:
    void depositButton_clicked();
    void cancelButton_clicked();
};

#endif // DEPOSITDIALOG_H
