

/*

备注
在类成员列表前面时， 关键字指定只能从类的成员函数和友元访问这些 private 成员。 这适用于声明到下一个访问指示符或类的末尾的所有成员。

在基类的名称前面，关键字指定基类的公共成员和受保护成员是派生类 private 的私有成员。

类中成员的默认访问是私有的。 结构或联合中成员的默认访问是公共的。

基类的默认访问对于类是私有的，而对于结构是公共的。 联合不能具有基类。

有关相关信息，请参阅控制对类成员的访问中的友元、公共、受保护和成员访问表。
*/


class BaseClass {
public:
    // privMem accessible from member function
    int pubFunc() { return privMem; }
private:
    int privMem;
};

class DerivedClass : public BaseClass {
public:
    void usePrivate(int i)
    {
     //   privMem = i;
    }   // C2248: priv Mem 不可访问
              //来自派生类
};

class DerivedClass2 : private BaseClass {
public:
    // pub Func() 可从派生类访问
    int usePublic() { return pubFunc(); }
};

int main050301() {
    BaseClass aBase;
    DerivedClass aDerived;
    DerivedClass2 aDerived2;
  //  aBase.privMem = 1;     // C2248: priv Mem 不可访问
  //  aDerived.privMem = 1;  // C2248: priv Mem 不可访问
                           //    in derived class
  //  aDerived2.pubFunc();   // C2247: pub Func() 是私有的
                           //    派生类

    return 0;
}
