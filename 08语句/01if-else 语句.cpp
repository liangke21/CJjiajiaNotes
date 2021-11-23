// if_else_statement.cpp
#include <iostream>

using namespace std;

class C
{
    public:
    void do_something(){
        cout << "c 初始化！\n";
    }
};
void init(C*){}
bool is_true() { return true; }
int x = 10;

int main0601()
{
    if (is_true())
    {
        cout << "b is true!\n";  // executed
    }
    else
    {
        cout << "b is false!\n";
    }

    // 没有其他语句
    if (x == 10)
    {
        x = 0;
    }

    C* c=NULL;
    init(c);

    if (c)
    {
        c->do_something();
    }
    else
    {
        cout << "c 为空！\n";
    }

    return 0;
}