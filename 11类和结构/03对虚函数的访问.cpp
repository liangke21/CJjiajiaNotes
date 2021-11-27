

// access_to_virtual_functions.cpp
class VFuncBase
{
public:
    virtual int GetState() { return _state; }
protected:
    int _state;
};

class VFuncDerived : public VFuncBase
{
private:
    int GetState() { return _state; }
};

int main05010301()
{
    VFuncDerived vfd;             // �������͵Ķ���
    VFuncBase* pvfb = &vfd;       // ָ������͵�ָ�롣
    VFuncDerived* pvfd = &vfd;    //ָ���������͵�ָ�롣
    int State;

    State = pvfb->GetState();     // ��ȡ״̬�ǹ����ġ�
   // State = pvfd->GetState();     // C2248 Ԥ�ڴ��� Get State ��˽�еģ�
    return 0;
}