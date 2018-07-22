#include "phone.h"

//构造函数，构造出一个空的手机
Phone::Phone():
    Product(),rate(0.0),brand(""){}

//构造函数，构造出一个具体的，信息完整的手机
Phone::Phone(QString name, QString description, float originalPrice, int inventory, float rate, QString brand):
    Product(name, description, originalPrice, inventory), rate(rate), brand(brand){}

//以下是set,get,toString等基本函数

void Phone::setRate(float rate)
{
    this->rate = rate;
}

QString Phone::toString()
{
    return "品牌:"+brand;
}

float Phone::getPrice()
{
    return rate*getOriginalPrice();
}

QString Phone::getType()
{
    return "PHONE";
}
