

/*

在二进制接口边界使用足够的可移植类型和约定。
"可移植类型" 是 C 内置类型或仅包含 C 内置类型的结构。
类类型只能在调用方和被调用方同意布局、调用约定等时使用。
仅当两者都用相同的编译器和编译器设置进行编译时，才可能出现这种情况。

*/

//如何为了 C 可移植性平展类
//如果调用方可以使用另一种编译器 / 语言编译，则使用特定的调用约定 "平展" 到 extern "C" API：


// class widget {
//   widget();
//   ~widget();
//   double method( int, gadget& );
// };
//extern "C" {        // 使用显式“this”的函数
//	struct widget;   // 不透明类型（仅限前向声明）
//	widget* STDCALL widget_create();      // 构造函数创建新的“this”
//	void STDCALL widget_destroy(widget*); // 析构函数消耗“this”
//	double STDCALL widget_method(widget*, int, gadget*); // 方法使用“这个”
//}