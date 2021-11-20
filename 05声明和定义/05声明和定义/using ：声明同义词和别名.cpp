// post_declaration_namespace_additions.cpp
// compile with: /c
namespace A {
	void f(int) {}
}

using A::f;   // f is a synonym for A::f(int) only

namespace A {
	void f(char) {}
}

 void f2() {
	f('ab');   // refers to A::f(int), even though A::f(char) exists
}

int main9999() {
	using A::f;   // refers to A::f(int) AND A::f(char)
	f('a');   // calls A::f(char);

	return 0;
}