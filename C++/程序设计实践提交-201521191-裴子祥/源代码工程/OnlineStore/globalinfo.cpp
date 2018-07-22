#include "globalinfo.h"

//商城全局信息（折扣信息，满减信息，当前用户账号（电话号码）
//运用了单例模式

GlobalInfo* GlobalInfo::instance()
{
    if(!s_instance)
    {
        s_instance = new GlobalInfo;
    }
    return s_instance;
}

//get\set函数

bool GlobalInfo::getIsLogin()
{
    return isLogin;
}
void GlobalInfo::setIsLogin(bool login)
{
    isLogin = login;
}

QString GlobalInfo::getUserNum()
{
    return userPhoneNum;
}
void GlobalInfo::setUserNum(QString num)
{
    userPhoneNum = num;
}

int GlobalInfo::getFull()
{
    return Full;
}
void GlobalInfo::setFull(int full)
{
    Full = full;
}

int GlobalInfo::getReduce()
{
    return Reduce;
}
void GlobalInfo::setReduce(int reduce)
{
    Reduce = reduce;
}

bool GlobalInfo::getIsPayed()
{
    return isPayed;
}
void GlobalInfo::setIsPayed(bool isPay)
{
    isPayed = isPay;
}

bool GlobalInfo::getIsFRstart()
{
    return isFRstart;
}
void GlobalInfo::setIsFRstart(bool fr)
{
    isFRstart = fr;
}
