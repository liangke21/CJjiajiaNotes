/*
与普通嵌套命名空间不同，内联命名空间的成员会被视为父命名空间的成员。
这一特性使针对重载函数的依赖于自变量的查找可以对父命名空间和嵌套内联命名空间中具有重载的函数起作用。
它还可让你在内联命名空间中声明的模板的父命名空间中声明专用化。 
下面的示例演示在默认情况下，外部代码如何绑定到内联命名空间：
*/



#include <string>

namespace Test
{
    namespace old_ns
    {
        std::string Func() { return std::string("你好从老"); }
    }

    inline namespace new_ns
    {
        std::string Func() { return std::string("你好来自新"); }
    }
}


#include <string>
#include <iostream>

int main()
{
    using namespace Test;
    using namespace std;

    string s = Func();
    std::cout << s << std::endl; // "Hello from new"
    return 0;
}