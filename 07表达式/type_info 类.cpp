/*

Type_info �������������ڳ��������ɵ�������Ϣ�� ����Ķ��������Ч�洢ָ�����͵����Ƶ�ָ�롣 Type_info �໹�洢��һ���ʺ����ڱȽ����������Ƿ���Ȼ�����ı���ֵ�� ���͵ı�����������˳����δָ���ģ����ҿ����������졣

<typeinfo>�������ͷ�ļ�����ʹ�� type_info �ࡣ Type_info ��Ľӿ��ǣ�

C++

����
class type_info {
public:
    type_info(const type_info& rhs) = delete; // cannot be copied
    virtual ~type_info();
    size_t hash_code() const;
    _CRTIMP_PURE bool operator==(const type_info& rhs) const;
    type_info& operator=(const type_info& rhs) = delete; // cannot be copied
    _CRTIMP_PURE bool operator!=(const type_info& rhs) const;
    _CRTIMP_PURE int before(const type_info& rhs) const;
    size_t hash_code() const noexcept;
    _CRTIMP_PURE const char* name() const;
    _CRTIMP_PURE const char* raw_name() const;
};
����ֱ��ʵ���� type_info ��Ķ�����Ϊ����ֻ��һ��˽�и��ƹ��캯���� ����(��ʱ) type_info �����Ψһ������ʹ�� typeid ������� ���ڸ�ֵ�����Ҳ��˽�еģ���˲��ܸ��ƻ���� type_info ��Ķ���

type_info::hash_code ���������ڽ����� typeinfo ��ֵӳ�䵽����ֵ�ֲ��Ĺ�ϣ������

����� == �� != �����ڷֱ�Ƚ��Ƿ������� type_info ������ȡ�

���͵�����˳����̳й�ϵ֮��û�й����� ʹ�� type_info::before ��Ա����ȷ�����͵�����˳�� ���ܱ�֤ type_info::before �ڲ�ͬ�ĳ����ͬһ����Ĳ�ͬ�����в�����ͬ�Ľ���� ͨ�����ַ�ʽ�� type_info::before �����ڵ�ַ(&) �������

type_info::name��Ա����������һ�� const char* �� null ��β���ַ��������ַ�����ʾ�����͵��û��ɶ����ơ� ��������ָ����ڴ棬Ӧ�ôӲ�ֱ���ͷ�����

type_info::raw_name��Ա����������һ�� const char* �� null ��β���ַ��������ַ�����ʾ�������͵��������� ������ʵ�����������ε���ʽ�洢�Խ�ʡ�ռ䡣 ��ˣ��˺������ٶ�Ҫ������һ�㣬 type_info::name ��Ϊ������Ҫȡ���������ơ� �������ص��ַ��� type_info::raw_name �ڱȽ������зǳ����ã������ɶ��� �����Ҫ�û��ɶ����ַ���������� type_info::name ������


*/