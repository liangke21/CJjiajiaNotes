// static1.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
void showstat(int curr) {
    static int nStatic;    // ���� n Static ��ֵ
                           //ÿ�κ�������֮��
    nStatic += curr;
    cout << "nStatic is " << nStatic << endl;
}

int main2() {
    for (int i = 0; i < 5; i++)
        showstat(i);
    return 0;
}