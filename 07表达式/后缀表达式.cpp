// expre_Formal_and_Actual_Arguments.cpp
void func(long param1, double param2);

int main01031()
{
    long i = 1;
    double j = 2;

    // ʹ��ʵ�� i �� j ���� func��
    func(i, j);

    return 0;
}

// ���β� param1 �� param2 ���� func��
void func(long param1, double param2)
{
}
//�Ա������͵Ĵ���

// expre_Treatment_of_Argument_Types.cpp
int func1(const int i, int j, char* c) {
   // i = 7;   // C3892 i is const.
    j = i;   // j ��ֵ�ڷ���ʱ��ʧ
    *c = 'a' + j;   // �ڵ��ú����и��� c ��ֵ
    return i;
}

double& func2(double& d, const char* c) {
    d = 14.387;   // �ڵ��ú����и��� d ��ֵ��
  //  *c = 'a';   // C3892 c ��һ��ָ�� const �����ָ�롣
    return d;
}
//ʡ�Ժź�Ĭ�ϲ���



#include <iostream>

// ������ӡ�ַ����ĺ���print��
// Ȼ�����ս��ߡ�
void print(const char* string,
    const char* terminator = "\n");

int main03031()
{
    print("hello,");
    print("world!");

    print("good morning", ", ");
    print("sunshine.");

    return 0;
}

using namespace std;
// �����ӡ��   ������ �Ѿ������˵ڶ���Ĭ�ϲ���Ϊ���з�
void print(const char* string, const char* terminator)
{
    if (string != NULL)
        cout << string;

    if (terminator != NULL)
        cout << terminator;
}