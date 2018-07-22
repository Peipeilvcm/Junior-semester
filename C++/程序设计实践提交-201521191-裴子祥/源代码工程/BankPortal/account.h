#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<QString>
#include"main.h"

//银行卡信息

class account
{
private:
    static constexpr balanceType ADDMAX=100000.0;

private:
    infoType num;//卡号
    infoType password;//密码
    infoType bankname;//银行名称
    infoType idcredit;//身份证号
    infoType phonenum;//联系电话
    balanceType balance;//账户余额

public:
    //构造函数
    account();
    account(QString num, QString password, QString bankname, QString idcredit, QString phonenum, balanceType balance = 0.0);
    ~account();

    //get、set函数
    infoType getNum();
    void setNum(QString num);
    infoType getPassword();
    void setPassword(QString password);
    infoType getBankName();
    void setBankName(QString bankname);
    infoType getIDcredit();
    void setIDcredit(QString idcredit);
    infoType getPhoneNum();
    void setPhoneNum(QString phonenum);
    balanceType getBalance();

    //存钱
    bool deposit(balanceType add);
    //取钱
    bool withdraw(balanceType sub);
};

#endif // ACCOUNT_H
