#include <string>
#include <iostream>
using namespace std;

//��������ִ�����Ʋ��������磬��֤�������Ķ�����캯����
class class_c {
public:
    int max;
    int min;
    int middle;

    class_c() {}
    class_c(int my_max) {
        max = my_max > 0 ? my_max : 10;
    }
    class_c(int my_max, int my_min) {
        max = my_max > 0 ? my_max : 10;
        min = my_min > 0 && my_min < max ? my_min : 1;
    }
    class_c(int my_max, int my_min, int my_middle) {
        max = my_max > 0 ? my_max : 10;
        min = my_min > 0 && my_min < max ? my_min : 1;
        middle = my_middle < max&& my_middle > min ? my_middle : 5;
    }
};

/*

�����ͨ�����һ��ִ��������֤�ĺ����������ظ��Ĵ��룬
�������һ�����캯�����Խ����ֹ���ί�и��������캯����
�� class_c �Ĵ���������˽��ά���� ��Ҫ���ί�й��캯����
��ʹ�� constructor (. . .) : constructor (. . .) �﷨��
*/

class class_c2 {
public:
    int max;
    int min;
    int middle;

    class_c2(int my_max) {
        max = my_max > 0 ? my_max : 10;
    }
    class_c2(int my_max, int my_min) : class_c2(my_max) {
        min = my_min > 0 && my_min < max ? my_min : 1;
    }
    class_c2(int my_max, int my_min, int my_middle) : class_c2(my_max, my_min) {
        middle = my_middle < max&& my_middle > min ? my_middle : 5;
    }
};
int main100501() {

    class_c2 c1{ 1, 3, 2 };

    //ÿ�����캯���������Լ�Ҫ��������,�����ǰ���캯��,��������,�������캯��Ҳ����,����ί�и��������캯������.

    return 0;

}
/*
��������������һʾ��ʱ����ע�⣬���캯�� class_c(int, int, int) ���ȵ��ù��캯�� class_c(int, int)��
�ù��캯������������ class_c(int)�� ÿ�����캯������ִ���������캯������ִ�еĹ�����
*/

/*
���õĵ�һ�����캯������ʼ�������Ա��ʱ��ʼ�������г�Ա�� ��������ί�и��������캯���Ĺ��캯����ִ�г�Ա��ʼ����������ʾ��
*/

class class_a {
public:
    class_a() {}
    // ��Ա��ʼ�������û��ί��
    class_a(string str) : m_string{ str } {}

    //���ﲻ������Ա��ʼ��
    // ���� C3511����ί�й��캯���ĵ���Ӧ��Ψһ�ĳ�Ա��ʼֵ�趨��
  //  class_a(string str, double dbl) : class_a(str)/*, m_double{ dbl }   ��������ί�и��������캯���Ĺ��캯����ִ�г�Ա��ʼ��*/ {}

 // ����Ա����
    class_a(string str, double dbl) : class_a(str) { m_double = dbl; }
    double m_double{ 1.0 };
    string m_string;
};
/*
��һʾ����ʾ�Ǿ�̬���ݳ�Ա��ʼֵ�趨���ʹ�á� 
��ע�⣬������캯��������ʼ���������ݳ�Ա������д��Ա��ʼֵ�趨�
*/

class class_a2 {
public:
    class_a2() {}
    class_a2(string str) : m_string{ str } {}
    class_a2(string str, double dbl) : class_a2(str) { m_double = dbl; }
    double m_double{ 1.0 };
    string m_string{ m_double < 10.0 ? "alpha" : "beta" };
};

int main100502() {
    class_a2 a{ "hello", 2.0 };  //expect a.m_double == 2.0, a.m_string == "hello"

    cout << a.m_double << " " << a.m_string; //2 hello
    int y = 4;
    //������ί���������캯��ȥִ�г�ʼ����Ա
    return 0;
}
/*

���캯��ί���﷨������ֹ���ⴴ�����캯���ݹ� - Constructor1 ������ Constructor2������� Constructor1�����ڳ��ֶ�ջ���֮ǰ������� ��Ӧ������ѭ����

*/
//�Ƿ���
//class class_f {
//public:
//    int max;
//    int min;
//
//    // ��Ҫ������
//    class_f() : class_f(6, 3) { }
//    class_f(int my_max, int my_min) : class_f() { }
//};