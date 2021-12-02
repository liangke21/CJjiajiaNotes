/*

�� C ��ʽ����У�����ָ����Ҫ���ڽ��������ݵ����������� �˷���������÷��Զ��庯������Ϊ���������޸ġ� ���ִ� c + + �У� lambda ���ʽ �ṩ��ͬ�Ĺ����Լ����ߵ����Ͱ�ȫ�Ժ������ŵ㡣

����ָ������ָ����ָ��ĺ���������е�ǩ����

C++

����
// ����ָ���κκ�����ָ��...

// ...����һ���ַ���������һ���ַ���
string (*g)(string a);

// û�з���ֵ�Ͳ���
void (*x)();

// ...����һ��������������������
// ָ������
int (*i)(int i, string s, double d);
�����ʾ����ʾһ������ combine ���ú��������ܵ��κκ�����Ϊ���� std::string �������� std::string �� ���ݴ��ݵ��ĺ��� combine ��������ӻ�׷���ַ�����




*/

#include <iostream>
#include <string>

using namespace std;

string base{ "hello world" };

string append(string s)
{
    return base.append(" ").append(s);
}

string prepend(string s)
{
    return s.append(" ").append(base);
}

string combine(string s, string(*g)(string a))
{
    return (*g)(s);
}

int main0501()
{
    cout << combine("from MSVC", append) << "\n";
    cout << combine("Good morning and", prepend) << "\n";
    return 0;
}