/*
https://docs.microsoft.com/zh-cn/cpp/cpp/how-to-create-and-use-ccomptr-and-ccomqiptr-instances?view=msvc-170
如何创建和使用CComPtr和CComQIPtr 实例
2021/12/01
此页面有帮助吗?
在经典 Windows 编程中，库通常作为 COM 对象（更准确地说是 COM 服务器）实现。 很多 Windows 操作系统组件都作为 COM 服务器实现，因此，很多参与者以这种形式提供库。 有关 COM 的基础知识的信息，请参阅 Component Object Model (COM)。

在实例化组件对象模型 (COM) 对象时，请将接口指针存储在 COM 智能指针中，后者将使用 AddRef 和 Release 执行引用计数。 如果您使用了活动模板库 (ATL) 或 Microsoft 基础类库 (MFC)，则使用 CComPtr 智能指针。 如果没有使用 ATL 或 MFC，则使用 _com_ptr_t。 由于没有等效于 std::unique_ptr的 COM，请对单个所有者和多个所有者的情况都使用这些智能指针。 CComPtr 和 ComQIPtr 都支持具有 rvalue 引用的移动操作。

示例： CComPtr
以下示例演示如何使用 CComPtr 实例化 COM 对象并获取指向其接口的指针。 请注意， CComPtr::CoCreateInstance 成员函数用于创建 COM 对象，而不是同名的 Win32 函数。
*/

