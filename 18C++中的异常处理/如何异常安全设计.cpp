


// 旧式新/删除版本
class NDResourceClass {
private:
    int* m_p;
    float* m_q;
public:
    NDResourceClass() : m_p(0), m_q(0) {
        m_p = new int;
        m_q = new float;
    }

    ~NDResourceClass() {
        delete m_p;
        delete m_q;
    }
// 潜在的泄漏！当构造函数发出异常时，
    // 不会调用析构函数。
};

// 共享ptr版本
#include <memory>

using namespace std;

class SPResourceClass {
private:
    shared_ptr<int> m_p;
    shared_ptr<float> m_q;
public:
    SPResourceClass() : m_p(new int), m_q(new float) { }
// 隐式定义的 dtor 对这些成员来说是可以的，
    // 无论如何，共享的ptr 将清理并避免泄漏。
};

// 一个更强大的共享ptr案例

class Shape {
    // ...
};

class Circle : public Shape {
    // ...
};

class Triangle : public Shape {
    // ...
};

class SPShapeResourceClass {
private:
    shared_ptr<Shape> m_p;
    shared_ptr<Shape> m_q;
public:
    SPShapeResourceClass() : m_p(new Circle), m_q(new Triangle) { }
};