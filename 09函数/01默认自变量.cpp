

// ԭ��������ӡ���ܡ�
int print(char* s);                  // ��ӡһ���ַ�����
int print(double dvalue);            // ��ӡ˫�ݡ�
//int print(double dvalue, int prec);  // ��ӡһ��˫
//  �������ȡ�

//�����Ӧ�ó����У���Ϊ prec �ṩ�����Ĭ��ֵ���Ӷ���������������������

// ԭ��������ӡ���ܡ�
//int print(char* s);                    // ��ӡһ���ַ�����
//int print(double dvalue, int prec = 2);  // ��ӡһ��˫
//  �������ȡ�


// Ĭ�ϲ���.cpp
// ���룺 /EHsc /c



// ��ָ�����ȴ�ӡ˫����ֵ��
// ���ȵ�������ʾ�ж���λ
// ��ʾС�����ľ��ȡ�������
// ���ھ��ȵ����ֱ�ʾ���������������λ��
//С������ߡ�

#include <iostream>
#include <math.h>
using namespace std;

//int print(double dvalue, int prec) {
//    //ʹ�ñ���ҽ�������/�ضϡ�
//    static const double rgPow10[] = {
//       10E-7, 10E-6, 10E-5, 10E-4, 10E-3, 10E-2, 10E-1, 10E0,
//          10E1,  10E2,  10E3,  10E4, 10E5,  10E6
//    };
//    const int iPowZero = 6;
//    // ������ȳ�����Χ��ֻ���ӡ���֡�
//    if (prec >= -6 && prec <= 7)
//        //���ţ��ضϣ�Ȼ���������š�
//        dvalue = floor(dvalue / rgPow10[iPowZero - prec]) *
//        rgPow10[iPowZero - prec];
//    cout << dvalue << endl;
//    return cout.good();
//}

//ʹ��Ĭ�ϲ���ʱ����ע�����¼��㣺

//Ĭ�ϲ�����������ʡ����β������ĺ���������ʹ�� - ���Ǳ��������Ĳ����� ��ˣ����´����ǷǷ���

//int print(double dvalue = 0.0, int prec);


// ��ӡ���ܵ�ԭ�͡�
int print2(double dvalue, int prec = 2);



// ��ӡ���ܵĶ��塣
//int print2(double dvalue, int prec = 2)
//{
//  
//}


int print2(double dvalue)
{

    return 0;

}