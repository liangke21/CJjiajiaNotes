// cpp_comma_operator.cpp
#include <stdio.h>
int main10() {
	int i = 10, b = 20, c = 30;
	//逗号运算符具有从左向右的关联性。 由逗号分隔的两个表达式将从左向右进行计算。 始终计算左操作数，并且在计算右操作数之前将完成所有副作用。
	i = b, c;  //始终在左
	printf("%i\n", i);
	//从左往右 圆括号强制编译器将第一个逗号解释为顺序计算运算符。
	i = (b, c,54+6);
	printf("%i\n", i);

	return 0;
}