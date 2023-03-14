//
// Created by sunchanghui on 2023/3/14.
//
//代理模式
#include "iostream"

using namespace std;

//Subject 定义了RealSubject和Proxy的共用接口..这样就在任何使用RealSubject的地方都可以使用Proxy
class Subject
{
public:
    virtual void func()
    {
        cout << "Subject" << endl;
    }
};
// RealSubject  定义proxy所代表的真实实体
class RealSubject:public Subject
{
public:
    virtual void func()
    {
        cout << "RealSubject" << endl;
    }
};
//proxy 保存一个引用使得代理可以访问实体,并且提供一个于Subject的接口相同的接口 这样代理就可以用来替代实体
class Proxy:public Subject
{
    RealSubject real;
public:
    virtual void func()
    {
        cout<<"Proxy" << endl;
        real.func();
    }
};
int main()
{
    Proxy proxy;
    proxy.func();
    return 0;
}