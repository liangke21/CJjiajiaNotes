// expre_typeid_Operator.cpp
// compile with: /GR /EHsc
#include <iostream>
#include <typeinfo>
//typeid �������������ʱȷ�����������
class Base {
public:
	//virtual void vvfunc() {}
};

class Derived : public Base {};

using namespace std;
int main320() {
	Derived* pd = new Derived;
	Base* pb = pd;
	cout << typeid(pb).name() << endl;   //prints "class Base *"
	cout << typeid(*pb).name() << endl;   //prints "class Derived"

	cout << typeid(pd).name() << endl;   //prints "class Derived *"
	cout << typeid(*pd).name() << endl;   //prints "class Derived"


	delete pd;

	return 0;
}



int main322()
{
	typeid(int) == typeid(int&); // ����Ϊ��

	return 0;
}


//typeid ��������ģ��������ȷ��ģ����������ͣ�
// expre_typeid_Operator_3.cpp
// compile with: /c
#include <typeinfo>
template < typename T >
T max(T arg1, T arg2) {
	cout << typeid(T).name() << "s compared." << endl;
	return (arg1 > arg2 ? arg1 : arg2);
}