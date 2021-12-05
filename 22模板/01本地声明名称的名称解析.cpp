/*
通过和不通过模板自变量都可引用模板名称本身。
在类模板的范围内，名称本身引用模板。
在模板专用化或部分专用化的范围中，名称单独引用专用化或部分专用化。
也可以通过适当的模板参数引用模板的其他专用化或部分专用化。


*/

// template_name_resolution3.cpp
// compile with: /c
template <class T> class A {
	A* a1;   // A 指的是 A<T>
	A<int>* a2;  // A<int> 指的是一个专业 A.
	A<T*>* a3;   // A<T*> 指的是部分专业化 A<T*>.
};

template <class T> class A<T*> {
	A* a4; // A 指的是 A<T*>.
};

template<> class A<int> {
	A* a5; // A 指的是 A<int>.
};