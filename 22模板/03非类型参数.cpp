#include "02类型参数.cpp"
/*其他语言（如 c # 和 Java）中的泛型类型不同，c + + 模板支持 非类型参数（也称为值参数）。 例如，你可以提供常量整数值来指定数组的长度，如此示例类似于标准库中的 std：： array 类：*/

template<typename T, size_t L>
class MyArray
{
   
public:
    T arr[L];
    MyArray() {  }
};

int main22010301() {

    MyArray<MyClass*, 10> arr;
 
    return 0;
}