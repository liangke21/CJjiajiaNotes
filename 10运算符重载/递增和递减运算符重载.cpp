#include <iostream>
using namespace std;

class Point
{
public:
	// ����ǰ׺�ͺ�׺�����������
	Point& operator++();       // ǰ׺�����������
	Point operator++(int);     // ��׺�����������

	// ����ǰ׺�ͺ�׺�ݼ��������
	Point& operator--();       // ǰ׺�ݼ��������
	Point operator--(int);     // ��׺�ݼ��������

	// ����Ĭ�Ϲ��캯����
	Point() { _x = _y = 1; }

	// Define accessor functions.
	int x() { return _x; }
	int y() { return _y; }
private:
	int _x, _y;
};

// ����ǰ׺�����������
Point& Point::operator++()
{
	_x++;
	_y++;
	return *this;
}

// �����׺�����������
Point Point::operator++(int)
{
	Point temp = *this;
	++* this;
	return temp;
}

// ����ǰ׺�ݼ��������
Point& Point::operator--()
{
	_x--;
	_y--;
	return *this;
}

// �����׺�ݼ��������
Point Point::operator--(int)
{
	Point temp = *this;
	--* this;
	return temp;
}
int main0301()
{
	Point p;

p.operator++(1);

		cout << "p.x : " << p.x() << " p.y : " <<p.y() << endl;

		return 0;

}
/*
friend Point& operator++( Point& )      // Prefix increment
friend Point& operator++( Point&, int ) // Postfix increment
friend Point& operator--( Point& )      // Prefix decrement
friend Point& operator--( Point&, int ) // Postfix decrement
*/

//int ��ʾ������ݼ�������ĺ�׺��ʽ�����͵Ĳ���ͨ�������ڴ��ݲ����� ��ͨ������ֵ 0�� ���ǣ��ɰ����·�ʽʹ������

// increment_and_decrement2.cpp
class Int
{
public:
	Int& operator++(int n);

	int git_int() {

		return _i;
	}
private:
	int _i;

	
};

Int& Int::operator++(int n)
{
	if (n != 0)    // �����ݲ����������
		_i += n;
	else
		_i++;       //����û�д��ݲ����������
	return *this;
}
int main0302()
{
	Int i;
	i.operator++(25); // Increment by 25.
	//i.operator++(0); // Increment by 25.

	cout << i.git_int() << endl;
	return 0;
}