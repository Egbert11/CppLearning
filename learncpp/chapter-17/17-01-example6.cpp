// ============================================================
// 来源小节：17.1 Introduction to std::array
// 示例说明：不带初始化列表时元素被默认初始化（int 元素为不确定值）；用
//           空花括号 {} 则做值初始化（int 元素清零），应当优先使用后者。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/
// 预期输出：（无输出；注意 a 的元素值未定义，请勿读取）
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <vector>

int main()
{
    std::array<int, 5> a;   // Members default initialized (int elements are left uninitialized)
    std::array<int, 5> b{}; // Members value initialized (int elements are zero initialized) (preferred)
    std::vector<int> v(5);  // Members value initialized (int elements are zero initialized)

    [[maybe_unused]] auto checkB = b[0];   // 0
    [[maybe_unused]] auto checkV = v[0];   // 0
    [[maybe_unused]] auto checkA = a;      // 仅取地址/避免警告，切勿读取 a 的元素值

    return 0;
}
