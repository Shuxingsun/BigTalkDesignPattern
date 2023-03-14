//
// Created by sunchanghui on 2023/3/12.
//
//����ģʽ ����ʵ��
#include<algorithm>
#include "iostream"
using namespace std;
#define free_ptr(p)if(p) delete p;p = nullptr;

//Stratety: ��������֧�ֵ��㷨�Ĺ����ӿ�
class Strategy
{
public:
    virtual ~Strategy(){};
    virtual void AlgorithmInterface() = 0;
};

//ConcretesStrategy ��װ������㷨����Ϊ
class ConcreteStrategyA:public Strategy
{
    void AlgorithmInterface()
    {
        cout << "�㷨Aʵ��" << endl;
    }
};
class ConcreteStrategyB : public Strategy {
    void AlgorithmInterface() {
        cout << "�㷨Bʵ��" << endl;
    }
};

class ConcreteStrategyC : public Strategy {
    void AlgorithmInterface() {
        cout << "�㷨Cʵ��" << endl;
    }
};

//context ,��һ��ConcreteStrategy�����ã�ά��һ��Strategy������
class Context
{
public:
    Context(Strategy* strategy) : m_strategy(strategy) {};
    ~Context() { free_ptr(m_strategy); };
    void AlgorithmInterface()
    {
        m_strategy->AlgorithmInterface();
    }
private:
    Strategy* m_strategy;
};

int main()
{
    Strategy* concreteStrategyA = new ConcreteStrategyA();
    Strategy* concreteStrategyB = new ConcreteStrategyB();
    Strategy* concreteStrategyC = new ConcreteStrategyC();

    concreteStrategyA->AlgorithmInterface();
    concreteStrategyB->AlgorithmInterface();
    concreteStrategyC->AlgorithmInterface();

    free_ptr(concreteStrategyA);
    free_ptr(concreteStrategyB);
    free_ptr(concreteStrategyC);

}