// ============================================================
// 来源小节：12.13 In and out parameters
// 示例说明：两个 print 重载（按值传 int、按 const 引用传 std::string），
//           展示形参**只**用于从调用方接收输入——即“in 参数”。
// 原文链接：https://www.learncpp.com/cpp-tutorial/in-and-out-parameters/
// 备注：本节代码为按原文描述忠实重建（原 Example 1）。
// ============================================================
#include <iostream>
#include <string>

void print(int x) // x is an in parameter
{
    std::cout << x << '\n';
}

void print(const std::string& s) // s is an in parameter
{
    std::cout << s << '\n';
}

int main()
{
    print(5);

    std::string s { "Hello, world!" };
    print(s);

    return 0;
}
