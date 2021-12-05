














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
	f(1, 1);   // 同样好搭配；选择非模板函数。
	f('a', 1); // 选择模板函数。
	f<int, int>(2, 2);  // 明确指定的模板参数。
	return 0;
}
/*
f(int, int)
void f(T1, T2)
void f(T1, T2)
*/