


/*
��ʱ���������洢���ʶ���Ļ������� shared_ptr�������� ���ü��������� 
ͨ������ʵ��֮�����ѭ������ʱ���ᷢ�� shared_ptr �������

�������Ǿ����ܱ���ָ��Ĺ�������Ȩ�� ���ǣ�����������ʵ���Ĺ��� shared_ptr ����Ȩ��
�������ʵ��֮��ѭ�����á� ��ѭ�������޷����⣬���߳���ĳ��ԭ�����ȡʱ��
��ʹ�� weak_ptrΪһ�������������ṩ����һ�� �������� �� ͨ��ʹ�� ��
���Դ������ӵ��������ʵ������ �������ڻ����ڴ���Դ weak_ptrshared_ptr ��Ȼ��Чʱ��
weak_ptr�����������ü����������������ֹ���ü��������㡣
���ǣ�����ʹ�� weak_ptr ���Ի�ȡ���ڳ�ʼ������ shared_ptr ���¸����� 
����ڴ��ѱ�ɾ���� weak_ptr �� �� bool ��������� false ��
����ڴ���Ȼ��Ч�����µĹ���ָ���������ü�����
����ֻ֤Ҫ���������ڷ�Χ�ڣ��ڴ� shared_ptr ����Ч��


ʾ��
����Ĵ���ʾ����ʾ��һ����������� ���� weak_ptr ȷ����ȷɾ������ѭ��������Ķ���
����ʾ��ʱ�����������ڿ��������������󴴽��� Controller�����ʾ��������̵�ĳЩ���棬
���Ƕ������С� ÿ�������������ܹ���ʱ��ѯ������������״̬��
����ÿ��������������һ�� vector<weak_ptr<Controller>> ר�ÿ�������
ÿ������������һ��ѭ�����ã����ʹ�� ʵ�� weak_ptr ������ shared_ptr ��
*/


#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



class Controller
{

public:
    int Num;
    wstring Status;
    vector<weak_ptr<Controller>> others;
    explicit Controller(int i) : Num(i), Status(L"On")
    {
        wcout << L"Creating Controller" << Num << endl;
    }

    ~Controller()
    {
        wcout << L"Destroying Controller" << Num << endl;
    }

// ��ʾ��β����Ƿ�
    // ָ����ڴ��Ƿ���Ȼ���ڡ�
    void CheckStatuses() const
    {
        for_each(others.begin(), others.end(), [](weak_ptr<Controller> wp) {
            auto p = wp.lock();
            if (p)
            {
                wcout << L"Status of " << p->Num << " = " << p->Status << endl;
            }
            else
            {
                wcout << L"Null object" << endl;
            }
            });
    }
};

void RunTest()
{
    vector<shared_ptr<Controller>> v{
        make_shared<Controller>(0),
        make_shared<Controller>(1),
        make_shared<Controller>(2),
        make_shared<Controller>(3),
        make_shared<Controller>(4),
    };

// ÿ����������������δ��ɾ��������������������
    // ��ÿ��������һ��ָ������������������ָ�롣
    for (int i = 0; i < v.size(); ++i)
    {
        for_each(v.begin(), v.end(), [&v, i](shared_ptr<Controller> p) {
            if (p->Num != i)
            {
                v[i]->others.push_back(weak_ptr<Controller>(p));
                wcout << L"push_back to v[" << i << "]: " << p->Num << endl;
            }
            });
    }

    for_each(v.begin(), v.end(), [](shared_ptr<Controller>& p) {
        wcout << L"use_count = " << p.use_count() << endl;
        p->CheckStatuses();
        });
}

int main170701()
{
    RunTest();
    wcout << L"�������" << endl;
    char ch;
    cin.getline(&ch, 1);

    return 0;
}