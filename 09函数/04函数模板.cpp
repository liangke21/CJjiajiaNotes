#include <string>
#include <iostream>
using namespace std;


template<typename Lhs, typename Rhs>
auto Add2(const Lhs& lhs, const Rhs& rhs)
{
    return lhs + rhs;
}

auto a = Add2(3.13, 2.895); // a ÊÇË«Êý

auto b = Add2(std::string{ "Hello" }, std::string{ " World" }); // b ÊÇ std::string

int main010401()
{

    cout << "b : " << b;

    return 0;
}
