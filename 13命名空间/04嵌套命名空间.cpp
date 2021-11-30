


/*
可以嵌套命名空间。 普通的嵌套命名空间具有对其父级成员的非限定访问权限，
但父成员不具有对嵌套命名空间 (的非限定访问权限，除非它被声明为内联) ，如以下示例中所示：
*/


//namespace ContosoDataServer3
//{
//    void Foo();
//
//    namespace Details
//    {
//        int CountImpl;
//        void Ban() { return Foo(); }
//    }
//
//    int Bar() { return 0; };
//   int Baz(int i) { return Details::CountImpl; }
//}//总点父级不具备访问嵌套命名空间