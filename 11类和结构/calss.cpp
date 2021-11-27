/*

template-spec
可选模板规范。 有关详细信息，请参阅 模板。

class
class 关键字。

ms-decl-spec
可选存储类规范。 有关详细信息，请参阅 __declspec关键字。

标记
给定给类的类型名称。 标记将成为 类范围内的保留字。 标记是可选项。 如果省略，则定义匿名类。 有关详细信息，请参阅 匿名类类型。

base-list
此类将派生其成员的类或结构的可选列表。 有关详细信息 ，请参阅 基类。 每个基类或结构名称前面都有一个访问说明 (公共、私有、受保护的) 和 virtual关键字。 有关详细信息，请参阅控制对类 成员的访问中的 成员访问表。

member-list
类成员的列表。 有关详细信息 ，请参阅类成员 概述。

declarators
声明符列表，指定类类型的一个或多个实例的名称。 如果 类的所有数据成员都是 ，则声明符可以包含初始值设置项列表 public 。 在默认情况下数据成员为 的结构中，这比在类 public 中更常见。 有关详细信息 ，请参阅声明 符概述。


*/


// class.cpp
// compile with: /EHsc
// Example of the class keyword
// Exhibits polymorphism/virtual functions.

#include <iostream>
#include <string>
#include <string>
using namespace std;



class dog
   
{
public:
    dog()
    {
        _legs = 4;
        _bark = true;
    }

    void setDogSize(string dogSize)
    {
        _dogSize = dogSize;
    }
    virtual void setEars(string type)      // 虚函数
    {
        _earType = type;
    }

private:
    string _dogSize, _earType;
    int _legs;
    bool _bark;

};

class breed : public dog
{
public:
    breed(string color, string size)
    {
        _color = color;
        setDogSize(size);
    }

    string getColor()
    {
        return _color;
    }

    //重新定义虚函数
    void setEars(string length, string type)
    {
        _earLength = length;
        _earType = type;
    }

protected:
    string _color, _earLength, _earType;
};

int main0201()
{
    dog mongrel;
    breed labrador("yellow", "large");
    mongrel.setEars("pointy");
    labrador.setEars("long", "floppy");
    cout << "Cody is a " << labrador.getColor() << " labrador" << endl;  //"yellow
    return 0;
}