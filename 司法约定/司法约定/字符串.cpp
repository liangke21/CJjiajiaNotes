#include <string>
#include <iostream>
using namespace std;
using namespace std::string_literals; // Ϊ std::string �������� s ��׺

int main11()
{
    // �ַ�����
    auto c0 = 'A'; // char
    auto c1 = u8'A'; // char
    auto c2 = L'A'; // wchar_t  ���ַ�
    auto c3 = u'A'; // char16_t
    auto c4 = U'A'; // char32_t

    // ���ַ�����
    auto m0 = 'abcd'; // ������ֵ 0x61626364
   
    cout << hex<< m0<<endl;

    // �ַ�������
    auto s0 = "hello"; // const char*
    auto s1 = u8"hello"; // const char*, ����Ϊ UTF-8
    auto s2 = L"hello"; // const wchar_t* ���ַ�
    auto s3 = u"hello"; // const char16_t*, ����Ϊ UTF-16
    auto s4 = U"hello"; // const char32_t*, ����Ϊ UTF-32
    cout << "�ַ�������"<<endl;
    cout << "hello : "<<s0 <<endl;
    cout << "hello : " << s1 << endl;
    cout << "hello : " << s2 << endl;
    cout << "hello : " << s3 << endl;
    cout << "hello : " << s4 << endl;



    // ����δת��� \ �� &quot; ��ԭʼ�ַ�������
    auto R0 = R"("Hello \ world")"; // const char*
    auto R1 = u8R"("Hello \ world")"; // const char*, ����Ϊ UTF-8
    auto R2 = LR"("Hello \ world")"; // const wchar_t*
    auto R3 = uR"("Hello \ world")"; // const char16_t*, ����Ϊ UTF-16
    auto R4 = UR"("Hello \ world")"; // const char32_t*, ����Ϊ UTF-32




    // ���ַ����������׼ s ��׺����
    auto S0 = "hello"s; // std::string
    auto S1 = u8"hello"s; // std::string
    auto S2 = L"hello"s; // std::wstring
    auto S3 = u"hello"s; // std::u16string
    auto S4 = U"hello"s; // std::u32string

    // ��ԭʼ�ַ����������׼ s ��׺����
    auto S5 = R"("Hello \ world")"s; // std::string from a raw const char*
    auto S6 = u8R"("Hello \ world")"s; // std::string from a raw const char*, encoded as UTF-8
    auto S7 = LR"("Hello \ world")"s; // std::wstring from a raw const wchar_t*
    auto S8 = uR"("Hello \ world")"s; // std::u16string from a raw const char16_t*, encoded as UTF-16
    auto S9 = UR"("Hello \ world")"s; // std::u32string from a raw const char32_t*, encoded as UTF-32
    return 0;
}


//�ַ��ı�
/*
* �ַ��ı� ��һ���ַ��������ɡ� �����õ��������������ַ���ʾ�� ���������͵��ַ��ı���

���͵���ͨ�ַ��ı� char ������ 'a'

char char8_t ���磬C++20 (������Ϊ) �� UTF-8 �ַ��ı�u8'a'

���͵Ŀ��ַ��ı� wchar_t ������ L'a'

���͵� UTF-16 �ַ��ı� char16_t ������ u'a'

���͵� UTF-32 �ַ��ı� char32_t ������ U'a'

�����ַ��ı����ַ��������κ��ַ����������ַ��� () �������� () ���� \ �г��� ' �� ����ʹ��ת������ָ�������ַ��� ����ͨ��ʹ��ͨ���ַ�����ָ���ַ���ֻҪ���͵Ĵ�С���Ա����ַ���
*/

