#include "cloth.h"

//构造函数，构造出一个空的服装
Cloth::Cloth():
    Product(),rate(0.0),kind(""){}

//构造函数，构造出一个具体的，信息完整的服装
Cloth::Cloth(QString name, QString description, float originalPrice, int inventory, float rate, QString kind):
    Product(name, description, originalPrice, inventory), rate(rate), kind(kind){}

//以下是set,get,toString等基本函数

void Cloth::setRate(float rate)
{
    this->rate = rate;
}

QString Cloth::toString()
{
    return "分类:"+kind;
}

float Cloth::getPrice()
{
    return rate*getOriginalPrice();
}

QString Cloth::getType()
{
    return "CLOTH";
}
