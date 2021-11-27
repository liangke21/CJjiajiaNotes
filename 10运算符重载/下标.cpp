



#include <iostream>

using namespace std;
class IntVector {
public:
    IntVector(int cElements);
    ~IntVector() { delete[] _iElements; }
    int& operator[](int nSubscript);
private:
    int* _iElements;
    int _iUpperBound;
};

// ����һ������������
IntVector::IntVector(int cElements) {
    _iElements = new int[cElements];
    _iUpperBound = cElements;
}

// Int Vector ���±��������
int& IntVector::operator[](int nSubscript) {
    static int iErr = -1;

    if (nSubscript >= 0 && nSubscript < _iUpperBound)
        return _iElements[nSubscript];
    else {
        clog << "����߽�Υ�档" << endl;
        return iErr;
    }
}
/*
�� i ����һ�������дﵽ 10 ʱ ��operator[] ��⵽ʹ���˱߽����±꣬������������Ϣ��

��ע�⣬���� �����[] �����������͡� ���ʹ����Ϊ��ֵ���Ӷ�ʹ�������ڸ�ֵ��������κ�һ��ʹ���±���ʽ��

*/
// ���� Int Vector �ࡣ
int main0601() {
    IntVector v(10);
    int i;

    for (i = 0; i <= 10; ++i)
        v[i] = i;

    v[3] = v[9];  //�ص��v[9]�Ǳ��ϵ�ֵ���Ƹ�v[3];

    for (i = 0; i <= 10; ++i)
        cout << "Element: [" << i << "] = " << v[i] << endl;

    return 0;
}

/*
Array bounds violation.
Element: [0] = 0
Element: [1] = 1
Element: [2] = 2
Element: [3] = 9       //ֵ����
Element: [4] = 4
Element: [5] = 5
Element: [6] = 6
Element: [7] = 7
Element: [8] = 8
Element: [9] = 9
Array bounds violation.
Element: [10] = 10

*/