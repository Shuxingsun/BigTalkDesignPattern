//
// Created by sunchanghui on 2023/3/14.
//
//����ģʽ
#include "iostream"

using namespace std;

//Subject ������RealSubject��Proxy�Ĺ��ýӿ�..���������κ�ʹ��RealSubject�ĵط�������ʹ��Proxy
class Subject
{
public:
    virtual void func()
    {
        cout << "Subject" << endl;
    }
};
// RealSubject  ����proxy���������ʵʵ��
class RealSubject:public Subject
{
public:
    virtual void func()
    {
        cout << "RealSubject" << endl;
    }
};
//proxy ����һ������ʹ�ô�����Է���ʵ��,�����ṩһ����Subject�Ľӿ���ͬ�Ľӿ� ��������Ϳ����������ʵ��
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