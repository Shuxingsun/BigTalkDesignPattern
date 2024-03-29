//
// Created by sunchanghui on 2023/3/17.
//
//建造者模式结构图对应代码
//#inlcude "" 通过相对路径访问  #include<> 通过头文件访问，推荐这个
#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
using namespace std;

//Product Class，产品类，由多个部件组成
class Product
{
private:
    vector<string> parts;
public:
    //添加产品部件
    void Add(string part)
    {
        parts.push_back(part);
    }
    //显示所有产品部件
    void show()
    {
        cout << "产品 创建 " << endl;
        for_each(parts.cbegin(),parts.cend(),[](const string& s) {cout << s << " ";});
        cout << endl;
    }

};
//Builder，抽象建造者,并声明一个得到产品建造后结果的方法GetResult。
class Builder
{
public:
    virtual ~Builder() = default;
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    virtual Product* GetResult() = 0;
};

//ConcreteBuilder1,具体建造者类,实现Builder接口中的具体方法。
class ConcreBuilder1:public Builder
{
private:
    Product* product = new Product;
public:
    void BuildPartA() override
    {
        product->Add("部件A");
    }
    void BuildPartB() override
    {
        product->Add("部件B");
    }
    Product* GetResult() override
    {
        return product;
    }
};

//ConcreteBuilder2,具体建造者类,实现Builder接口中的具体方法。
class ConcreBuilder2:public Builder
{
private:
    Product* product = new Product;
public:
    void BuildPartA() override
    {
        product->Add("部件X");
    }
    void BuildPartB() override
    {
        product->Add("部件Y");
    }
    Product* GetResult() override
    {
        return product;
    }
};
//  指挥者类，指挥建造Product的过程（控制构建各部分组件的顺序）。
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
    //用户并不需要知道具体的建造过程，只需指定建造 Product 具体类型。
    Director director;
    Builder* b1 = new ConcreBuilder1;
    Builder* b2 = new ConcreBuilder2;

    cout << "用ConcreBuilder1的方法建造产品" << endl;
    director.Construct(b1);
    Product* p1 = b1->GetResult();
    p1->show();
    cout << endl;

    cout << "用ConcreBuilder2的方法建造产品" << endl;
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

