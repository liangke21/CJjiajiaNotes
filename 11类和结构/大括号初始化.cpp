//����������ҪΪ�ඨ�幹�캯�����ر�����ԱȽϼ򵥵��ࡣ �û�����ʹ��ͳһ��ʼ������ʼ�����ṹ�Ķ����������ʾ����ʾ��


#include <time.h>

//û�н�����
struct TempData
{
    int StationId;
    time_t timeSet;
    double current;
    double maxTemp;
    double minTemp;
};

// ��һ�����캯��
struct TempData2
{
    TempData2(double minimum, double maximum, double cur, int id, time_t t) :
        stationId{ id }, timeSet{ t }, current{ cur }, maxTemp{ maximum }, minTemp{ minimum } {}
    int stationId;
    time_t timeSet;
    double current;
    double maxTemp;
    double minTemp;
};

int main050601()
{
    time_t time_to_set;

    // ��Ա��ʼ����������˳�򣩣�
    TempData td{ 45978, time(&time_to_set), 28.9, 37.0, 16.7 };

    // Ĭ�ϳ�ʼ�� = {0,0,0,0,0}
    TempData td_default{};

    // δ��ʼ�� = ���ʹ�ã��������� C4700 δ��ʼ���ľֲ�����
  //  TempData td_noInit;

    // ��Ա��������ctor����˳��
    TempData2 td2{ 16.7, 37.0, 28.9, 45978, time(&time_to_set) };

    return 0;
}

/*
��ע�⣬�����ṹû�й��캯��ʱ������������������Ա��˳���ṩ�б�Ԫ�ء� �������й��캯�����밴������˳���ṩԪ�ء�
������;�����ʽ����ʽ������Ĭ�Ϲ��캯������������ʹ��Ĭ�ϴ����ų�ʼ�������пմ����ţ��� ���磬��ͨ��ʹ��Ĭ�Ϻͷ�Ĭ�ϴ����ų�ʼ������ʼ�������ࣺ
*/

#include <string>
using namespace std;

class class_a {
public:
    class_a() {}
    class_a(string str) : m_string{ str } {}
    class_a(string str, double dbl) : m_string{ str }, m_double{ dbl } {}
    double m_double;
    string m_string;
};

int main0602()
{
    class_a c1{};
    class_a c1_1;

    class_a c2{ "ww" };  //��Ĭ��ָ���������캯��
    class_a c2_1("xx");  //��Ĭ��ָ���������캯��

    // ����˳���빹�캯����ͬ
    class_a c3{ "yy", 4.4 };  //��Ĭ��ָ���������캯��
    class_a c3_1("zz", 5.5);  //��Ĭ��ָ���������캯��

    return 0;
}

/*
�������з�Ĭ�Ϲ��캯���������Ա�ڴ����ų�ʼֵ�趨���е���ʾ˳���Ƕ�Ӧ�����ڹ��캯���е���ʾ˳��
�����ǳ�Ա������˳������һʾ���е� class_a һ������ �����������û�������Ĺ��캯����
���Ա�ڴ����ų�ʼֵ�趨���е���ʾ˳����������˳��һ��������������£����ɳ�ʼ�����������Ĺ�����Ա��
���޷������κγ�Ա�� ����ʾ����ʾ�����������Ĺ��캯��ʱ�ڴ����ų�ʼ����ʹ�õ�˳��
*/


class class_d {
public:
    float m_float;
    string m_string;
    wchar_t m_char;
};

int main0603()
{
    class_d d1{};
    class_d d1{ 4.5 };
    class_d d2{ 4.5, "string" };
    class_d d3{ 4.5, "string", 'c' };

  //  class_d d4{ "string", 'c' }; // ����������  //û�а�˳���Ӧ��ʼ������
  //  class_d d5{ "string", 'c', 2.0 }; // ���������� ////û�а�˳���Ӧ��ʼ������

    return 0;
}

//���Ĭ�Ϲ��캯������ʽ�����������Ϊ����ɾ���������޷�ʹ��Ĭ�ϴ����ų�ʼ����

class class_f {
public:
    class_f() = delete;
    class_f(string x) : m_string{ x } {}
    string m_string;
};
int main0604()
{
    class_f cf{ "hello" };
  //  class_f cf1{}; //���������� C2280����ͼ������ɾ���ĺ���

    return 0;
}