
template<class T> void f(T t)
{
};

// ��ʽ�ػ� f ��'char' ��
// template argument explicitly specified:
//
template<> void f<char>(char c)
{
}

// ��ʽ�ػ� f ��'double' ��
// ģ������Ƶ�:
//
template<> void f(double d)
{
}
int main22040401()
{

	return 0;
}