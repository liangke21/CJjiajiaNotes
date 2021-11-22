#include <iostream>

using namespace std;
//ʡ�ԺźͿɱ����ģ�� 
void print() {
    cout << endl;
}

template <typename T> void print(const T& t) {
    cout << t << endl;
}

template <typename First, typename... Rest> void print(const First& first, const Rest&... rest) {
    cout << first << ", ";
    print(rest...); // ʹ�ð���չ�﷨�ĵݹ����
}

int main01021()
{
    print(); // ���õ�һ�����أ�ֻ���һ�����з�
    print(1); // ���õڶ�������

    // ��Щ���õ��������أ��ɱ����ģ�壬
    // ������Ҫʹ�õݹ顣
    print(10, 20);
    print(100, 200, 300);
    print("first", 2, "third", 3.14159);

    return  0;

    //�ܽ� �ɱ����,������,��֪���û�Ҫ�����ٸ�����
}