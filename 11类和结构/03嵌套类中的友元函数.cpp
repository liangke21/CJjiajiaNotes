
/*
嵌套类中声明的友元函数被认为是在嵌套类而不是封闭类的范围内。
因此，友元函数未获得对封闭类的成员或成员函数的特定访问权限。
如果需要使用在友元函数中的嵌套类中声明的名称，
并且友元函数是在文件范围内定义的，请使用限定的类型名称，

如下所示：
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
    int iMsgNo = 1; //分配任意值作为消息号

    strcpy_s(BufferedIO2::BufferedInput::message,
        BufferedIO2::BufferedInput::messageSize,
        rgszMessage[iMsgNo]);

    return iMsgNo;
}

int main170301()
{
    //只要是在文件范围以类,可以使用友元定义函数,

    return 0;
}