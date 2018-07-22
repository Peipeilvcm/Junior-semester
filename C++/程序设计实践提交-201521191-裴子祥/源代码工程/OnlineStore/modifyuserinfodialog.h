#ifndef MODIFYUSERINFODIALOG_H
#define MODIFYUSERINFODIALOG_H

#include <QDialog>

namespace Ui {
class modifyUserInfoDialog;
}

class modifyUserInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit modifyUserInfoDialog(QWidget *parent = 0);
    ~modifyUserInfoDialog();

private:
    Ui::modifyUserInfoDialog *ui;

private slots:
    void modifyPasswordButton_clicked();
    void returnButton_clicked();
    void modifyNameButton_clicked();
};

#endif // MODIFYUSERINFODIALOG_H
