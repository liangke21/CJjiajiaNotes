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
int main040201() {
    Shape shape_instance;
    Shape& ref_shape = shape_instance;
    try {
        Circle& ref_circle = dynamic_cast<Circle&>(ref_shape);  //这里向下转型为啥会异常
    }
    catch (bad_cast b) {
        cout << "Caught: " << b.what();
    }
    //引发异常的原因是要强制转换 (形状对象) 从指定的强制转换类型派生 (圆形) 。 若要避免此异常，请将下列声明添加到

    return 0;
}