
/*
��ģ����Ծ��� ��Ԫ�� �����ģ�塢��������ģ�������ģ�������Ԫ�� ��ԪҲ��������ģ�����ģ���ר�û��������ǲ���ר�û���

������ʾ���У���Ԫ����������Ϊ��ģ���еĺ���ģ�塣 �˴���Ϊģ���ÿ��ʵ��������һ����Ԫ�����汾�� ���������Ԫ����������������ͬ��ģ���������˹�������á�
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

/*
��һ��ʾ���漰����ģ��ר�û�����Ԫ�� ���ԭʼ����ģ������Ԫ������ģ��ר�û����Զ�Ϊ��Ԫ��

Ҳ����ֻ��ģ���ר�ð汾����Ϊ��Ԫ�������´����е���Ԫ����ǰ���ע����ʾ�� ���������������뽫��Ԫģ��ר�û��Ķ������ģ����֮�⡣
*/



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
// ������� int-specific �滻��Ԫ����
    // �汾��ֻ�� int �ػ��Ż������ѡ�
    // ���� f �еĴ��뽫ʧ��
    // with C2248: 'Array<T>::size' :
    // �޷���������������˽�г�Ա 'Array<T>'.
    //friend void f<int>(Array<int>& a);

    friend void f<>(Array<T>& a);
};

// f function template, friend of Array<T>
template <class T>
void f(Array<T>& a)
{
    cout << a.size << " generic" << endl;
}

// f �� int ������ػ�
// �������ѣ���Ϊģ�� f �����ѡ�
template<> void f(Array<int>& a)
{
    cout << a.size << " int" << endl;
}

int main()
{
    Array<char> ac(10);
    f(ac);

    Array<int> a(10);
    f(a);
}
//Output:
//10 generic
//10 int