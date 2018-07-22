#include "food.h"

//构造函数，构造出一个空的食物
Food::Food():
    Product(),rate(0.0),category(""){}

//构造函数，构造出一个具体的，信息完整的食物
Food::Food(QString name, QString description, float originalPrice, int inventory, float rate, QString category):
    Product(name, description, originalPrice, inventory), rate(rate), category(category){}

//以下是set,get,toString等基本函数

void Food::setRate(float rate)
{
    this->rate = rate;
}

QString Food::toString()
{
    return "类别:"+category;
}

float Food::getPrice()
{
    return rate*getOriginalPrice();
}

QString Food::getType()
{
    return "FOOD";
}
