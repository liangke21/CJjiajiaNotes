/*
ͨ���Ͳ�ͨ��ģ���Ա�����������ģ�����Ʊ���
����ģ��ķ�Χ�ڣ����Ʊ�������ģ�塣
��ģ��ר�û��򲿷�ר�û��ķ�Χ�У����Ƶ�������ר�û��򲿷�ר�û���
Ҳ����ͨ���ʵ���ģ���������ģ�������ר�û��򲿷�ר�û���


*/

// template_name_resolution3.cpp
// compile with: /c
template <class T> class A {
	A* a1;   // A ָ���� A<T>
	A<int>* a2;  // A<int> ָ����һ��רҵ A.
	A<T*>* a3;   // A<T*> ָ���ǲ���רҵ�� A<T*>.
};

template <class T> class A<T*> {
	A* a4; // A ָ���� A<T*>.
};

template<> class A<int> {
	A* a5; // A ָ���� A<int>.
};