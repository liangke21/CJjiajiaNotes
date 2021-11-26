

/*

内联函数最适用于小函数使用，例如访问私有数据成员。 这些单行或双行"访问器"函数的主要用途是返回有关对象的状态信息。 
短函数对函数调用的开销敏感。 较长的函数花费在调用和返回序列上的时间按比例减少，并且从内内线中获益更少。

Point类可以定义如下：

*/


// when_to_use_inline_functions.cpp
class Point
{
public:
    // 将“访问器”功能定义为
    //  参考类型。
    unsigned& x();
    unsigned& y();
private:
    unsigned _x;
    unsigned _y;
};

inline unsigned& Point::x()
{
    return _x;
}
inline unsigned& Point::y()
{
    return _y;
}
int main070201()
{

    return 0;
}