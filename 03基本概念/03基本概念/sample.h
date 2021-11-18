// sample.h
#pragma once  //以确保不会多次将它们插入到单个 .cpp 文件中
#include <vector> // #包含指令
#include <string>

namespace M  // 命名空间声明
{
    inline namespace P
    {
        //...
    }

    enum class colors : short { red, blue, purple, azure };

    const double PI = 3.14;  // const 和 constexpr 定义
    constexpr int MeaningOfLife{ 42 };
    constexpr int get_meaning()
    {
        static_assert(MeaningOfLife == 42, "unexpected!"); //静态断言
        return MeaningOfLife;
    }
    using vstr = std::vector<int>;  // 类型别名
    extern double d; // 外部变量

#define LOG   // 宏定义

#ifdef LOG   // 条件编译指令    判断是否在其他.cpp定义过这段代码, 如果定义过就会跳过这段代码
    void print_to_log();
#endif

    class my_class2   // 常规类定义，
    {                // 但没有非内联函数定义

        friend class other_class;
    public:
        void do_something();   // 在我的 class.cpp 中定义
        inline void put_value(int i) { vals.push_back(i); } // 内联确定

    private:
        vstr vals;
        int i;
    };

    struct RGB
    {
        short r{ 0 };  // 成员初始化
        short g{ 0 };
        short b{ 0 };
    };

    template <typename T>  // 模板定义
    class value_store
    {
    public:
        value_store<T>() = default;
        void write_value(T val)
        {
            //... 模板中的函数定义 OK
        }
    private:
        std::vector<T> vals;
    };

    template <typename T>  // 模板声明
    class value_widget;
}
