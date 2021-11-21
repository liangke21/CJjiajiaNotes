

// expre_Postfix_Increment_and_Decrement_Operators.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

int main261() {
	int i = 10;
	cout << i++ << endl;  //当前引用不增加
	cout << i << endl;

	return 0;
}