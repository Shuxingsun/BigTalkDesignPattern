//
// Created by sunchanghui on 2023/3/15.
//

#ifndef BIGTALKDESIGNPATTERN_TESTPAPER_H
#define BIGTALKDESIGNPATTERN_TESTPAPER_H

#include "iostream"
using namespace std;

class TestPaper
{
public:
    void testQuestion1();
    void testQuestion2();
    void testQuestion3();
    //����template_mathod ��
    //���̳е�������д��ÿ���˵Ĵ𰸲�ͬ
    virtual string answer1() = 0;
    virtual string answer2() = 0;
    virtual string answer3() = 0;
};

class TestPaperA:public TestPaper
{
public:
    string answer1() override;
    string answer2() override;
    string answer3() override;
};

class  TestPaperB:public TestPaper
{
public:
    string answer1() override;
    string answer2() override;
    string answer3() override;
};
#endif //BIGTALKDESIGNPATTERN_TESTPAPER_H
