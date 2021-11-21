// expre_Explicit_Type_Conversion_Operator.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
class Point
{
public:
    // Define default constructor.
    Point() { _x = _y = 0; }
    // Define another constructor.
    Point(int X, int Y) { _x = X; _y = Y; }

    // Define "accessor" functions as
    // reference types.
    unsigned& x() { return _x; }
    unsigned& y() { return _y; }
    void Show() {
        cout << "x = " << _x << ", "
            << "y = " << _y << "\n";
    }
private:
    unsigned _x;
    unsigned _y;
};

int main14()
{
    Point Point1, Point2;

    // ���� Point1 ��ʽת��
    //  of ( 10, 10 ).
    Point1 = Point(10, 10);

    // ͨ��������ʽ�� x() ������ֵ
    //  �� 20 ת��Ϊ�޷������͡�
    Point1.x() = unsigned(20);
    Point1.Show();  //-x 20 //_y 10

    // �� Point2 ָ��ΪĬ�� Point ����
    Point2 = Point();
    Point2.Show();//-x 0 //_y 0

    return 0;
}