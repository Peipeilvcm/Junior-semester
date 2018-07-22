#ifndef GLOBALINFO_H
#define GLOBALINFO_H

//singleton pattern单例模式
//存储商城的全局信息，如是否登录，用户账号（手机号），满减信息，折扣信息

#include<QString>

class GlobalInfo
{
private:
    //全局变量
    static GlobalInfo* s_instance;
    bool isLogin;                   //是否登录
    QString userPhoneNum;           //用户账号(手机号)
    int Full;                       //满减信息，满值
    int Reduce;                     //满减信息，减值
    bool isFRstart;                 //满减信息，满减是否开始
    bool isPayed;                   //是否完成付款

    GlobalInfo(bool login = false, QString num = "", int full = 0,
               int reduce = 0, bool fr = false, bool isPay = false)
    {
        isLogin = login;
        userPhoneNum = num;
        Full = full;
        Reduce = reduce;
        isFRstart = fr;
        isPayed = isPay;
    }

public:
    static GlobalInfo* instance();  //获取实例

    //get、set函数

    bool getIsLogin();
    void setIsLogin(bool login);

    QString getUserNum();
    void setUserNum(QString num);

    int getFull();
    void setFull(int full);

    int getReduce();
    void setReduce(int reduce);

    bool getIsFRstart();
    void setIsFRstart(bool fr);

    bool getIsPayed();
    void setIsPayed(bool isPay);
};

#endif // GLOBALINFO_H
