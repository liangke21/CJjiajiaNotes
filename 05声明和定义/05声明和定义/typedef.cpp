#include <iostream>
using namespace std;


int main81()
{
	// typedef_names1.cpp
// C2377 expected
	typedef unsigned long UL;   // ����һ�� typedef ���ƣ�UL��
	//int UL;                     // C2377�����¶��塣
	UL a= -1;

	cout << "bool: \t\t" << "��ռ�ֽ�����" << sizeof(UL);
	cout << "\t���ֵ��" << (numeric_limits< UL>::max)();
	return 0;

}

// ��������ʶ����ص��������ع��򻹿ɿ���ʹ�����������ƵĿɼ��� typedef �� ��ˣ�����ʾ���� C++ ���ǺϷ��ģ�
typedef unsigned long UL;   // ����һ�� typedef ���ƣ�UL
int main82()
{
	unsigned int UL;   // ������������ typedef ����
	return 0;
}

// typedef UL �ص���Χ��

//typedef ��������

typedef void DRAWF(int, int);

DRAWF boox;
int main83()
{
	
	boox(9, 9);

	return 0;
}

void boox(int, int) {

	cout << "���ɶ";
}

// typedef ͨ�����ϣ� struct �������������û���������ͣ�


#include <stdio.h>

typedef struct mystructtag
{
	int   i;
	double f;
} mystruct;

int main84()
{
	mystruct ms;
	ms.i = 10;
	ms.f = 0.99;
	printf_s("%d   %f\n", ms.i, ms.f);

	return 0;
}