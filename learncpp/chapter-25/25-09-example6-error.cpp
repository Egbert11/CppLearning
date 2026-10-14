// ---------------------------------------------------------------------------
// 来源小节：25.9 Object slicing
// 原文链接：https://www.learncpp.com/cpp-tutorial/object-slicing/
// 示例说明：不能用 std::vector<Base&>——vector 的元素必须可赋值，而引用只能
//           初始化一次，因此无法编译。这是切片问题的「不能这样绕」的例子。
// 预期错误：error: 形成指向引用的指针 / 'Base&' 不能作为 vector 的元素类型
//           （std::vector 的元素类型不能是引用）。
//           编译命令：g++ -std=c++20 -Wall 25-09-example6-error.cpp
//           该文件按设计无法编译，请勿修复。
// 原文该片段为逐字提取；这里补上最小的 Base 定义，以让报错落在
// 「vector 的元素不能是引用」这一点上（原文此片段省略了 Base 的定义）。
// ---------------------------------------------------------------------------

#include <vector>

class Base
{
public:
    virtual ~Base() = default;
};

// --- 原文示例片段 ---
int main()
{
    std::vector<Base&> v{};

    return 0;
}
