


// ��ʽ��/ɾ���汾
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
// Ǳ�ڵ�й©�������캯�������쳣ʱ��
    // �����������������
};

// ����ptr�汾
#include <memory>

using namespace std;

class SPResourceClass {
private:
    shared_ptr<int> m_p;
    shared_ptr<float> m_q;
public:
    SPResourceClass() : m_p(new int), m_q(new float) { }
// ��ʽ����� dtor ����Щ��Ա��˵�ǿ��Եģ�
    // ������Σ������ptr ����������й©��
};

// һ����ǿ��Ĺ���ptr����

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