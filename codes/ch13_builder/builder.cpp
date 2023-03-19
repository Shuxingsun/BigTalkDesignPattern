//
// Created by sunchanghui on 2023/3/17.
//
//������ģʽ�ṹͼ��Ӧ����
//#inlcude "" ͨ�����·������  #include<> ͨ��ͷ�ļ����ʣ��Ƽ����
#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
using namespace std;

//Product Class����Ʒ�࣬�ɶ���������
class Product
{
private:
    vector<string> parts;
public:
    //��Ӳ�Ʒ����
    void Add(string part)
    {
        parts.push_back(part);
    }
    //��ʾ���в�Ʒ����
    void show()
    {
        cout << "��Ʒ ���� " << endl;
        for_each(parts.cbegin(),parts.cend(),[](const string& s) {cout << s << " ";});
        cout << endl;
    }

};
//Builder����������,������һ���õ���Ʒ��������ķ���GetResult��
class Builder
{
public:
    virtual ~Builder() = default;
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    virtual Product* GetResult() = 0;
};

//ConcreteBuilder1,���彨������,ʵ��Builder�ӿ��еľ��巽����
class ConcreBuilder1:public Builder
{
private:
    Product* product = new Product;
public:
    void BuildPartA() override
    {
        product->Add("����A");
    }
    void BuildPartB() override
    {
        product->Add("����B");
    }
    Product* GetResult() override
    {
        return product;
    }
};

//ConcreteBuilder2,���彨������,ʵ��Builder�ӿ��еľ��巽����
class ConcreBuilder2:public Builder
{
private:
    Product* product = new Product;
public:
    void BuildPartA() override
    {
        product->Add("����X");
    }
    void BuildPartB() override
    {
        product->Add("����Y");
    }
    Product* GetResult() override
    {
        return product;
    }
};
//  ָ�����ָ࣬�ӽ���Product�Ĺ��̣����ƹ��������������˳�򣩡�
class Director
{
public:
    void Construct(Builder * const b)
    {
        b->BuildPartA();
        b->BuildPartB();
    }
};
int main()
{
    //�û�������Ҫ֪������Ľ�����̣�ֻ��ָ������ Product �������͡�
    Director director;
    Builder* b1 = new ConcreBuilder1;
    Builder* b2 = new ConcreBuilder2;

    cout << "��ConcreBuilder1�ķ��������Ʒ" << endl;
    director.Construct(b1);
    Product* p1 = b1->GetResult();
    p1->show();
    cout << endl;

    cout << "��ConcreBuilder2�ķ��������Ʒ" << endl;
    director.Construct(b2);
    Product* p2 = b2->GetResult();
    p2->show();
    cout << endl;

    delete p2;
    delete p1;
    delete b1;
    delete b2;
    p2 = p1 = nullptr;
    b1 = b2 = nullptr;
    system("pause");
    return 0;

}

