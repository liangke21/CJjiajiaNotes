



/*

利用 Microsoft C 扩展，您可以在另一个结构中声明结构变量，而无需为其指定名称。 这些嵌套结构称为匿名结构。 C++ 不允许匿名结构。

您可以像访问包含结构中的成员一样访问匿名结构的成员。
*/



//#include <stdio.h>
//
//struct phone
//{
//    int  areacode;
//    long number;
//};
//
//struct person
//{
//    char   name[30];
//    char   gender;
//    int    age;
//    int    weight;
//    struct phone;    // 匿名结构；不需要名字
//} Jim;
//
//int main()
//{
//    Jim.number = 1234567;
//    printf_s("%d\n", Jim.number);
//}
////Output: 1234567