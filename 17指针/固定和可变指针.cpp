/*
const 和volatile关键字更改指针处理方式。 
关键字指定在初始化后不能修改指针;之后将保护指针 const 免遭修改。

关键字指定，与后跟名称关联的值可以通过用户应用程序中除这些操作 volatile 外的其他操作进行修改。
因此， 关键字可用于声明共享内存中的对象，
这些对象可通过多个进程或全局数据区域访问，这些进程或全局数据区域用于与 volatile 中断服务例程通信。

将名称声明为 时，编译器每次程序访问它时，会重新加载内存中 volatile 的值。
这将显著减少可能的优化。 但是，当对象的状态可能意外更改时，这是保证可预见的程序性能的唯一方法。

若要将指针指向的对象声明为 或 constvolatile ，请使用 窗体的声明：
*/

//若要将指针指向的对象声明为 或 constvolatile ，请使用 窗体的声明：
namespace a {

	const char* cpch;
	volatile char* vpch;
}

//若要将指针的值（即指针中存储的实际地址）声明为 const 或 volatile ，请使用窗体的声明：
namespace b {

//	char* const pchc;
	char* volatile pchv;

}
//C++ 语言阻止允许修改声明为 的对象或指针的分配 const 。 此类赋值会移除用来声明对象或指针的信息，从而违反原始声明的意图。 请考虑以下声明：
namespace c {

	const char cch = 'A';
	char ch = 'B';
}
//鉴于上述两个对象的声明 (类型为 cchcch和 的类型 chch) ，以下声明/初始化有效：
int main0201() {
	using namespace a;
	using namespace b;
	using namespace c;


	const char* pch1 = &cch;
	const char* const pch4 = &cch;
	const char* pch5 = &ch;
	char* pch6 = &ch;
	char* const pch7 = &ch;
	const char* const pch8 = &ch;

	//以下声明/初始化存在错误。
	//char* pch2 = &cch;   // Error
	//char* const pch3 = &cch;   // Error



	/*
	pch2 的声明声明了一个可以用来修改常量对象的指针，因此不允许使用。 的声明指定指针是常量，而不是对象;禁止声明的原因与禁止声明 pch3pch2 的原因相同。

以下八个赋值显示了通过指针进行的赋值以及对前面的声明的指针值的更改；现在，假设 pch1 到 pch8 的初始化是正确的。
	*/
	//* pch1 = 'A';  // Error: object declared const
	//pch1 = &ch;   // OK: pointer not declared const
	//*pch2 = 'A';  // OK: normal pointer
	//pch2 = &ch;   // OK: normal pointer
	//*pch3 = 'A';  // OK: object not declared const
	//pch3 = &ch;   // Error: pointer declared const
	//*pch4 = 'A';  // Error: object declared const
	//pch4 = &ch;   // Error: pointer declared const

	//指向 对象的 const 指针通常在函数声明中使用，如下所示：

	
		//errno_t strcpy_s(char* strDestination, size_t numberOfElements, const char* strSource);
	//前面的 语句声明一个函数 strcpy_s，其中三个参数中的两个类型为指向 的指针 。 由于参数是按引用传递的，而不是按值传递的，因此函数可以随意修改 和 （如果未 strDestinationstrSourcestrSource 声为 
	////const ）。 的 strSource 声明 const 可确保被调用的函数 strSource 无法更改调用方。


	return 0;
}

/*
const可以将给定类型的指针分配给同一类型的指针。 但是，不能将非 const 的指针分配给 const 指针。 以下代码显示了正确和错误的赋值：
*/


int* const cpObject = 0;
int* pObject;

int main0202() {
	pObject = cpObject;
	//cpObject = pObject;   // C3892
	return 0;
}

/*
* 以下示例显示了当有指针指向某个指向对象的指针时如何将对象声明为 const。
*/


struct X {
	X(int i) : m_i(i) { }
	int m_i;
};

int main0203() {
	// correct
	const X cx(10);
	const X* pcx = &cx;
	const X** ppcx = &pcx;

	// 也正确
	X const cx2(20);
	X const* pcx2 = &cx2;
	X const** ppcx2 = &pcx2;
	return 0;
}