// 来源小节：11.7 Function template instantiation
// 示例说明：模板的非模板参数带默认实参 print(T val, int times=1)，所有实例共享该默认值
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-template-instantiation/
// 本节代码为按原文描述重建
// 预期输出：5aaa

#include <iostream>

template <typename T>
void print(T val, int times=1)
{
    while (times--)
        std::cout << val;
}

int main()
{
    print(5);      // prints 5 once  (T = int,  times 默认 1)
    print('a', 3); // prints aaa      (T = char, times = 3)

    std::cout << '\n';

    return 0;
}
