


int main0601() {
	char chArray[10];
	char* pch = chArray;   // ����ָ���һ��Ԫ�ص�ָ�롣
	char   ch = chArray[0];   // �����һ��Ԫ�ص�ֵ��
	ch = chArray[3];   // ������ĸ�Ԫ�ص�ֵ��

	return 0;
}


#include <iostream>
using namespace std;
int main0602() {
	double multi[4][4][3];   //�������顣
	double(*p2multi)[3];
	double(*p1multi);

	cout << multi[3][2][2] << "\n";   // C4700 ʹ�������±ꡣ
	p2multi = multi[3];               // ʹ p2multi ָ��
									  // ��ĵ��ĸ���ƽ�桱��
	p1multi = multi[3][2];            // ʹ p1multi ָ��
									  // ����ƽ�������

	return 0;
}