

struct Document {
    char* Name;
    void PrintNameOf() {}
};

class PaperbackBook : public Document {};

int main130301() {
    Document* DocLib[10];   // ʮ���ĵ��⡣
    for (int i = 0; i < 5; i++)
        DocLib[i] = new Document;
    for (int i = 5; i < 10; i++)
        DocLib[i] = new PaperbackBook;

    return 0;
}
/*
��ǰ���ʾ���У������˲�ͬ�����͡� ���ǣ�������Щ���Ͷ������� Document �࣬��˴��ڶ� Document * ����ʽת���� ��ˣ�DocLib �ǡ������б������а��������ж��󲢷�����ͬһ���ͣ������б������ͬ���͵Ķ���

���� Document �����һ�� PrintNameOf ��������������Դ�ӡ����ÿ��������ƣ��������ܻ����ĳЩ�ض����ĵ����͵���Ϣ��Book ��ҳ������HelpFile ���ֽ����ȣ���

 ��ע

ǿ��ʹ�û�����ʵ�ֺ������� PrintNameOf��ͨ�����������ơ� ���⺯�� �ṩ����������������
*/