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
int main() {
	Derived* pd = new Derived;
	Base* pb = pd;
	cout << typeid(pb).name() << endl;   //prints "class Base *"
	cout << typeid(*pb).name() << endl;   //prints "class Derived"

	cout << typeid(pd).name() << endl;   //prints "class Derived *"
	cout << typeid(*pd).name() << endl;   //prints "class Derived"
	delete pd;
}