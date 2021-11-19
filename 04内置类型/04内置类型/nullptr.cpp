#include <cstddef>
#include <iostream>


using namespace std;
int main2()
{
	int a = 23;
	//a = nullptr;//	E0513	不能将 "std::nullptr_t" 类型的值分配到 "int" 类型的实体	7
	
	int b = 25;
	cout << "a : " << b << endl;
	b = NULL;

	cout << "a : " << b << endl;

	char c1 = 's';
	cout << "C1 : " << c1 << endl;

	char* c = &c1;
	cout << "C2 : " << &c << endl;
	cout << "C3 : " << *c << endl;

	c = NULL; 
	if(c)
	cout << "C4 : " << c << endl;

	char e = 'e';
	c = &e;
	c = nullptr;
	if(c)
	cout << "C5 : " << c << endl;

	char f = 'f';
	c = &f;
	c = 0;
	if(c)
	cout << "C6 : " << c << endl;


	char* d = nullptr;
	if(d)
	cout << "d : " << d << endl;
	exit(0);

}