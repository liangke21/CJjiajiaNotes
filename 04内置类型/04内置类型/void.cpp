// void.cpp
//void vobject;   ////C2182	“vobject” : 非法使用“void”类型	


void* pv;   // okay
int* pint; int i;
int main() {
	pv = &i;
	// Cast optional in C required in C++
	pint = (int*)pv;
}