/*
const ��volatile�ؼ��ָ���ָ�봦��ʽ�� 
�ؼ���ָ���ڳ�ʼ�������޸�ָ��;֮�󽫱���ָ�� const �����޸ġ�

�ؼ���ָ�����������ƹ�����ֵ����ͨ���û�Ӧ�ó����г���Щ���� volatile ����������������޸ġ�
��ˣ� �ؼ��ֿ��������������ڴ��еĶ���
��Щ�����ͨ��������̻�ȫ������������ʣ���Щ���̻�ȫ���������������� volatile �жϷ�������ͨ�š�

����������Ϊ ʱ��������ÿ�γ��������ʱ�������¼����ڴ��� volatile ��ֵ��
�⽫�������ٿ��ܵ��Ż��� ���ǣ��������״̬�����������ʱ�����Ǳ�֤��Ԥ���ĳ������ܵ�Ψһ������

��Ҫ��ָ��ָ��Ķ�������Ϊ �� constvolatile ����ʹ�� �����������
*/

//��Ҫ��ָ��ָ��Ķ�������Ϊ �� constvolatile ����ʹ�� �����������
namespace a {

	const char* cpch;
	volatile char* vpch;
}

//��Ҫ��ָ���ֵ����ָ���д洢��ʵ�ʵ�ַ������Ϊ const �� volatile ����ʹ�ô����������
namespace b {

//	char* const pchc;
	char* volatile pchv;

}
//C++ ������ֹ�����޸�����Ϊ �Ķ����ָ��ķ��� const �� ���ำֵ���Ƴ��������������ָ�����Ϣ���Ӷ�Υ��ԭʼ��������ͼ�� �뿼������������
namespace c {

	const char cch = 'A';
	char ch = 'B';
}
//��������������������� (����Ϊ cchcch�� ������ chch) ����������/��ʼ����Ч��
int main02012() {
	using namespace a;
	using namespace b;
	using namespace c;


	const char* pch1 = &cch;
	const char* const pch4 = &cch;
	const char* pch5 = &ch;
	char* pch6 = &ch;
	char* const pch7 = &ch;
	const char* const pch8 = &ch;

	//��������/��ʼ�����ڴ���
	//char* pch2 = &cch;   // Error
	//char* const pch3 = &cch;   // Error



	/*
	pch2 ������������һ�����������޸ĳ��������ָ�룬��˲�����ʹ�á� ������ָ��ָ���ǳ����������Ƕ���;��ֹ������ԭ�����ֹ���� pch3pch2 ��ԭ����ͬ��

���°˸���ֵ��ʾ��ͨ��ָ����еĸ�ֵ�Լ���ǰ���������ָ��ֵ�ĸ��ģ����ڣ����� pch1 �� pch8 �ĳ�ʼ������ȷ�ġ�
	*/
	//* pch1 = 'A';  // Error: object declared const
	//pch1 = &ch;   // OK: pointer not declared const
	//*pch2 = 'A';  // OK: normal pointer
	//pch2 = &ch;   // OK: normal pointer
	//*pch3 = 'A';  // OK: object not declared const
	//pch3 = &ch;   // Error: pointer declared const
	//*pch4 = 'A';  // Error: object declared const
	//pch4 = &ch;   // Error: pointer declared const

	//ָ�� ����� const ָ��ͨ���ں���������ʹ�ã�������ʾ��

	
		//errno_t strcpy_s(char* strDestination, size_t numberOfElements, const char* strSource);
	//ǰ��� �������һ������ strcpy_s���������������е���������Ϊָ�� ��ָ�� �� ���ڲ����ǰ����ô��ݵģ������ǰ�ֵ���ݵģ���˺������������޸� �� �����δ strDestinationstrSourcestrSource ��Ϊ 
	////const ���� �� strSource ���� const ��ȷ�������õĺ��� strSource �޷����ĵ��÷���


	return 0;
}

/*
const���Խ��������͵�ָ������ͬһ���͵�ָ�롣 ���ǣ����ܽ��� const ��ָ������ const ָ�롣 ���´�����ʾ����ȷ�ʹ���ĸ�ֵ��
*/


int* const cpObject = 0;
int* pObject;

int main0202() {
	pObject = cpObject;
	//cpObject = pObject;   // C3892
	return 0;
}

/*
* ����ʾ����ʾ�˵���ָ��ָ��ĳ��ָ������ָ��ʱ��ν���������Ϊ const��
*/


struct X {
	X(int i) : m_i(i) { }
	int m_i;
};

int main0203() {
	// correct
	const X cx(10);
	const X* pcx = &cx;
	const X** ppcx = &pcx;

	// Ҳ��ȷ
	X const cx2(20);
	X const* pcx2 = &cx2;
	X const** ppcx2 = &pcx2;
	return 0;
}