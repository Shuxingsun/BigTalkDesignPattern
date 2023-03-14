//
// Created by sunchanghui on 2023/3/13.
//

#ifndef BIGTALKDESIGNPATTERN_DECORATOR_H
#define BIGTALKDESIGNPATTERN_DECORATOR_H

#include <iostream>
using namespace std;

class Human
{
public:
    Human(){};
    Human(string name);
    virtual void show() = 0;
protected:
    string m_name;
};
class Finery:public Human
{
public:
    Finery(){};
    void decorate(Human * component);
    void show();
protected:
    Human * m_component;
};

#endif //BIGTALKDESIGNPATTERN_DECORATOR_H
