
#include <typeinfo>
#include <iostream>
using namespace std;
class Mybad_typeid : public exception
{

public:
	Mybad_typeid() {

		cout << "����Ϊ NULL" << endl;
	};
	Mybad_typeid(const char* _Message = "��������") {

		cout << "����Ϊ NULL" << endl;
	}
	Mybad_typeid(const Mybad_typeid&);
	virtual ~Mybad_typeid();

	Mybad_typeid& operator=(const Mybad_typeid&);
	const char* what() const;
};


class A {
public:
	// ��Ķ�����Ҫ vtable
	// for RTTI
	virtual ~A();
};

//����Ĳ�����Ϊ NULL ָ�룬�� typeid ��������� bad_typeid �쳣 typeid ��
int main22222() {

	A* a = NULL;

	try {
		

		cout << typeid(*a).name() << endl;  // ��������
		throw Mybad_typeid("");
	}
	catch (Mybad_typeid) {
		cout << "����Ϊ NULL" << endl;
	}
	return 0;
}