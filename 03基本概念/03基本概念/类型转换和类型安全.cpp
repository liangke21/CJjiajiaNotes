#include <climits>
#include <stdlib.h>
#include <limits>
#include <iostream>
//����ת����ǿ�ƣ�
int main121()
{


    int i = INT_MAX + 1; //warning C4307:'+':���ֳ������
    wchar_t wch = 'A'; //OK
    char c = wch; // warning C4244:'initializing':conversion from 'wchar_t'
                  // to 'char', ���ܶ�ʧ����
    unsigned char c2 = 0xfffe; //���� C4305�������ڳ�ʼ�������ض���
                               // 'int' to 'unsigned char'
    int j = 1.9f; // warning C4244:'initializing':conversion from 'float' to
                  // 'int&#39;, ���ܶ�ʧ����
    int k = 7.7; // warning C4244:'initializing':conversion from 'double' to
                 // 'int&#39;, ���ܶ�ʧ����

    exit(0);
}

//�з��ŵ��޷��ŵ�ת��

int main122()
{
    using namespace std;
    //�޷���ת��Ϊ�з���
    unsigned short num = numeric_limits<unsigned short>::max(); // #include <limits>  //���ֵ
    short num2 = num;   
    cout << "unsigned val = " << num << " signed val = " << num2 << endl;
    // Prints: "unsigned val = 65535 signed val = -1"

    // �з���ת��Ϊ�޷���
    num2 = -1;
    num = num2;
    cout << "unsigned val = " << num << " signed val = " << num2 << endl;
    // Prints: "unsigned val = 65535 signed val = -1"

    //�޷�ȷ�����з���ת��
    unsigned int u3 =   0 - 1;   //����û��������int ��һ��long��
    cout << u3 << endl; // prints 4294967295

    //ָ��ת��
   // char* s = "Help" + 3;
    exit(0);
}