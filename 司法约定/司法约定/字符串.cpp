#include <string>
#include <iostream>
using namespace std;
using namespace std::string_literals; // 为 std::string 文字启用 s 后缀

int main11()
{
    // 字符文字
    auto c0 = 'A'; // char
    auto c1 = u8'A'; // char
    auto c2 = L'A'; // wchar_t  宽字符
    auto c3 = u'A'; // char16_t
    auto c4 = U'A'; // char32_t

    // 多字符文字
    auto m0 = 'abcd'; // 整数，值 0x61626364
   
    cout << hex<< m0<<endl;

    // 字符串文字
    auto s0 = "hello"; // const char*
    auto s1 = u8"hello"; // const char*, 编码为 UTF-8
    auto s2 = L"hello"; // const wchar_t* 宽字符
    auto s3 = u"hello"; // const char16_t*, 编码为 UTF-16
    auto s4 = U"hello"; // const char32_t*, 编码为 UTF-32
    cout << "字符串文字"<<endl;
    cout << "hello : "<<s0 <<endl;
    cout << "hello : " << s1 << endl;
    cout << "hello : " << s2 << endl;
    cout << "hello : " << s3 << endl;
    cout << "hello : " << s4 << endl;



    // 包含未转义的 \ 和 &quot; 的原始字符串文字
    auto R0 = R"("Hello \ world")"; // const char*
    auto R1 = u8R"("Hello \ world")"; // const char*, 编码为 UTF-8
    auto R2 = LR"("Hello \ world")"; // const wchar_t*
    auto R3 = uR"("Hello \ world")"; // const char16_t*, 编码为 UTF-16
    auto R4 = UR"("Hello \ world")"; // const char32_t*, 编码为 UTF-32




    // 将字符串文字与标准 s 后缀相结合
    auto S0 = "hello"s; // std::string
    auto S1 = u8"hello"s; // std::string
    auto S2 = L"hello"s; // std::wstring
    auto S3 = u"hello"s; // std::u16string
    auto S4 = U"hello"s; // std::u32string

    // 将原始字符串文字与标准 s 后缀相结合
    auto S5 = R"("Hello \ world")"s; // std::string from a raw const char*
    auto S6 = u8R"("Hello \ world")"s; // std::string from a raw const char*, encoded as UTF-8
    auto S7 = LR"("Hello \ world")"s; // std::wstring from a raw const wchar_t*
    auto S8 = uR"("Hello \ world")"s; // std::u16string from a raw const char16_t*, encoded as UTF-16
    auto S9 = UR"("Hello \ world")"s; // std::u32string from a raw const char32_t*, encoded as UTF-32
    return 0;
}


//字符文本
/*
* 字符文本 由一个字符常量构成。 它由用单引号括起来的字符表示。 有五种类型的字符文本：

类型的普通字符文本 char ，例如 'a'

char char8_t 例如，C++20 (中类型为) 的 UTF-8 字符文本u8'a'

类型的宽字符文本 wchar_t ，例如 L'a'

类型的 UTF-16 字符文本 char16_t ，例如 u'a'

类型的 UTF-32 字符文本 char32_t ，例如 U'a'

用于字符文本的字符可能是任何字符，但保留字符反 () 、单引号 () 或新 \ 行除外 ' 。 可以使用转义序列指定保留字符。 可以通过使用通用字符名称指定字符，只要类型的大小足以保留字符。
*/

