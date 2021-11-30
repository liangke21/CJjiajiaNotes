
/*命名空间是一个声明性区域，为其内部的标识符（类型、函数和变量等的名称）提供一个范围。 
命名空间用于将代码组织到逻辑组中，还可用于避免名称冲突，尤其是在基本代码包括多个库时。 
命名空间范围内的所有标识符彼此可见，而没有任何限制。 
命名空间之外的标识符可以通过对每个标识符使用完全限定名称来访问成员，
例如 std::vector<std::string> vec; ，或通过对单个标识符 () 使用 声明 ， 
using std::string 或对命名空间中的所有标识符使用 using 指令 (using namespace std;) 。
头文件中的代码应始终使用完全限定的命名空间名称。

下面的示例演示了一个命名空间声明和命名空间之外的代码可访问其成员的三种方法。*/

namespace ContosoData
{
    class ObjectManager
    {
    public:
        void DoSomething() {}
    };
    void Func(ObjectManager) {}
}
//使用完全限定名：
int main0101() {

    ContosoData::ObjectManager mgr;
    mgr.DoSomething();
    ContosoData::Func(mgr);
    return 0;
}
//使用 using 声明，以将一个标识符引入范围：
int main0102() {

    using ContosoData::ObjectManager;
    ObjectManager mgr;
    mgr.DoSomething();
    return 0;

    return 0;
}
//使用 using 指令，以将命名空间中的所有内容引入范围：
int main0103() {

    using namespace ContosoData;

    ObjectManager mgr;
    mgr.DoSomething();
    Func(mgr);

    return 0;
}