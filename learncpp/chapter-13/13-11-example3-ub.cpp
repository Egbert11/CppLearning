// ============================================================
// 来源小节：13.11 Struct miscellany
// 示例说明：拥有者 vs 观察者。Owner 拷贝临时 string（安全）；Viewer 只观察它（悬垂 → 未定义行为）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/struct-miscellany/
// 备注：本节代码为按原文描述忠实重建。打印 Viewer 的 string_view 是未定义行为，
//       输出依实现而定（可能打印乱码或空行）。可用 -fsanitize=address 观察。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

// --- 原文示例片段（原 Example 3）---
std::string getName()
{
    return "Alex"; // returns a temporary std::string
}

struct Owner
{
    std::string name{}; // std::string is an owner
};

struct Viewer
{
    std::string_view name {}; // std::string_view is a viewer
};

int main()
{
    Owner o { getName() };      // getName() returns a temporary that is copied into o.name (safe)
    std::cout << "owner: " << o.name << '\n';

    Viewer v { getName() };     // the temporary is destroyed at the end of this full expression,
    std::cout << "viewer: " << v.name << '\n'; // v.name now dangles -> undefined behavior

    return 0;
}

// 预期输出（o.name 部分确定；v.name 部分依实现而定，切勿依赖）：
// owner: Alex
// viewer: <未定义行为，可能为空/乱码>
