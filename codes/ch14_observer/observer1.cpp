//
// Created by sunchanghui on 2023/3/17.
//
#include <iostream>
#include <list>
using namespace std;

//Observer�� ����۲���,Ϊ���еľ���۲��߶���һ���ӿڣ��ڵõ������֪ͨʱ�����Լ�������ӿ�Ҫ�����½ӿڡ�
//�۲���һ����һ����������߽ӿ�ʵ�֣����½ӿ�ͨ������һ��Update()���� ��������������·�����
class Observer
{
public:
    virtual void Update(int) = 0;
};
//Subject�� �ɷ���Ϊ��������֪ͨ�� һ����һ�����������һ���ӿ�ʵ�֡��������жԹ۲��߶�������ñ���
//��һ���ۼ���,ÿ�����ⶼ�������κ������Ĺ۲��ߡ����������ṩһ���ӿڣ������ӻ���ɾ���۲��߶���
class Subject
{
public:
    virtual void Attach(Observer*) = 0;
    virtual void Detach(Observer*) = 0;
    virtual void Notify() = 0;
};
//ConcreteObserver ����۲��� ʵ�ֳ���۲��ɫ��Ҫ��ĸ��½ӿ�,�Ա�ʹ�����״̬�������״̬��Э��.
//����۲��߽�ɫ���Ա���һ��ָ�����������������.����۲���Уɫͨ����һ����������ʵ��
class ConcreteObserver:public Observer
{
private:
    Subject* m_pSubject;
public:
    ConcreteObserver(Subject* pSubject) : m_pSubject(pSubject){};
    void Update(int val)
    {
        cout << "ConcreteObserver get the update. New State:" << val << endl;
    }
};

class ConcreteObserver2:public Observer
{
public:
    ConcreteObserver2(Subject* pSubject) : m_pSubject(pSubject) {}

    void Update(int value)
    {
        cout << "ConcreteObserver2 get the update. New State:" << value << endl;
    }

private:
    Subject* m_pSubject;
};
//ConcreteSubject�࣬��������������߾���֪ͨ��..���й�״̬�������۲��߶����ھ��������ڲ�״̬�ı�ʱ...�����еǼǹ��Ĺ۲��߷���֪ͨ.
//�����������ͨ����һ����������ʵ��.
class ConcreteSubject:public Subject
{
private:
    list<Observer*> m_ObserverList;
    int m_iState;
public:
    void Attach(Observer* pObserver)
    {
        m_ObserverList.push_back(pObserver);
    }
    void Detach(Observer* pObserver)
    {
        m_ObserverList.remove(pObserver);
    }
    void Notify()
    {
        list<Observer*>::iterator it = m_ObserverList.begin();
        while(it != m_ObserverList.end())
        {
            (*it)->Update(m_iState);
            ++it;
        }

    }
    void SetState(int state)
    {
        m_iState = state;
    }

};
int main()
{
    //create Subject
    ConcreteSubject* pSubject = new ConcreteSubject();

    //create observer
    Observer* pObserver = new ConcreteObserver(pSubject);
    Observer* pObserver2 = new ConcreteObserver2(pSubject);

    //change the state
    pSubject->SetState(2);

    //register the observer
    pSubject->Attach(pObserver);
    pSubject->Attach(pObserver2);

    pSubject->Notify();

    //Unregister the observer
    pSubject->Detach(pObserver);

    pSubject->SetState(3);
    pSubject->Notify();

    delete pObserver;
    delete pObserver2;
    delete pSubject;
    system("pause");
    return 0;

}
