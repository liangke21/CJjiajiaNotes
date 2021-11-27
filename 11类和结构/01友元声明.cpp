
/*
尽管具有全局范围的函数可以在其原型之前声明为友元函数，但是成员函数在它们的完整类声明出现前不能声明为友元函数。 以下代码演示此失败的原因：
*/

class ForwardDeclared;   // Class name is known.
class HasFriends
{
  //  friend int ForwardDeclared::IsAFriend();   // C2039 error expected
};
//前面的示例将类名 ForwardDeclared 输入到范围中，但是完整的声明（具体而言，声明函数 IsAFriend 的部分）是未知的。 因此， friend 类中的声明会 HasFriends 生成错误。


//friend class F;
//friend F;

/*
如果在最内层的命名空间中找不到该名称的现有类，则第一种形式会引入新的类 F。 C + + 11：第二种形式不引入新类;当已经声明类时，可以使用它，并且在将模板类型参数或 typedef 声明为友元时必须使用它。

friend class F在尚未声明引用的类型时使用：
*/

namespace NS
{
    class M
    {
        friend class F;  //引入 F 但没有定义它
    };
}

namespace NSs
{
    class M
    {
       // friend F; // error C2433: 'NS::F': 'friend' not permitted on data declarations
    };
}

//在下面的示例中， friend F 引用在 F NS 范围之外声明的类。
class F {};
namespace NSa
{
    class M
    {
        friend F;  // OK
    };
}

// 使用 friend F 将模板参数声明为 friend：
template <typename T>
class my_class
{
    friend T;
    //...
};
//使用 friend F 将 typedef 声明为 friend：
class Foo {};
typedef Foo Fa;

class G
{
    friend Fa; // OK
    //friend class Fa // Error C2371 --重新定义
};

int main050201() {
    return 0;
}