#include "product.h"

Product::Product()
{
    name = "";
    originalPrice = 0.0;
    description = "";
    inventory = -1;
}

Product::Product(QString s1, QString s2, float f, int i):
    name(s1),description(s2),originalPrice(f),inventory(i){}

QString Product::getName()
{
    return name;
}

void Product::setName(QString name)
{
    this->name = name;
}

QString Product::getDescroption()
{
    return description;
}

void Product::setDescription(QString description)
{
    this->description = description;
}

float Product::getOriginalPrice()
{
    return originalPrice;
}

void Product::setOriginalPrice(float originalPrice)
{
    this->originalPrice = originalPrice;
}

int Product::getInventory()
{
    return inventory;
}

void Product::setInventory(int inventory)
{
    this->inventory = inventory;
}


//虚函数
float Product::getPrice()
{
    return 0.0;
}

QString Product::getType()
{
    return "";
}


QString Product::toString()
{
    return "";
}

