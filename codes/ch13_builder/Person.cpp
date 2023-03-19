//
// Created by sunchanghui on 2023/3/17.
//

#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

void Person::add(string part)
{
    m_parts.push_back(part);
}
void Person::show()
{
    cout << "\n ���� չʾ ----" << endl;
    for(auto v:m_parts)
    {
        cout << v << endl;
    }
}
Pen::Pen(Color color)
{
    m_color = color;
}
void Pen::getColor()
{
    switch (m_color)
    {
        case Color::yellow:
            cout << "ʹ�û�ɫ����";
            break;
        case Color::white:
            cout << "ʹ�ð�ɫ����";
            break;
        case Color::blank:
            cout<<"ʹ�ú�ɫ����";
            break;
    }
}
void print(string action,int a,int b,int c,int d)
{
    cout << action << a << " "<< b << " "<< c<< " " << d << " "<< endl;
}
void Graphics::drawEllipse(Pen *p, int a, int b, int c, int d)
{
    p->getColor();
    print("��ͼ:" ,a,b,c,d);
}
void Graphics::drawRectangle(Pen * p, int a, int b, int c, int d)
{
    p->getColor();
    print("������", a, b, c, d);
}

void Graphics::drawLine(Pen * p, int a, int b, int c, int d)
{
    p->getColor();
    print("���ߣ�", a, b, c, d);
}
ThinBuilder::ThinBuilder(Graphics* g,Pen* p)
{
    m_g = g;
    m_pen = p;
};

void ThinBuilder::buildHead()
{
    m_g->drawEllipse(m_pen,50,20,30,30);
    m_per->add("ͷ��");
}
void ThinBuilder::buildBody()
{
    m_g->drawRectangle(m_pen, 50, 20, 30, 30);
    m_per->add("����");
}

void ThinBuilder::buildArmLeft()
{
    m_g->drawLine(m_pen, 50, 20, 30, 30);
    m_per->add("����");
}

void ThinBuilder::buildArmRight()
{
    m_g->drawLine(m_pen, 50, 20, 30, 30);
    m_per->add("����");
}

void ThinBuilder::buildLegLeft()
{
    m_g->drawLine(m_pen, 50, 20, 30, 30);
    m_per->add("����");
}

void ThinBuilder::buildLegRight()
{
    m_g->drawLine(m_pen, 50, 20, 30, 30);
    m_per->add("����");
}
Person * ThinBuilder::getPerson()
{
    return m_per;
}

FatBuilder::FatBuilder(Graphics * g, Pen * p)
{
    m_g = g;
    m_pen = p;
};

void FatBuilder::buildHead()
{
    m_g->drawEllipse(m_pen, 50, 20, 30, 30);
    m_per->add("ͷ��");
}

void FatBuilder::buildBody()
{
    m_g->drawRectangle(m_pen, 60, 50, 10, 50);
    m_per->add("����");
}

void FatBuilder::buildArmLeft()
{
    m_g->drawLine(m_pen, 60, 50, 40, 100);
    m_per->add("����");
}

void FatBuilder::buildArmRight()
{
    m_g->drawLine(m_pen, 70, 50, 40, 100);
    m_per->add("����");
}

void FatBuilder::buildLegLeft()
{
    m_g->drawLine(m_pen, 60, 100, 45, 150);
    m_per->add("����");
}

void FatBuilder::buildLegRight()
{
    m_g->drawLine(m_pen, 70, 100, 85, 150);
    m_per->add("����");
}

Person * FatBuilder::getPerson()
{
    return m_per;
}

Director::Director(Builder * b)
{
    m_b = b;
}
void Director::createPerson()
{
    m_b->buildHead();
    m_b->buildBody();
    m_b->buildArmLeft();
    m_b->buildArmRight();
    m_b->buildLegLeft();
    m_b->buildLegRight();
}

int main()
{
    Pen * p = new Pen(Color::yellow);
    Graphics * g = new Graphics();

    cout << "\n\n��ʼ��������" << endl;
    ThinBuilder * tb = new ThinBuilder(g, p);
    Director * dtb = new Director(tb);
    dtb->createPerson();
    Person * tp = tb->getPerson();
    tp->show();

    cout << "\n\n��ʼ��������" << endl;
    FatBuilder * fb = new FatBuilder(g, p);
    Director * dfb = new Director(fb);
    dfb->createPerson();
    Person * fp = fb->getPerson();
    fp->show();

    return 0;
}
