/*
��λ "���" ����� (|) �����һ����������ÿ��λ����ڶ�����������Ӧλ���бȽϡ� 
�������һ��λ�� 1���򽫶�Ӧ�Ľ��λ����Ϊ 1�� ���򣬽���Ӧ�Ľ��λ����Ϊ 0��
*/

// expre_Bitwise_Inclusive_OR_Operator.cpp
// compile with: /EHsc
// Demonstrate bitwise inclusive OR
#include <iostream>
using namespace std;

int main09() {
	unsigned short a = 0x5555;      // pattern 0101 ...
	unsigned short b = 0xAAAA;      // pattern 1010 ...

	cout << hex << (a | b) << endl;   // prints "ffff" pattern 1111 ...

	return 0;
}