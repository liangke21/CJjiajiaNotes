// expre_Indirection_Operator.cpp
// compile with: /EHsc
// Demonstrate indirection operator
#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int* pn = &n;
    int** ppn = &pn;

    cout << "Value of n:\n"
        << "直接价值: " << n << endl
        << "间接价值: " << *pn << endl
        << "双重间接价值: " << **ppn << endl
        << "n的地址: " << pn << endl
        << "n 通过间接寻址的地址: " << *ppn << endl
        << "n 的地址" << &n << endl;
    return 0;
}