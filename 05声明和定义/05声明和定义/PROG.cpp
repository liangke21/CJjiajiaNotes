#include "file1.h"
#include "file2.h"   // OK
//只要两个声明都引用同一个类型，则此类重新声明是可以接受的。


typedef char CHAR;
typedef CHAR CHAR;      // OK: redeclared as same type

typedef union REGS      // OK: name REGS redeclared
{                       //  通过 typedef 名称与
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