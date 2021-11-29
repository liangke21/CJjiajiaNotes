//Lambda ���ʽ����ɲ���

//ISO C++ ��׼չʾ����Ϊ�������������ݸ� std::sort() �����ļ� lambda��

#include <algorithm>
#include <cmath>

void abssort(float* x, unsigned n) {
    std::sort(x, x + n,
        // Lambda ���ʽ��ʼ
        [](float a, float b) {
            return (std::abs(a) < std::abs(b));
        } // lambda ���ʽ����
    );
}




//https://docs.microsoft.com/zh-cn/cpp/cpp/media/lambdaexpsyntax.png?view=msvc-170
//[] �����Ӿ�(Ҳ��Ϊ c + +�淶�е� ���� ��)
//
//(float a, float b) �����б� ���п���. (Ҳ��Ϊ lambda ������)
//
//�ɱ�淶 ���п���.
//
//�쳣�淶 ���п���.
//
//β�� - �������� ���п���.
//
//lambda �塣