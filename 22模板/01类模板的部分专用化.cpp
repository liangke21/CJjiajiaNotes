/*
��ģ����Բ���ר�û������ɵ�������ģ�塣 �����������������£�����ר�û�����Ϊ�ض����Ͳ����Զ���ģ����룺

ģ���ж�����ͣ���ֻ��һ������Ҫר�û��� ����ǻ����������Ͳ�������ģ�塣

ģ��ֻ��һ�����ͣ���ָ�롢���á�ָ���Ա��ָ�����ָ��������Ҫר�û��� ר�û���������ָ������õ������ϵ�ģ�塣

*/



#include <stdio.h>

template <class T> struct PTS {
    enum {
        IsPointer = 0,
        IsPointerToDataMember = 0
    };
};

template <class T> struct PTS<T*> {
    enum {
        IsPointer = 1,
        IsPointerToDataMember = 0
    };
};

template <class T, class U> struct PTS<T U::*> {
    enum {
        IsPointer = 0,
        IsPointerToDataMember = 1
    };
};

struct S {};

int main220501() {
    printf_s("PTS<S>::IsPointer == %d \nPTS<S>::IsPointerToDataMember == %d\n",
        PTS<S>::IsPointer, PTS<S>::IsPointerToDataMember);//0 0
    printf_s("PTS<S*>::IsPointer == %d \nPTS<S*>::IsPointerToDataMember == %d\n"
        , PTS<S*>::IsPointer, PTS<S*>::IsPointerToDataMember);//1 0
    printf_s("PTS<int S::*>::IsPointer == %d \nPTS"
        "<int S::*>::IsPointerToDataMember == %d\n",
        PTS<int S::*>::IsPointer, PTS<int S::*>::
        IsPointerToDataMember);//0  1
    return 0;
}