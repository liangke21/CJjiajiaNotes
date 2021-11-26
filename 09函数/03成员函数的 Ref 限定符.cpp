















#include <iostream>
#include <vector>

using namespace std;


/*
通过引用限定符，可以根据指向的对象 this 是右值还是左值，来重载成员函数。 当你选择不提供对数据的指针访问权限时，可以使用此功能来避免不必要的复制操作。 例如，假设类 C 在其构造函数中初始化某些数据，并在成员函数中返回该数据的副本 get_data() 。 如果类型为的对象 C 是要销毁的右值，则编译器将选择 get_data() && 重载，这会移动数据而不是复制数据。

*/

class C
{

public:
    C() {/*昂贵的初始化*/ }
    vector<unsigned> get_data()&
    {
        cout << "lvalue\n";
        return _data;
    }
    vector<unsigned> get_data()&&
    {
        cout << "rvalue\n";
        return _data;
    }

private:
    vector<unsigned> _data;
};

int main010301()
{
    C c;
    auto v = c.get_data(); // 拿一份。打印“左值".
    auto v2 = C().get_data(); // 得到原件。打印“右值”


    return 0;
}