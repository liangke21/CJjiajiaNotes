
/*
��λ��ģ��������֮��Ķ����У����ģ������в�������ģ���Ա����Ļ��࣬���Ҹû�������Ա֮һ��ģ���Ա�����������ͬ����û�����Ա���ƽ�����ģ���Ա�����
*/

#include <iostream>
using namespace std;

struct B {
	int i;
	void print() { cout << "Base" << endl; }
};

template <class T, int i> struct C : public B {
	void f();
};

template <class B, int i>
void C<B, i>::f() {
	B b;   // ���� b��������ģ�������
	b.print();
	i = 1; // ������� i ����Ϊ 1.
}

int main2206030501() {
	C<int, 1> c;
	c.f();
	cout << c.i << endl;

	return 0;
}