// continue_statement.cpp
#include <stdio.h>
int main()
{
    int i = 0;
    do
    {
        i++;
        printf_s("在继续之前\n");
        continue;  //相当于分界线
        printf("继续后，不应打印\n"); //这里会绕过不执行

        printf("继续后，不应打印\n"); //这里会绕过不执行

        printf("继续后，不应打印\n"); //这里会绕过不执行

    } while (i < 3);

    printf_s("在 do 循环之后\n");
}