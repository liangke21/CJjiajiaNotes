// void.cpp
//void vobject;   ////C2182	“vobject” : 非法使用“void”类型	


void* pv;   // okay
int* pint; int i;
int main3() {
	pv = &i;
	// 在 C++ 中需要在 C 中强制转换为可选
	pint = (int*)pv;  //这里强化转为其int指针
}