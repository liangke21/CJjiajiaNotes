/*

类可以包含静态成员数据和成员函数。 当数据成员声明为 时，只会为 类的所有对象 static 维护一个数据副本。

静态数据成员不是给定的类类型的对象的一部分。 因此，静态数据成员的声明不被视为一个定义。 在类范围中声明数据成员，但在文件范围内执行定义。 这些静态类成员具有外部链接。 以下示例对此进行了说明：
*/
class BufferedOutput
{
public:
    // 返回此类的任何对象写入的字节数。
    short BytesWritten()
    {
        return bytecount;
    }

    // 重置计数器。
    static void ResetCount()
    {
        bytecount = 0;
    }

    // 静态成员声明。
    static long bytecount;
};

// 在文件范围内定义字节数。
long BufferedOutput::bytecount;

int main1401()
{
    return 0;
}