#include "contosodata.h"
using namespace ContosoDataServer;

void ContosoDataServer::Foo() // �ڴ˴�ʹ����ȫ�޶�����
{
	// Bar() ����Ҫ�ʸ�
	Bar();
}

int ContosoDataServer::Bar() { return 0; }










namespace V {
	void f();
}

void V::f() { }        // ok
//void V::g() { }        //C2039, g() ������ V �ĳ�Ա   ��Ϊ�����ռ䶨����������

namespace V {
	void g();
}