
/*
���ģ�嶨���е�������������ģ��������޶����������ʹ�ô˹ؼ���;����޶������������������ǿ�ѡ�ġ� �й���ϸ��Ϣ������� ģ������ƽ�����

typename ����ģ����������������λ�õ��κ�����ʹ�á� �������ڻ����б���ʹ�øùؼ��֣����ǽ�������ģ������ģ���Ա�����

*/


//template <class T>
//class C1 : typename T::InnerType // ���� - ������ʹ����������.
//{};


//template <class T>
//class C2 : A<typename T::InnerType>  // ��������ȷ��.
//{};

//typename�ؼ��ֻ������������ class ģ������б��еġ� ���磬�����������������ǵ�Ч�ģ�

//template<class T1, class T2>
//template<typename T1, typename T2>





template<class T> class X
{
	typename T::Y m_y;   // �� Y ��Ϊһ������
};

int main220201()
{

	return 0;
}