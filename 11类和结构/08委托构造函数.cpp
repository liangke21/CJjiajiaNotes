



/*
委托构造函数在同 一类中调用不同的构造函数，以执行初始化的一些工作。 
如果有多个构造函数，所有这些构造函数必须执行类似的工作，这很有用。 
可以在一个构造函数中编写主逻辑，然后从其他构造函数调用它。 
在下面的普通示例中，Box (int) 将工作委托给 Box (int，int，int) ：
*/
/*

class Box {
public:
    // 默认构造函数
    Box() {}

    // 初始化具有相等尺寸的 Box（即立方体）
    Box(int i) : Box(i, i, i);  // 委托构造函数
    {}

    // 用自定义尺寸初始化一个 Box
    Box(int width, int length, int height)
        : m_width(width), m_length(length), m_height(height)
    {}
    //... 剩下的课和以前一样
};

*/