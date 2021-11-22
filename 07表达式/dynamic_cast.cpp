


//// dynamic_cast_1.cpp
//// compile with: /c
//class B { };
//class C : public B { };
//class D : public C { };
//
//void f(D* pd) {
//    C* pc = dynamic_cast<C*>(pd);   // 好的：C 是一个直接基类  把 子类强转为基类
//                                    // pc 指向 pd 的 C 子对象
//    B* pb = dynamic_cast<B*>(pd);   // 好的：B 是一个间接基类 把 子类强转为基类
//                                    // pb 指向 pd 的 B 子对象
//}
////这种类型的转换称为 "向上转换"，因为它将指向派生类的指针向上移动到它派生自的类。 向上转换是一个隐式转换。
//
//
////如果 type - id 为 void* ，则进行运行时检查以确定的实际类型 expression 。 结果是指向指向的完整对象的指针 expression 。 例如：
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
//    // pv 现在指向类型 A 的对象
//
//    pv = dynamic_cast<void*>(pb);
//    // pv 现在指向类型 B 的对象
//}
//
////如果不 type-id 是 void *，则会执行运行时检查，以查看指向的对象是否 expression 可以转换为指向的类型 type-id 。
//
//
////如果的类型 expression 是的类型的基类，则执行 type-id 运行时检查，以查看是否 expression 确实指向的类型的完整对象 type-id 。
////如果为 true，则结果为指向的类型的完整对象的指针 type-id 。 例如：
//
//
//class B { virtual void f(); };
//class D : public B { virtual void f(); };
//
//void f() {
//    B* pb = new D;   // 不清楚但可以
//    B* pb2 = new B;
//
//    D* pd = dynamic_cast<D*>(pb);   // ok: pb 实际上指向一个 D
//    D* pd2 = dynamic_cast<D*>(pb2);   // pb2 指向 B 而不是 D   
//
//    //总结这里的 pd2 是B的指针 D实例    
//}
////这种类型的转换称为 "向下转换"，
////因为它将指向某个类层次结构的指针向下移动到一个派生自的类。
//
//
//
////注意要明确转换
//// dynamic_cast_4.cpp
//// compile with: /c /GR
//class A { virtual void f(); };
//class B : public A { virtual void f(); };
//class C : public A { virtual void f(); };
//class D : public B, public C { virtual void f(); };
//
//void f() {
//    D* pd = new D;
//   // A* pa = dynamic_cast<A*>(pd);   // C4540, 模糊转换在运行时失败
//    B* pb = dynamic_cast<B*>(pd);   // 首先投射到 B  //向上转型
//    A* pa2 = dynamic_cast<A*>(pb);   // 确定：明确  //向上转型
//}
