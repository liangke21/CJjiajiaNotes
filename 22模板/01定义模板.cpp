#include <iostream>
using namespace std;


//�����ʹ��ģ��

template <typename T>
T minimum(const T& lhs, const T& rhs)
{
    return lhs < rhs ? lhs : rhs;
}

int main220101() {

    int a = 20;
    int b = 30;
    int i = minimum<int>(a, b);//ok ��
    //���ǣ���������һ������ģ�壬���ұ��������� T �Ӳ��� T �� b�Ƶ������ͣ���˿�������ͨ����һ����������
    int i = minimum(a, b);//ko
    cout << i << endl;
    return 0;
}
//���������������һ�����ʱ����������һ���º��������У�ģ���е�ÿ�� T ���滻Ϊ ��

int minimum(const int& lhs, const int& rhs)
{
    return lhs < rhs ? lhs : rhs;
}