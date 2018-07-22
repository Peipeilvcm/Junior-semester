#ifndef PHONE_H
#define PHONE_H

#include "product.h"

class Phone : public Product
{
private:
    static const int type = PHONE;
    float rate;//折扣率
    QString brand;

public:
    Phone();
    Phone(QString name, QString description, float originalPrice, int inventory,
          float rate, QString brand);

    void setRate(float rate);
    QString toString();
    QString getType();
    float getPrice();
};

#endif // PHONE_H
