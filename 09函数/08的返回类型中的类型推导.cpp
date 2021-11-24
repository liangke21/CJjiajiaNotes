/*

请注意，不 auto 会保留它推导的类型的常量类型。 对于返回值需要保留其参数的常量性或引用性的转发函数，可以使用 decltype(auto) 关键字，该关键字使用 decltype 类型推断规则并保留所有类型信息。 decltype(auto) 可用作左侧的普通返回值或作为尾随返回值。

下面的示例基于 N3493) 中的代码 (，其中显示了 decltype(auto) 用于启用在实例化模板之前不知道的返回类型中的函数参数的完美转发。




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