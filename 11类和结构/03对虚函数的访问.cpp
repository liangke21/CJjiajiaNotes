

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
    VFuncDerived vfd;             // 派生类型的对象。
    VFuncBase* pvfb = &vfd;       // 指向基类型的指针。
    VFuncDerived* pvfd = &vfd;    //指向派生类型的指针。
    int State;

    State = pvfb->GetState();     // 获取状态是公开的。
   // State = pvfd->GetState();     // C2248 预期错误； Get State 是私有的；
    return 0;
}