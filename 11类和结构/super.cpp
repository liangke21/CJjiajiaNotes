

/*

在重载决策阶段将考虑所有可访问的基类方法，可提供最佳匹配项的函数就是调用的函数。

__super 只能出现在成员函数体中。

__super 不能与 using 声明一起使用。 有关详细信息，请参阅 Using 声明 。

引入用于注入代码的 特性 后，你的代码可能包含一个或多个基类，这些基类的名称可能不知道，但包含你希望调用的方法。
*/
struct B1 {
    void mf(int) {}
};

struct B2 {
    void mf(short) {}

    void mf(char) {}
};

struct D : B1, B2 {
    void mf(short) {
        __super::mf(1);   //从顶部基类开始初始化
        __super::mf('s');   
    }
};