#ifndef FOOD_H
#define FOOD_H

#include "product.h"

class Food : public Product
{
private:
    static const int type = FOOD;
    float rate;//折扣率
    QString category;

public:
    Food();
    Food(QString name, QString description, float originalPrice, int inventory,
          float rate, QString category);

    void setRate(float rate);
    QString getType();
    float getPrice();
    QString toString();
};


#endif // FOOD_H
