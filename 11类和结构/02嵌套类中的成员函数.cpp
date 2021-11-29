

//在嵌套类中声明的成员函数可在文件范围中定义。 前面的示例可能已编写：


class BufferedIO
{
public:
    enum IOError { None, Access, General };
    class BufferedInput
    {
    public:
        int read(); // 声明但不定义成员
        int good(); //  功能看了，不错。
    private:
        IOError _inputerror;
    };

    class BufferedOutput
    {
        // 会员名单。
    };
};
// 定义成员函数read and good in
//  文件范围。
int BufferedIO::BufferedInput::read()
{
    return(1);
}

int BufferedIO::BufferedInput::good()
{
    return _inputerror == None;
}
int main170201()
{
    return 0;
}