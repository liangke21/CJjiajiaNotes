#include "contosodata.h"
using namespace ContosoDataServer;

void ContosoDataServer::Foo() // 在此处使用完全限定名称
{
	// Bar() 不需要资格
	Bar();
}

int ContosoDataServer::Bar() { return 0; }










namespace V {
	void f();
}

void V::f() { }        // ok
//void V::g() { }        //C2039, g() 还不是 V 的成员   因为命名空间定义在了下面

namespace V {
	void g();
}