// ============================================================
// 来源小节：16.11 std::vector and stack behavior —— 测验 #1 解答
// 示例说明：用 push_back()/pop_back() 复现指定的栈操作序列：
//           Push 1, Push 2, Push 3, Pop, Push 4, Pop, Pop, Pop
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-and-stack-behavior/
// 预期输出：
//   (Stack: empty)
//   Push 1  (Stack: 1)
//   Push 2  (Stack: 1 2)
//   Push 3  (Stack: 1 2 3)
//   Pop     (Stack: 1 2)
//   Push 4  (Stack: 1 2 4)
//   Pop     (Stack: 1 2)
//   Pop     (Stack: 1)
//   Pop     (Stack: empty)
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

void printStackValues(const std::vector<int>& v)
{
    std::cout << "\t(Stack:";

    for (auto e : v)
        std::cout << ' ' << e;

    if (v.empty()) // if v.size == 0
        std::cout << " empty";

    std::cout << ")\n";
}

void pushAndPrint(std::vector<int>& v, int val)
{
    v.push_back(val);
    std::cout << "Push " << val;
    printStackValues(v);
}

void popAndPrint(std::vector<int>& v)
{
    v.pop_back();
    std::cout << "Pop ";
    printStackValues(v);
}

int main()
{
    std::vector<int> v {};

    printStackValues(v);

    pushAndPrint(v, 1);
    pushAndPrint(v, 2);
    pushAndPrint(v, 3);
    popAndPrint(v);
    pushAndPrint(v, 4);
    popAndPrint(v);
    popAndPrint(v);
    popAndPrint(v);

    return 0;
}
