#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>

//注册界面
#include<QException>
#include"main.h"


namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT
public:
    static const int accountLength = 19;
    static const int idcreditLength = 18;
    static const int passwordLength = 6;
    static const int phonenumLength = 11;

public:
    explicit RegisterDialog(QWidget *parent = 0);
    ~RegisterDialog();

private:
    Ui::RegisterDialog *ui;
    void check();//查错

private slots:
    void buttonRegister_clicked();

};

//注册时发生异常
class registerException:public QException{
    //错误类型
public:
    static const errorType ACCOUNTERROR=0;
    static const errorType PASSWORDERROR=1;
    static const errorType IDCREDITERROR=2;
    static const errorType PHONENUMERROR=3;
    static const errorType ACCOUNTCONFLICT=4;
private:
    errorType kind;//注册时哪一信息发生错误
             //0卡号错误，1密码不一致，2身份证号码错误，3电话号码错误
public:
    explicit registerException(errorType kind=-1);
    QString what();
};



#endif // REGISTERDIALOG_H
