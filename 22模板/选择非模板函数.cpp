














#include <iostream>
using namespace std;

void f(int, int) { cout << "f(int, int)" << endl; }
void f(char, char) { cout << "f(char, char)" << endl; }

template <class T1, class T2>
void f(T1, T2)
{
	cout << "void f(T1, T2)" << endl;
};

int main22060401()
{
	f(1, 1);   // ͬ���ô��䣻ѡ���ģ�庯����
	f('a', 1); // ѡ��ģ�庯����
	f<int, int>(2, 2);  // ��ȷָ����ģ�������
	return 0;
}
/*
f(int, int)
void f(T1, T2)
void f(T1, T2)
*/