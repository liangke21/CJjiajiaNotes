// expre_Additive_Operators.cpp
// compile with: /EHsc
#include <iostream>
#define SIZE 5
using namespace std;

//�ӷ��������+ �� -
int main() {
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


}