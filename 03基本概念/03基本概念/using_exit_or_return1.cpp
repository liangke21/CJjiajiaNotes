// using_exit_or_return1.cpp






#include <stdlib.h>
#include <stdio.h>
//return 语句 main
int main61()
{
    exit(3);
  //  return 3;  可以不写
}

//静态对象的析构
class ShowData {
public:
    // 构造函数打开一个文件。
    ShowData(const char* szDev) {
        errno_t err;    //基本类型 
        err = fopen_s(&OutputDev, szDev, "w"); //打开文件
		/* fopen_s 函数
		第一个参数 :指向文件指针的指针，文件指针将接收指向已打开文件的指针。
		第二个参数 :文件名
		第三个参数 :字符串指定为 mode 文件请求的访问类型，如下所示
			mode	Access
        "r"	打开以便读取。 如果文件不存在或找不到，调用将 fopen_s 失败。
        "w"	打开用于写入的空文件。 如果给定文件存在，则其内容会被销毁。
        "a"	在文件末尾打开以进行写入（追加），在新数据写入到文件之前不移除文件末尾 (EOF) 标记。 如果文件不存在，则创建文件。
        "r+"	打开以便读取和写入。 文件必须存在。
        "w +"	打开用于读取和写入的空文件。 如果文件存在，则其内容会被销毁。
        "a+"	打开以进行读取和追加。 追加操作包括在新数据写入文件之前移除 EOF 标记。 写入完成后，EOF 标记不会还原。 如果文件不存在，则创建文件。
		*/
    }

    // 析构函数关闭文件。
    ~ShowData() { fclose(OutputDev); }  //关流
        /*  关闭流 (fclose) 或关闭所有打开的流 (_fcloseall) 。
         参数 :  流 (stream)
                指向 文件 结构的指针。
        */
    // Disp 函数在输出设备上显示一个字符串。
    void Disp(const char* szData) {
        fputs(szData, OutputDev);  //将字符串写入流。

        /*
        第一个参数要输出的字符串
        第二个参数 :stream
        指向 结构的 FILE 指针。
        */
    }
private:
    FILE* OutputDev;   //所需的流 I/O 声明
};

//  定义一个 Show Data 类型的静态对象。输出设备
//   选择的是“CON”——标准输出设备。
ShowData sd1 = "CON";

//  定义另一个显示数据类型的静态对象。输出
//   被定向到一个名为“HELLO.DAT”的文件
ShowData sd2 = "hello.dat";
/*
总结 :
当程序 运行最先初始化的就是静态对象和mai主函数,
在下面的示例中，将在 sd1 sd2 进入之前创建并初始化静态对象和 main 。
此程序使用语句终止后 return ，首先 sd2 销毁，然后再销毁 sd1 。 ShowData 类的析构函数将关闭与这些静态对象关联的文件。
*/


int main62() {
    sd1.Disp("hello to default device\n");
    sd2.Disp("hello to file hello.dat\n");

    return 0;
}
//另一种编写此代码的方式为，使用块范围声明 ShowData 对象，并允许在它们超出范围时将其销毁：
//int main() {
//    ShowData sd1("CON"), sd2("hello.dat");
//
//    sd1.Disp("hello to default device\n");
//    sd2.Disp("hello to file hello.dat\n");
//}