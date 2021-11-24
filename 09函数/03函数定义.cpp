#include <string>
//函数定义 由声明和函数体组成，括在大括号中，其中包含变量声明、语句和表达式。 以下示例显示了完整的函数定义：
/*
int foo(int i, const char* s)
{
    int value{ i };
    MyClass mc;
    if (strcmp(s, "default") != 0)
    {
        value = mc.do_something(i);
    }
    return value;
}
*/

//函数体内声明的变量称为局部变量。 它们会在函数退出时超出范围；因此，函数应永远不返回对局部变量的引用！
/*
MyClass& boom(int i, std::string s)
{
    int value{ i };
    MyClass mc;
    mc.Initialize(i, s);
    return mc;
}
*/
