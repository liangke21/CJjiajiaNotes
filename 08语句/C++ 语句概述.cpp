/*

+1
此页面有帮助吗 ?
C++ 语句将按顺序执行，除非表达式语句、选择语句、迭代语句或跳转语句特意修改了顺序。

语句可以是以下类型之一：

labeled - statement
expression - statement
compound - statement
selection - statement
iteration - statement
jump - statement
declaration - statement
try - throw - catch

在大多数情况下，C++ 语句语法与 ANSI C89 的语法相同。 这两者之间的主要区别在于，在 C89 中，声明仅在 块的开始时允许;C++ 添加 declaration - statement ，它有效地消除了此限制。 这样，您就能够在程序中可以计算预计算初始化值的某个时点引入变量。

通过在块中的声明变量，您还可以对这些变量的范围和生存期进行精确的控制。

有关 语句的文章介绍了以下 C++ 关键字：

break
case
catch
continue
default
do

else
__except
__finally
for
goto

if
__if_exists
__if_not_exists
__leave
return

switch
throw
__try
try
while

*/