

class Point
{
public:
    int _x, _y;

    // 复制赋值的右侧是参数。
    Point& operator=(const Point&);
};

// 定义复制赋值运算符。
Point& Point::operator=(const Point& otherPoint)
{
    /*this->_x = otherPoint._x;  
    this->_y = otherPoint._y;*/   //和下面等效

   _x = otherPoint._x;
   _y = otherPoint._y;

    // 赋值运算符返回赋值的左侧。
    return *this;
}

int main0501()
{
    Point pt1, pt2;
    pt1 = pt2;

    ////////////////////上面是复制运算符下面是复制构造函数//////////////////////////////////////

    //复制赋值运算符不会与复制构造函数写混淆。 在从现有对象构造新对象的过程中调用后者：
    //调用复制构造函数——不是重载复制赋值运算符！
    Point pt3 = pt1;

    // 之前的初始化类似如下：
    Point pt4(pt1); // 复制构造函数调用。

    return 0;
}
