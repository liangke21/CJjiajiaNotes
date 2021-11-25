
#include <stdio.h>
#include <stdarg.h>
#include <iostream>
using namespace std;

//  Show Var �������������Ƕ��塣
void ShowVar(const  char* szTypes, ...);
int main() {
    ShowVar("fcsi", 32.4f, 'a', "Test string", 4,5);
}

// Show Var ���ܱ��ĸ�ʽ�ַ���
// &quot;ifcs&quot;������ÿ���ַ�ָ��
// ��λ�ò��������͡�
//
//  i = int
//  f = float
//  c = char
//  s = string (char *)
//
// ��ѭ��ʽ�淶����һ������
// �����б�ÿ��������Ӧ��
// ��ʽ�ַ����еĸ�ʽ�ַ�
// sz Types ������
void ShowVar(const char* szTypes, ...) {
    va_list vl; //�ڷ����κα�������ǰ�����뽨��һ���б�����Ϊ���� va_list �ı����� ��ǰ���ʾ���У��ñ�ǳ�Ϊ vl��
    int i;

 // sz Types ��ָ�������һ����������������
    // ʹ�ÿɱ����������������ˡ�
    va_start(vl, szTypes);

    // ������б�
    for (i = 0; szTypes[i] != '\0'; ++i) {

        
        cout << "szTypes : " << szTypes[i] <<endl;

        union Printable_t {
        
            int     k;
            float   f;
            char    c;
            char* s;
        } Printable;

        switch (szTypes[i]) {   // ����������
        //case 'i':
        //    Printable.i = va_arg(vl, int);
        //    printf_s("%i\n", Printable.i);
        //    break;
        case 'k':
            Printable.k = va_arg(vl, int);
            printf_s("%k\n", Printable.k);
            break;

        case 'f':
            Printable.f = va_arg(vl, double);
            printf_s("%f\n", Printable.f);
            break;

        case 'c':
            Printable.c = va_arg(vl, char);
            printf_s("%c\n", Printable.c);
            break;

        case 's':
            Printable.s = va_arg(vl, char*);
            printf_s("%s\n", Printable.s);
            break;


        default:
            break;
        }
    }
    va_end(vl);
}
