

/*


�� identifier ָ���ı��������λ�ڵ�ǰ�����С� ���� identifier ���ƶ����ڲ������ռ�ĳ�Ա����˲������������ʶ����

����ǩ������������� goto ; ���򣬽���������ǩ�� ��������������ǩ��

goto ��������佫����ת�Ƶ�������ʼ����λ�÷�Χ�ڵ��κα�����λ�á� �����ʾ������ C2362��


int goto_fn(bool b)
{
    if (!b)
    {
        goto exit;  // C2362
    }
    else
    { 
    }

    int error_code = 42;

exit:
    return error_code;


}

*/


#include <stdio.h>
int main080401()
{
    int i, j;

    for (i = 0; i < 10; i++)
    {
        printf_s("Outer loop executing. i = %d\n", i);
        for (j = 0; j < 2; j++)
        {
            printf_s(" Inner loop executing. j = %d\n", j);
            if (i == 3)
                goto stop; //��������� �ⲿѭ�����ڲ�ѭ����������
        }
    }

    // ����Ϣ����ӡ��
    printf_s("Loop exited. i = %d\n", i);

stop:
    printf_s("Jumped to stop. i = %d\n", i);

    return 0;
}


