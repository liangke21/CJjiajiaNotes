#include "file1.h"
#include "file2.h"   // OK
//ֻҪ��������������ͬһ�����ͣ���������������ǿ��Խ��ܵġ�


typedef char CHAR;
typedef CHAR CHAR;      // OK: redeclared as same type

typedef union REGS      // OK: name REGS redeclared
{                       //  ͨ�� typedef ������
   // struct wordregs x;  //  same meaning.
   // struct byteregs h;
} REGS;

// typedef_with_class_types2.cpp
// compile with: /c /W1
//typedef struct {
//	int POINT();
//	unsigned x;
//	unsigned y;
//} POINT;

int main88()
{

	return 0;
}