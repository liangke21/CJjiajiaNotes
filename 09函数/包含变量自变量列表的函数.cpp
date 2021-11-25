
#include <stdio.h>
#include <stdarg.h>
#include <iostream>
using namespace std;

//  Show Var 的声明，但不是定义。
void ShowVar(const  char* szTypes, ...);
int main010201() {
    ShowVar("fcsi", 32.4f, 'a', "Test string", 4,5);

    return 0;
}

// Show Var 接受表单的格式字符串
// &quot;ifcs&quot;，其中每个字符指定
// 该位置参数的类型。
//
//  i = int
//  f = float
//  c = char
//  s = string (char *)
//
// 遵循格式规范的是一个变量
// 参数列表。每个参数对应于
// 格式字符串中的格式字符
// sz Types 参数点
void ShowVar(const char* szTypes, ...) {
    va_list vl; //在访问任何变量参数前，必须建立一个列表标记作为类型 va_list 的变量。 在前面的示例中，该标记称为 vl。
    int i;

 // sz Types 是指定的最后一个参数；你必须访问
    // 使用可变参数宏的所有其他人。
    va_start(vl, szTypes);

    // 逐步浏览列表。
    for (i = 0; szTypes[i] != '\0'; ++i) {

        
        cout << "szTypes : " << szTypes[i] <<endl;

        union Printable_t {
        
            int     i;
            float   f;
            char    c;
            char* s;
        } Printable;

        switch (szTypes[i]) {   // 键入期望。
        case 'i':
            Printable.i = va_arg(vl, int);
            printf_s("%i\n", Printable.i);
            break;
 

        case 'f':
            Printable.f = va_arg(vl, double);
            printf_s("%f\n", Printable.f);
            break;

        case 'c':
            Printable.c = va_arg(vl, char);
            printf_s("%c\n", Printable.c);
            break;

        case 's':
            Printable.s = va_arg(vl, char*);
            printf_s("%s\n", Printable.s);
            break;


        default:
            break;
        }
    }
    va_end(vl);
}
