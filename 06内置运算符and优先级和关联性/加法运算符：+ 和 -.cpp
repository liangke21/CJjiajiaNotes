// expre_Additive_Operators.cpp
// compile with: /EHsc
#include <iostream>
#define SIZE 5
using namespace std;

//加法运算符：+ 和 -
int main3() {
    int i = 5, j = 10;
    int n[SIZE] = { 0, 1, 2, 3, 4 };
    cout << "5 + 10 = " << i + j << endl
        << "5 - 10 = " << i - j << endl;

    // 在数组上使用指针算法

    cout << "n[3] = " << *(n + 2) << endl;
    cout << "n[3] = " << (n + 2) << endl;
    cout << "n[3] = " << n[2] << endl;
    cout << "n[3] = " << (n[2]) << endl;
    cout << "n[3] = " << *&(n[2]) << endl;
    cout << "n[3] = " << &n[2] << endl;

    return 0;
}


//指针加减法
int main03()
{

    short IntArray[10]; // Objects of type short occupy 2 bytes
    short* pIntArray = IntArray;

    for (int i = 0; i < 10; ++i)
    {
        *pIntArray = i;
        cout << *pIntArray << "\n";
        pIntArray = pIntArray + 1;  //虽然将整数值 1 添加到 pIntArray，但这并不表示“将 1 添加到该地址”，而是指“调整指针使其指向数组中的下一个对象”，而该对象恰好是在 2 字节（或者 sizeof( int )）之外。
    }

    for (short a : IntArray) {

        cout << "a : " << a<< endl;
    }
    return 0;
}