// ============================================================
// 来源小节：12.5 Pass by lvalue reference
// 示例说明：按值传递 std::string——类类型通常复制代价高，为一个马上
//           就要销毁的副本付出昂贵拷贝是浪费。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/
// 备注：本节代码为按原文描述忠实重建（原 Example 2）。
// ============================================================
#include <iostream>
#include <string>

void printValue(std::string y)
{
    std::cout << y << '\n';
} // y is destroyed here

int main()
{
    std::string x { "Hello, world!" }; // x is a std::string

    printValue(x); // x is passed by value (copied) into parameter y (expensive)

    return 0;
}

// 预期输出：
// Hello, world!
