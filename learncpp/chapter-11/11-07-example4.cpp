// 来源小节：11.7 Function template instantiation
// 示例说明：泛型 print<T> 与专用 print(bool) 并存；bool 专用版用 boolalpha 打印 true/false
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-template-instantiation/
// 本节代码为按原文描述重建
// 预期输出：
// 1
// 1
// true

#include <iostream>

template <typename T>
void print(T x)
{
    std::cout << x << '\n';
}

void print(bool x)
{
    std::cout << std::boolalpha << x << '\n'; // print bool as true or false, not 1 or 0
}

int main()
{
    print<bool>(true); // calls print<bool>(bool) -> prints 1
    print<>(true);     // deduces print<bool>(bool) -> prints 1
    print(true);       // calls print(bool) -> prints true

    return 0;
}
