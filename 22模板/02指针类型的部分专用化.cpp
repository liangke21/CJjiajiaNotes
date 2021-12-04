// partial_specialization_of_class_templates2.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

// Original template collection class.
template <class T> class Bag {
    T* elem;
    int size;
    int max_size;

public:
    Bag() : elem(0), size(0), max_size(1) {}
    void add(T t) {
        T* tmp;
        if (size + 1 >= max_size) {
            max_size *= 2;
            tmp = new T[max_size];
            for (int i = 0; i < size; i++)
                tmp[i] = elem[i];
            tmp[size++] = t;
            delete[] elem;
            elem = tmp;
        }
        else
            elem[size++] = t;
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << elem[i] << " ";
        cout << endl;
    }
};

// ָ�����͵�ģ�岿���ػ���
// �ü����ѱ��޸�Ϊ��� NULL
// ���洢ָ������͡�
template <class T> class Bag<T*> {
    T* elem;
    int size;
    int max_size;

public:
    Bag() : elem(0), size(0), max_size(1) {}
    void add(T* t) {
        T* tmp;
        if (t == NULL) {   // Check for NULL
            cout << "Null pointer!" << endl;
            return;
        }

        if (size + 1 >= max_size) {
            max_size *= 2;
            tmp = new T[max_size];
            for (int i = 0; i < size; i++)
                tmp[i] = elem[i];
            tmp[size++] = *t;  // Dereference
            delete[] elem;
            elem = tmp;
        }
        else
            elem[size++] = *t; // Dereference
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << elem[i] << " ";
        cout << endl;
    }
};

int main220502() {
    Bag<int> xi;
    Bag<char> xc;
    Bag<int*> xp; // Uses partial specialization for pointer types.

    xi.add(10);
    xi.add(9);
    xi.add(8);
    xi.print();

    xc.add('a');
    xc.add('b');
    xc.add('c');
    xc.print();

    int i = 3, j = 87, * p = new int[2];
    *p = 8;
    *(p + 1) = 100;
    xp.add(&i);
    xp.add(&j);
    xp.add(p);
    xp.add(p + 1);
    delete[] p;
    p = NULL;
    xp.add(p);
    xp.print();

    return 0;
}
/*
���ģ�弯��������κ����͵� �����Դ��������κ�ָ�����͵Ĳ��� T ר�û� T* �� ���´�����ʾ��һ��������ģ�� Bag �Լ�ָ�����͵Ĳ���ר�û����ڴ�ר�û��У��ü����ڽ�ָ�����͸��Ƶ�����ǰȡ���������ǡ� �ü������洢ָ���ֵ�� ����ԭʼģ�壬ֻ��ָ�뱾���洢�ڼ����У��Ӷ�ʹ��������ɾ�����޸ġ� �ڴ�����ָ��汾�ļ����У�������� add �����м�� null ָ��Ĵ��롣
*/