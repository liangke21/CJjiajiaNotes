/*
* ָ�� void ԭʼ�ڴ�λ�õ�ָ�롣 ��ʱ��Ҫʹ�� void* ָ�룬������ c + + ����� c ����֮�䴫��ʱ��

�����ͻ���ָ��ǿ��ת��Ϊ void ָ��ʱ���ڴ�λ�õ����ݽ����ֲ��䡣
��������Ϣ�ᶪʧ����˲���ִ�е�����ݼ�������
���磬���Խ��ڴ�λ��ת��Ϊ��Ҳ����ǿ��ת�� MyClass*void* �� MyClass* ��
����������������׳�������ҪС�Ĵ��� void ���� �ִ� c + + void �ڼ�����������¶�������ʹ��ָ�롣



*/

//func.c
void func(void* data, int length)
{
    char* c = (char*)(data);

    // fill in the buffer with data
    for (int i = 0; i < length; ++i)
    {
        *c = 0x41;
        ++c;
    }
}

// main.cpp
#include <iostream>

extern "C"
{
   // void func(void* data, int length);
}

class MyClass
{
public:
    int num;
    std::string name;
    void print() { std::cout << name << ":" << num << std::endl; }
};

int main0401()
{
    MyClass* mc = new MyClass{ 10, "Marian" };
    std::cout << mc << std::endl; 

    void* p = static_cast<void*>(mc);
    std::cout << p << std::endl;

    MyClass* mc2 = static_cast<MyClass*>(p);
    std::cout << mc2 << std::endl;

    std::cout << mc2->name << std::endl; // "Marian"

    // ʹ�� operator new �����������ڴ��
    void* pvoid = operator new(1000);
    char* pchar = static_cast<char*>(pvoid);
    for (char* c = pchar; c < pchar + 1000; ++c)
    {
        *c = 0x00;
    }
    func(pvoid, 1000);
    char ch = static_cast<char*>(pvoid)[0];
    std::cout << ch << std::endl; // 'A'
    operator delete(p);
    return 0;
}