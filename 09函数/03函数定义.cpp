#include <string>
//�������� �������ͺ�������ɣ����ڴ������У����а����������������ͱ��ʽ�� ����ʾ����ʾ�������ĺ������壺
/*
int foo(int i, const char* s)
{
    int value{ i };
    MyClass mc;
    if (strcmp(s, "default") != 0)
    {
        value = mc.do_something(i);
    }
    return value;
}
*/

//�������������ı�����Ϊ�ֲ������� ���ǻ��ں����˳�ʱ������Χ����ˣ�����Ӧ��Զ�����ضԾֲ����������ã�
/*
MyClass& boom(int i, std::string s)
{
    int value{ i };
    MyClass mc;
    mc.Initialize(i, s);
    return mc;
}
*/
