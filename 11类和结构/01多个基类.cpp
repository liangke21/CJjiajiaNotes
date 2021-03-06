/*
一个类可以从多个基类派生。 在多重继承模型中 (其中的类派生自多个基类) ，
则使用 " 基本列表 " 语法元素指定基类。 例如，可以指定派生自 CollectionOfBook 和 Collection 的 Book 的类声明：
*/
class Collection {
};
class Book {};
class CollectionOfBook : public Book, public Collection {
    //一个类可以继承多个基类
};
/*

指定基类的顺序并不重要，只不过在某些情况下，将调用构造函数和析构函数。 在这些情况下，指定基类的顺序将影响：

构造函数进行初始化的顺序。 如果你的代码依赖要在 Book 部分之前初始化的 CollectionOfBook 的 Collection 部分，则规范的顺序很重要。 初始化按在 基础列表 中指定类的顺序进行。

调用析构函数以进行清理的顺序。 同样，如果在销毁另一部分时必须呈现类的特定“部分”，则顺序非常重要。 析构函数的调用顺序与在 基础列表 中指定的类的顺序相反。

 备注

基类的规范顺序会影响类的内存布局。 不要基于内存中基成员的顺序做出任何编程决策。

指定 基础列表 时，不能多次指定相同的类名。 但是，可以将类多次作为派生类的间接基。
*/