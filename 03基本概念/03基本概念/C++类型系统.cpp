#include <string>
#include <iostream>
//
int main1()
{
	int result = 0;              // 声明并初始化一个整数。
	double coefficient = 10.8;   // 声明并初始化一个浮动

	auto name = "Lady G.";       // 声明一个变量并让编译器
								 // 推断类型。
   // auto address;                // 错误。编译器无法推导出类型
								 // 没有初始化值。
  //  age = 12;                    // 错误。变量声明必须
								 // 指定类型或使用 auto!
   // result = "Kenny G.";         // 错误。无法将文本分配给 int。
   // string result = "zero";      // 错误。无法重新定义变量
								 //新型。
   // int maxValue;                //不建议！最大值包含
								 //垃圾位，直到它被初始化。
	return 0;
}
using namespace std;
//基本（内置）类型
int main2()
{
	cout << "type: \t\t" << "************size**************" << endl;
	cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);
	cout << "\t最大值：" << (numeric_limits<bool>::max)();
	cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;
	cout << "char: \t\t" << "所占字节数：" << sizeof(char);
	cout << "\t最大值：" << (numeric_limits<char>::max)();
	cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl;
	cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);
	cout << "\t最大值：" << (numeric_limits<signed char>::max)();
	cout << "\t\t最小值：" << (numeric_limits<signed char>::min)() << endl;
	cout << "unsigned char: \t" << "所占字节数：" << sizeof(unsigned char);
	cout << "\t最大值：" << (numeric_limits<unsigned char>::max)();
	cout << "\t\t最小值：" << (numeric_limits<unsigned char>::min)() << endl;
	cout << "wchar_t: \t" << "所占字节数：" << sizeof(wchar_t);
	cout << "\t最大值：" << (numeric_limits<wchar_t>::max)();
	cout << "\t\t最小值：" << (numeric_limits<wchar_t>::min)() << endl;
	cout << "short: \t\t" << "所占字节数：" << sizeof(short);
	cout << "\t最大值：" << (numeric_limits<short>::max)();
	cout << "\t\t最小值：" << (numeric_limits<short>::min)() << endl;
	cout << "int: \t\t" << "所占字节数：" << sizeof(int);
	cout << "\t最大值：" << (numeric_limits<int>::max)();
	cout << "\t最小值：" << (numeric_limits<int>::min)() << endl;
	cout << "unsigned: \t" << "所占字节数：" << sizeof(unsigned);
	cout << "\t最大值：" << (numeric_limits<unsigned>::max)();
	cout << "\t最小值：" << (numeric_limits<unsigned>::min)() << endl;
	cout << "long: \t\t" << "所占字节数：" << sizeof(long);
	cout << "\t最大值：" << (numeric_limits<long>::max)();
	cout << "\t最小值：" << (numeric_limits<long>::min)() << endl;
	cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long);
	cout << "\t最大值：" << (numeric_limits<unsigned long>::max)();
	cout << "\t最小值：" << (numeric_limits<unsigned long>::min)() << endl;
	cout << "double: \t" << "所占字节数：" << sizeof(double);
	cout << "\t最大值：" << (numeric_limits<double>::max)();
	cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;
	cout << "long double: \t" << "所占字节数：" << sizeof(long double);
	cout << "\t最大值：" << (numeric_limits<long double>::max)();
	cout << "\t最小值：" << (numeric_limits<long double>::min)() << endl;
	cout << "float: \t\t" << "所占字节数：" << sizeof(float);
	cout << "\t最大值：" << (numeric_limits<float>::max)();
	cout << "\t最小值：" << (numeric_limits<float>::min)() << endl;
	cout << "size_t: \t" << "所占字节数：" << sizeof(size_t);
	cout << "\t最大值：" << (numeric_limits<size_t>::max)();
	cout << "\t最小值：" << (numeric_limits<size_t>::min)() << endl;
	cout << "string: \t" << "所占字节数：" << sizeof(string) << endl;
	// << "\t最大值：" << (numeric_limits<string>::max)() << "\t最小值：" << (numeric_limits<string>::min)() << endl;  
	cout << "type: \t\t" << "************size**************" << endl;
	return 0;
}

//const 类型限定符
int main3()
{
	/*
	任何内置或用户定义的类型都可由 const 关键字限定。
	此外，成员函数可能是 const 限定的，甚至是 const 重载的。 初始化类型 const 后，无法修改其值
	*/
	const double PI = 3.1415;
	// PI = .75 //错误。无法修改 const 变量。

	return 0;
}

//字符串类型
//?

//用户定义类型
//?

//指针类型
int main()
{

	int* pNumber;       // 声明一个指向 int 的指针变量。
  //  *pNumber = 10;      // 错误。虽然这可以编译，但它是   这里的意思是要一个地址而不是一个值

						// 一个严重的错误。我们正在取消引用一个
						// 没有初始化的指针变量
						// 分配的内存指向。
   // pNumber = 10;   //报错

	int name = 23;

	//*pNumber = name; ///报错

	//cout << "pNumber : " << pNumber << endl;

	pNumber = &name;

	cout << "pNumber : " << pNumber << endl; //输出指针地址

	cout << "pNumber : " << *pNumber << endl; //输出这个指针的值

	*pNumber = 20;
	cout << "pNumber : " << *pNumber << endl; //改变这个指针地址变量的值
	return 0;
}