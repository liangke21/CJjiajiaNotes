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
   ��һ������
Null ��ֹ��Ŀ���ַ�����������

�ڶ�������
Ŀ���ַ����������Ĵ�С��

����������
�� null ��β��Դ�ַ�����������
   */

   
    cout << s1 << endl;  //C++

    return 0;
}