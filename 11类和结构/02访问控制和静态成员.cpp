
class Base
{
public:
    int Print();             // �Ǿ�̬��Ա��
    static int CountOf();    // ��̬��Ա��

};

// Derived1 �� Base ����Ϊ˽�л��ࡣ
class Derived1 : private Base
{
  
};
// Derived2 �� Derived1 ����Ϊ�������ࡣ
class Derived2 : public Derived1
{
    int ShowCount();    // �Ǿ�̬��Ա��

  
};
// Ϊ Derived2 ���� Show Count ������
int Derived2::ShowCount()
{
    // ��ʽ���þ�̬��Ա���� Count Of��
 //   int cCount = Base::CountOf();     // OK.

   // ʹ��ָ����þ�̬��Ա���� Count ��
 //   cCount = this->CountOf();  // C2247. ��ת��
                               //  Derived2 * to Base * not
                               //  permitted.



    return 0;
}

/*


������ָ��Ϊ ʱ private ������Ӱ���״̬��Ա�� ���������У�������̬��Ա���ǿɷ��ʵġ� ���ǣ�ʹ��ָ�롢���û������ʻ���ĳ�Ա��Ҫת������ʱ���ٴ�Ӧ�÷��ʿ��ơ� �뿼������ʾ����

*/

/*
��ǰ��Ĵ����У����ʿ��ƽ�ֹ��ָ�� Derived2 ��ָ��ת��Ϊָ�� Base ��ָ�롣 ָ�� this ��ʽΪ ���� Derived2 * �� ��Ҫѡ�� CountOf ������ this ����ת��Ϊ���� Base * �� ������ִ�д���ת������Ϊ Base �� Derived2 ��˽�м�ӻ��ࡣ ��˽�л������͵�ת��������ָ�������������ָ���ǿɽ��ܵġ� ��ˣ����Խ� Derived1 * ���͵�ָ��ת��Ϊ Base * ���͡�

��ע�⣬��ʽ���� CountOf ��������ʹ��ָ�롢���û������ѡ���������ʾû��ת���� ��ˣ�����õ��á�

������ T �ĳ�Ա�����ѿ��Խ�ָ�� T ��ָ��ת��Ϊָ�� T ��˽��ֱ�ӻ����ָ�롣
*/

int main05010201()
{

    return 0;
}