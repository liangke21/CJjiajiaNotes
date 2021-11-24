#include <string>
using namespace std;

/*
函数签名中的最后一个或几个参数可能会分配有默认自变量，这意味着调用方可能会在调用函数时省略自变量（除非要指定某个其他值）。
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

// C2548: 'DoMore':缺少参数 2 的默认参数
int DoMore(int num = 5, // Not a trailing parameter!
    string str,
    Allocator & = defaultAllocator)
{
    ...
}

*/