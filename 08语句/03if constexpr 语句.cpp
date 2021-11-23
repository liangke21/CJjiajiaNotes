template <class T, class... Rest>
void f(T&& t, Rest&&... r)
{
    // 处理 t
    do_something(t);

    // 有条件地处理 r
    if constexpr (sizeof...(r))
    {
        f(r...);
    }
    else
    {
        g(r...);
    }
}