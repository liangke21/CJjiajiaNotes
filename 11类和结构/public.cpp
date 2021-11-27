

/*

备注
在类成员列表之前， public 关键字指定可以从任何函数访问这些成员。 这适用于声明到下一个访问指示符或类的末尾的所有成员。

在基类的名称前面时， public 关键字指定基类的公共成员和受保护成员分别是派生类的公共和受保护成员。

类中成员的默认访问是私有的。 结构或联合中成员的默认访问是公共的。

基类的默认访问对于类是私有的，而对于结构是公共的。 联合不能具有基类。

有关详细信息，请参阅控制对类成员的访问中的私有、受保护、友元和成员访问表。



*/



class BaseClass {
public:
    int pubFunc() { return 0; }
};

class DerivedClass : public BaseClass {};

int main050501() {
    BaseClass aBase;
    DerivedClass aDerived;
    aBase.pubFunc();       // pub Func() 是可访问的
                           //    从任何函数
    aDerived.pubFunc();    // pub Func() 仍然是公开的
                
    return 0;//    派生类
}