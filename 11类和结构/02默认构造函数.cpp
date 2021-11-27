//默认构造函数 通常没有参数，但它们可以具有默认值的参数。

class Box {
public:
    Box() { /*执行任何必需的默认初始化步骤*/ }

    // All params have default values
    Box(int w = 1, int l = 1, int h = 1) : m_width(w), m_height(h), m_length(l) {}
private:
    int m_width;
    int m_height;
    int m_length;
};
//默认构造函数是特殊成员函数 之一。 如果未在类中声明任何构造函数，编译器将提供隐式默认 inline 构造函数。

#include <iostream>
using namespace std;

class Box2 {
public:
    int Volume() { return m_width * m_height * m_length; }
private:
    int m_width{ 0 };
    int m_height{ 0 };
    int m_length{ 0 };
};

int main10010201() {
    Box2 box1; // 调用编译器生成的构造函数
    cout << "box1.Volume: " << box1.Volume() << endl; // 输出 0

    //可以通过将编译器定义为已删除 来阻止编译器生成隐式 默认构造函数：
    // 默认构造函数
   // Box2() = delete;

    return 0;
}

/*
如果任何类成员不可默认构造，则编译器生成的默认构造函数将定义为已删除。
例如，类类型的所有成员及其类类型成员必须具有可访问的默认构造函数和析构函数。
引用类型的所有数据成员以及 const 成员必须具有默认成员初始值设置项。

调用编译器生成的默认构造函数并尝试使用括号时，将发出警告：
*/

class myclass {};
int main10010202() {
    myclass mc();     // warning C4930:未调用原型函数（是否打算定义变量？）

    return 0;
}

/*
这是“最棘手的解析”问题的示例。 这种示例表达式既可以解释为函数的声明，
也可以解释为对默认构造函数的调用，而且 C++ 分析器更偏向于声明，
因此表达式会被视为函数声明。 有关详细信息，请参阅大多数 Vexing Parse。

如果声明了任何非默认构造函数，编译器不会提供默认构造函数：
*/
class Box3 {
public:
    Box3(int width, int length, int height)
        : m_width(width), m_length(length), m_height(height) {}
private:
    int m_width;
    int m_length;
    int m_height;

};

int main100203() {

    Box3 box1(1, 2, 3);
    Box3 box2{ 2, 3, 4 }; //两种初始化方式等效
   // Box3 box3; // C2512:没有合适的默认构造函数可用

   /* 如果类没有默认构造函数，将无法通过单独使用方括号语法来构造该类的对象数组。
        例如，在前面提到的代码块中，框的数组无法进行如下声明*/

 //   Box boxes[3]; // C2512: 没有合适的默认构造函数可用

    //但是，可以使用一组初始值设定项列表来初始化 Box 对象的数组：
    Box boxes[3]{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    return 0;
}