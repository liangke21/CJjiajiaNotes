// void.cpp
//void vobject;   ////C2182	��vobject�� : �Ƿ�ʹ�á�void������	


void* pv;   // okay
int* pint; int i;
int main() {
	pv = &i;
	// Cast optional in C required in C++
	pint = (int*)pv;
}