// expre_One_Complement_Operator.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;

int main241() {
	unsigned short y = 0xFFFF; // 1111 1111 1111
	cout << hex << y << endl; //fff
	//1�Ĳ�������� (~) ����ʱ��Ϊ ��λ�� �������������������İ�λ�����Ʒ��롣 ������������Ϊ 1 ��ÿ��λ�ڽ����Ϊ 0�� �෴����������Ϊ 0 ��ÿ��λ�ڽ����Ϊ 1�� �����Ʒ���������Ĳ���������Ϊ���͡�
	//1111 1111 1111
	//0000 0000 0000

	y = ~y;   // ȡ�Լ��Ĳ���   
	cout << hex << y << endl;

	return 0;
}