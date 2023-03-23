//
// Created by sunchanghui on 2023/3/21.
//
#include<iostream>
using namespace std;

class State;
class ForenoonState;
class NoonSatate;
class AfternoonState;
class EveningState;
class SleepingState;
class RestState;
class Work;

// ����״̬��ɫ�����������״̬����Щ��Ϊ���ó���״̬�������о���״̬�ķ��������ҷ�װ������ɫ�������л�״̬��
class State
{
public:
    virtual void writeprogram(Work* w) = 0;
    virtual ~State() = default;
};
// Context ��ɫ���ڸ����ڲ�ά��һ��ConcreteState�����һ��ʵ�������Ը������״̬���л�
class Work
{
private:
    State* current;
    double m_hour;
    bool m_finish = false;
public:
    Work();
    ~Work();
    void setHour(double hour) {m_hour = hour;}
    double getHour() {return m_hour;}

    void setFinish(bool finish) {m_finish = finish;}
    bool getFinish(){return m_finish;}
    void SetState(State* s)
    {
        delete current;
        current = s;
    }
    void WorkProgram()
    {
        current->writeprogram(this);
    }

};
// ���涼�Ǿ����״̬�࣬ÿһ������״̬������������ְ�𣺸��౾״̬��Ҫ�������飬�Լ����ִ�е���������״̬���״̬��
class ForenoonState:public State
{
public:
    void writeprogram(Work* w) override;

};
class NoonState :public State
{
public:
    void writeprogram(Work* w)override;
};

class AfternoonState :public State
{
public:
    void writeprogram(Work* w)override;
};

class EveningState :public State
{
public:
    void writeprogram(Work* w)override;
};

class SleepingState :public State
{// ˯��״̬
public:
    void writeprogram(Work* w)override;

};

class RestState :public State
{// �°���Ϣ״̬
public:
    void writeprogram(Work* w)override;

};

Work::Work()
{
    current = new ForenoonState();
}
Work::~Work()
{
    delete current;
}

void ForenoonState::writeprogram(Work *w)
{
    if(w->getHour() < 12)
    {
        cout << "��ǰʱ�䣺" << w->getHour() <<"�㣬���繤��������ٱ�"<< endl;
    }
    else
    {
        w->SetState((new NoonState()));
        w->WorkProgram();
    }

}
void NoonState::writeprogram(Work* w)
{
    if (w->getHour() < 13)
    {
        cout << "��ǰʱ�䣺" << w->getHour() << "�㣬���緹��˯���" << endl;
    }
    else
    {
        w->SetState(new AfternoonState());
        w->WorkProgram();
    }
}
void AfternoonState::writeprogram(Work* w)
{
    if (w->getHour() < 17)
    {
        cout << "��ǰʱ�䣺" << w->getHour() << "�㣬����״̬������" << endl;
    }
    else
    {
        w->SetState(new EveningState());
        w->WorkProgram();
    }
}

void EveningState::writeprogram(Work* w)
{
    if (w->getFinish())
    {
        w->SetState(new RestState());
        w->WorkProgram();
    }
    else
    {
        if (w->getHour() < 21)
        {
            cout << "��ǰʱ�䣺" << w->getHour() << "��,�Ӱ�Ŷ��ƣ������ " << endl;
        }
        else
        {
            w->SetState(new SleepingState());
            w->WorkProgram();
        }
    }
}

void SleepingState::writeprogram(Work* w)
{
    cout << "��ǰʱ�䣺" << w->getHour() << "��,�����ˣ�˯���� " << endl;
}

void RestState::writeprogram(Work* w)
{
    cout << "��ǰʱ�䣺" << w->getHour() << "��,�°�ؼ��� " << endl;
}
int main()
{
    Work emergencyProjects;

    emergencyProjects.setHour(9);
    emergencyProjects.WorkProgram();

    emergencyProjects.setHour(10);
    emergencyProjects.WorkProgram();

    emergencyProjects.setHour(12);
    emergencyProjects.WorkProgram();

    emergencyProjects.setHour(13);
    emergencyProjects.WorkProgram();

    emergencyProjects.setHour(14);
    emergencyProjects.WorkProgram();

    emergencyProjects.setHour(17);
    emergencyProjects.WorkProgram();

    emergencyProjects.setFinish(false);

    emergencyProjects.setHour(19);
    emergencyProjects.WorkProgram();

    emergencyProjects.setHour(22);
    emergencyProjects.WorkProgram();

    system("pause");
    return 0;
}