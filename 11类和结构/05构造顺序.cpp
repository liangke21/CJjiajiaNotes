
/*
�����๹�캯��ʼ�յ��û��๹�캯������ˣ�������κζ�������֮ǰ����������������ȫ����Ļ��ࡣ 
���๹�캯��������˳����ã����磬��� ������ �������� ���������ȵ��ù��캯����Ȼ����ù��캯����
Ȼ����� ClassA ClassB ClassC ClassC ClassB ClassA ���캯����

�������û��Ĭ�Ϲ��캯����������������๹�캯�����ṩ���๹�캯��������
*/

#include <iostream>

using namespace std;

class Contained1 {
public:
    Contained1() { cout << "���� 1 ����Ա\n"; }//1
};

class Contained2 {
public:
    Contained2() { cout << "���� 2 ctor\n"; }//2
};

class Contained3 {
public:
    Contained3() { cout << "���� 3 ctor\n"; }//4
};

class BaseContainer {
public:
    BaseContainer() { cout << "��������������\n"; }//3
private:
    Contained1 c1;
    Contained2 c2;
};

class DerivedContainer : public BaseContainer {
public:
    DerivedContainer() : BaseContainer() { cout << "�����������캯��\n"; }//5
private:
private:
    Contained3 c3;
};

int main100105() {
    DerivedContainer dc;
    return 0;
}

/*

�����๹�캯��ʼ�յ��û��๹�캯������ˣ�������κζ�������֮ǰ����������������ȫ����Ļ��ࡣ
���๹�캯��������˳����ã����磬��� ������ �������� ���������ȵ��ù��캯����Ȼ����ù��캯����
Ȼ����� ClassA ClassB ClassC ClassC ClassB ClassA ���캯����

�������û��Ĭ�Ϲ��캯����������������๹�캯�����ṩ���๹�캯��������
*/

class Box {
public:
    Box(int width, int length, int height) {
        m_width = width;
        m_length = length;
        m_height = height;
    }

private:
    int m_width;
    int m_length;
    int m_height;
};

class StorageBox : public Box {
public:
    StorageBox(int width, int length, int height, const string label) : Box(width, length, height) {
        m_label = label;
    }
private:
    string m_label;
};

int main10010501() {

    const string aLabel = "aLabel";
    StorageBox sb(1, 2, 3, aLabel);

    return 0;
}