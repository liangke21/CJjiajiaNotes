#include <string>
using namespace std;



template< class T > void MySwap(T& a, T& b) {
	T c(a);
	a = b;
	b = c;
}
int main2204010101() {

	int j = 10;
	int k = 18;
	string Hello = "Hello, Windows!";
	MySwap(j, k);          //OK
	//MySwap(j, Hello);      //error

	return 0;
}
//�ڶ��� MySwap ���ô����˱���ʱ������Ϊ�������޷����ɾ��в�ͬ���͵Ĳ����� MySwap ������ ���ʹ���� void ָ�룬�����������ö�����ȷ���룬������������ʱ�޷�����������


// function_templates2.cpp
template<class T> void f(T) {}
int main2204010102(int j) {
	f<char>(j);   // ����רҵ f(char).
	// ���û����ȷָ��, f(int) �ᱻ�Ƶ�������

	return 0;
}