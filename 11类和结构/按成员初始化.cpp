class CanInit
{
public:
    long num{ 7 };       // OK in C++11
    int k = 9;          // OK in C++11
   // static int i = 9; // 错误：必须定义和初始化
                      //在类声明之外。

    // 将 num 初始化为 7，将 k 初始化为 9
    CanInit() {}

// 覆盖 num 的原始初始化值：
    CanInit(int val) : num(val) {}
};
int main0401()
{
    //如果在构造函数中对一个成员分配了一个值，则该值将覆盖声明时用于初始化该成员的值。

    return 0;
}


class CanInit2
{
public:
    CanInit2() {} // 当类型为新对象时将 num 初始化为 7
                 //  可以初始化创建。
    long     num{ 7 };
    static int i;
    static int j;
};

// At file scope:

// i 在文件范围内定义并初始化为 15。
// 初始化程序在 Can Init 的范围内进行评估。
int CanInit2::i = 15;

// 初始化器的右侧在范围内
// 被初始化的对象
int CanInit2::j = i;

//类名 CanInit2 的前面必须有 i 以指定所定义的 i 是类 CanInit2 的成员。