// static1.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
void showstat(int curr) {
    static int nStatic;    // 保留 n Static 的值
                           //每次函数调用之间
    nStatic += curr;
    cout << "nStatic is " << nStatic << endl;
}

int main2() {
    for (int i = 0; i < 5; i++)
        showstat(i);
    return 0;
}