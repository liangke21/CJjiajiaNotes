#include <iostream>

using namespace std;
/*
��ѡ (����) �ǳ�Ա�ڳ����з��ʵ����ơ� ���������������ͣ�����ö�����ͣ��� 
constant-expression ָ����Ա�� �ṹ��ռ�õ�λ���� ����λ�� �� ��������ʶ����λ���Ա����������䡣

 ��ע

���Ϊ 0 ��δ����λ�ֶ�ǿ�ƽ���һλ�ֶζ��뵽��һ�����ͱ߽磬���� type �ǳ�Ա�����͡�
*/


struct Date {
	unsigned short nWeekDay : 3;    // 0..7   (3 bits)
	unsigned short nMonthDay : 6;    // 0..31  (6 bits)
	unsigned short nMonth : 5;    // 0..12  (5 bits)
	unsigned short nYear : 8;    // 0..100 (8 bits)
};
/*
��ע�⣬ nYear �� 8 λ����������������͵ĵ��ʱ߽� unsigned short ��
��ˣ������� �Ŀ�ͷ��ʼ unsigned short �� ������ʹ����λ����ʺϻ������͵Ķ��󣻸��������������λ���������µĴ洢��Ԫ��


*/

struct Date2 {
	unsigned nWeekDay : 3;    // 0..7   (3 bits)
	unsigned nMonthDay : 6;    // 0..31  (6 bits)
	unsigned : 0;    // Force alignment to next boundary.
	unsigned nMonth : 5;    // 0..12  (5 bits)
	unsigned nYear : 8;    // 0..100 (8 bits)
};

int main2101() {

	cout<< "����  : " << alignof(Date2);

	return 0;
}