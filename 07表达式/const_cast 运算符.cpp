// expre_const_cast_Operator.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
class CCTest {
public:
	void setNumber(int);
	void printNumber() const;
private:
	int number;
};

void CCTest::setNumber(int num) {
	  
	number = num; 

}

void CCTest::printNumber() const { //只读
	cout << "\nBefore: " << number;
	const_cast<CCTest*>(this)->number--;  //指针的数据类型 this 为 const CCTest *  //const_cast 运算符将指针的数据类型更改 this 为 CCTest * ，从而允许修改该成员 number
	cout << "\nAfter: " << number;
}

int main() {
	CCTest X;
	X.setNumber(8);
	X.printNumber();
}

//总结改变一个 const的值  1, 通过指针指向它的地址. 2,通过引用起个别名来改变 .

//onst_cast<type-id>  type-id要么是引用要么是指针.