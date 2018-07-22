#ifndef MODIFYDIALOG_H
#define MODIFYDIALOG_H

#include <QDialog>

namespace Ui {
class ModifyDialog;
}

class ModifyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyDialog(QWidget *parent = 0);
    ~ModifyDialog();

private:
    Ui::ModifyDialog *ui;

private slots:
    void confirmButton_clicked();
    void cancelButton_clicked();
};

#endif // MODIFYDIALOG_H
