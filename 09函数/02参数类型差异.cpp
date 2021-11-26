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
	Over o1;            // 调用默认构造函数。
	Over o2(o1);      // 调用结束( Over&amp; )。
	const Over o3;      // 调用默认构造函数。
	Over o4(o3);      // 调用 Over( const Over&amp; )。
	volatile Over o5;   // 调用默认构造函数。
	Over o6(o5);      // 调用结束（ volatile Over&amp; ）.

	return 0;
}