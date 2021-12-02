










// ����ʾ���ٶ���Щ������
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct MediaAsset
{
    virtual ~MediaAsset() = default; // ʹ���̬
};

struct Song : public MediaAsset
{
    std::wstring artist;
    std::wstring title;
    Song(const std::wstring& artist_, const std::wstring& title_) :
        artist{ artist_ }, title{ title_ } {}
};

struct Photo : public MediaAsset
{
    std::wstring date;
    std::wstring location;
    std::wstring subject;
    Photo(
        const std::wstring& date_,
        const std::wstring& location_,
        const std::wstring& subject_) :
        date{ date_ }, location{ location_ }, subject{ subject_ } {}
};

using namespace std;

int main170601()
{
// ʾ�����������˳��
    // ʾ�� 1
 // ������ʹ�� make shared ������
    auto sp1 = make_shared<Song>(L"The Beatles", L"Im Happy Just to Dance With You");

// �õģ���Ч���Ե͡�
    // ע�⣺ʹ�� new ���ʽ��Ϊ���캯������
    // ��������������������������ʡ�
    shared_ptr<Song> sp2(new Song(L"Lady Gaga", L"Just Dance"));

// ����ʼ�������������ֿ�ʱ������༶��Ա��
    // ʹ�� nullptr ���г�ʼ����ʹ���ı����ͼ��ȷ��
    shared_ptr<Song> sp5(nullptr);
//�൱�ڣ�shared ptr&lt;Song&gt; sp5;
    //...
    sp5 = make_shared<Song>(L"Elton John", L"I'm Still Standing"); //����



    // Example 2  ����ʾ����ʾ��������ͳ�ʼ�������� shared_ptr �ѷ���Ķ�����й�������Ȩ�� shared_ptr ʵ���� ���� sp2 ���ѳ�ʼ���� shared_ptr��
    

    //�ø��ƹ��캯����ʼ�����������ü�����
    auto sp3(sp2);

    //ͨ����ֵ��ʼ�����������ü�����
    auto sp4 = sp2;

    //�� nullptr ��ʼ���� sp7 �ǿյġ�
    shared_ptr<Song> sp7(nullptr);

   // ����һ�������ptr��ʼ���� sp1 �� sp2
    // ����ָ������ü�����
    sp1.swap(sp2);



    // Example 3
    // ����ʹ�ø���Ԫ�ص��㷨ʱ��shared_ptr �� C++ ��׼�������к����á� 
    // �����Խ�Ԫ�ذ�װ�� shared_ptr �У�Ȼ���临�Ƶ����������У����ס��ֻҪ����Ҫ�������ڴ�ͻ�һֱ��Ч���� 
    // ����ʾ����ʾ����������ж� remove_copy_if ʵ��ʹ�� shared_ptr �㷨��
    vector<shared_ptr<Song>> v{
  make_shared<Song>(L"Bob Dylan", L"The Times They Are A Changing"),
  make_shared<Song>(L"Aretha Franklin", L"Bridge Over Troubled Water"),
  make_shared<Song>(L"Thal��a", L"Entre El Mar y Una Estrella")
    };

    vector<shared_ptr<Song>> v2;
    remove_copy_if(v.begin(), v.end(), back_inserter(v2), [](shared_ptr<Song> s)
        {
            return s->artist.compare(L"Bob Dylan") == 1; //ɾ���±�1��ֵ
        });

    for (const auto& s : v2)
    {
        wcout << s->artist << L":" << s->title << endl;
    }
    
    cout << "-------------------------"<<endl;
    // Example 4
 /*
 ������ʹ�� dynamic_pointer_cast��static_pointer_cast �� const_pointer_cast ��ת�� shared_ptr�� 
 ��Щ���������� dynamic_cast��static_cast �� const_cast �������
 ����ʾ����ʾ��β��Ի���� shared_ptr ������ÿ��Ԫ�ص��������ͣ�Ȼ����Ԫ�ز���ʾ�й����ǵ���Ϣ��
 */

    vector<shared_ptr<MediaAsset>> assets{
      make_shared<Song>(L"Himesh Reshammiya", L"Tera Surroor"),
      make_shared<Song>(L"Penaz Masani", L"Tu Dil De De"),
      make_shared<Photo>(L"2011-04-06", L"Redmond, WA", L"Soccer field at Microsoft.")
    };

    vector<shared_ptr<MediaAsset>> photos;

    copy_if(assets.begin(), assets.end(), back_inserter(photos), [](shared_ptr<MediaAsset> p) -> bool
        {
// ʹ�ö�ָ̬��ǿ��ת���������Ƿ�
            // Ԫ����һ�������ptr&lt;Photo&gt;��
            shared_ptr<Photo> temp = dynamic_pointer_cast<Photo>(p);
            return temp.get() != nullptr;
        });

    for (const auto& p : photos)
    {
// ����֪����Ƭ����ֻ����
        // ���� ptr&lt;Photo&gt; ��������ʹ�þ�̬ת����
        wcout << "Photo location: " << (static_pointer_cast<Photo>(p))->location << endl;
    }





    // Example 6

// ��ʼ������������ԭʼָ�롣
// ��ע�⣬���ǰ�����ͬ��ֵ��
    auto song1 = new Song(L"Village People", L"YMCA");
    auto song2 = new Song(L"Village People", L"YMCA");

// ������������صĹ���ptr��
    shared_ptr<Song> p1(song1);
    shared_ptr<Song> p2(song2);

    // ����صĹ��� ptr ��Զ������ȡ�
    wcout << "p1 < p2 = " << std::boolalpha << (p1 < p2) << endl;
    wcout << "p1 == p2 = " << std::boolalpha << (p1 == p2) << endl;

    // ��صĹ��� ptr ʵ��������ȵġ�
    shared_ptr<Song> p3(p2);
    wcout << "p3 == p2 = " << std::boolalpha << (p3 == p2) << endl;
    return 0;
}