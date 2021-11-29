
/*
析构函数是一个成员函数，该函数在对象超出范围时自动调用，或通过对的调用进行显式销毁 delete 。
析构函数具有与类相同的名称，前面有一个波形符 (~) 。
例如，声明 String 类的析构函数：~String()。

如果未定义析构函数，则编译器将提供一个默认析构函数;对于许多类，这就足够了。
仅当类将句柄存储到需要释放的系统资源或拥有它们指向的内存的指针时，才需要定义自定义析构函数。
*/


// spec1_destructors.cpp
#include <string>

class String {
public:
    String(const char* ch);  // 声明构造函数
    ~String();           //  和析构函数。
private:
    char* _text;
    size_t  sizeOfText;
};

// Define the constructor.
String::String(const char* ch) {
    sizeOfText = strlen(ch) + 1;

    // 动态分配正确的内存量。
    _text = new char[sizeOfText];

    // 如果分配成功，则复制初始化字符串。
    if (_text)
        strcpy_s(_text, sizeOfText, ch);
}

// 定义析构函数。
String::~String() {
    //释放之前保留的内存
    //  对于这个字符串。
    delete[] _text;
}

int main1101() {
    String str("The piper in the glen...");

    return 0;
}

/*
在前面的示例中，析构函数 String::~String 使用 delete 运算符来释放为文本存储动态分配的空间。

声明析构函数
析构函数是具有与类相同的名称但前面是波形符 (~) 的函数

多个规则管理析构函数的声明。 析构函数：

不接受自变量。

不要将值返回 (或 void) 。

不能声明为 const 、 volatile 或 static 。 但是，可以调用它们来销毁作为、或声明的对象 const volatile static 。

可以声明为 virtual 。 通过使用虚拟析构函数，无需知道对象的类型即可销毁对象 - 使用虚函数机制调用该对象的正确析构函数。 请注意，析构函数也可以声明为抽象类的纯虚函数。

使用构造函数
当下列事件之一发生时，将调用析构函数：

具有块范围的本地（自动）对象超出范围。

使用运算符分配的对象 new 使用进行了显式释放 delete 。

临时对象的生存期结束。

程序结束，并且存在全局或静态对象。

使用析构函数的完全限定名显式调用了析构函数。

析构函数可以随意调用类成员函数和访问类成员数据。

对析构函数的使用有两个限制：

不能采用其地址。

派生类不继承其基类的析构函数。
*/