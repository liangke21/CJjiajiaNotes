
#include <windows.h>
#include <stdio.h>
#include <exception>
#include <stdexcept>

using namespace std;
// �߳��쳣�ĵ� https://docs.microsoft.com/zh-cn/cpp/cpp/transporting-exceptions-between-threads?view=msvc-170
//�����߳��ض�����Ϣ��
#define THREADCOUNT 2
exception_ptr aException[THREADCOUNT];
int           aArg[THREADCOUNT];

DWORD WINAPI ThrowExceptions(LPVOID);

// ָ���û�������Զ����쳣��
// ��Ϊ���ʵ�������������쳣
// ֱ�ӻ������� std::exception��
class myException : public std::exception {
};
int main()
{
    HANDLE aThread[THREADCOUNT];
    DWORD ThreadID;

    // ���������̡߳�
    for (int i = 0; i < THREADCOUNT; i++)
    {
        aArg[i] = i;
        aThread[i] = CreateThread(
            NULL,       // Ĭ�ϰ�ȫ���ԡ�
            0,          // Ĭ�϶�ջ��С��
            (LPTHREAD_START_ROUTINE)ThrowExceptions,
            (LPVOID)&aArg[i], // �̺߳���������
            0,          // Ĭ�ϴ�����־��
            &ThreadID); // �����̱߳�ʶ����
        if (aThread[i] == NULL)
        {
            printf("CreateThread error: %d\n", GetLastError());
            return -1;
        }
    }

    // �ȴ������߳���ֹ��
    WaitForMultipleObjects(THREADCOUNT, aThread, TRUE, INFINITE);
    // �ر��߳̾����
    for (int i = 0; i < THREADCOUNT; i++) {
        CloseHandle(aThread[i]);
    }

    // �����׳�����������쳣��
    for (int i = 0; i < THREADCOUNT; i++) {
        try {
            if (aException[i] == NULL) {
                printf("exception_ptr %d: ��һ����ر����͡�\n", i);
            }
            else {
                rethrow_exception(aException[i]);
            }
        }
        catch (const invalid_argument&) {
            printf("exception_ptr %d: ������Ч�����쳣��\n", i);
        }
        catch (const myException&) {
            printf("exception_ptr %d: �������ҵ��쳣�쳣��\n", i);
        }
    }
}
// ÿ���̸߳������߳��׳��쳣
// ����������Ȼ�������
DWORD WINAPI ThrowExceptions(LPVOID lpParam)
{
    int x = *((int*)lpParam);
    if (x == 0) {
        try {
            // ��׼ C++ �쳣��
            // ��ʾ����ʽ�׳���Ч�����쳣��
            // ʵ���ϣ�����Ӧ�ó���ִ�еĲ�����
            // ��ʽ�׳��쳣��
            throw invalid_argument("A C++ exception.");
        }
        catch (const invalid_argument&) {
            aException[x] = current_exception();
        }
    }
    else {
        // �û�������쳣��
        aException[x] = make_exception_ptr(myException());
    }
    return TRUE;
}