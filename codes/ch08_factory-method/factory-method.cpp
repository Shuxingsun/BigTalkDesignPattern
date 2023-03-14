//
// Created by sunchanghui on 2023/3/14.
//
//工厂方法模式实现
#include "iostream"
using namespace std;

class Operator
{
public:
    virtual void GetResult() = 0;
    void setNumA(double numA)
    {
        a = numA;
    }
    void setB(double numB)
    {
        b = numB;
    }
protected:
    double a,b;
};
class OperatorAdd:public Operator
{
public:
    void GetResult()
    {
        printf("a+b=%lf\n",a+b);
    }
};

class OperatorSub:public Operator
{
public:
    void GetResult()
    {
        printf("a-b=%lf\n",a-b);
    }
};
class IFactory
{
public:
    virtual Operator* CreateOperator() = 0;
};

class AddFactory:public IFactory
{
    Operator* CreateOperator()
    {
        return new OperatorAdd();
    }
};

class SubFactory:public IFactory
{
public:
    Operator* CreateOperator()
    {
        return new OperatorSub();
    }
};
int main()
{
    IFactory* operFactory = new SubFactory();
    Operator*  oper = operFactory->CreateOperator();
    oper->setNumA(1.3);
    oper->setB(1.8);
    oper->GetResult();

    return 0;
}