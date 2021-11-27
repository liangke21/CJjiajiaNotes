//Ĭ�Ϲ��캯�� ͨ��û�в����������ǿ��Ծ���Ĭ��ֵ�Ĳ�����

class Box {
public:
    Box() { /*ִ���κα����Ĭ�ϳ�ʼ������*/ }

    // All params have default values
    Box(int w = 1, int l = 1, int h = 1) : m_width(w), m_height(h), m_length(l) {}
private:
    int m_width;
    int m_height;
    int m_length;
};
//Ĭ�Ϲ��캯���������Ա���� ֮һ�� ���δ�����������κι��캯�������������ṩ��ʽĬ�� inline ���캯����

#include <iostream>
using namespace std;

class Box2 {
public:
    int Volume() { return m_width * m_height * m_length; }
private:
    int m_width{ 0 };
    int m_height{ 0 };
    int m_length{ 0 };
};

int main10010201() {
    Box2 box1; // ���ñ��������ɵĹ��캯��
    cout << "box1.Volume: " << box1.Volume() << endl; // ��� 0

    //����ͨ��������������Ϊ��ɾ�� ����ֹ������������ʽ Ĭ�Ϲ��캯����
    // Ĭ�Ϲ��캯��
   // Box2() = delete;

    return 0;
}

/*
����κ����Ա����Ĭ�Ϲ��죬����������ɵ�Ĭ�Ϲ��캯��������Ϊ��ɾ����
���磬�����͵����г�Ա���������ͳ�Ա������пɷ��ʵ�Ĭ�Ϲ��캯��������������
�������͵��������ݳ�Ա�Լ� const ��Ա�������Ĭ�ϳ�Ա��ʼֵ�����

���ñ��������ɵ�Ĭ�Ϲ��캯��������ʹ������ʱ�����������棺
*/

class myclass {};
int main10010202() {
    myclass mc();     // warning C4930:δ����ԭ�ͺ������Ƿ���㶨���������

    return 0;
}

/*
���ǡ���ֵĽ����������ʾ���� ����ʾ�����ʽ�ȿ��Խ���Ϊ������������
Ҳ���Խ���Ϊ��Ĭ�Ϲ��캯���ĵ��ã����� C++ ��������ƫ����������
��˱��ʽ�ᱻ��Ϊ���������� �й���ϸ��Ϣ������Ĵ���� Vexing Parse��

����������κη�Ĭ�Ϲ��캯���������������ṩĬ�Ϲ��캯����
*/
class Box3 {
public:
    Box3(int width, int length, int height)
        : m_width(width), m_length(length), m_height(height) {}
private:
    int m_width;
    int m_length;
    int m_height;

};

int main100203() {

    Box3 box1(1, 2, 3);
    Box3 box2{ 2, 3, 4 }; //���ֳ�ʼ����ʽ��Ч
   // Box3 box3; // C2512:û�к��ʵ�Ĭ�Ϲ��캯������

   /* �����û��Ĭ�Ϲ��캯�������޷�ͨ������ʹ�÷������﷨���������Ķ������顣
        ���磬��ǰ���ᵽ�Ĵ�����У���������޷�������������*/

 //   Box boxes[3]; // C2512: û�к��ʵ�Ĭ�Ϲ��캯������

    //���ǣ�����ʹ��һ���ʼֵ�趨���б�����ʼ�� Box ��������飺
    Box boxes[3]{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    return 0;
}