//可以使用 final 关键字 来指定不能在派生类中重写的虚拟函数。 您还可以使用它指定无法继承的类。



/*
final 是上下文相关的，并且仅在函数声明或类名之后使用时具有特殊含义;否则，它不是保留关键字。

当 在 类声明中使用 final 时， base-classes 是声明的可选部分。
*/

//class BaseClass
//{
//    virtual void func() final;
//};
//
//class DerivedClass : public BaseClass
//{
//    virtual void func() ; // 编译器错误：试图
//                         // 覆盖最终功能
//
//    //函数不能被覆盖
//};
//
//
//class BaseClass3 final
//{
//};
//
//class DerivedClass3 : public BaseClass3 // compiler error: BaseClass is
//                                     // marked as non-inheritable
//{
//};

//类 不能被继承

int main() {

	return 0;
}