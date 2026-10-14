// 来源小节：21.9 Overloading the subscript operator（原文“For advanced readers”）
// 示例说明：C++23 起可用“显式对象参数”（deducing this）：this auto&& self 同时匹配
//           const 与非 const 对象，于是用单个函数即可承担两种重载。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator/
// 说明：本节代码为按原文描述重建。需要 C++23（g++ -std=c++23；本机 GCC 15 支持）。
// 预期输出：3

#include <iostream>

class IntList
{
private:
    int m_list[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

public:
    auto&& operator[](this auto&& self, int index)
    {
        return self.m_list[index];
    }
};

int main()
{
    // --- 原文示例片段 ---
    IntList list{};
    list[2] = 3;

    std::cout << list[2] << '\n'; // prints 3
    // --- 原文示例片段结束 ---

    return 0;
}
