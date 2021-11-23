
#include <typeinfo>
#include <iostream>
using namespace std;
class Mybad_typeid : public exception
{

public:
	Mybad_typeid() {

		cout << "对象为 NULL" << endl;
	};
	Mybad_typeid(const char* _Message = "错误类型") {

		cout << "对象为 NULL" << endl;
	}
	Mybad_typeid(const Mybad_typeid&);
	virtual ~Mybad_typeid();

	Mybad_typeid& operator=(const Mybad_typeid&);
	const char* what() const;
};


class A {
public:
	// 类的对象需要 vtable
	// for RTTI
	virtual ~A();
};

//如果的操作数为 NULL 指针，则 typeid 运算符引发 bad_typeid 异常 typeid 。
int main22222() {

	A* a = NULL;

	try {
		

		cout << typeid(*a).name() << endl;  // 错误条件
		throw Mybad_typeid("");
	}
	catch (Mybad_typeid) {
		cout << "对象为 NULL" << endl;
	}
	return 0;
}