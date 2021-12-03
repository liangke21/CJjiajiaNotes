//将 module 声明置于模块实现文件的开头，以指定该文件的内容属于命名模块。

//export module Module;
//
//export void MyFunc();

//在接口文件中，对要 export 作为公共接口的一部分的名称使用修饰符：


// ModuleA.ixx

export module ModuleA;

namespace Bar22
{
	export int f();
	export double d();
	double internal_f(); // not exported
}