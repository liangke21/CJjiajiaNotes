


class Point
{
public:
	Point()   // 默认构造函数。
	{
	}
	Point(int, int)   // 从两个整数构造
	{
	}
};

// Point 对象的数组可以声明如下：
Point aPoint[3] = {
   Point(3, 3)     // 使用 int, int 构造函数。
};

int main0501()
{

	return 0;
}