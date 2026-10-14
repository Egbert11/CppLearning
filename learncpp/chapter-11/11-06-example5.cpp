// 来源小节：11.6 Function templates
// 示例说明：进阶——标准库 std::max 的三参数（带 Compare）版本，说明更复杂处的模板参数命名。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-templates/
//
// 编译：g++ -std=c++20 -Wall 11-06-example5.cpp -o a
//
// 本节代码为按原文描述重建。
// 原文给出的声明为（此处按标准库实际用法演示其调用）：
//   template< class T, class Compare >
//   const T& max( const T& a, const T& b, Compare comp );
//
// 预期输出：
//   2

#include <algorithm> // for std::max
#include <iostream>

int main()
{
    int a{ 1 };
    int b{ 2 };

    // Compare 参数决定"小于"的含义；这里用等价的默认比较。
    const int& m = std::max(a, b, [](int x, int y) { return x < y; });

    std::cout << m << '\n';

    return 0;
}
