#include <stdlib.h>


int main131()
{
	long  long_num1, long_num2;
	int   int_num;

	// int num �ڸ�ֵ֮ǰ����Ϊ long ���͡�
//	long_num1 = int_num;  

	//int num �ڳ˷�֮ǰ����Ϊ long ���͡�
	//long_num2 = int_num * long_num2; 
	exit(0);
}
//�з���ת��Ϊ�޷���
#include <iostream>
//�з���ת��Ϊ�޷���
using namespace std;
int main132()
{
	short  i = -3;
	unsigned short u;

	cout << (u = i) << "\n";
	exit(0);
}
// Output: 65533

//����ת��������

double dVal;
float fVal;
int iVal;
unsigned long ulVal;

int main133() {
	// �� Val ת��Ϊ unsigned long
	// �˷����ת��Ϊ˫����
	//dVal = iVal * ulVal;

	// ul Val ת��Ϊ������
	// �ӷ����ת��Ϊ˫����
	//dVal = ulVal + fVal;
	exit(0);
}

//ָ�����ָ��
// C2039 expected
class A
{
public:
	int AComponent;
	int AMemberFunc();
};

class B : public A
{
public:
	int BComponent;
	int BMemberFunc();
};
int main134()
{
	B bObject;
	A* pA = &bObject;
	B* pB = &bObject;

	//pA->AMemberFunc();   // OK in class A
	//pB->AMemberFunc();   // OK: inherited from class A
	//pA->BMemberFunc();   //���󣺲��� A ����
	exit(0);
}
//ָ����ʽת��
char szPath[_MAX_PATH]; // Array of type char.
char* pszPath = szPath; // Equals &szPath[0].

//ָ���Աת���� null ָ��
class Ab
{
public:
	int i;
};

int Ab::* pai = 0;



int main()
{
	exit(0);
}