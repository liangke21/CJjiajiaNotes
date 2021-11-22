// expre_typeid_Operator.cpp
// compile with: /GR /EHsc
#include <iostream>
#include <typeinfo>
//typeid 运算符允许运行时确定对象的类型
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
	typeid(int) == typeid(int&); // 评估为真

	return 0;
}


//typeid 还可以在模板中用于确定模板参数的类型：
// expre_typeid_Operator_3.cpp
// compile with: /c
#include <typeinfo>
template < typename T >
T max(T arg1, T arg2) {
	cout << typeid(T).name() << "s compared." << endl;
	return (arg1 > arg2 ? arg1 : arg2);
}