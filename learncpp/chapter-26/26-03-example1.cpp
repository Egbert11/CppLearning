// ============================================================
// 来源小节：26.3 Function template specialization（原 Example 1）
// 示例说明：一个普通的函数模板 print<T>，对任何类型都用同一套实现。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-template-specialization/
// 预期输出：
//   5
//   6.7
// 备注：代码取自原文 HTML 逐字抽取。
// ============================================================
#include <iostream>

template <typename T>
void print(const T& t)
{
    std::cout << t << '\n';
}

int main()
{
    print(5);
    print(6.7);

    return 0;
}
