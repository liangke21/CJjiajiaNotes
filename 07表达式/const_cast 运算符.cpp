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

void CCTest::printNumber() const { //ֻ��
	cout << "\nBefore: " << number;
	const_cast<CCTest*>(this)->number--;  //ָ����������� this Ϊ const CCTest *  //const_cast �������ָ����������͸��� this Ϊ CCTest * ���Ӷ������޸ĸó�Ա number
	cout << "\nAfter: " << number;
}

int main() {
	CCTest X;
	X.setNumber(8);
	X.printNumber();
}

//�ܽ�ı�һ�� const��ֵ  1, ͨ��ָ��ָ�����ĵ�ַ. 2,ͨ����������������ı� .

//onst_cast<type-id>  type-idҪô������Ҫô��ָ��.