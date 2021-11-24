/*

��ע�⣬�� auto �ᱣ�����Ƶ������͵ĳ������͡� ���ڷ���ֵ��Ҫ����������ĳ����Ի������Ե�ת������������ʹ�� decltype(auto) �ؼ��֣��ùؼ���ʹ�� decltype �����ƶϹ��򲢱�������������Ϣ�� decltype(auto) ������������ͨ����ֵ����Ϊβ�淵��ֵ��

�����ʾ������ N3493) �еĴ��� (��������ʾ�� decltype(auto) ����������ʵ����ģ��֮ǰ��֪���ķ��������еĺ�������������ת����




template<typename F, typename Tuple = tuple<T...>, int... I>
decltype(auto) apply_(F&& f, Tuple&& args, index_sequence<I...>)
{
    return std::forward<F>(f)(std::get<I>(std::forward<Tuple>(args))...);
}

template<typename F, typename Tuple = tuple<T...>,
    typename Indices = make_index_sequence<tuple_size<Tuple>::value >>
    decltype(auto)
    apply(F&& f, Tuple&& args)
{
    return apply_(std::forward<F>(f), std::forward<Tuple>(args), Indices());
}

*/