
#include <windows.h>
#include <stdio.h>
#include <exception>
#include <stdexcept>

using namespace std;
// 线程异常文档 https://docs.microsoft.com/zh-cn/cpp/cpp/transporting-exceptions-between-threads?view=msvc-170
//定义线程特定的信息。
#define THREADCOUNT 2
exception_ptr aException[THREADCOUNT];
int           aArg[THREADCOUNT];

DWORD WINAPI ThrowExceptions(LPVOID);

// 指定用户定义的自定义异常。
// 作为最佳实践，导出您的异常
// 直接或间接来自 std::exception。
class myException : public std::exception {
};
int main()
{
    HANDLE aThread[THREADCOUNT];
    DWORD ThreadID;

    // 创建辅助线程。
    for (int i = 0; i < THREADCOUNT; i++)
    {
        aArg[i] = i;
        aThread[i] = CreateThread(
            NULL,       // 默认安全属性。
            0,          // 默认堆栈大小。
            (LPTHREAD_START_ROUTINE)ThrowExceptions,
            (LPVOID)&aArg[i], // 线程函数参数。
            0,          // 默认创建标志。
            &ThreadID); // 接收线程标识符。
        if (aThread[i] == NULL)
        {
            printf("CreateThread error: %d\n", GetLastError());
            return -1;
        }
    }

    // 等待所有线程终止。
    WaitForMultipleObjects(THREADCOUNT, aThread, TRUE, INFINITE);
    // 关闭线程句柄。
    for (int i = 0; i < THREADCOUNT; i++) {
        CloseHandle(aThread[i]);
    }

    // 重新抛出并捕获传输的异常。
    for (int i = 0; i < THREADCOUNT; i++) {
        try {
            if (aException[i] == NULL) {
                printf("exception_ptr %d: 无一例外地被运送。\n", i);
            }
            else {
                rethrow_exception(aException[i]);
            }
        }
        catch (const invalid_argument&) {
            printf("exception_ptr %d: 捕获无效参数异常。\n", i);
        }
        catch (const myException&) {
            printf("exception_ptr %d: 捕获了我的异常异常。\n", i);
        }
    }
}
// 每个线程根据其线程抛出异常
// 函数参数，然后结束。
DWORD WINAPI ThrowExceptions(LPVOID lpParam)
{
    int x = *((int*)lpParam);
    if (x == 0) {
        try {
            // 标准 C++ 异常。
            // 此示例显式抛出无效参数异常。
            // 实际上，您的应用程序执行的操作是
            // 隐式抛出异常。
            throw invalid_argument("A C++ exception.");
        }
        catch (const invalid_argument&) {
            aException[x] = current_exception();
        }
    }
    else {
        // 用户定义的异常。
        aException[x] = make_exception_ptr(myException());
    }
    return TRUE;
}