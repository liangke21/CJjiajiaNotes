#include <string>
#include "02类型参数.cpp"
using namespace std;

/*
在某些情况下，不可能或不需要模板为任何类型定义完全相同的代码。 
例如，你可能希望定义要在类型参数是指针、std：： wstring 或从特定基类派生的类型时执行的代码路径。
在这种情况下，您可以为该特定类型定义模板的 专用化 。 
当用户使用该类型对模板进行实例化时，编译器将使用特殊化来生成类，
对于所有其他类型，编译器将选择更常规的模板。 
专用化，其中所有参数都是专用的。 如果仅某些参数是专用的，则称为 部分专用化。
*/




template <typename K, typename V>
class MyMap {/*...*/ };

// 字符串键的部分特化
template<typename V>
class MyMap<string, V> {/*...*/ };

MyMap<int, MyClass> classes; // 使用原始模板
MyMap<string, MyClass> classes2; // 使用偏特化
/*
只要每个专用类型参数都是唯一的，模板就可以拥有任意数量的专用化。 只有类模板可以部分专用化。 模板的所有完整和部分专用化必须在与原始模板相同的命名空间中声明。
*/