
//typename��ģ�嶨����ʹ���޶��������߱������������޶����Ʊ�ʶ���͡� �й���ϸ��Ϣ������� �������ơ�

#include <stdio.h>
template <class T> class X
{
public:
	void f(typename T::myType* mt) {}
};

class Yarg
{
public:
	struct myType { };
};

int main22060201()
{
	X<Yarg> x;
	x.f(new Yarg::myType());
	printf("ʹ�� typename �ؼ��ֽ���������.");
	return 0;
}

/*
������Ƶ����Ʋ��Ҵ�ģ�嶨����������м������-�������ʾ���У�
�������Ļᷢ�� myFunction(char) ��ģ��ʵ�����������ġ�
�������ʾ���У�ģ���� main ��ʵ����;��ˣ�
�� MyNamespace::myFunction ʵ������ɼ���
������ѡȡΪ���õ�ƥ��� ��������� MyNamespace::myFunction���򽫵��� myFunction(char)��


�������ƶ���õ�����������ͬ��������������һ���� ������ˣ���������κο��ܵĳ�ͻ��������ʹ����ȫ�޶�����
*/


#include <iostream>
using namespace std;

void myFunction(char)
{
	cout << "Char myFunction" << endl;
}

template <class T> class Class1
{
public:
	Class1(T i)
	{
		// ����滻Ϊ�ҵĺ�����1�����ҵĺ������ַ���
        // ��������
		myFunction(i);
	}
};

namespace MyNamespace
{
	void myFunction(int)
	{
		cout << "Int MyNamespace::myFunction" << endl;
	}
};

using namespace MyNamespace;

int main22060202()
{
	Class1<int>* c1 = new Class1<int>(100);
	return 0;
}