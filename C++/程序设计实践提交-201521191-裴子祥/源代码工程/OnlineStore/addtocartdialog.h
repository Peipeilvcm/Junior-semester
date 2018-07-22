#ifndef ADDTOCARTDIALOG_H
#define ADDTOCARTDIALOG_H

#include <QDialog>

namespace Ui {
class addToCartDialog;
}

class addToCartDialog : public QDialog
{
    Q_OBJECT
private:
    int id;
    //QString name;

public:
    explicit addToCartDialog(QWidget *parent = 0,int id=1);
    ~addToCartDialog();

    int getId(){return id;}
    //QString getName(){return name;}

private:
    Ui::addToCartDialog *ui;

private slots:
    void addConfirmButton_clicked();
    void returnButton_clicked();
};

#endif // ADDTOCARTDIALOG_H
