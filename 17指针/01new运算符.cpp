#include <malloc.h>
#include <memory.h>
//���� operator new �ķ�Χ
class Blanks
{
public:
    Blanks() {}
    void* operator new(size_t stAllocateBlock, char chInit);
};
void* Blanks::operator new(size_t stAllocateBlock, char chInit)
{
    void* pvTemp = malloc(stAllocateBlock);
    if (pvTemp != 0)
        memset(pvTemp, chInit, stAllocateBlock);
    return pvTemp;
}
// ���� Blanks ���͵���ɢ����ȫ������� new ����
// �����صġ���ˣ�����Ĵ��������һ������Ϊ
// ��ղ������ʼ��Ϊ 0xa5
int main030101()
{
    Blanks* a5 = new(0xa5) Blanks;
    return a5 != 0;
   
}

//������֧���������еĳ�Ա newdelete ������������ ���磺
class MyClass
{
public:
    void* operator new[](size_t)
    {
        return 0;
    }
        void   operator delete[](void*)
    {
    }
};

int main030201()
{
    MyClass* pMyClass = new MyClass[5];
    delete[] pMyClass;
    return 0;
}