// using_declaration_inheritance2.cpp
// C2876 expected
class A {
private:
	void f(char);
public:
	void f(int);
protected:
	void g();
};

class B : public A {
	//using A::f;   // C2876: A::f(char) is inaccessible  //已经声明不可访问
public:
	using A::g;   // B::g is a public synonym for A::g
};

int main()
{
	return 0;
}