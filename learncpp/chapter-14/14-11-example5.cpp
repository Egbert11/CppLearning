// ============================================================
// 来源小节：14.11 Default constructors and default arguments
// 示例说明：类没有声明任何构造函数时，编译器隐式生成一个 public 的空体默认构造函数，
//           使对象可被值初始化。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-constructors-and-default-arguments/
// 备注：本节代码为按原文描述忠实重建（原文 Example 6 与 Example 7 合并）
//       编译器为 Foo 生成的默认构造函数等价于：
//           public:
//               Foo() {}
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 6、7）---
class Foo
{
private:
    int m_x {};
    int m_y {};

    // no declared constructors -> the compiler generates a public default constructor
public:
    int x() const { return m_x; }
    int y() const { return m_y; }
};

int main()
{
    Foo foo{}; // uses the implicit default constructor

    std::cout << foo.x() << ' ' << foo.y() << '\n';

    return 0;
}

// 预期输出：
// 0 0
