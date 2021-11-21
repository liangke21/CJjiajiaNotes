// expre_Function_Call_Operator.cpp
// compile with: /EHsc

#include <iostream>
#include <string>

// C++ Standard Library name space
using namespace std;

int main151()
{
    enum
    {
        sizeOfBuffer = 20
    };

    char s1[sizeOfBuffer] = "Welcome to ";
    char s2[] = "C++";

    strcat_s(s1, sizeOfBuffer, s2);
   /*
   第一个参数
Null 终止的目标字符串缓冲区。

第二个参数
目标字符串缓冲区的大小。

第三个参数
以 null 结尾的源字符串缓冲区。
   */

   
    cout << s1 << endl;  //C++

    return 0;
}