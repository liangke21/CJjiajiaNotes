/*
备注

从 C++11 开始，语言支持两种类型的分配： 复制分配 和 移动分配。 在本文中，“赋值”意味着复制赋值，除非有其他显式声明。 有关移动赋值的信息，请参阅移动构造函数和移动赋值运算符(C++) 。

赋值操作和初始化操作都会导致对象被复制。

赋值：将一个对象的值分配给另一个对象时，第一个对象将复制到第二个对象。 因此，



复制
Point a, b;
...
a = b;
导致 b 的值被复制到 a 中。

初始化： 当声明新对象、按值将参数传递给函数或按值从函数返回值时，将发生初始化。

您可以为类类型的对象定义“复制”的语义。 例如，假设有以下代码：



复制
TextFile a, b;
a.Open("FILE1.DAT");
b.Open("FILE2.DAT");
b = a;
前面的代码可能表示“将 FILE1.DAT 的内容复制到 FILE2.DAT”，也可能表示“忽略 FILE2.DAT 并使 b 成为 FILE1.DAT 的另一个句柄”。 您必须将适当的复制语义附加到每个类，如下所示。

将赋值运算符 operator= 与对类类型的引用一起用作返回类型和通过引用传递的参数 const （例如 ClassName& operator=(const ClassName& x); ）。

通过通过复制构造函数。

如果不声明复制构造函数，编译器将为你生成 member - wise 复制构造函数。 如果不声明复制赋值运算符，编译器将为你生成 member - wise 复制赋值运算符。 声明复制构造函数不会取消编译器生成的复制赋值运算符，反之亦然。 如果实现上述其中一项，建议你还实现另一项以使代码的含义变得明确。

复制构造函数采用 class - name类型的参数，其中 & class - name 是定义构造函数的类的名称。 例如：



*/





//class Window
//{
//public:
//	Window();
//	Window(const Window&); // 声明复制构造函数。
//
//};
//
//int main100201()
//{
//
//	Window w;
//
//	Window b = w; //“赋值”意味着复制赋值
//
//	return 0;
//}



