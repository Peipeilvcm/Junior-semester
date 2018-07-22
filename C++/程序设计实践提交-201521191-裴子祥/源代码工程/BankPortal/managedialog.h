#ifndef MANAGEDIALOG_H
#define MANAGEDIALOG_H

#include <QDialog>
#include <QSqlTableModel>

//管理员界面

namespace Ui {
class ManageDialog;
}

class ManageDialog : public QDialog
{
    Q_OBJECT
private:
    QSqlTableModel *model;//数据库表格模式
    void accountInfoShow();

public:
    explicit ManageDialog(QWidget *parent = 0);
    ~ManageDialog();

private:
    Ui::ManageDialog *ui;

private slots:
    void returnButton_clicked();
    void deleteButton_clicked();
};

#endif // MANAGEDIALOG_H
