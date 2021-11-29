

/*
类可以是匿名的，也就是说，可以在不使用 标识符 的情况下声明它们。 
将类名替换为名称时，这会很有用 typedef ，如下所示：
*/

typedef struct
{
    unsigned x;
    unsigned y;
} POINT;

/*
 备注

上面示例中显示的匿名类的用法对于保留与现有 C 代码的兼容性很有用。 在某些 C 代码中，将 typedef 与匿名结构结合使用非常普遍。
*/

struct PTValue
{
    POINT ptLoc;
    union
    {
        int  iValue;
        long lValue;
    };
};

int main1801() {

  //  PTValue ptv;
   // int i = ptv.iValue;

    return 0;
}