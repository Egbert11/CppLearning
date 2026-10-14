// 来源小节：11.7 Function template instantiation
// 示例说明：模板中的 static 局部变量——每个实例化出的函数有自己独立的 id 副本
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-template-instantiation/
// 本节代码为按原文描述重建
// 预期输出：
// 1) 12
// 2) 13
// 1) 14.5

#include <iostream>

template <typename T>
void printIDAndValue(T value)
{
    static int id{ 0 };
    std::cout << ++id << ") " << value << '\n';
}

int main()
{
    printIDAndValue(12);  // instantiates printIDAndValue<int>,    id -> 1
    printIDAndValue(13);  // calls same printIDAndValue<int>,       id -> 2
    printIDAndValue(14.5); // instantiates printIDAndValue<double>, id -> 1 (独立的副本)

    return 0;
}
