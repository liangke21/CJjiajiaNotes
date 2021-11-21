// expre_Logical_OR_Operator.cpp
// compile with: /EHsc
// Demonstrate logical OR
#include <iostream>
using namespace std;
int main201() {
    int a = 5, b = 10, c = 15;
    cout << boolalpha
        << "真实的表达 "
        << "a < b || b > c yields "
        << (a < b || b > c) << endl  //true
        //   true     false
        << "虚假的表达 "
        << "a > b || b > c yields "
        << (a > b || b > c) << endl; //false
        // false     false

    //总结  一个为true 表达式值为true
    return 0;
}