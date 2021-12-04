
/*
对于多个模板参数，第一个默认参数后的所有参数必须具有默认参数。

如果使用的模板的参数均为默认参数，请使用空白尖括号：
*/
template<typename A = int, typename B = double>
class Bar
{
 
};

int main22010501()
{
    Bar<> bar; // 使用所有默认类型参数

    return 0;
}