// template_friend2.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

template <class T>
class Array;

template <class T>
void f(Array<T>& a);

template <class T> class Array
{
    T* array;
    int size;

public:
    Array(int sz) : size(sz)
    {
        array = new T[size];
        memset(array, 0, size * sizeof(T));
    }
    Array(const Array& a)
    {
        size = a.size;
        array = new T[size];
        memcpy_s(array, a.array, sizeof(T));
    }
    T& operator[](int i)
    {
        return *(array + i);
    }
    int Length()
    {
        return size;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << *(array + i) << " ";
        }
        cout << endl;
    }
// 如果你用 int-specific 替换友元声明
    // 版本，只有 int 特化才会是朋友。
    // 泛型 f 中的代码将失败
    // with C2248: 'Array<T>::size' :
    // cannot access private member declared in class 'Array<T>'.
    //friend void f<int>(Array<int>& a);

    friend void f<>(Array<T>& a);
};

// f function template, friend of Array<T>
template <class T>
void f(Array<T>& a)
{
    cout << a.size << " generic" << endl;
}

// f 对 int 数组的特化
// 将是朋友，因为模板 f 是朋友。
template<> void f(Array<int>& a)
{
    cout << a.size << " int" << endl;
}

int main22030401()
{
    Array<char> ac(10);
    f(ac);

    Array<int> a(10);
    f(a);

    return 0;
}
////Output:
//10 generic
//10 int