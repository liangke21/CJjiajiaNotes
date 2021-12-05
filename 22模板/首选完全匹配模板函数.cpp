



#include <iostream>
using namespace std;

void f2(int, int) { cout << "f(int, int)" << endl; }

template <class T1, class T2>
void f2(T1, T2)
{
	cout << "void f(T1, T2)" << endl;
};

int main22060401()
{
	long l = 0;
	int i = 0;
	// 调用模板函数 f(long, int) because f(int, int)
	//将需要从 long 到 int 的转换。
	f2(l, i);
	return 0;
}