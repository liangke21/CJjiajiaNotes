// continue_statement.cpp
#include <stdio.h>
int main()
{
    int i = 0;
    do
    {
        i++;
        printf_s("�ڼ���֮ǰ\n");
        continue;  //�൱�ڷֽ���
        printf("�����󣬲�Ӧ��ӡ\n"); //������ƹ���ִ��

        printf("�����󣬲�Ӧ��ӡ\n"); //������ƹ���ִ��

        printf("�����󣬲�Ӧ��ӡ\n"); //������ƹ���ִ��

    } while (i < 3);

    printf_s("�� do ѭ��֮��\n");
}