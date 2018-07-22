#ifndef CLOTH_H
#define CLOTH_H

#include "product.h"

class Cloth: public Product
{
private:
    static const int type = CLOTH;
    float rate;//折扣率
    QString kind;//男上，女上，男下，女下装

public:
    Cloth();
    Cloth(QString name, QString description, float originalPrice, int inventory,
          float rate, QString kind);

    void setRate(float rate);
    QString getType();
    float getPrice();
    QString toString();

};

#endif // CLOTH_H
