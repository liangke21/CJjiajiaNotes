#include <iostream>

//数值、布尔和指针文本
const int answer = 42;      // 整数文本
double d = sin(108.87);     // 传递给 sin 函数的浮点文本
bool b = true;              // 布尔文本
//MyClass* mc = nullptr;      // 指针字面量

//整数文本

//十进制文本
int i = 157;        //十进制文字
//int j = 0198;       // 不是十进制数；错误的八进制文字   吧进制0后面跟的整数不能大于0到7
int k = 0365;       // 前导零指定八进制文字，而不是十进制
int m = 36'000'000; // 数字分隔符使大值更具可读性

//八进制文本
int n = 0377;   // 八进制文字
//int j = 0397;   // 错误：9 不是八进制数字



//十六进制
int i1 = 0x3fff;   // 十六进制文字
int j = 0X3FFF;   // 等于我

//其他类型
unsigned val_1 = 328u;                  // 无符号值
long val_2 = 0x7FFFFFL;                 // 指定的Long值 // 作为十六进制文字
                                        
unsigned long val_3 = 0776745ul;        // 无符号Long值
auto val_4 = 108LL;                           // 签了很长很长  不建议这样写
auto val_42 = 0x8000000000000000ULL << 16;     // 无符号长长  不建议这样写


//数字分隔

int a = 20'300'400;  //可以使用单引号字符 (撇号) 分隔较大数字中的值，使其更易于阅读。 分隔符不会对编译产生任何影响。


//浮点小数
double a1 = 12.3;
double a2 = 12.;
//指数（如果有）指定数字的量级为 10 次幂，如以下示例所示
double a3 = 15.5e0;
double a4 = 15.5e1;

//函数
void func(double); //接收一个double浮点小数

void func(long double); //接收一个32位 的浮点小数

void func(long ,double);//接收两个参数,一个long ,一个double

//布尔类型
bool b1 = true;
bool b2 = false;

//指针文本
int* ip;    /* 一个整型的指针 */
double* dp;    /* 一个 double 型的指针 */
float* fp;    /* 一个浮点型的指针 */
char* ch;    /* 一个字符型的指针 */

using namespace std;
int main1()
{
    int  var = 20;   // 实际变量的声明
    int* ip;        // 指针变量的声明

    ip = &var;       // 在指针变量中存储 var 的地址

    cout << "var 变量的值: ";
    cout << var << endl;

    cout << "var 中存储的地址: ";
    cout << &var << endl;

    // 输出在指针变量中存储的地址
    cout << "地址存储在 ip 变量中: ";
    cout << ip << endl;

    // 访问指针中地址的值
    cout << "*ip 变量的值: ";
    cout << *ip << endl;

    // 访问指针中地址的值
    cout << "*ip 变量自己的地址: ";
    cout << &ip << endl;

    return 0;
}


//二进制文本

auto c2 = 0b0101;
auto c3 = 0b0100;

int main2() {
    cout << c2;
    return 0;
}

//魔术常量 
//母鸡