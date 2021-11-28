#include <string>

/*

���������ͳ�Ա�����Ϊ���� �ࡣ ����������������ͳ�Աʱ��
�������Լ��Ĺ��캯��֮ǰ���ȵ��ù��캯���� ����������û��Ĭ�Ϲ��캯���ǣ�
����ʹ�ø����๹�캯���еĳ�ʼ���б� ��֮ǰ�� StorageBox ʾ���У�
����� m_label ��Ա���������͸���Ϊ�µ� Label �࣬�������û��๹�캯����
���ҽ� m_label ������λ�� StorageBox ���캯���У���ʼ����
*/

class Box {
public:
    Box(int width, int length, int height) {
        m_width = width;
        m_length = length;
        m_height = height;
    }

private:
    int m_width;
    int m_length;
    int m_height;
};



class Label {
public:
    Label(const std::string& name, const std::string& address) { m_name = name; m_address = address; }
    std::string m_name;
    std::string m_address;
};

class StorageBox : public Box {//���������ͳ�Ա�����Ϊ���� ��
public:
    StorageBox(int width, int length, int height, Label label)
        : Box(width, length, height), m_label(label) {}
private:
    Label m_label;
};

int main10011001() {
    // ����������ǩ
    Label label1{ "some_name", "some_address" };
    StorageBox sb1(1, 2, 3, label1);//����������������ͳ�Աʱ�������Լ��Ĺ��캯��֮ǰ���ȵ��ù��캯���� �����ȵ���Label
   

    // ������ʱ��ǩ
    StorageBox sb2(3, 4, 5, Label{ "another name", "another address" });//����������������ͳ�Աʱ�������Լ��Ĺ��캯��֮ǰ���ȵ��ù��캯���� �����ȵ���Label

    // ����һ����ʱ��ǩ��Ϊ��ʼ���б�
    StorageBox sb3(1, 2, 3, { "myname", "myaddress" });//����������������ͳ�Աʱ�������Լ��Ĺ��캯��֮ǰ���ȵ��ù��캯���� �����ȵ���Label

    return 0;
}