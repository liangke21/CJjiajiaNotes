




namespace CardGame_Scoped
{
    enum class Suit { Diamonds, Hearts, Clubs, Spades };

    void PlayCard(Suit suit)
    {
        if (suit == Suit::Clubs) // 枚举器必须由枚举类型限定
        { /*...*/
        }
    }
}

/*
枚举提供上下文来描述以命名常数表示的一系列值，这些值也称为枚举器。 
在原始 C 和 C++ 枚举类型中，非限定枚举器在声明枚举的整个范围中可见。 
在区分范围的枚举中，枚举器名称必须由枚举类型名称限定。 以下示例演示两种枚举之间的基本差异：
*/
namespace CardGame_NonScoped2
{
    enum Suit { Diamonds, Hearts, Clubs, Spades };

    void PlayCard(Suit suit)
    {
        if (suit == Clubs) // 枚举数是可见的，无需限定
        { /*...*/
        }
    }
}


//将为枚举中的每个名称分配一个整数值，该值与其在枚举中的顺序相对应。 默认情况下，为第一个值分配 0，为下一个值分配 1，以此类推，但你可以显式设置枚举器的值，如下所示：


enum Suit { Diamonds = 1, Hearts, Clubs, Spades };

//为枚举器 Diamonds 分配值 1。 后续枚举器接收的值会在前一个枚举器的值的基础上加一（如果没有显式赋值）。 在前面的示例中，Hearts 将具有值 2，Clubs 将具有值 3，依此类推。
//每个枚举器都被视为常量，并且在为未区分范围的) 枚举定义(的作用域中必须具有唯一的名称，并且在 enum (范围内枚举)的自身中必须具有唯一的名称 enum 。 为这些名称指定的值不必是唯一的。 例如，如果一个未区分范围//的枚举 Suit 的声明如下：

   
  //  enum Suit2 { Diamonds = 5, Hearts, Clubs = 4, Spades };
//Diamonds、Hearts、Clubs 和 Spades 的值分别是 5、6、4 和 5。 请注意，5 使用了多次；尽管这并不符合预期，但是允许的。 对于区分范围的枚举来说，这些规则是相同的。


    //强制转换规则

    int account_num = 135692;
    Suit hand;
  //  hand = account_num; // error C2440: '=' : 无法从“int”转换为“Suit”  E0077	此声明没有存储类或类型说明符	53	IntelliSense

  // 需要强制转换才能将转换 int 为限定范围或未区分范围的枚举器。 但是，你可以将区分范围的枚举器提升为整数值，而不进行强制转换。
    int account_num2 = Hearts; //OK if Hearts is in a unscoped enum
  
    /*按照这种方式使用隐式转换可能导致意外副作用。 若要帮助消除与区分范围的枚举相关的编程错误，区分范围的枚举值必须是强类型值。 区分范围的枚举器必须由枚举类型名称（标识符）限定，并且无法进行隐式转换，如以下示例所示：*/

    namespace ScopedEnumConversions
    {
        enum class Suit { Diamonds, Hearts, Clubs, Spades };

        void AttemptConversions()
        {
            Suit hand;
           // hand = Clubs; // error C2065: 'Clubs' : 未声明的标识符
            hand = Suit::Clubs; //Correct.
            int account_num = 135692;
          //  hand = account_num; // error C2440: '=' : 无法从“int”转换为“Suit”
            hand = static_cast<Suit>(account_num); // OK, 但可能是一个错误！！！

            //account_num = Suit::Hearts; // error C2440: '=' : 无法转换自 'Suit' to 'int'
            account_num = static_cast<int>(Suit::Hearts); // OK
        }
    }
    /*注意，hand = account_num; 行仍会导致对未区分范围的枚举发生的错误，如前面所示。 它可以与显式强制转换一起使用。 但是，借助区分范围的枚举，不再允许在没有显式强制转换的情况下在下一条语句 account_num = Suit::Hearts; 中尝试转换。*/


