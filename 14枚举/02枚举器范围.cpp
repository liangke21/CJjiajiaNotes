




namespace CardGame_Scoped
{
    enum class Suit { Diamonds, Hearts, Clubs, Spades };

    void PlayCard(Suit suit)
    {
        if (suit == Suit::Clubs) // ö����������ö�������޶�
        { /*...*/
        }
    }
}

/*
ö���ṩ������������������������ʾ��һϵ��ֵ����ЩֵҲ��Ϊö������ 
��ԭʼ C �� C++ ö�������У����޶�ö����������ö�ٵ�������Χ�пɼ��� 
�����ַ�Χ��ö���У�ö�������Ʊ�����ö�����������޶��� ����ʾ����ʾ����ö��֮��Ļ������죺
*/
namespace CardGame_NonScoped2
{
    enum Suit { Diamonds, Hearts, Clubs, Spades };

    void PlayCard(Suit suit)
    {
        if (suit == Clubs) // ö�����ǿɼ��ģ������޶�
        { /*...*/
        }
    }
}


//��Ϊö���е�ÿ�����Ʒ���һ������ֵ����ֵ������ö���е�˳�����Ӧ�� Ĭ������£�Ϊ��һ��ֵ���� 0��Ϊ��һ��ֵ���� 1���Դ����ƣ����������ʽ����ö������ֵ��������ʾ��


enum Suit { Diamonds = 1, Hearts, Clubs, Spades };

//Ϊö���� Diamonds ����ֵ 1�� ����ö�������յ�ֵ����ǰһ��ö������ֵ�Ļ����ϼ�һ�����û����ʽ��ֵ���� ��ǰ���ʾ���У�Hearts ������ֵ 2��Clubs ������ֵ 3���������ơ�
//ÿ��ö����������Ϊ������������Ϊδ���ַ�Χ��) ö�ٶ���(���������б������Ψһ�����ƣ������� enum (��Χ��ö��)�������б������Ψһ������ enum �� Ϊ��Щ����ָ����ֵ������Ψһ�ġ� ���磬���һ��δ���ַ�Χ//��ö�� Suit ���������£�

   
  //  enum Suit2 { Diamonds = 5, Hearts, Clubs = 4, Spades };
//Diamonds��Hearts��Clubs �� Spades ��ֵ�ֱ��� 5��6��4 �� 5�� ��ע�⣬5 ʹ���˶�Σ������Ⲣ������Ԥ�ڣ���������ġ� �������ַ�Χ��ö����˵����Щ��������ͬ�ġ�


    //ǿ��ת������

    int account_num = 135692;
    Suit hand;
  //  hand = account_num; // error C2440: '=' : �޷��ӡ�int��ת��Ϊ��Suit��  E0077	������û�д洢�������˵����	53	IntelliSense

  // ��Ҫǿ��ת�����ܽ�ת�� int Ϊ�޶���Χ��δ���ַ�Χ��ö������ ���ǣ�����Խ����ַ�Χ��ö��������Ϊ����ֵ����������ǿ��ת����
    int account_num2 = Hearts; //OK if Hearts is in a unscoped enum
  
    /*�������ַ�ʽʹ����ʽת�����ܵ������⸱���á� ��Ҫ�������������ַ�Χ��ö����صı�̴������ַ�Χ��ö��ֵ������ǿ����ֵ�� ���ַ�Χ��ö����������ö���������ƣ���ʶ�����޶��������޷�������ʽת����������ʾ����ʾ��*/

    namespace ScopedEnumConversions
    {
        enum class Suit { Diamonds, Hearts, Clubs, Spades };

        void AttemptConversions()
        {
            Suit hand;
           // hand = Clubs; // error C2065: 'Clubs' : δ�����ı�ʶ��
            hand = Suit::Clubs; //Correct.
            int account_num = 135692;
          //  hand = account_num; // error C2440: '=' : �޷��ӡ�int��ת��Ϊ��Suit��
            hand = static_cast<Suit>(account_num); // OK, ��������һ�����󣡣���

            //account_num = Suit::Hearts; // error C2440: '=' : �޷�ת���� 'Suit' to 'int'
            account_num = static_cast<int>(Suit::Hearts); // OK
        }
    }
    /*ע�⣬hand = account_num; ���Իᵼ�¶�δ���ַ�Χ��ö�ٷ����Ĵ�����ǰ����ʾ�� ����������ʽǿ��ת��һ��ʹ�á� ���ǣ��������ַ�Χ��ö�٣�����������û����ʽǿ��ת�������������һ����� account_num = Suit::Hearts; �г���ת����*/


