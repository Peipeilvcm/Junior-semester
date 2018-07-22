#ifndef ACCOUNTDIALOG_H
#define ACCOUNTDIALOG_H

#include <QDialog>

namespace Ui {
class AccountDialog;
}

class AccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AccountDialog(QWidget *parent = 0);
    ~AccountDialog();

private:
    Ui::AccountDialog *ui;

    void accountInfoShow();
    void updateInfo();

private slots:
    void withdrawEntryButton_clicked();
    void depositEntryButton_clicked();
    void setButton_clicked();
    void logoutButton_clicked();
    void getSignal();
};

#endif // ACCOUNTDIALOG_H
