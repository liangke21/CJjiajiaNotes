// sample.h
#pragma once  //��ȷ�������ν����ǲ��뵽���� .cpp �ļ���
#include <vector> // #����ָ��
#include <string>

namespace M  // �����ռ�����
{
    inline namespace P
    {
        //...
    }

    enum class colors : short { red, blue, purple, azure };

    const double PI = 3.14;  // const �� constexpr ����
    constexpr int MeaningOfLife{ 42 };
    constexpr int get_meaning()
    {
        static_assert(MeaningOfLife == 42, "unexpected!"); //��̬����
        return MeaningOfLife;
    }
    using vstr = std::vector<int>;  // ���ͱ���
    extern double d; // �ⲿ����

#define LOG   // �궨��

#ifdef LOG   // ��������ָ��    �ж��Ƿ�������.cpp�������δ���, ���������ͻ�������δ���
    void print_to_log();
#endif

    class my_class2   // �����ඨ�壬
    {                // ��û�з�������������

        friend class other_class;
    public:
        void do_something();   // ���ҵ� class.cpp �ж���
        inline void put_value(int i) { vals.push_back(i); } // ����ȷ��

    private:
        vstr vals;
        int i;
    };

    struct RGB
    {
        short r{ 0 };  // ��Ա��ʼ��
        short g{ 0 };
        short b{ 0 };
    };

    template <typename T>  // ģ�嶨��
    class value_store
    {
    public:
        value_store<T>() = default;
        void write_value(T val)
        {
            //... ģ���еĺ������� OK
        }
    private:
        std::vector<T> vals;
    };

    template <typename T>  // ģ������
    class value_widget;
}
