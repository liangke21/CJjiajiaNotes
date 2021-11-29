

/*
指向成员的指针的声明是指针声明的特例。 它们使用以下顺序进行声明：

存储类说明符可选 cv 限定符opt 类型说明符**可选的 名称 ::* cv 限定符 opt 标识符 ，初始值设定项opt;

声明说明符：

可选存储类说明符。

可选 const 和 volatile 说明符。

类型说明符：类型的名称。 这是要指向的成员的类型，而不是类。

声明符：

可选的 Microsoft 专用修饰符。 有关详细信息，请参阅 Microsoft 特定的修饰符。

包含要指向的成员的类的限定名。

:: 运算符。

* 运算符。

可选 const 和 volatile 说明符。

命名指向成员的指针的标识符。

指向成员的可选指针初始值设定项：

= 运算符。

& 运算符。

类的限定名。

:: 运算符。

适当类型的类的非静态成员的名称。

像往常一样，允许在单个声明中使用多个声明符（以及任何关联的初始值设定项）。 指向成员的指针可能不指向类的静态成员、引用类型的成员或 void 。

指向类的成员的指针与普通指针不同：它同时包含成员类型的类型信息和该成员所属类的类型信息。 常规指针只标识内存中的一个对象或只具有其地址。 指向类的某个成员的指针标识类的所有实例中的该成员。 以下示例声明类、Window 和一些指向成员数据的指针。
*/




class Window
{
public:
	Window();                               // 默认构造函数。
	Window(int x1, int y1,                 // 构造函数指定
		int x2, int y2);                       //窗口大小。
	bool SetCaption(const char* szTitle); // 设置窗口标题。
	const char* GetCaption();               // 获取窗口标题。
	char* szWinCaption;                     // 窗口标题。
};

// 声明一个指向数据成员 sz Win Caption 的指针。
char* Window::* pwCaption = &Window::szWinCaption;
int main190101()
{

	return 0;
}