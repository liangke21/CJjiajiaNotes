


#include <stdio.h>
struct S {
	short i;
};

int main0201() {
	S  s;   // ��������
	S& SRef = s;   // �������á�
	s.i = 3;

	printf_s("%d\n", s.i);
	printf_s("%d\n", SRef.i);

	SRef.i = 4;
	printf_s("%d\n", s.i);
	printf_s("%d\n", SRef.i);

	return 0;
}