//编码
/*
字符文本的编码方式基于其前缀不同。

不带前缀的字符文本是普通字符文本。 包含单个字符、转义序列或可在执行字符集表示的通用字符名称的普通字符文本的值具有的值等于执行字符集内其编码的数字值。 包含多个字符、转义序列或通用字符名称的普通字符文本是 多字符文本。 不能在执行字符集内表示的多字符文本或普通字符文本的类型为 int ，其值是实现定义的。 有关MSVC，请参阅下面的 特定于 Microsoft 的部分。

以 前缀开头的字符 L 文本是宽字符文本。 包含单个字符、转义序列或通用字符名称的宽字符文本的值值等于执行宽字符集内其编码的数字值，除非字符文本在执行宽字符集内没有表示形式，在这种情况下，该值是实现定义的。 包含多个字符、转义序列或通用字符名称的宽字符文本的值是实现定义的。 有关MSVC，请参阅下面的 特定于 Microsoft 的部分。

以 前缀开头的字符 u8 文本是 UTF-8 字符文本。 如果由对应于 C0 控件和基本拉丁语 Unicode 块) 的单个 UTF-8 代码单元 (表示，则包含单个字符、转义序列或通用字符名称的 UTF-8 字符文本的值的值等于其 ISO 10646 码位值。 如果值不能由单个 UTF-8 代码单元表示，则程序格式不正确。 包含多个字符、转义序列或通用字符名称的 UTF-8 字符文本格式不正确。

以 前缀开头的字符 u 文本是 UTF-16 字符文本。 如果 UTF-16 代码单元 (对应于基本多语言平面) ，则包含单个字符、转义序列或通用字符名称的 UTF-16 字符文本的值的值等于其 ISO 10646 码位值。 如果值不能由单个 UTF-16 代码单元表示，则程序格式不正确。 包含多个字符、转义序列或通用字符名称的 UTF-16 字符文本格式不正确。

以 前缀开头的字符 U 文本是 UTF-32 字符文本。 包含单个字符、转义序列或通用字符名称的 UTF-32 字符文本的值的值等于其 ISO 10646 码位值。 包含多个字符、转义序列或通用字符名称的 UTF-32 字符文本格式不正确。
*/

//转义序列

int main12()
{
    char newline = '\n';
    char tab = '\t';
    char backspace = '\b';
    char backslash = '\\';
    char nullChar = '\0';

    cout << "换行符: " << newline << "ending" << endl;
    cout << "制表符: " << tab << "ending" << endl;
    cout << "退格字符: " << backspace << "ending" << endl;
    cout << "反斜杠字符: " << backslash << "ending" << endl;
    cout << "空字符: " << nullChar << "ending" << endl;
    return 0;
}
/*输出：
换行符：
结尾
制表符：结尾
退格字符：结尾
反斜杠字符：\ending
空字符：结束
*/

int main13() 
{

    //窄多字符文本创建值
    char c0 = 'abcd';    // C4305, C4309,截断为“d”
    wchar_t w0 = 'abcd';    // C4305、C4309，截断为“\x6364”
    int i0 = 'abcd';    // 0x61626364 

    cout << "c0的值 : " << c0 << "  ;w0的值 : " << w0 << "  i0 的值 :"<<hex <<i0;

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
    wchar_t w2 = L'\1000';  // C4066 L'@', 0 忽略了
    wchar_t w3 = L'\009';   // C4066 L'\0', 9 忽略了
    wchar_t w4 = L'\089';   // C4066 L'\0', 89忽略
    wchar_t w5 = L'\qrs';   // C4129, C4066 L'q' 逃脱，rs 被忽略
    wchar_t w6 = L'\x0050'; // L'P'
    wchar_t w7 = L'\x0pqr'; // C4066 L'\0', 忽略 pqr

  
    cout << "w1  " << (char)w1 << endl;
    cout << "w2  " << (char)w2 << endl;
    cout << "w3  " << (char)w3 << endl;
    cout << "w4  " << (char)w4 << endl;
    cout << "w5  " << (char)w5 << endl;
    cout << "w6  " << (char)w6 << endl;
    cout << "w7  " << (char)w7 << endl;

    return 0;
}
//通用字符名称
int main18()
{
    char u1 = 'A';          // 'A'
    //八进制
    char u2 = '\101';       // octal, 'A'
    //十六进制
    char u3 = '\x41';       // hexadecimal, 'A'
    //通用字符名称由前缀 \U 后跟八位数 unicode 码位组成，或者由前缀 \u 后跟四位数 unicode 码位组成
    char u4 = '\u0041';     // \u UCN 'A'
    char u5 = '\U00000041'; // \U UCN 'A'

    cout << "u1 : " << u1 <<endl; // A >>十进制编码>>ASCII>>二进制
    cout << "u2 : " << u2 << endl;//八进制>>十进制>>A>>ASCII>>二进制
    cout << "u3 : " << u3 << endl;//十六进制>>十进制>>A>>ASCII>>二进制
    cout << "u4 : " << u4 << endl;//unicode>>十进制>>A>>ASCII>>二进制
    cout << "u5 : " << u5 << endl;//unicode>>十进制>>A>>ASCII>>二进制

    return 0;

}
//窄字符串文本
int main19()
{
    const char* narrow = "abcd";

    // 代表字符串：yes\no
    const char* escaped = "yes\\no"; 
    // 八进制
    const char* escaped2 = "yes\\no\101";
    //八进制 十六进制
    const char* escaped3 = "yes\\no\101\x41";
    //通用 unicode 码
    //就不写了
    cout << "narrow : " << narrow<<endl;
    cout << "escaped : " << escaped<<endl;
    cout << "escaped2 : " << escaped2 << endl;
    cout << "escaped3 : " << escaped3 << endl;
    return 0;
}

