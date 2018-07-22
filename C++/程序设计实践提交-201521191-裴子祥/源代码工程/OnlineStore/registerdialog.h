#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT
private:
    static const int phoneNumLen = 11;
public:
    explicit RegisterDialog(QWidget *parent = 0);
    ~RegisterDialog();

private:
    Ui::RegisterDialog *ui;

private slots:
    void registerButton_clicked();
    void returnButton_clicked();
};

#endif // REGISTERDIALOG_H
