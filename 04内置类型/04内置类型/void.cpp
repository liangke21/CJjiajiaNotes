// void.cpp
//void vobject;   ////C2182	��vobject�� : �Ƿ�ʹ�á�void������	


void* pv;   // okay
int* pint; int i;
int main3() {
	pv = &i;
	// �� C++ ����Ҫ�� C ��ǿ��ת��Ϊ��ѡ
	pint = (int*)pv;  //����ǿ��תΪ��intָ��
}