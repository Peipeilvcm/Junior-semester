#ifndef MODIFYQUANTITYDIALOG_H
#define MODIFYQUANTITYDIALOG_H

#include <QDialog>

namespace Ui {
class modifyQuantityDialog;
}

class modifyQuantityDialog : public QDialog
{
    Q_OBJECT
private:
    int id;

public:
    explicit modifyQuantityDialog(QWidget *parent = 0, int id=1, int quantity=0);
    ~modifyQuantityDialog();

    int getId(){return id;}

private:
    Ui::modifyQuantityDialog *ui;

private slots:
    void modifyConfirmButton_clicked();
    void returnButton_clicked();
};

#endif // MODIFYQUANTITYDIALOG_H
