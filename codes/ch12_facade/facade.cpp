//
// Created by sunchanghui on 2023/3/17.
//
#include "iostream"
#include "string"
using namespace std;

class SubSystem1
{
public:
    void Method1()
    {
        cout <<"Method1" << endl;
    }
};
class SubSystem2
{
public:
    void Method2()
    {
        cout <<"Method2" << endl;
    }
};
class SubSystem3
{
public:
    void Method3()
    {
        cout <<"Method3" << endl;
    }
};
//����� ����Ҫ�˽����е���ϵͳ�ķ��������ԣ�������� �Ա�������
class Facade
{
public:
    Facade()
    {
        m_a = new SubSystem1();
        m_b = new SubSystem2();
        m_c = new SubSystem3();
    }
    void Method1()
    {
        m_a->Method1();
        m_b->Method2();
    }
    void Method2()
    {
        m_b->Method2();
        m_c->Method3();
    }

private:
    SubSystem1* m_a;
    SubSystem2* m_b;
    SubSystem3* m_c;
};
int main()
{
    Facade* face = new Facade();     //����Facade������ �ͻ��˿��Ը�����֪��������ϵͳ��Ĵ���
    face->Method1();
    face->Method2();
    system("pause");
    return 0;
}