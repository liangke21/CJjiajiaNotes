template <class T, class... Rest>
void f(T&& t, Rest&&... r)
{
    // ���� t
    do_something(t);

    // �������ش��� r
    if constexpr (sizeof...(r))
    {
        f(r...);
    }
    else
    {
        g(r...);
    }
}