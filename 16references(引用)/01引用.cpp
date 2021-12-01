


#include <stdio.h>
struct S {
	short i;
};

int main0201() {
	S  s;   // 声明对象。
	S& SRef = s;   // 声明引用。
	s.i = 3;

	printf_s("%d\n", s.i);
	printf_s("%d\n", SRef.i);

	SRef.i = 4;
	printf_s("%d\n", s.i);
	printf_s("%d\n", SRef.i);

	return 0;
}