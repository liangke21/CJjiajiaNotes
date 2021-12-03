export module Foo;

#define ANSWER 42
/*
下面的示例在名为 ixx的源文件中显示一个简单的模块定义。 Visual Studio 中的模块接口文件需要ixx扩展名。 在此示例中，接口文件包含函数定义和声明。 但是，还可以将定义放置在一个或多个单独的文件中 (如后面的示例) 中所示。 导出模块 Foo语句指示此文件是名为的模块的主要接口 。 的 export 修饰符 f() 指示当 Foo 由其他程序或模块导入时，此函数将可见。 请注意，该模块引用命名空间 Bar 。
*/
namespace Bar2
{
  

  
    int f_internal() {
        return ANSWER;
    }

  

    

    export int f222() {
        return f_internal();
    }
}\