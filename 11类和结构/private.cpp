

/*

��ע
�����Ա�б�ǰ��ʱ�� �ؼ���ָ��ֻ�ܴ���ĳ�Ա��������Ԫ������Щ private ��Ա�� ����������������һ������ָʾ�������ĩβ�����г�Ա��

�ڻ��������ǰ�棬�ؼ���ָ������Ĺ�����Ա���ܱ�����Ա�������� private ��˽�г�Ա��

���г�Ա��Ĭ�Ϸ�����˽�еġ� �ṹ�������г�Ա��Ĭ�Ϸ����ǹ����ġ�

�����Ĭ�Ϸ��ʶ�������˽�еģ������ڽṹ�ǹ����ġ� ���ϲ��ܾ��л��ࡣ

�й������Ϣ������Ŀ��ƶ����Ա�ķ����е���Ԫ���������ܱ����ͳ�Ա���ʱ�
*/


class BaseClass {
public:
    // privMem accessible from member function
    int pubFunc() { return privMem; }
private:
    int privMem;
};

class DerivedClass : public BaseClass {
public:
    void usePrivate(int i)
    {
     //   privMem = i;
    }   // C2248: priv Mem ���ɷ���
              //����������
};

class DerivedClass2 : private BaseClass {
public:
    // pub Func() �ɴ����������
    int usePublic() { return pubFunc(); }
};

int main050301() {
    BaseClass aBase;
    DerivedClass aDerived;
    DerivedClass2 aDerived2;
  //  aBase.privMem = 1;     // C2248: priv Mem ���ɷ���
  //  aDerived.privMem = 1;  // C2248: priv Mem ���ɷ���
                           //    in derived class
  //  aDerived2.pubFunc();   // C2247: pub Func() ��˽�е�
                           //    ������

    return 0;
}
