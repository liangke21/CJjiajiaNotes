
class Example
{
public:
    void Func();          //  * const this
    void Func() const;    //  const * const this
    void Func() volatile; //  volatile * const this
};

//主表达式的示例包括：

//100// literal
//'c' // literal
//this // 在成员函数中，指向类实例的指针
//::func // 全局函数
//::operator + // 全局运算符函数
//::A::B // 全局限定名称
//(i + 1) // a parenthesized expression


//MyClass // 标识符
//MyClass::f // 一个合格的名字
//operator = // 运算符函数名
//operator char* // 转换运算符函数名称
//~MyClass // 析构函数名称
//A::B   // 一个合格的名字
//A<int> // 模板标识