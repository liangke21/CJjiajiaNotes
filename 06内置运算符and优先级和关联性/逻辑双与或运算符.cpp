// expre_Logical_OR_Operator.cpp
// compile with: /EHsc
// Demonstrate logical OR
#include <iostream>
using namespace std;
int main201() {
    int a = 5, b = 10, c = 15;
    cout << boolalpha
        << "��ʵ�ı�� "
        << "a < b || b > c yields "
        << (a < b || b > c) << endl  //true
        //   true     false
        << "��ٵı�� "
        << "a > b || b > c yields "
        << (a > b || b > c) << endl; //false
        // false     false

    //�ܽ�  һ��Ϊtrue ���ʽֵΪtrue
    return 0;
}