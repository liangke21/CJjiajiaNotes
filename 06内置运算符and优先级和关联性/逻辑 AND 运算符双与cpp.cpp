// expre_Logical_AND_Operator.cpp
// compile with: /EHsc
// Demonstrate logical AND
#include <iostream>

using namespace std;

int main181() {
    int a = 5, b = 10, c = 15;
    cout << boolalpha
        << "真实的表达 "
        << "a < b && b < c yields "
        << (a < b&& b < c) << endl  //true
         //  true    true
        << "虚假的表达 "
        << "a > b && b < c yields "
        << (a > b && b < c) << endl; // false
        //  false    true

     //总结 必须两个都是 true 
    return 0;
}