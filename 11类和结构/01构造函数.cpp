

/*
若要自定义类成员的初始化方式，或创建类的对象时调用函数，请定义 构造函数。
构造函数具有与类相同的名称，没有返回值。 可以根据需要定义多个重载构造函数，
以各种方式自定义初始化。 通常，构造函数具有公共可访问性，因此类定义或继承层次结构外部的代码可以创建类的对象。
但也可以将构造函数声明为 protected 或 private 。

构造函数可以选择性地使用成员 init 列表。
与在构造函数体中分配值不同，这是初始化类成员更有效的方法。
下面的示例演示具有三 Box 个重载构造函数的类。 最后两个使用成员 init 列表：
*/

class Box {
public:
    // 默认构造函数
    Box() {}

    // 初始化具有相等尺寸的 Box（即立方体）
    explicit Box(int i) : m_width(i), m_length(i), m_height(i) // 成员初始化列表
    {}

    // 用自定义尺寸初始化一个 Box
    Box(int width, int length, int height)
        : m_width(width), m_length(length), m_height(height)
    {}

    int Volume() { return m_width * m_length * m_height; }

private:
// 当默认构造函数被调用时，其值为 0。
    // 如果我们没有在这里进行零初始化，默认构造函数会
    // 使用垃圾值使它们未初始化。
    int m_width{ 0 };
    int m_length{ 0 };
    int m_height{ 0 };
};
//声明类的实例时，编译器根据重载解析规则选择要调用的构造函数：

int main()
{
    Box b; // Calls Box()
   // Box b = 1; //隐式调用//去掉explicit 就不会报错
    // 使用统一初始化（首选）：
    Box b2{ 5 }; // Calls Box(int)
    Box b3{ 5, 8, 12 }; // Calls Box(int, int, int)

    // 使用函数风格的符号：
    Box b4(2, 4, 6); // 调用 Box(int, int, int)
}