#include <iostream>
using namespace std;
int sum(int a, int b) //这是一个标识符为sum的函数
{
    return a + b;
}

int main010101()
{
    int i = sum(10, 32);
    int j = sum(i, 66);
    cout << "The value of j is" << j << endl; // 108

    return 0;
}