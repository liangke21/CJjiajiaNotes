

/*
可以在一个类的范围内声明另一个类。 这样的类称为“嵌套类”。
嵌套类被视为在封闭类的范围内且可在该范围内使用。
若要从嵌套类的即时封闭范围之外的某个范围引用该类，则必须使用完全限定名。
*/


class BufferedIO
{
public:
    enum IOError { None, Access, General };

    //声明嵌套类缓冲输入。
    class BufferedInput
    {
    public:
        int read();
        int good()
        {
            return _inputerror == None;
        }
    private:
        IOError _inputerror;
    };

    // 声明嵌套类缓冲输出。
    class BufferedOutput
    {
        // 会员名单
    };
};

int main1701()
{

    return 0;
}


class C
{
public:
    typedef class U u_t; // U 类在 C 类范围之外可见
    typedef class V {} v_t; // V 类在 C 类外不可见
};

int main1703()
{
    // 好的，上面使用了前向声明，因此使用了文件范围
    U* pu;

    // 错误，类型名称只存在于 C 类作用域中
  //  u_t* pu2; // C2065

    // 错误，上面定义的类所以类 C 范围
   // V* pv; // C2065

    // 好的，完全限定名称
    C::V* pv2;

    return 0;
}
/*
 备注

嵌套类仅在类范围内声明类型。 它们不会导致创建嵌套类的包含对象。 前面的示例声明两个嵌套类，但未声明这些类类型的任何对象。
*/