//����
/*
�ַ��ı��ı��뷽ʽ������ǰ׺��ͬ��

����ǰ׺���ַ��ı�����ͨ�ַ��ı��� ���������ַ���ת�����л����ִ���ַ�����ʾ��ͨ���ַ����Ƶ���ͨ�ַ��ı���ֵ���е�ֵ����ִ���ַ���������������ֵ�� ��������ַ���ת�����л�ͨ���ַ����Ƶ���ͨ�ַ��ı��� ���ַ��ı��� ������ִ���ַ����ڱ�ʾ�Ķ��ַ��ı�����ͨ�ַ��ı�������Ϊ int ����ֵ��ʵ�ֶ���ġ� �й�MSVC������������ �ض��� Microsoft �Ĳ��֡�

�� ǰ׺��ͷ���ַ� L �ı��ǿ��ַ��ı��� ���������ַ���ת�����л�ͨ���ַ����ƵĿ��ַ��ı���ֵֵ����ִ�п��ַ���������������ֵ�������ַ��ı���ִ�п��ַ�����û�б�ʾ��ʽ������������£���ֵ��ʵ�ֶ���ġ� ��������ַ���ת�����л�ͨ���ַ����ƵĿ��ַ��ı���ֵ��ʵ�ֶ���ġ� �й�MSVC������������ �ض��� Microsoft �Ĳ��֡�

�� ǰ׺��ͷ���ַ� u8 �ı��� UTF-8 �ַ��ı��� ����ɶ�Ӧ�� C0 �ؼ��ͻ��������� Unicode ��) �ĵ��� UTF-8 ���뵥Ԫ (��ʾ������������ַ���ת�����л�ͨ���ַ����Ƶ� UTF-8 �ַ��ı���ֵ��ֵ������ ISO 10646 ��λֵ�� ���ֵ�����ɵ��� UTF-8 ���뵥Ԫ��ʾ��������ʽ����ȷ�� ��������ַ���ת�����л�ͨ���ַ����Ƶ� UTF-8 �ַ��ı���ʽ����ȷ��

�� ǰ׺��ͷ���ַ� u �ı��� UTF-16 �ַ��ı��� ��� UTF-16 ���뵥Ԫ (��Ӧ�ڻ���������ƽ��) ������������ַ���ת�����л�ͨ���ַ����Ƶ� UTF-16 �ַ��ı���ֵ��ֵ������ ISO 10646 ��λֵ�� ���ֵ�����ɵ��� UTF-16 ���뵥Ԫ��ʾ��������ʽ����ȷ�� ��������ַ���ת�����л�ͨ���ַ����Ƶ� UTF-16 �ַ��ı���ʽ����ȷ��

�� ǰ׺��ͷ���ַ� U �ı��� UTF-32 �ַ��ı��� ���������ַ���ת�����л�ͨ���ַ����Ƶ� UTF-32 �ַ��ı���ֵ��ֵ������ ISO 10646 ��λֵ�� ��������ַ���ת�����л�ͨ���ַ����Ƶ� UTF-32 �ַ��ı���ʽ����ȷ��
*/

//ת������

int main12()
{
    char newline = '\n';
    char tab = '\t';
    char backspace = '\b';
    char backslash = '\\';
    char nullChar = '\0';

    cout << "���з�: " << newline << "ending" << endl;
    cout << "�Ʊ��: " << tab << "ending" << endl;
    cout << "�˸��ַ�: " << backspace << "ending" << endl;
    cout << "��б���ַ�: " << backslash << "ending" << endl;
    cout << "���ַ�: " << nullChar << "ending" << endl;
    return 0;
}
/*�����
���з���
��β
�Ʊ������β
�˸��ַ�����β
��б���ַ���\ending
���ַ�������
*/

int main13() 
{

    //խ���ַ��ı�����ֵ
    char c0 = 'abcd';    // C4305, C4309,�ض�Ϊ��d��
    wchar_t w0 = 'abcd';    // C4305��C4309���ض�Ϊ��\x6364��
    int i0 = 'abcd';    // 0x61626364 

    cout << "c0��ֵ : " << c0 << "  ;w0��ֵ : " << w0 << "  i0 ��ֵ :"<<hex <<i0;

    return 0;
}

int main14()
{
    char c1 = '\100';
    char c2 = '\1000';

    cout << "c1  : " << c1 << "  c2 :  " << c2;
    return 0;
}

int main15()
{
    char c3 = '\009';   // '9'
    char c4 = '\378';   // C4305, C4309, truncates to '9'
    char c5 = '\qrs';   // C4129, C4305, C4309, truncates to 's'

    cout << "c3  : " << c3 << "  c4 :  " << c4 << "  c5 :  " << c5;

    return 0;
}

int main16()
{
    char c6 = '\x0050'; // 'P'
    char c7 = '\x0pqr'; // C4305, C4309, truncates to 'r'

    cout << c6;
    return 0;
}

