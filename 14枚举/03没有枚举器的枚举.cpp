



/*
通过使用显式基础类型定义枚举 (常规或范围) ，而不是枚举器，实际上可以引入不包含任何其他类型的隐式转换的新整型类型。 
通过使用此类型（而不是其内置基础类型），可以消除无意中的隐式转换导致的细微错误的可能性。



enum class byte : unsigned char { };


新类型是基础类型的精确副本，因此具有相同的调用约定，这意味着可在 Abi 中使用，而不会造成任何性能损失。 
使用直接列表初始化来初始化类型的变量时不需要强制转换。 下面的示例演示如何在不同的上下文中初始化没有枚举器的枚举：
*/

enum class byte : unsigned char { };

enum class E : int { };
E e1{ 0 };
E e2 = E{ 0 };

struct X
{
    E e{ 0 };
    X() : e{ 0 } { }
};

E* p = new E{ 0 };

void f(E e) {};

int main1()
{
    f(E{ 0 });
    byte i{ 42 };
    byte j = byte{ 42 };

    // unsigned char c = j; // C2440: 'initializing': cannot convert from 'byte' to 'unsigned char'
    return 0;
}