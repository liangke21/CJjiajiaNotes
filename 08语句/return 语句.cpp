// return_statement2.cpp
#include <stdio.h>

int max(int a, int b)
{
    return (a > b ? a : b);
}
/*
终止函数的执行并返回对调用函数的控制（或对操作系统的控制，如果您从 main 函数转移控制）。 紧接在调用之后在调用函数中恢复执行。
*/
int main080302()
{
    int nOne = 5;
    int nTwo = 7;

    printf_s("\n%d 更大\n", max(nOne, nTwo));

    return 0;
}