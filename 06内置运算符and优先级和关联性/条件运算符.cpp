// expre_Expressions_with_the_Conditional_Operator.cpp
// compile with: /EHsc
// Demonstrate conditional operator
#include <iostream>

/*
第一个操作nd 隐式转换为 bool 。 计算该操作数，并在继续前完成所有副作用。

如果第一个操作数计算 true 结果为 (1) ，则计算第二个操作数。

如果第一个操作数计算 false 结果为 (0) ，则计算第三个操作数。
*/
using namespace std;
int main11() {
	int i = 1, j = 2;
	cout << (i > j ? i : j) << " is greater." << endl;//2
	cout << (i < j ? i : j) << " is greater." << endl;//1
	return 0;
}