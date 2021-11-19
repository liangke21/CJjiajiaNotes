// static3.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;


struct C {
    void Test(int value) {
        static int var = 0;
        if (var == value)
            cout << "var == value" << endl;
        else
            cout << "var != value" << endl;

        var = value;
    }
};

int main23() {
    C c1;
    C c2;
    c1.Test(100);

    c2.Test(100);
    return 0;
}

//thread_local (C++11)

thread_local float f = 42.0; // ȫ�������ռ䡣������ʽ��̬�ġ�

struct S // ����Ӧ�������Ͷ���
{
  //  thread_local int i; // �Ƿ��ġ��ó�Ա�����Ǿ�̬�ġ�
    thread_local static char buf[10]; // OK
};

void DoSomething()
{
    // ���ֲ߳̾�Ӧ���ھֲ�������
    // ��ʽ���ֲ߳̾���̬ S �ҵĽṹ����
    thread_local S my_struct;
}