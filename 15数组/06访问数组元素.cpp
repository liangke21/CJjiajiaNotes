


int main0601() {
	char chArray[10];
	char* pch = chArray;   // 计算指向第一个元素的指针。
	char   ch = chArray[0];   // 计算第一个元素的值。
	ch = chArray[3];   // 计算第四个元素的值。

	return 0;
}


#include <iostream>
using namespace std;
int main0602() {
	double multi[4][4][3];   //声明数组。
	double(*p2multi)[3];
	double(*p1multi);

	cout << multi[3][2][2] << "\n";   // C4700 使用三个下标。
	p2multi = multi[3];               // 使 p2multi 指向
									  // 多的第四个“平面”。
	p1multi = multi[3][2];            // 使 p1multi 指向
									  // 第四平面第三排

	return 0;
}