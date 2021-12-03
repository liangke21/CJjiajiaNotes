#include <stdexcept>
#include <limits>
#include <iostream>

using namespace std;

void MyFunc(int c)
{
    if (c > numeric_limits< char> ::max())//char 类型的最大值
        throw invalid_argument("我的 Func 参数太大.");

}

int main180101()
{
    try
    {
        MyFunc(256); //导致异常抛出
    }

    catch (invalid_argument& e)
    {
        cerr << e.what() << endl;
        return -1;
    }
  
    return 0;
}