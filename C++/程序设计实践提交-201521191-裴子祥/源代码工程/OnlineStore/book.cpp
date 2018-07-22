#include "book.h"

//构造一本空书
Book::Book():
    Product(),rate(0.0),author(""){}

//构造函数，构造出一个具体的，信息完整的书
Book::Book(QString name, QString description, float originalPrice, int inventory, float rate, QString author):
    Product(name, description, originalPrice, inventory), rate(rate), author(author){}

//以下是set,get,toString等基本函数

void Book::setRate(float rate)
{
    this->rate = rate;
}

QString Book::toString()
{
    return "作者:"+author;
}

float Book::getPrice()
{
    return rate*getOriginalPrice();
}

QString Book::getType()
{
    return "BOOK";
}


