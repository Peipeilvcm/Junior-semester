#ifndef OBSERVER_H
#define OBSERVER_H

//观察者模式
class Observer
{
public:
    Observer();
public:
    virtual void Update() = 0;
};

class Subject
{
public:
    Subject();
public:
    virtual void registerObserver(Observer *) = 0;
    virtual void removeObserver(Observer *) = 0;
    virtual void NotifyObservers() = 0;
};

#endif // OBSERVER_H
