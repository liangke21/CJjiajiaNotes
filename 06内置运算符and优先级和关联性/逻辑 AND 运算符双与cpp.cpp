// expre_Logical_AND_Operator.cpp
// compile with: /EHsc
// Demonstrate logical AND
#include <iostream>

using namespace std;

int main181() {
    int a = 5, b = 10, c = 15;
    cout << boolalpha
        << "��ʵ�ı�� "
        << "a < b && b < c yields "
        << (a < b&& b < c) << endl  //true
         //  true    true
        << "��ٵı�� "
        << "a > b && b < c yields "
        << (a > b && b < c) << endl; // false
        //  false    true

     //�ܽ� ������������ true 
    return 0;
}