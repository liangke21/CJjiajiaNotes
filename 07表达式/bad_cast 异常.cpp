// expre_bad_cast_Exception.cpp
// compile with: /EHsc /GR
#include <typeinfo>
#include <iostream>

class Shape {
public:
    virtual void virtualfunc() const {}
};

class Circle : public Shape {
public:
    virtual void virtualfunc() const {}
};

using namespace std;
int main() {
    Shape shape_instance;
    Shape& ref_shape = shape_instance;
    try {
        Circle& ref_circle = dynamic_cast<Circle&>(ref_shape);  //��������ת��Ϊɶ���쳣
    }
    catch (bad_cast b) {
        cout << "Caught: " << b.what();
    }
    //�����쳣��ԭ����Ҫǿ��ת�� (��״����) ��ָ����ǿ��ת���������� (Բ��) �� ��Ҫ������쳣���뽫����������ӵ�
}