#ifndef BOOK_H
#define BOOK_H

#include "product.h"

//图书基类、继承product
class Book : public Product
{
private:
    static const int type = BOOK;   //BOOK类
    float rate;                     //折扣率
    QString author;                 //作者名

public:
    //构造函数
    Book();
    Book(QString name, QString description, float originalPrice, int inventory,
          float rate, QString author);

    //get、set
    void setRate(float rate);
    virtual QString getType();
    virtual float getPrice();
    virtual QString toString();
};

#endif // BOOK_H
