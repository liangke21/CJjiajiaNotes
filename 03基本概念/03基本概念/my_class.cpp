// my_class.cpp
#include "my_class.h" // ����Ŀ¼�еı���
#include <iostream> // ��׼���е�ͷ�ļ�

using namespace N;
using namespace std;

void my_class::do_something()
{
    cout << "���£�" << endl;
}

int main31()
{
    class my_class aa;

    aa.do_something();

    class my_class* aa2 = new my_class;

    aa.do_something();
    return 0;
}