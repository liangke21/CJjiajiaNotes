// return_statement2.cpp
#include <stdio.h>

int max(int a, int b)
{
    return (a > b ? a : b);
}
/*
��ֹ������ִ�в����ضԵ��ú����Ŀ��ƣ���Բ���ϵͳ�Ŀ��ƣ�������� main ����ת�ƿ��ƣ��� �����ڵ���֮���ڵ��ú����лָ�ִ�С�
*/
int main080302()
{
    int nOne = 5;
    int nTwo = 7;

    printf_s("\n%d ����\n", max(nOne, nTwo));

    return 0;
}