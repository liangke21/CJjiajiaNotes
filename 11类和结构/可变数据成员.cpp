



//此关键字只能应用于类的非静态和非常量数据成员。 如果声明了数据成员，则从成员函数向 mutable 此数据成员赋值 const 是合法的。
//以下代码将编译而不出错，因为 已声明为 ，因此即使 是 const 成员函数，也可以 m_accessCount mutable 修改 GetFlag GetFlag 。

class X
{
public:
    bool GetFlag() const
    {
        m_accessCount++;
        return m_flag;
    }
private:
    bool m_flag;
    mutable int m_accessCount;
};

int main1601()
{
    return 0;
}