// expre_Additive_Operators.cpp
// compile with: /EHsc
#include <iostream>
#define SIZE 5
using namespace std;

//�ӷ��������+ �� -
int main3() {
    int i = 5, j = 10;
    int n[SIZE] = { 0, 1, 2, 3, 4 };
    cout << "5 + 10 = " << i + j << endl
        << "5 - 10 = " << i - j << endl;

    // ��������ʹ��ָ���㷨

    cout << "n[3] = " << *(n + 2) << endl;
    cout << "n[3] = " << (n + 2) << endl;
    cout << "n[3] = " << n[2] << endl;
    cout << "n[3] = " << (n[2]) << endl;
    cout << "n[3] = " << *&(n[2]) << endl;
    cout << "n[3] = " << &n[2] << endl;

    return 0;
}


//ָ��Ӽ���
int main03()
{

    short IntArray[10]; // Objects of type short occupy 2 bytes
    short* pIntArray = IntArray;

    for (int i = 0; i < 10; ++i)
    {
        *pIntArray = i;
        cout << *pIntArray << "\n";
        pIntArray = pIntArray + 1;  //��Ȼ������ֵ 1 ��ӵ� pIntArray�����Ⲣ����ʾ���� 1 ��ӵ��õ�ַ��������ָ������ָ��ʹ��ָ�������е���һ�����󡱣����ö���ǡ������ 2 �ֽڣ����� sizeof( int )��֮�⡣
    }

    for (short a : IntArray) {

        cout << "a : " << a<< endl;
    }
    return 0;
}