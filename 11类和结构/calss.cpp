/*

template-spec
��ѡģ��淶�� �й���ϸ��Ϣ������� ģ�塣

class
class �ؼ��֡�

ms-decl-spec
��ѡ�洢��淶�� �й���ϸ��Ϣ������� __declspec�ؼ��֡�

���
����������������ơ� ��ǽ���Ϊ �෶Χ�ڵı����֡� ����ǿ�ѡ� ���ʡ�ԣ����������ࡣ �й���ϸ��Ϣ������� ���������͡�

base-list
���ཫ�������Ա�����ṹ�Ŀ�ѡ�б� �й���ϸ��Ϣ ������� ���ࡣ ÿ�������ṹ����ǰ�涼��һ������˵�� (������˽�С��ܱ�����) �� virtual�ؼ��֡� �й���ϸ��Ϣ������Ŀ��ƶ��� ��Ա�ķ����е� ��Ա���ʱ�

member-list
���Ա���б� �й���ϸ��Ϣ ����������Ա ������

declarators
�������б�ָ�������͵�һ������ʵ�������ơ� ��� ����������ݳ�Ա���� �������������԰�����ʼֵ�������б� public �� ��Ĭ����������ݳ�ԱΪ �Ľṹ�У�������� public �и������� �й���ϸ��Ϣ ����������� ��������


*/


// class.cpp
// compile with: /EHsc
// Example of the class keyword
// Exhibits polymorphism/virtual functions.

#include <iostream>
#include <string>
#include <string>
using namespace std;



class dog
   
{
public:
    dog()
    {
        _legs = 4;
        _bark = true;
    }

    void setDogSize(string dogSize)
    {
        _dogSize = dogSize;
    }
    virtual void setEars(string type)      // �麯��
    {
        _earType = type;
    }

private:
    string _dogSize, _earType;
    int _legs;
    bool _bark;

};

class breed : public dog
{
public:
    breed(string color, string size)
    {
        _color = color;
        setDogSize(size);
    }

    string getColor()
    {
        return _color;
    }

    //���¶����麯��
    void setEars(string length, string type)
    {
        _earLength = length;
        _earType = type;
    }

protected:
    string _color, _earLength, _earType;
};

int main0201()
{
    dog mongrel;
    breed labrador("yellow", "large");
    mongrel.setEars("pointy");
    labrador.setEars("long", "floppy");
    cout << "Cody is a " << labrador.getColor() << " labrador" << endl;  //"yellow
    return 0;
}