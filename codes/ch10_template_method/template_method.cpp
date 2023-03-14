//
// Created by sunchanghui on 2023/3/15.
//
//模板方法模式

#include "iostream"
using namespace std;

class AbstractClass
{
public:
    virtual ~AbstractClass(){};
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;
    void TemplateMethod()
    {
        PrimitiveOperation1();
        PrimitiveOperation2();
    }
};

class ConcreteClassA:public AbstractClass
{
public:
    void PrimitiveOperation1()
    {
        cout << "具体类A 的方法1实现" << endl;
    }
    void PrimitiveOperation2()
    {
        cout << "具体类A 的方法2实现 " << endl;
    }
};
class ConcreteClassB:public AbstractClass
{
public:
    void PrimitiveOperation1()
    {
        cout<<"具体类B 的方法1实现" << endl;
    }
    void PrimitiveOperation2()
    {
        cout<< "具体类B 的方法2实现" << endl;
    }
};
int main()
{
    AbstractClass * a  = new ConcreteClassA();
    a->TemplateMethod();

    AbstractClass  * b  = new ConcreteClassB();
    b->TemplateMethod();
    system("pause");
    return 0;

}