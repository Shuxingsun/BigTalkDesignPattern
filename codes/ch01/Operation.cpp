#include <iostream>

#include "Operation.h"

using namespace std;

class OperationAdd : public Operation
{
public:
    double getResult() const override
    {
        double result = 0;
        result = m_numberA + m_numberB;
        return result;
    }
};
class OperationSub : public Operation
{
public:
    double getResult() const override
    {
        double result = 0;
        result = m_numberA - m_numberB;
        return result;
    }
};

class OperationMul : public Operation
{
public:
    double getResult() const override
    {
        double result = 0;
        result = m_numberA * m_numberB;
        return result;
    }
};

class OperationDiv : public Operation
{
public:
    double getResult() const override
    {
        double result = 0;
        if (m_numberB == 0)
        {
            throw new invalid_argument("��������Ϊ0��");
        }
        result = m_numberA / m_numberB;
        return result;
    }
};

Operation *OperationFactory::createOperate(const char operate)
{
    Operation *oper;
    switch (operate)
    {
        case '+':
            oper = new OperationAdd();
            break;
        case '-':
            oper = new OperationSub();
            break;
        case '*':
            oper = new OperationMul();
            break;
        case '/':
            oper = new OperationDiv();
            break;
    }
    return oper;
};

int main()
{
    try
    {
        string numA;
        string operate;
        string numB;
        cout << " ����������A�� ";
        cin >> numA;
        cout << " ��ѡ��������ţ�+��-��*��/���� ";
        cin >> operate;
        cout << " ����������B�� ";
        cin >> numB;

        Operation *oper;
        oper = OperationFactory::createOperate(operate[0]);
        oper->setNumberA(stod(numA));
        oper->setNumberB(stod(numB));
        double result = oper->getResult();
        cout << result << endl;
    }
    catch (char *msg)
    {
        cerr << msg << endl;
    }
    return 0;
}