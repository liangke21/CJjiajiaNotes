






#include <stdio.h>
#include <windows.h> // �쳣����Υ��
#include <excpt.h>

int filter(unsigned int code, struct _EXCEPTION_POINTERS* ep)
{
    puts("in filter.");
    if (code == EXCEPTION_ACCESS_VIOLATION)
    {
        puts("caught AV as expected.");
        return EXCEPTION_EXECUTE_HANDLER;
    }
    else
    {
        puts("didn't catch AV, unexpected.");
        return EXCEPTION_CONTINUE_SEARCH;
    };
}

int main181101()
{
    int* p = 0x00000000;   // ָ�� NULL ��ָ��
    puts("hello");
    __try
    {
        puts("in try");
        __try
        {
            puts("in try");
            *p = 13;    // causes an access violation exception;
        }
        __finally
        {
            puts("in finally. termination: ");
            puts(AbnormalTermination() ? "\tabnormal" : "\tnormal");
        }
    }
    __except (filter(GetExceptionCode(), GetExceptionInformation()))  //û�з����쳣 Ҳִ�� �����쳣 ��3��ִ�з�ʽ
    {
        puts("in except");
    }
    puts("world");

    return 0;

    /*
    
    hello
in try
in try
in filter.
caught AV as expected.
in finally. termination:
        abnormal
in except
world
    */
}
/*
�Ӿ��ĸ��� __try �����__try���ѱ������֡� __except���ʽҲ��Ϊɸѡ��__except�� ��ֵȷ����δ����쳣�� �� __except �Ӿ��ĸ���������쳣������� �������ָ����ִ�����Ĳ����ڼ������쳣ʱҪ��ȡ�Ĳ����� ִ�й���������ʾ��

ִ���ܱ����ڡ�

������ܱ�����ִ�й�����δ�����쳣�������ִ�� __except �Ӿ�֮�����䡣

�����ִ���ѱ����Ľ��ڼ�����κ����̵��ѱ����ڵ����з����쳣�� __except �������ʽ�� �����ֿ��ܵ�ֵ��

EXCEPTION_CONTINUE_EXECUTION (-1) �쳣�������� �ӳ����쳣�ĵ����ִ�С�

EXCEPTION_CONTINUE_SEARCH (0) �޷�ʶ���쳣�� ��������������ջ���Ҵ���������������ڵ� try-except ��䣬Ȼ���Ǿ�����һ��������ȼ��Ĵ������

EXCEPTION_EXECUTE_HANDLER (1) ʶ���쳣�� ͨ��ִ�и�����佫����ת�Ƶ��쳣�������Ȼ���� __except ������ִ�� __except ��

__except���ʽ��Ϊ C ���ʽ���㡣 �������ڵ���ֵ���������ʽ������򶺺�������� �����Ҫ�������Ĵ������ʽ�ɵ��÷��������г�������ֵ֮һ�����̡�

ÿ��Ӧ�ó��򶼿����и��Ե��쳣�������

��ת�� �����Ч������ת��һ�� ��� __try ��Ч�� ���������ִ�� ���Ĺ�������ֹ���򲻵����쳣 try-except �������
*/