//
// Created by sunchanghui on 2023/3/17.
//


#include "iostream"
#include "Fund.h"
using namespace std;


void Stock1::buy()
{
    cout << "��Ʊ1����" << endl;
}

void Stock1::sell()
{
    cout << "��Ʊ1����" << endl;
}

void Stock2::buy()
{
    cout << "��Ʊ2����" << endl;
}

void Stock2::sell()
{
    cout << "��Ʊ2����" << endl;
}

void Stock3::buy()
{
    cout << "��Ʊ3����" << endl;
}

void Stock3::sell()
{
    cout << "��Ʊ3����" << endl;
}

void NationalDebt1::buy()
{
    cout << "��ծ1����" << endl;
}

void NationalDebt1::sell()
{
    cout << "��ծ1����" << endl;
}

void Realty1::buy()
{
    cout << "���ز�1����" << endl;
}

void Realty1::sell()
{
    cout << "���ز�1����" << endl;
}


void Fund::buyFund()
{
    m_gu1->buy();
    m_gu2->buy();
    m_gu3->buy();
    m_nd1->buy();
    m_rt1->buy();
}

void Fund::sellFund()
{
    m_gu1->sell();
    m_gu2->sell();
    m_gu3->sell();
    m_nd1->sell();
    m_rt1->sell();
}


int main()
{
    Fund * jijin = new Fund();
    jijin->buyFund();
    jijin->sellFund();
}
