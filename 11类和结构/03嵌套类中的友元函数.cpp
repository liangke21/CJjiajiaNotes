
/*
Ƕ��������������Ԫ��������Ϊ����Ƕ��������Ƿ����ķ�Χ�ڡ�
��ˣ���Ԫ����δ��öԷ����ĳ�Ա���Ա�������ض�����Ȩ�ޡ�
�����Ҫʹ������Ԫ�����е�Ƕ���������������ƣ�
������Ԫ���������ļ���Χ�ڶ���ģ���ʹ���޶����������ƣ�

������ʾ��
*/



#include <string.h>

enum
{
    sizeOfMessage = 255
};

char* rgszMessage[sizeOfMessage];

class BufferedIO2
{
public:
    class BufferedInput
    {
    public:
        friend int GetExtendedErrorStatus();
        static char* message;
        static int  messageSize;
        int iMsgNo;
    };
};

char* BufferedIO2::BufferedInput::message;
int BufferedIO2::BufferedInput::messageSize;

int GetExtendedErrorStatus()
{
    int iMsgNo = 1; //��������ֵ��Ϊ��Ϣ��

    strcpy_s(BufferedIO2::BufferedInput::message,
        BufferedIO2::BufferedInput::messageSize,
        rgszMessage[iMsgNo]);

    return iMsgNo;
}

int main170301()
{
    //ֻҪ�����ļ���Χ����,����ʹ����Ԫ���庯��,

    return 0;
}