//UTF-8 编码的字符串
int main20()
{
    const char* str1 = u8"Hello World";
    const char* str2 = u8"\U0001F607 is O:-)";

    cout << "str1 : " << str1<<endl;
    cout << "str2 : " << str2 << endl;

    return 0;
}
//宽字符串文本
int main21()
{
    const wchar_t* wide = L"zyxw";
    const wchar_t* newline = L"hello\ngoodbye";

    cout << "wide : " << wide << endl;
    cout << "newline : " << newline << endl;
    cout << "newline : " << (char)newline[5] << endl;
    //字符
    const wchar_t wide2 = L'a';
    cout << "wide2 : " << wide2 << endl;
    //字符串
    const wchar_t* wide3 = L"a";
    cout << "wide3 : " << wide3[0] << endl;
    return 0;
}
//char16_t 和 char32_t (C++11)
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

//(c + + 11) 的原始字符串文本
int main23()
{
    // 表示字符串：未转义的 \ 字符
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

    //总结  R"()" 里面的字符是没有转义的字符,就是\n 这些一样可以被看做字符

    // 表示字符串：)&quot;
   // const char* bad_parens = R"()")";  // error C2059
 

    //分隔符xa( 类容 )xa  分隔符类容可以自定义
    const char* good_parens = R"xa()")xa";
    cout << "good_parens : " << good_parens;

    return 0;
}

//可以构造包含换行符的原始字符串文本，而不是源中的转义字符) (：

int main24()
{
    // represents the string: hello
//goodbye

    //不用转义换行
    const char* newline21 = R"(hello
goodbye)";

    cout << "newline21  : " << newline21 << endl;


    const wchar_t* newline22 = LR"(hello
goodbye)";

    cout << "newline22  : " << newline22 << endl;

    return 0;
}

#include<string>
//std：： string 文本 (c + + 14)
int main25()
{
    //#include <string>
    //使用命名空间 std::string 文字；
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
    return 0;

}
//字符串文本的大小
int main26()
{
    const wchar_t *str = L"Hello!";
    const size_t byteSize = (wcslen(str) + 1) * sizeof(wchar_t);

    cout << "str : " << str<<endl;
    cout << "byteSize : " << byteSize;
    return 0;
}
//修改字符串文本
int main27()
{
  //   wchar_t* str2 = L"hello";
 //   str2[2] = L'a'; // 运行时错误：访问冲突

    auto str3 = L"hello";
 //   str3[2] = L'a'; // C3892：不能分配给 const 的变量。

    return 0;
}
//串联相邻字符串文本
int main28()
{
    //相邻宽或窄字符串文本是串联的。 声明如下：
    char str[] = "12" "34" ;
    //与此声明相同：
    char atr[] = "1234";
    //也与此声明相同：
    char atr2[] = "12\
34";
    cout << "str[] : " << str << endl;
    cout << "atr[] : " << atr << endl;
    cout << "atr2[] : " << atr2 << endl;

    return 0;
}
//具有通用字符名称的字符串文本
int main()
{
    // ASCII 笑脸
    const char* s1 = ":-)";

    //UTF-16（在 Windows 上）编码的眨眼脸 (U+1F609)
    const wchar_t* s2 = L"😉 = \U0001F609 is ;-)";

    // UTF-8 编码的带光环的笑脸 (U+1F607)
    const char* s3 = u8"😇 = \U0001F607 is O:-)";

    // UTF-16 编码笑脸张开嘴 (U+1F603)
    const char16_t* s4 = u"😃 = \U0001F603 is :-D";

    // UTF-32 编码带太阳镜的笑脸 (U+1F60E)
    const char32_t* s5 = U"😎 = \U0001F60E is B-)";

    cout << "s1 : " << s1 << endl;
    cout << "s2 : " << s2 << endl;
    cout << "s3 : " << s3 << endl;
    cout << "s4 : " << s4 << endl;
    cout << "s5 : " << s5 << endl;
    return 0;
}