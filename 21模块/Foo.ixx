export module Foo;

#define ANSWER 42
/*
�����ʾ������Ϊ ixx��Դ�ļ�����ʾһ���򵥵�ģ�鶨�塣 Visual Studio �е�ģ��ӿ��ļ���Ҫixx��չ���� �ڴ�ʾ���У��ӿ��ļ�������������������� ���ǣ������Խ����������һ�������������ļ��� (������ʾ��) ����ʾ�� ����ģ�� Foo���ָʾ���ļ�����Ϊ��ģ�����Ҫ�ӿ� �� �� export ���η� f() ָʾ�� Foo �����������ģ�鵼��ʱ���˺������ɼ��� ��ע�⣬��ģ�����������ռ� Bar ��
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