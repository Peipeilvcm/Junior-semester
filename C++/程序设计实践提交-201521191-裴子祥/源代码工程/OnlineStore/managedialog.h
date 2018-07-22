#ifndef MANAGEDIALOG_H
#define MANAGEDIALOG_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class ManageDialog;
}

class ManageDialog : public QDialog
{
    Q_OBJECT
private:
    QSqlTableModel *manageModel;
    void updateGoodsInfo();
    void goodsInfoShow();

public:
    explicit ManageDialog(QWidget *parent = 0);
    ~ManageDialog();

private:
    Ui::ManageDialog *ui;

private slots:
    void returnButton_clicked();
    void addGoodsButton_clicked();
    void delGoodsButton_clicked();
    //void modifyGoodsButton_clicked();
    void discountSetButton_clicked();
    void onSaleSetButton_clicked();
};

#endif // MANAGEDIALOG_H
