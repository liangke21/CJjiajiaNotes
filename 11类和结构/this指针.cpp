
/*

ָ���ǽ��� �� �� ���͵� this ��״̬��Ա�����пɷ��� class struct �� union ָ�롣 ��ָ��Ϊ����ó�Ա�����Ķ��� ��̬��Ա����û�� this ָ�롣

�﷨
C++

����
this
this->member-identifier
��ע
�����ָ�� this ���Ƕ������һ���֡� ��δ��ӳ�� �����ϵ� sizeof ���Ľ���С� Ϊ������÷�״̬��Ա����ʱ���������Ὣ����ĵ�ַ��Ϊ���ز������ݸ��ú����� ���磬���º������ã�

C++

����
myDate.setMonth( 3 );
�ɽ���Ϊ��

C++

����
setMonth( &myDate, 3 );
����ĵ�ַ�ڳ�Ա��������Ϊָ�� this �ṩ�� ����� this ָ��ʹ�ö�����ʽ�ġ� ���� �ĳ�Աʱ��ʹ����ʽ �ǺϷ��� this ����Ҫ�� class �� ���磺

C++

����
void Date::setMonth( int mn )
{
   month = mn;            // ������˵��
   this->month = mn;      // �ǵȼ۵�
   (*this).month = mn;
}
���ʽ *this ͨ�����ڴӳ�Ա�������ص�ǰ����

C++

����
return *this;
this ָ�뻹���ڷ�ֹ�����ã�

C++

����
if (&Object != this) {
// do not execute in cases of self-reference
 ��ע

���� this ָ�벻���޸ģ���˲������ this ָ����и�ֵ�� C++ �����ڰ汾ʵ������ ��ֵ�� this ��

��ʱ��ָ��ֱ��ʹ�� - ���磬���ڲ������������� this struct uri�����е�ǰ����ĵ�ַ�Ǳ���ġ�
*/






#include <iostream>
#include <string.h>

using namespace std;

class Buf
{
public:
    Buf(const char* szBuffer, size_t sizeOfBuffer);
    Buf& operator=(const Buf&);
    void Display() { cout << buffer << endl; }

private:
    char* buffer;
    size_t  sizeOfBuffer;
};

Buf::Buf(const char* szBuffer, size_t sizeOfBuffer)
{
    sizeOfBuffer++; //ռ����ֹ��

    buffer = new char[sizeOfBuffer];
    if (buffer)
    {
        strcpy_s(buffer, sizeOfBuffer, szBuffer);
        sizeOfBuffer = sizeOfBuffer;
    }
}

Buf& Buf::operator=(const Buf& otherbuf)
{
    if (&otherbuf != this)
    {
        if (buffer)
            delete[] buffer;

        sizeOfBuffer = strlen(otherbuf.buffer) + 1;
        buffer = new char[sizeOfBuffer];
        strcpy_s(buffer, sizeOfBuffer, otherbuf.buffer);
    }
    return *this;
}

int main2001()
{
    Buf myBuf("my buffer", 10);
    Buf yourBuf("your buffer", 12);

    // ��ʾ���ҵĻ�������
    myBuf.Display();//my buffer    4���ո�

    // ��ֵ�����
    myBuf = yourBuf;

    // ��ʾ����Ļ�������
    myBuf.Display(); //your buffer 3���ո�
    return 0;
}