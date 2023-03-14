//
// Created by sunchanghui on 2023/3/13.
//装饰器模式 ，动态地给一个对象添加一些额外的职责，就增加功能来说 装饰模式比生成子类更为灵活
//
#include "iostream"
using namespace std;

//ConcreteComponent即Component
class Person
{
protected:
    string name;
public:
    Person(){};
    Person(string name) :name(name){};
    virtual void show()
    {
        cout << "装扮的 "<<name<< endl;
    }
};

//Decorator类（装饰类）继承了Person类，并且弱拥有Person类
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

//ConcreteDecorator类
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
    Person * p = new Person("小菜");
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