#include <stdexcept>
#include <limits>
#include <iostream>

using namespace std;

void MyFunc(int c)
{
    if (c > numeric_limits< char> ::max())//char ���͵����ֵ
        throw invalid_argument("�ҵ� Func ����̫��.");

}

int main180101()
{
    try
    {
        MyFunc(256); //�����쳣�׳�
    }

    catch (invalid_argument& e)
    {
        cerr << e.what() << endl;
        return -1;
    }
  
    return 0;
}