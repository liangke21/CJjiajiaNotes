// argument_type_differences.cpp
// compile with: /EHsc /W3
// C4521 expected
#include <iostream>

using namespace std;
class Over {
public:
	Over() { cout << "Over default constructor\n"; }
	Over(Over& o) { cout << "Over&\n"; }
	Over(const Over& co) { cout << "const Over&\n"; }
	Over(volatile Over& vo) { cout << "volatile Over&\n"; }
};

int main030201() {
	Over o1;            // ����Ĭ�Ϲ��캯����
	Over o2(o1);      // ���ý���( Over&amp; )��
	const Over o3;      // ����Ĭ�Ϲ��캯����
	Over o4(o3);      // ���� Over( const Over&amp; )��
	volatile Over o5;   // ����Ĭ�Ϲ��캯����
	Over o6(o5);      // ���ý����� volatile Over&amp; ��.

	return 0;
}