

// 枚举的前向声明(C++11):
enum A : int; // 非作用域枚举必须指定类型
enum class B; // 范围枚举默认为 int 但 ...
enum class C : short;  // ... 可能有任何完整的基础类型

/*
// unscoped enum:
enum [identifier] [: type]
{enum-list};

// scoped enum:
enum [class|struct]
[identifier] [: type]
{enum-list};


参数
identifier
指定给与枚举的类型名称。

type
枚举器的基础类型；所有枚举器都具有相同的基础类型。 可能是任何整型。

枚举列表
枚举中以逗号分隔的枚举器列表。 范围中的每个枚举器或变量名必须是唯一的。 但是，值可以重复。 在未区分范围的枚举中，范围为环绕范围;在范围枚举中，范围是 枚举列表 本身。 在限定范围的枚举中，该列表可能为空，这实际上定义了一个新的整型类型。

class
通过在声明中使用此关键字，指定枚举的作用域，并且必须提供 标识符 。 你还可以使用 struct 关键字代替 class ，因为在此上下文中它们在语义上是等效的。
*/