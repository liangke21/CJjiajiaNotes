#include <iostream>

using namespace std;
/*
可选 (声明) 是成员在程序中访问的名称。 它必须是整型类型（包括枚举类型）。 
constant-expression 指定成员在 结构中占用的位数。 匿名位域 — 即不带标识符的位域成员，可用于填充。

 备注

宽度为 0 的未命名位字段强制将下一位字段对齐到下一个类型边界，其中 type 是成员的类型。
*/


struct Date {
	unsigned short nWeekDay : 3;    // 0..7   (3 bits)
	unsigned short nMonthDay : 6;    // 0..31  (6 bits)
	unsigned short nMonth : 5;    // 0..12  (5 bits)
	unsigned short nYear : 8;    // 0..100 (8 bits)
};
/*
请注意， nYear 是 8 位长，会溢出声明类型的单词边界 unsigned short 。
因此，它从新 的开头开始 unsigned short 。 并不必使所有位域均适合基础类型的对象；根据声明中请求的位数来分配新的存储单元。


*/

struct Date2 {
	unsigned nWeekDay : 3;    // 0..7   (3 bits)
	unsigned nMonthDay : 6;    // 0..31  (6 bits)
	unsigned : 0;    // Force alignment to next boundary.
	unsigned nMonth : 5;    // 0..12  (5 bits)
	unsigned nYear : 8;    // 0..100 (8 bits)
};

int main2101() {

	cout<< "对齐  : " << alignof(Date2);

	return 0;
}