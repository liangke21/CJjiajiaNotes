// expre_Using_delete.cpp
#include <iostream>
struct UDType
{
};

int main121()
{
	// 分配一个用户定义的对象、UDObject 和一个对象
	// 在免费商店中使用 double 类型
	//  new operator.
	UDType* UDObject = new UDType;
	double* dObject = new double(3.14);
	std::cout << " 没删除之前 : " << &dObject << std::endl;
	std::cout << " 没删除之前 : " << dObject << std::endl;
	std::cout << " 没删除之前 : " << *dObject << std::endl;
	// 删除这两个对象。
	delete UDObject;
	delete dObject;
	std::cout << " 对象删除没有 : " << &dObject << std::endl; //自身指针不会删除
	std::cout << " 对象删除没有 : " << dObject << std::endl;  // 被赋值的变量指针 和值都被删除
	//std::cout << " 对象删除没有 : " << *dObject << std::endl;
	// 分配一组用户定义的对象
	// 使用 new 运营商的免费商店。
	UDType(*UDArr)[7] = new UDType[5][7];
	// 使用数组语法删除对象数组。
	delete[] UDArr;

	return 0;
}