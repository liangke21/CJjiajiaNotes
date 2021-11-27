/*
friend ������һ����������������ĳ�Ա�������Է������˽�к��ܱ�����Ա�� ��Ԫ����������Ϊ���Ա�������ǻ�����������Ȩ�޵���ͨ�ⲿ������ ��Ԫ������ķ�Χ�ڣ����Ҳ���ʹ�ó�Աѡ������� (�����õ� �� ��- >) ��������������һ����ĳ�Ա�� friend �������������Ȩ�޵��������� friend �����ɷ������������е��κ�λ�á� �����ܷ��ʿ��ƹؼ��ֵ�Ӱ�졣
*/

//����ʾ����ʾ Point �����Ԫ���� ChangePrivate�� friend ������Ȩ������Ϊ�������յĶ����˽�����ݳ�Ա Point ��
#include <iostream>

using namespace std;
class Point
{
    friend void ChangePrivate(Point&); //����һ����Ԫ����
public:
    Point(void) : m_i(0) {}
    void PrintPrivate(void) { cout << m_i << endl; }

private:
    int m_i;
};

void ChangePrivate(Point& i) { i.m_i++; } //���庯��

int main05020201()
{
    Point sPoint;
    sPoint.PrintPrivate();
    ChangePrivate(sPoint); //���ú���
    sPoint.PrintPrivate();
    // Output: 0
    1;

    return 0;
}