// expre_Multiplicative_Operators.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;
int main22() {
    int x = 3, y = 6, z = 10;
    cout << "3 * 6 is " << x * y << endl //18
        << "6 / 3 is " << y / x << endl//2
        << "10 % 3 is " << z % x << endl//гр 1
        << "10 / 3 is " << (float)z / x << endl;//3.33333

    return 0;
}