//
// Created by sunchanghui on 2023/3/13.
//װ����ģʽ ����̬�ظ�һ���������һЩ�����ְ�𣬾����ӹ�����˵ װ��ģʽ�����������Ϊ���
//
#include "iostream"
using namespace std;

//ConcreteComponent��Component
class Person
{
protected:
    string name;
public:
    Person(){};
    Person(string name) :name(name){};
    virtual void show()
    {
        cout << "װ��� "<<name<< endl;
    }
};

//Decorator�ࣨװ���ࣩ�̳���Person�࣬������ӵ��Person��
class Finery:public Person
{
protected:
    Person *m_component;
public:
    Finery():m_component(nullptr){};
    void Decorator(Person* component)
    {
        this->m_component = component;
    }
    void show() override
    {
        if(m_component)
            m_component->show();
    }
};
//ConcreteDecoration
class Tshirts:public Finery
{
    virtual void show()
    {
        cout << "Tshirts" << endl;
        Finery::show();
    }

public:
    virtual ~Tshirts(){}
};

//ConcreteDecorator��
class Jeans : public Finery
{
public:
    virtual	~Jeans() {}
    virtual void show()
    {
        cout << "Jeans" << endl;
        Finery::show();
    }
};

int main()
{
    Person * p = new Person("С��");
    Tshirts* oTshirt = new Tshirts();
    Jeans* oJeans = new Jeans();
    oTshirt->Decorator(p);
    oJeans->Decorator(oTshirt);
    oJeans->show();

    delete p;p = nullptr;
    delete oTshirt;oTshirt = nullptr;
    delete oJeans;oJeans = nullptr;
    system("pause");
    return 0;
}