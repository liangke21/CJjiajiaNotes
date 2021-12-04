



#include <iostream>

template <class T> void f(T) {
	printf_s("不太专业的函数调用\n");
}

template <class T> void f(T*) {
	printf_s("更专业的函数称为\n");
}

template <class T> void f(const T*) {
	printf_s("更专业的 const 函数 T*\n");
}

int main22040501() {
	int i = 0;
	const int j = 0;
	int* pi = &i;
	const int* cpi = &j;

	f(i);   // 调用不太专业的函数。
	f(pi);  // 调用更专业的函数称为
	f(cpi); // 调用更专业的 const 函数
	// 如果没有偏序，这些调用将是模棱两可的。

	return 0;
}