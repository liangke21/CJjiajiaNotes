

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

//�ٶ���Ҫ��д���ɶ���ķ��ͺ����� ����ʾ����ʾ��һ�ֱ�д�˺����ķ�ʽ��

template <typename T, typename A1, typename A2>
T* factory(A1& a1, A2& a2)
{
	return new T(a1, a2);
}

//����ʾ����ʾ�˶� factory ��������Ч���ã�

int a = 4, b = 5;
W* pw = factory<W>(a, b);

//���ǣ������ʾ���������Ժ�������Ч���� factory �� ������Ϊ factory ���ÿ��޸ĵ���ֵ������Ϊ�������������ͨ��ʹ���ҵ��õģ�

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