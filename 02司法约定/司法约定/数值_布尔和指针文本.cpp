#include <iostream>

//��ֵ��������ָ���ı�
const int answer = 42;      // �����ı�
double d = sin(108.87);     // ���ݸ� sin �����ĸ����ı�
bool b = true;              // �����ı�
//MyClass* mc = nullptr;      // ָ��������

//�����ı�

//ʮ�����ı�
int i = 157;        //ʮ��������
//int j = 0198;       // ����ʮ������������İ˽�������   �ɽ���0��������������ܴ���0��7
int k = 0365;       // ǰ����ָ���˽������֣�������ʮ����
int m = 36'000'000; // ���ַָ���ʹ��ֵ���߿ɶ���

//�˽����ı�
int n = 0377;   // �˽�������
//int j = 0397;   // ����9 ���ǰ˽�������



//ʮ������
int i1 = 0x3fff;   // ʮ����������
int j = 0X3FFF;   // ������

//��������
unsigned val_1 = 328u;                  // �޷���ֵ
long val_2 = 0x7FFFFFL;                 // ָ����Longֵ // ��Ϊʮ����������
                                        
unsigned long val_3 = 0776745ul;        // �޷���Longֵ
auto val_4 = 108LL;                           // ǩ�˺ܳ��ܳ�  ����������д
auto val_42 = 0x8000000000000000ULL << 16;     // �޷��ų���  ����������д


//���ַָ�

int a = 20'300'400;  //����ʹ�õ������ַ� (Ʋ��) �ָ��ϴ������е�ֵ��ʹ��������Ķ��� �ָ�������Ա�������κ�Ӱ�졣


//����С��
double a1 = 12.3;
double a2 = 12.;
//ָ��������У�ָ�����ֵ�����Ϊ 10 ���ݣ�������ʾ����ʾ
double a3 = 15.5e0;
double a4 = 15.5e1;

//����
void func(double); //����һ��double����С��

void func(long double); //����һ��32λ �ĸ���С��

void func(long ,double);//������������,һ��long ,һ��double

//��������
bool b1 = true;
bool b2 = false;

//ָ���ı�
int* ip;    /* һ�����͵�ָ�� */
double* dp;    /* һ�� double �͵�ָ�� */
float* fp;    /* һ�������͵�ָ�� */
char* ch;    /* һ���ַ��͵�ָ�� */

using namespace std;
int main1()
{
    int  var = 20;   // ʵ�ʱ���������
    int* ip;        // ָ�����������

    ip = &var;       // ��ָ������д洢 var �ĵ�ַ

    cout << "var ������ֵ: ";
    cout << var << endl;

    cout << "var �д洢�ĵ�ַ: ";
    cout << &var << endl;

    // �����ָ������д洢�ĵ�ַ
    cout << "��ַ�洢�� ip ������: ";
    cout << ip << endl;

    // ����ָ���е�ַ��ֵ
    cout << "*ip ������ֵ: ";
    cout << *ip << endl;

    // ����ָ���е�ַ��ֵ
    cout << "*ip �����Լ��ĵ�ַ: ";
    cout << &ip << endl;

    return 0;
}


//�������ı�

auto c2 = 0b0101;
auto c3 = 0b0100;

int main2() {
    cout << c2;
    return 0;
}

//ħ������ 
//ĸ��