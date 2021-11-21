// expre_Relational_Operators.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;

int main() {
    cout << "真正的表达式 3 &gt; 2 产生："
        << (3 > 2) << endl //1
        << "错误表达式 20 &lt; 10 产生： "
        << (20 < 10) << endl;//0
}