

class Point
{
public:
    int _x, _y;

    // ���Ƹ�ֵ���Ҳ��ǲ�����
    Point& operator=(const Point&);
};

// ���帴�Ƹ�ֵ�������
Point& Point::operator=(const Point& otherPoint)
{
    this->_x = otherPoint._x;
    this->_y = otherPoint._y;

    // ��ֵ��������ظ�ֵ����ࡣ
    return this;
}

int main0501()
{
    Point pt1, pt2;
    pt1 = pt2;

    ////////////////////�����Ǹ�������������Ǹ��ƹ��캯��//////////////////////////////////////

    //���Ƹ�ֵ����������븴�ƹ��캯��д������ �ڴ����ж������¶���Ĺ����е��ú��ߣ�
    //���ø��ƹ��캯�������������ظ��Ƹ�ֵ�������
    Point pt3 = pt1;

    // ֮ǰ�ĳ�ʼ���������£�
    Point pt4(pt1); // ���ƹ��캯�����á�

    return 0;
}
