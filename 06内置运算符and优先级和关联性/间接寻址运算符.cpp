// expre_Indirection_Operator.cpp
// compile with: /EHsc
// Demonstrate indirection operator
#include <iostream>
using namespace std;

int main16() {
    int n = 5;
    int* pn = &n;
    int** ppn = &pn;

    cout << "Value of n:\n"
        << "ֱ�Ӽ�ֵ: " << n << endl
        << "��Ӽ�ֵ: " << *pn << endl
        << "˫�ؼ�Ӽ�ֵ: " << **ppn << endl
        << "n�ĵ�ַ: " << pn << endl
        << "n ͨ�����Ѱַ�ĵ�ַ: " << *ppn << endl
        << "n �ĵ�ַ" << &n << endl;
    return 0;
}