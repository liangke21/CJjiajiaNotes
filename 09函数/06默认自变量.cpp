#include <string>
using namespace std;

/*
����ǩ���е����һ���򼸸��������ܻ������Ĭ���Ա���������ζ�ŵ��÷����ܻ��ڵ��ú���ʱʡ���Ա���������Ҫָ��ĳ������ֵ����
*/
/*
int DoSomething(int num,
    string str,
    Allocator& alloc = defaultAllocator)
{
    ...
}

// OK both parameters are at end
int DoSomethingElse(int num,
    string str = string{ "Working" },
    Allocator& alloc = defaultAllocator)
{
    ...
}

// C2548: 'DoMore':ȱ�ٲ��� 2 ��Ĭ�ϲ���
int DoMore(int num = 5, // Not a trailing parameter!
    string str,
    Allocator & = defaultAllocator)
{
    ...
}

*/