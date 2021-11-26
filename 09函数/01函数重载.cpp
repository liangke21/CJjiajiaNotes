


// function_overloading.cpp
// compile with: /EHsc
#include <iostream>
#include <math.h>
#include <string>

// ԭ��������ӡ���ܡ�
int print(std::string s);             //��ӡһ���ַ�����
int print(double dvalue);            // ��ӡ˫�ݡ�
int print(double dvalue, int prec);  // ��ӡһ��˫
                                     //  �������ȡ�
using namespace std;
int main030101(int argc, char* argv[])
{
    const double d = 893094.2987;
    if (argc < 2)
    {
        // ��Щ�� print �ĵ��õ����� print( char *s )��
        print("���������Ҫһ��������");
        print("�ò���ָ����");
        print("�ڶ������ֵ�λ������");
        print("printed.");
        exit(0);
    }

    // ���ô�ӡ��˫ dvalue ����
    print(d);

    // ���� print( double dvalue, int prec )��
    print(d, atoi(argv[1]));

    return 0;
}

// ��ӡһ���ַ�����
int print(string s)
{
    cout << s << endl;
    return cout.good();
}

// ��Ĭ�Ͼ��ȴ�ӡ˫���ȡ�
int print(double dvalue)
{
    cout << dvalue << endl;
    return cout.good();
}

// ��ָ�����ȴ�ӡ˫����ֵ��
// ���ȵ�������ʾ�ж���λ
// ��ʾС�����ľ��ȡ�������
// ���ھ��ȵ����ֱ�ʾ���������������λ��
//С������ߡ�
int print(double dvalue, int prec)
{
    // ʹ�ñ���ҽ�������/�ضϡ�
    static const double rgPow10[] = {
        10E-7, 10E-6, 10E-5, 10E-4, 10E-3, 10E-2, 10E-1,
        10E0, 10E1,  10E2,  10E3,  10E4, 10E5,  10E6 };
    const int iPowZero = 6;

    // ������ȳ�����Χ��ֻ���ӡ���֡�
    if (prec < -6 || prec > 7)
    {
        return print(dvalue);
    }
    // ���ţ��ضϣ�Ȼ���������š�
    dvalue = floor(dvalue / rgPow10[iPowZero - prec]) *
        rgPow10[iPowZero - prec];
    cout << dvalue << endl;
    return cout.good();
}