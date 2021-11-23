#include <iostream>
using namespace std;



// 读取输入，直到输入非数字字符。
int main080501()
{
    char MyArray[5] = { '2','2','a','c' };
    int i = 0;
    while (1)
    {
        int total = 0;

        char ch = MyArray[i++];

        if (ch >= '0' && ch <= '9')
        {
           goto Label1;

           //  int i = ch - '0';   //这里声明就会隐藏外部相同名称的变量
        Label1:
            total += i;   // C4700: 转移 i 的过去初始化。  //while 在块范围内显式声明相同了相同的i,外部的i被隐藏了
            cout << "total1 : " << total << endl;
        } // 如果不存在 goto 错误，我将在这里被销毁
        else
            // Break 语句将控制转移到循环外，
            //  破坏总和通道。
            cout << "total : " << total << endl;
            break;
    }

    return 0;
}