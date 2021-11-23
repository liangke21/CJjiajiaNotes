


// static_cast_Operator.cpp
// compile with: /LD
class B {};
//在下面的示例中，因为 D* pd2 = static_cast<D*>(pb); 
//可能有不在 D 内的字段和方法，所以行 B 不安全。 
//但是，因为 B* pb2 = static_cast<B*>(pd); 始终包含所有 D，所以行 B 是安全的转换。
class D : public B {};

void f(B* pb, D* pd) {
    //因为 D* pd2 = static_cast<D*>(pb); 可能有不在 D 内的字段和方法，所以行 B 不安全
    D* pd2 = static_cast<D*>(pb);   // 不安全，D 可以有字段
                                    // 和不在 B 中的方法。

    B* pb2 = static_cast<B*>(pd);   // 安全转换，D 始终
                                    // 包含所有 B.
}

int main0401031()
{

    return 0;
}

// 运算符可用于将指向基类的指针转换为指向派生类的指针 static_cast 等操作。 此类转换并非始终安全。

class B1 {
public:
    virtual void Test() {}
};
class D1 : public B1 {

    virtual void Test();
};

void f(B1* pb) {

   // B* pb2 = new B;

 //   D* pd1 = dynamic_cast<D*>(pb);
    //这里不是基类
  //  D* pd2 = static_cast<D*>(pb);
}

int main0401032()
{

    int a = 5;

    return 0;
}


// dynamic_cast 向下转型
// 
class B2 { virtual void f(); };
class D2 : public B2 { virtual void f(); };

void f() {
  //  B* pb = new D;   // 不清楚但可以 //未定义
 //   B* pb2 = new B; //未定义

  //  D* pd = dynamic_cast<D*>(pb);   // ok: pb 实际上指向一个 D
   // D* pd2 = dynamic_cast<D*>(pb2);   // pb2 指向 B 而不是 D
}