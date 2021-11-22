


//// dynamic_cast_1.cpp
//// compile with: /c
//class B { };
//class C : public B { };
//class D : public C { };
//
//void f(D* pd) {
//    C* pc = dynamic_cast<C*>(pd);   // �õģ�C ��һ��ֱ�ӻ���  �� ����ǿתΪ����
//                                    // pc ָ�� pd �� C �Ӷ���
//    B* pb = dynamic_cast<B*>(pd);   // �õģ�B ��һ����ӻ��� �� ����ǿתΪ����
//                                    // pb ָ�� pd �� B �Ӷ���
//}
////�������͵�ת����Ϊ "����ת��"����Ϊ����ָ���������ָ�������ƶ����������Ե��ࡣ ����ת����һ����ʽת����
//
//
////��� type - id Ϊ void* �����������ʱ�����ȷ����ʵ������ expression �� �����ָ��ָ������������ָ�� expression �� ���磺
//
//// dynamic_cast_2.cpp
//// compile with: /c /GR
//class A { virtual void f(); };
//class B { virtual void f(); };
//
//void f() {
//    A* pa = new A;
//    B* pb = new B;
//    void* pv = dynamic_cast<void*>(pa);
//    // pv ����ָ������ A �Ķ���
//
//    pv = dynamic_cast<void*>(pb);
//    // pv ����ָ������ B �Ķ���
//}
//
////����� type-id �� void *�����ִ������ʱ��飬�Բ鿴ָ��Ķ����Ƿ� expression ����ת��Ϊָ������� type-id ��
//
//
////��������� expression �ǵ����͵Ļ��࣬��ִ�� type-id ����ʱ��飬�Բ鿴�Ƿ� expression ȷʵָ������͵��������� type-id ��
////���Ϊ true������Ϊָ������͵����������ָ�� type-id �� ���磺
//
//
//class B { virtual void f(); };
//class D : public B { virtual void f(); };
//
//void f() {
//    B* pb = new D;   // �����������
//    B* pb2 = new B;
//
//    D* pd = dynamic_cast<D*>(pb);   // ok: pb ʵ����ָ��һ�� D
//    D* pd2 = dynamic_cast<D*>(pb2);   // pb2 ָ�� B ������ D   
//
//    //�ܽ������ pd2 ��B��ָ�� Dʵ��    
//}
////�������͵�ת����Ϊ "����ת��"��
////��Ϊ����ָ��ĳ�����νṹ��ָ�������ƶ���һ�������Ե��ࡣ
//
//
//
////ע��Ҫ��ȷת��
//// dynamic_cast_4.cpp
//// compile with: /c /GR
//class A { virtual void f(); };
//class B : public A { virtual void f(); };
//class C : public A { virtual void f(); };
//class D : public B, public C { virtual void f(); };
//
//void f() {
//    D* pd = new D;
//   // A* pa = dynamic_cast<A*>(pd);   // C4540, ģ��ת��������ʱʧ��
//    B* pb = dynamic_cast<B*>(pd);   // ����Ͷ�䵽 B  //����ת��
//    A* pa2 = dynamic_cast<A*>(pb);   // ȷ������ȷ  //����ת��
//}
