#include <iostream>
#include <mutex>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<int, string> m;
mutex mx;
bool shared_flag; // guarded by mx
void unsafe_operation() {}

int main0601021()
{
    cout << "����������\n";

    if (auto it = m.find(10); it != m.end())
    {
        cout << it->second;
        cout << "����������2\n";
        return 0;
    }

    if (char buf[10]; fgets(buf, 10, stdin))
    {
        cout << "����������3\n";
        m[0] += buf;
    }

    if (lock_guard<mutex> lock(mx); shared_flag)
    {
        cout << "����������4\n";
        unsafe_operation();
        shared_flag = false;
    }

    string s{ "if" };
    if (auto keywords = { "if", "for", "while" }; any_of(keywords.begin(), keywords.end(), [&s](const char* kw) { return s == kw; }))
    {
        cout << "�������Ʋ����ǹؼ���\n";
    }

    return 0;
}