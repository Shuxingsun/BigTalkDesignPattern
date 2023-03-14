//
// Created by sunchanghui on 2023/3/15.
//
//ģ�巽��ģʽ

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
        cout << "������A �ķ���1ʵ��" << endl;
    }
    void PrimitiveOperation2()
    {
        cout << "������A �ķ���2ʵ�� " << endl;
    }
};
class ConcreteClassB:public AbstractClass
{
public:
    void PrimitiveOperation1()
    {
        cout<<"������B �ķ���1ʵ��" << endl;
    }
    void PrimitiveOperation2()
    {
        cout<< "������B �ķ���2ʵ��" << endl;
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