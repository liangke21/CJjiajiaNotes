

/*
通过一个继承关系图到达多个名称（函数、对象或枚举器）是可能的。 
这种情况被视为与非虚拟基类一起使用时目的不明确。 
这些名称与虚拟基类一起使用时目的不明确，除非其中一个名称“决定”其他名称。

如果某个名称在两个类中定义并且一个类派生自另一个类，则该名称可控制另一个名称。
基准名称是派生类中的名称；此名称在本应出现多义性时使用，如以下示例所示：
*/



class A {
public:
    int a;
};

class B : public virtual A {
public:
    int a();
};

class C : public virtual A {};

class D : public B, public C {
public:
    D() { a(); } // 不模棱两可。 B::a() 支配 A::a。
};
int main() {

  
    return 0;
}