// ============================================================
// 来源小节：17.8 C-style array decay
// 示例说明：按值传递单个 int——作为"复制代价"问题的对照（原 Example 1）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-array-decay/
// 预期输出：5
// ============================================================
#include <iostream>

void print(int val)
{
    std::cout << val;
}

int main()
{
    int x { 5 };
    print(x);

    return 0;
}