int main17()
{
    wchar_t w1 = L'\100';   // L'@'
    wchar_t w2 = L'\1000';  // C4066 L'@', 0 ������
    wchar_t w3 = L'\009';   // C4066 L'\0', 9 ������
    wchar_t w4 = L'\089';   // C4066 L'\0', 89����
    wchar_t w5 = L'\qrs';   // C4129, C4066 L'q' ���ѣ�rs ������
    wchar_t w6 = L'\x0050'; // L'P'
    wchar_t w7 = L'\x0pqr'; // C4066 L'\0', ���� pqr

  
    cout << "w1  " << (char)w1 << endl;
    cout << "w2  " << (char)w2 << endl;
    cout << "w3  " << (char)w3 << endl;
    cout << "w4  " << (char)w4 << endl;
    cout << "w5  " << (char)w5 << endl;
    cout << "w6  " << (char)w6 << endl;
    cout << "w7  " << (char)w7 << endl;

    return 0;
}
//ͨ���ַ�����
int main18()
{
    char u1 = 'A';          // 'A'
    //�˽���
    char u2 = '\101';       // octal, 'A'
    //ʮ������
    char u3 = '\x41';       // hexadecimal, 'A'
    //ͨ���ַ�������ǰ׺ \U �����λ�� unicode ��λ��ɣ�������ǰ׺ \u �����λ�� unicode ��λ���
    char u4 = '\u0041';     // \u UCN 'A'
    char u5 = '\U00000041'; // \U UCN 'A'

    cout << "u1 : " << u1 <<endl; // A >>ʮ���Ʊ���>>ASCII>>������
    cout << "u2 : " << u2 << endl;//�˽���>>ʮ����>>A>>ASCII>>������
    cout << "u3 : " << u3 << endl;//ʮ������>>ʮ����>>A>>ASCII>>������
    cout << "u4 : " << u4 << endl;//unicode>>ʮ����>>A>>ASCII>>������
    cout << "u5 : " << u5 << endl;//unicode>>ʮ����>>A>>ASCII>>������

    return 0;

}
//խ�ַ����ı�
int main19()
{
    const char* narrow = "abcd";

    // �����ַ�����yes\no
    const char* escaped = "yes\\no"; 
    // �˽���
    const char* escaped2 = "yes\\no\101";
    //�˽��� ʮ������
    const char* escaped3 = "yes\\no\101\x41";
    //ͨ�� unicode ��
    //�Ͳ�д��
    cout << "narrow : " << narrow<<endl;
    cout << "escaped : " << escaped<<endl;
    cout << "escaped2 : " << escaped2 << endl;
    cout << "escaped3 : " << escaped3 << endl;
    return 0;
}

//UTF-8 ������ַ���
int main20()
{
    const char* str1 = u8"Hello World";
    const char* str2 = u8"\U0001F607 is O:-)";

    cout << "str1 : " << str1<<endl;
    cout << "str2 : " << str2 << endl;

    return 0;
}
//���ַ����ı�
int main21()
{
    const wchar_t* wide = L"zyxw";
    const wchar_t* newline = L"hello\ngoodbye";

    cout << "wide : " << wide << endl;
    cout << "newline : " << newline << endl;
    cout << "newline : " << (char)newline[5] << endl;
    //�ַ�
    const wchar_t wide2 = L'a';
    cout << "wide2 : " << wide2 << endl;
    //�ַ���
    const wchar_t* wide3 = L"a";
    cout << "wide3 : " << wide3[0] << endl;
    return 0;
}
//char16_t �� char32_t (C++11)
int main22()
{
    auto s3 = u"hello"; 
    auto s4 = U"hello";
    auto s5 = u8"hello";

    cout << "s3 : " << s3 << endl;
    cout << "s4 : " << s4 << endl;
    cout << "s5 : " << s5 << endl;

    return 0;
}

//(c + + 11) ��ԭʼ�ַ����ı�
int main23()
{
    // ��ʾ�ַ�����δת��� \ �ַ�
    const char* raw_narrow = R"(An unescaped \n character)";
    const wchar_t* raw_wide = LR"(An unescaped \ character)";
    const char* raw_utf8 = u8R"(An unescaped \ character)";
    const char16_t* raw_utf16 = uR"(An unescaped \ character)";
    const char32_t* raw_utf32 = UR"(An unescaped \ character)";

    cout << "raw_narrow  : " << raw_narrow << endl;
    cout << "raw_wide  : " << raw_wide << endl;
    cout << "raw_utf8  : " << raw_utf8 << endl;
    cout << "raw_utf16  : " << raw_utf16 << endl;
    cout << "raw_utf32  : " << raw_utf32 << endl;

    //�ܽ�  R"()" ������ַ���û��ת����ַ�,����\n ��Щһ�����Ա������ַ�

    // ��ʾ�ַ�����)&quot;
   // const char* bad_parens = R"()")";  // error C2059
 

    //�ָ���xa( ���� )xa  �ָ������ݿ����Զ���
    const char* good_parens = R"xa()")xa";
    cout << "good_parens : " << good_parens;

    return 0;
}

//���Թ���������з���ԭʼ�ַ����ı���������Դ�е�ת���ַ�) (��

int main24()
{
    // represents the string: hello
//goodbye

    //����ת�廻��
    const char* newline21 = R"(hello
goodbye)";

    cout << "newline21  : " << newline21 << endl;


    const wchar_t* newline22 = LR"(hello
goodbye)";

    cout << "newline22  : " << newline22 << endl;

    return 0;
}

#include<string>
//std���� string �ı� (c + + 14)
int main()
{
    //#include <string>
    //ʹ�������ռ� std::string ���֣�
    string str{ "hello"s };
    string str2{ u8"Hello World" };
    wstring str3{ L"hello"s };
    u16string str4{ u"hello"s };
    u32string str5{ U"hello"s };

   
    cout << "str : " << str << endl;
    cout << "str2 : " << str2 << endl;
    wcout << "str3 : " << str3<< endl;
   // cout << "str4 : " << str4 << endl;
   // cout << "str5 : " << str5 << endl;

    u32string str6{ UR"(She said "hello.")"s };

   // cout << "str6 : " << str6 << endl;
}
//�ַ����ı��Ĵ�С
