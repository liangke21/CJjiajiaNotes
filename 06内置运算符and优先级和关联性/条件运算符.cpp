// expre_Expressions_with_the_Conditional_Operator.cpp
// compile with: /EHsc
// Demonstrate conditional operator
#include <iostream>

/*
��һ������nd ��ʽת��Ϊ bool �� ����ò����������ڼ���ǰ������и����á�

�����һ������������ true ���Ϊ (1) �������ڶ�����������

�����һ������������ false ���Ϊ (0) ��������������������
*/
using namespace std;
int main11() {
	int i = 1, j = 2;
	cout << (i > j ? i : j) << " is greater." << endl;//2
	cout << (i < j ? i : j) << " is greater." << endl;//1
	return 0;
}