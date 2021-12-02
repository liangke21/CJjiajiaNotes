

struct W
{
	W(int&, int&) {}
};

struct X
{
	X(const int&, int&) {}
};

struct Y
{
	Y(int&, const int&) {}
};

struct Z
{
	Z(const int&, const int&) {}
};

//假定您要编写生成对象的泛型函数。 以下示例演示了一种编写此函数的方式：

template <typename T, typename A1, typename A2>
T* factory(A1& a1, A2& a2)
{
	return new T(a1, a2);
}

//以下示例演示了对 factory 函数的有效调用：

int a = 4, b = 5;
W* pw = factory<W>(a, b);

//但是，下面的示例不包含对函数的有效调用 factory 。 这是因为 factory 采用可修改的左值引用作为其参数，但它是通过使用右调用的：

//Z* pz = factory<Z>(2, 2);

int main0301()
{
	int a = 4, b = 5;
	W* pw = factory<W>(a, b);
	//X* px = factory<X>(2, b);
	//Y* py = factory<Y>(a, 2);
	//Z* pz = factory<Z>(2, 2);

	delete pw;
	//delete px;
	////delete py;
	//delete pz;
	return 0;
}