
/*

逻辑求反运算符 (!) 反转操作数的含义。 操作数必须是算法或指针类型（或计算结果为算法或指针类型的表达式）。 操作数将隐式转换为类型 bool 。 如果转换后的操作数为，则结果为 true false ; false 如果转换的操作数为，则结果为 true 。 结果的类型为 bool 。
*/

#include <iostream>
using namespace std;

int main19() {
    int i = 0;
    if (!i)
        cout << "我是零" << endl;

    return 0;
}