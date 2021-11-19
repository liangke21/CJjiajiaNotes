#include <string>

//声明
int f(int i); // 提前申报

int main1()
{
    const double pi = 3.14; //OK
    int i = f(2); //OK. f 是预先声明的
    std::string str; // OK std::string 在 &lt;string&gt; 标头中声明
  //  C obj; // 错误！ C 尚未宣布。
 //   j = 0; // 错误！未指定类型。
    auto k = 0; // 好的。类型被编译器推断为 int。

    return 0;
}

int f(int i)
{
    return i + 42;
}

namespace N {
    class C {/*...*/ };
}

//定义
// 声明和定义 int 变量 i 和 j。
int i;
int j = 10;

// 声明枚举套装。
enum suits { Spades = 1, Clubs, Hearts, Diamonds };

// 声明类复选框。
//class CheckBox : public Control
//{
//public:
//   // Boolean IsChecked();
//    virtual int     ChangeState() = 0;
//};

class a {
    //声明虚拟函数
    virtual int     ChangeState() = 0;
    virtual int     cha() = 0;
};

// 不是定义的声明
extern int i;
char* strchr(const char* Str, const char Target);