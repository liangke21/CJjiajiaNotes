// if_else_statement.cpp
#include <iostream>

using namespace std;

class C
{
    public:
    void do_something(){
        cout << "c ��ʼ����\n";
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

    // û���������
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
        cout << "c Ϊ�գ�\n";
    }

    return 0;
}