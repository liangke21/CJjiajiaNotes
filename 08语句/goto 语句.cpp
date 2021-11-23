

/*


由 identifier 指定的标记语句必须位于当前函数中。 所有 identifier 名称都是内部命名空间的成员，因此不会干扰其他标识符。

语句标签仅对语句有意义 goto ; 否则，将忽略语句标签。 不能重新声明标签。

goto 不允许语句将控制转移到跳过初始化该位置范围内的任何变量的位置。 下面的示例引发 C2362：


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
                goto stop; //这里的跳出 外部循环和内部循环都会跳出
        }
    }

    // 此消息不打印：
    printf_s("Loop exited. i = %d\n", i);

stop:
    printf_s("Jumped to stop. i = %d\n", i);

    return 0;
}


