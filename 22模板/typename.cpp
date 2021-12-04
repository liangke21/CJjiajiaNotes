
/*
如果模板定义中的名称是依赖于模板参数的限定名，则必须使用此关键字;如果限定名不是依赖项，则此项是可选的。 有关详细信息，请参阅 模板和名称解析。

typename 可由模板声明或定义中任意位置的任何类型使用。 不允许在基类列表中使用该关键字，除非将它用作模板基类的模板自变量。

*/


//template <class T>
//class C1 : typename T::InnerType // 错误 - 不允许使用类型名称.
//{};


//template <class T>
//class C2 : A<typename T::InnerType>  // 类型名称确定.
//{};

//typename关键字还可以用于替代 class 模板参数列表中的。 例如，下面的语句在语义上是等效的：

//template<class T1, class T2>
//template<typename T1, typename T2>





template<class T> class X
{
	typename T::Y m_y;   // 将 Y 视为一种类型
};

int main220201()
{

	return 0;
}