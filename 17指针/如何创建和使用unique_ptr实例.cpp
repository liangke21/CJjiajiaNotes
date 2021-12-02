/*
һ unique_ptr ��������ָ�롣 �����ܸ��Ƶ���һ�� ����ֵ���ݸ�������Ҳ��������Ҫ�����������κ� C++ ��׼���㷨 unique_ptr ��ʹ�á� ֻ���ƶ� unique_ptr�� ����ζ�ţ��ڴ���Դ����Ȩ��ת�Ƶ���һ unique_ptr������ԭʼ unique_ptr ����ӵ�д���Դ�� ���ǽ����㽫��������Ϊ��һ�����������У���Ϊ�������Ȩ��ʹ�����߼���ø��ӡ� ��ˣ�����Ҫ�� C++ ���������ָ��ʱ����ʹ�� ���ڹ��� ʱ����ʹ�� make_unique unique_ptrunique_ptr �������� unique_ptr

��ͼ��ʾ������ unique_ptr ʵ��֮�������Ȩת����



unique_ptr �� <memory> C++ ��׼��� ��ͷ�ж��塣 ����Ч����ԭʼָ����ȫ��ͬ�������� C++ ��׼�������� �� C++ ��׼��������� ʵ���ǳ���Ч����Ϊ ���ƶ����캯������ unique_ptrunique_ptr ���Ʋ�����
*/

//ʾ�� 1 ����ʾ����ʾ��δ��� unique_ptr ʵ�����ں���֮�䴫����Щʵ����


#include <string>
#include <memory>
#include <vector>
#include <iostream>
using namespace std;

//class a {
//
//    unique_ptr<Song> SongFactory(const std::wstring& artist, const std::wstring& title)
//    {
//        // ��ʽ�ƶ��������洢����ı����С�
//        return make_unique<Song>(artist, title);
//    }
//
//    void MakeSongs()
//    {
//        // ʹ���¶��󴴽�һ���µ�Ψһ ptr��
//        auto song = make_unique<Song>(L"Mr. Children", L"Namonaki Uta");
//
//        // ʹ��Ψһ��ptr��
//        vector<wstring> titles = { song->title };
//
//        // ��ԭʼָ���һ��Ψһ�� ptr �ƶ�����һ��.
//        unique_ptr<Song> song2 = std::move(song);
//
//        // �Ӱ�ֵ���صĺ����л�ȡΨһ��ptr��
//        auto song3 = SongFactory(L"Michael Jackson", L"Beat It");
//    }
//};

//ʾ�� 2 ����ʾ����ʾ��δ��� unique_ptr ʵ������������ʹ����Щʵ����
//void SongVector()
//{
//    vector<unique_ptr<Song>> songs;
//
//    // Create a few new unique_ptr<Song> instances
//    // and add them to vector using implicit move semantics.
//    songs.push_back(make_unique<Song>(L"B'z", L"Juice"));
//    songs.push_back(make_unique<Song>(L"Namie Amuro", L"Funky Town"));
//    songs.push_back(make_unique<Song>(L"Kome Kome Club", L"Kimi ga Iru Dake de"));
//    songs.push_back(make_unique<Song>(L"Ayumi Hamasaki", L"Poker Face"));
//
//// ������ͨ���������������⸴�ơ�
//    for (const auto& song : songs)
//    {
//        wcout << L"Artist: " << song->artist << L"   Title: " << song->title << endl;
//    }
//}

//ʾ�� 3 ����ʾ����ʾ��γ�ʼ�����Ա unique_ptr��
//class MyClass
//{
//private:
//    // �ҵİ༶ӵ��Ψһ��ptr��
//    unique_ptr<ClassFactory> factory;
//public:
//
//    // ʹ�þ����๤��Ĭ�Ϲ��캯���� make unique ���г�ʼ����
//    MyClass() : factory(make_unique<ClassFactory>())
//    {
//    }
//
//    void MakeClass()
//    {
//        factory->DoSomething();
//    }
//};

// ʾ�� 4 ����ʹ�� make_unique ��������� ��������ʹ�� make_unique ��ʼ������Ԫ�ء�


int main0501() {

    // Ϊ���� 5 �����������鴴��Ψһ�� ptr��
    auto p = make_unique<int[]>(5);
    wcout << p << endl;
    wcout << &p << endl;
    wcout << "------------" << endl;
    // ��ʼ�����顣
    for (int i = 0; i <5; ++i)
    {
        p[i] = i;
        wcout << &p[i] << endl;
    }
    return  0;
}