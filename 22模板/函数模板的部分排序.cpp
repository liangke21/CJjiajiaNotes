



#include <iostream>

template <class T> void f(T) {
	printf_s("��̫רҵ�ĺ�������\n");
}

template <class T> void f(T*) {
	printf_s("��רҵ�ĺ�����Ϊ\n");
}

template <class T> void f(const T*) {
	printf_s("��רҵ�� const ���� T*\n");
}

int main22040501() {
	int i = 0;
	const int j = 0;
	int* pi = &i;
	const int* cpi = &j;

	f(i);   // ���ò�̫רҵ�ĺ�����
	f(pi);  // ���ø�רҵ�ĺ�����Ϊ
	f(cpi); // ���ø�רҵ�� const ����
	// ���û��ƫ����Щ���ý���ģ�����ɵġ�

	return 0;
}