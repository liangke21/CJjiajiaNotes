

/*

�ڶ����ƽӿڱ߽�ʹ���㹻�Ŀ���ֲ���ͺ�Լ����
"����ֲ����" �� C �������ͻ������ C �������͵Ľṹ��
������ֻ���ڵ��÷��ͱ����÷�ͬ�Ⲽ�֡�����Լ����ʱʹ�á�
�������߶�����ͬ�ı������ͱ��������ý��б���ʱ���ſ��ܳ������������

*/

//���Ϊ�� C ����ֲ��ƽչ��
//������÷�����ʹ����һ�ֱ����� / ���Ա��룬��ʹ���ض��ĵ���Լ�� "ƽչ" �� extern "C" API��


// class widget {
//   widget();
//   ~widget();
//   double method( int, gadget& );
// };
//extern "C" {        // ʹ����ʽ��this���ĺ���
//	struct widget;   // ��͸�����ͣ�����ǰ��������
//	widget* STDCALL widget_create();      // ���캯�������µġ�this��
//	void STDCALL widget_destroy(widget*); // �����������ġ�this��
//	double STDCALL widget_method(widget*, int, gadget*); // ����ʹ�á������
//}