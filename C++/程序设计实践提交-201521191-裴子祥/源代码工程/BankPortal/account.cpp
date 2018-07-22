#include "account.h"

#include "account.h"
#include"main.h"

//构造函数，构造一个空的银行卡账户实例
account::account()
{
    this->num="";
    this->password="";
    this->bankname="";
    this->idcredit="";
    this->phonenum="";
    this->balance=-1.0;
}

//构造函数，构造一个具体的银行卡账户实例
account::account(QString num, QString password, QString bankname, QString idcredit, QString phonenum, balanceType balance)
{
    this->num=num;
    this->password=password;
    this->bankname=bankname;
    this->idcredit=idcredit;
    this->phonenum=phonenum;
    this->balance=balance;
}

//析构函数
account::~account()
{
    num="";
    password="";
    bankname="";
    phonenum="";
    idcredit="";
    balance=-1.0;
}


//账户存钱，向账户存取add金额，不能超过规定最大值ADDMAX
bool account::deposit(balanceType add)
{
    if(add>ADDMAX)
    {
        return false;
    }
    else
    {
        this->balance+=add;
        return true;
    }
}

//账户存钱，从账户去sub金额，不能超过余额
bool account::withdraw(balanceType sub)
{
    if(balance<sub)
    {
        return false;
    }
    else
    {
        balance-=sub;
        return true;
    }
}


//以下是常规get/set函数

infoType account::getNum()
{
    return num;
}

infoType account::getPassword()
{
    return password;
}

infoType account::getBankName()
{
    return bankname;
}

infoType account::getIDcredit()
{
    return idcredit;
}

balanceType account::getBalance()
{
    return balance;
}

infoType account::getPhoneNum()
{
    return phonenum;
}

void account::setNum(QString num)
{
    this->num=num;
}

void account::setPassword(QString password)
{
    this->password=password;
}

void account::setBankName(QString bankname)
{
    this->bankname=bankname;
}

void account::setIDcredit(QString idcredit)
{
    this->idcredit=idcredit;
}

void account::setPhoneNum(QString phonenum)
{
    this->phonenum=phonenum;
}
