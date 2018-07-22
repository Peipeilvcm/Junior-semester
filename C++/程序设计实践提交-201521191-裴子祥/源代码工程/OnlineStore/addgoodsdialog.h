#ifndef ADDGOODSDIALOG_H
#define ADDGOODSDIALOG_H

#include <QDialog>

namespace Ui {
class addGoodsDialog;
}

class addGoodsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addGoodsDialog(QWidget *parent = 0);
    ~addGoodsDialog();

private:
    Ui::addGoodsDialog *ui;

private slots:
    void addConfirmButton_clicked();
    void returnButton_clicked();

};

#endif // ADDGOODSDIALOG_H
