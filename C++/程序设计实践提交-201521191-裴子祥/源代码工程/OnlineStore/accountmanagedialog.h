#ifndef ACCOUNTMANAGEDIALOG_H
#define ACCOUNTMANAGEDIALOG_H

#include <QDialog>

//银行卡绑定窗口类
namespace Ui {
class accountManageDialog;
}

class accountManageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit accountManageDialog(QWidget *parent = 0);
    ~accountManageDialog();

    static const int SUCCESS = 1;                        //绑定成功
    static const int NOSEVER = 2;                        //为找到服务器
    static const int DISCONNECT = 3;                     //失去连接
    static const int WRONGNUM = 4;                       //卡号错误
    static const int WRONGPW = 5;                        //密码错误

private:
    Ui::accountManageDialog *ui;
    static int askBank(QString sendStr);                 //向银行发送连接请求，并银行卡绑定信息

private slots:
    void bindConfirmButton_clicked();                    //绑定确认按钮
    void returnButton_clicked();                         //取消返回按钮
};

#endif // ACCOUNTMANAGEDIALOG_H
