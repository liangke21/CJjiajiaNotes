
/*
类模板可以具有 友元。 类或类模板、函数或函数模板可以是模板类的友元。 友元也可以是类模板或函数模板的专用化，但不是部分专用化。

在以下示例中，友元函数将定义为类模板中的函数模板。 此代码为模板的每个实例化生成一个友元函数版本。 如果您的友元函数与类依赖于相同的模板参数，则此构造很有用。
*/


#include <iostream>
using namespace std;

template <class T> class Array {
    T* array;
    int size;

public:
    Array(int sz) : size(sz) {
        array = new T[size];
        memset(array, 0, size * sizeof(T));
    }

    Array(const Array& a) {
        size = a.size;
        array = new T[size];
        memcpy_s(array, a.array, sizeof(T));
    }

    T& operator[](int i) {
        return *(array + i);
    }

    int Length() { return size; }

    void print() {
        for (int i = 0; i < size; i++)
            cout << *(array + i) << " ";

        cout << endl;
    }

    template<class T>
    friend Array<T>* combine(Array<T>& a1, Array<T>& a2);
};

template<class T>
Array<T>* combine(Array<T>& a1, Array<T>& a2) {
    Array<T>* a = new Array<T>(a1.size + a2.size);
    for (int i = 0; i < a1.size; i++)
        (*a)[i] = *(a1.array + i);

    for (int i = 0; i < a2.size; i++)
        (*a)[i + a1.size] = *(a2.array + i);

    return a;
}

int main22030301() {
    Array<char> alpha1(26);
    for (int i = 0; i < alpha1.Length(); i++)
        alpha1[i] = 'A' + i;

    alpha1.print();

    Array<char> alpha2(26);
    for (int i = 0; i < alpha2.Length(); i++)
        alpha2[i] = 'a' + i;

    alpha2.print();
    Array<char>* alpha3 = combine(alpha1, alpha2);
    alpha3->print();
    delete alpha3;

    return 0;
}

