#include <string>

/*

包含类类型成员的类称为复合 类。 创建复合类的类类型成员时，
调用类自己的构造函数之前，先调用构造函数。 当包含的类没有默认构造函数是，
必须使用复合类构造函数中的初始化列表。 在之前的 StorageBox 示例中，
如果将 m_label 成员变量的类型更改为新的 Label 类，则必须调用基类构造函数，
并且将 m_label 变量（位于 StorageBox 构造函数中）初始化：
*/

class Box {
public:
    Box(int width, int length, int height) {
        m_width = width;
        m_length = length;
        m_height = height;
    }

private:
    int m_width;
    int m_length;
    int m_height;
};



class Label {
public:
    Label(const std::string& name, const std::string& address) { m_name = name; m_address = address; }
    std::string m_name;
    std::string m_address;
};

class StorageBox : public Box {//包含类类型成员的类称为复合 类
public:
    StorageBox(int width, int length, int height, Label label)
        : Box(width, length, height), m_label(label) {}
private:
    Label m_label;
};

int main10011001() {
    // 传递命名标签
    Label label1{ "some_name", "some_address" };
    StorageBox sb1(1, 2, 3, label1);//创建复合类的类类型成员时调用类自己的构造函数之前，先调用构造函数。 就是先调用Label
   

    // 传递临时标签
    StorageBox sb2(3, 4, 5, Label{ "another name", "another address" });//创建复合类的类类型成员时调用类自己的构造函数之前，先调用构造函数。 就是先调用Label

    // 传递一个临时标签作为初始化列表
    StorageBox sb3(1, 2, 3, { "myname", "myaddress" });//创建复合类的类类型成员时调用类自己的构造函数之前，先调用构造函数。 就是先调用Label

    return 0;
}