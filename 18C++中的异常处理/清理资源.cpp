
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <windows.h>
/*
����ֹ�������ִ���ڼ䣬����ܲ�֪���ڵ�����ֹ�������֮ǰ�ѻ�ȡ����Щ��Դ�� ���ܻ��� __try ��ȡ������Դ֮ǰ�ж����飬�Ա㲻���������Դ��

Ϊ�˰�ȫ�������Ӧ���ȼ����Щ��Դ�Ѵ򿪣�Ȼ���ټ���������ֹ���� ����Ĺ����ǣ�

�������ʼ��Ϊ NULL��

�� __try �����У���ȡ��Դ�� ��ȡ��Դʱ���������Ϊ��ֵ��

�� __finally �����У��ͷ����Ӧ�ľ�����־����Ϊ������ NULL ��ÿ����Դ��
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