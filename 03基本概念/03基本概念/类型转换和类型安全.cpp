#include <climits>
#include <stdlib.h>
#include <limits>
#include <iostream>
//收缩转换（强制）
int main121()
{


    int i = INT_MAX + 1; //warning C4307:'+':积分常数溢出
    wchar_t wch = 'A'; //OK
    char c = wch; // warning C4244:'initializing':conversion from 'wchar_t'
                  // to 'char', 可能丢失数据
    unsigned char c2 = 0xfffe; //警告 C4305：“正在初始化”：截断自
                               // 'int' to 'unsigned char'
    int j = 1.9f; // warning C4244:'initializing':conversion from 'float' to
                  // 'int&#39;, 可能丢失数据
    int k = 7.7; // warning C4244:'initializing':conversion from 'double' to
                 // 'int&#39;, 可能丢失数据

    exit(0);
}

//有符号到无符号的转换

int main122()
{
    using namespace std;
    //无符号转换为有符号
    unsigned short num = numeric_limits<unsigned short>::max(); // #include <limits>  //最大值
    short num2 = num;   
    cout << "unsigned val = " << num << " signed val = " << num2 << endl;
    // Prints: "unsigned val = 65535 signed val = -1"

    // 有符号转换为无符号
    num2 = -1;
    num = num2;
    cout << "unsigned val = " << num << " signed val = " << num2 << endl;
    // Prints: "unsigned val = 65535 signed val = -1"

    //无法确定的有符号转换
    unsigned int u3 =   0 - 1;   //这里没有声明是int 万一是long呢
    cout << u3 << endl; // prints 4294967295

    //指针转换
   // char* s = "Help" + 3;
}