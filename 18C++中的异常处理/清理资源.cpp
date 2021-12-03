
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <windows.h>
/*
在终止处理程序执行期间，你可能不知道在调用终止处理程序之前已获取了哪些资源。 可能会在 __try 获取所有资源之前中断语句块，以便不会打开所有资源。

为了安全起见，您应该先检查哪些资源已打开，然后再继续处理终止处理。 建议的过程是：

将句柄初始化为 NULL。

在 __try 语句块中，获取资源。 获取资源时，句柄设置为正值。

在 __finally 语句块中，释放其对应的句柄或标志变量为非零或非 NULL 的每个资源。
*/
void fileOps() {
    FILE* fp1 = NULL,
        * fp2 = NULL,
        * fp3 = NULL;
    LPVOID lpvoid = NULL;
    errno_t err;

    __try {
        lpvoid = malloc(BUFSIZ);

        err = fopen_s(&fp1, "ADDRESS.DAT", "w+");
        err = fopen_s(&fp2, "NAMES.DAT", "w+");
        err = fopen_s(&fp3, "CARS.DAT", "w+");
    }
    __finally {
        if (fp1)
            fclose(fp1);
        if (fp2)
            fclose(fp2);
        if (fp3)
            fclose(fp3);
        if (lpvoid)
            free(lpvoid);
    }
}

int main181201() {
    fileOps();

    return 0;
}