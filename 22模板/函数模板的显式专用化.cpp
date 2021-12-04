
template<class T> void f(T t)
{
};

// 显式特化 f 和'char' 与
// template argument explicitly specified:
//
template<> void f<char>(char c)
{
}

// 显式特化 f 和'double' 与
// 模板参数推导:
//
template<> void f(double d)
{
}
int main22040401()
{

	return 0;
}