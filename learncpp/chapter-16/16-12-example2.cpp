// ============================================================
// 来源小节：16.12 std::vector<bool>
// 示例说明：一个取"第一个元素的引用"的泛型函数模板：对除 bool 之外的任何 T 都能工作。
//           因为 std::vector<bool> 对 operator[] 返回的是代理（proxy）对象而不是 bool&，
//           所以 T = bool 时 T& first = v[0] 无法编译——这正是它"不是真正容器"的体现。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-bool/
// 预期输出：（无输出）
// 备注：本节代码为按原文描述重建。原文为函数模板片段，此处补全为可编译程序。
// ============================================================
#include <vector>

template <typename T>
void foo(std::vector<T>& v)
{
    T& first = v[0]; // get a reference to the first element
    // Do something with first
    (void)first;
}

int main()
{
    std::vector<int> v { 1, 2, 3 };
    foo(v); // works for any T except bool

    // std::vector<bool> b { true, false, true };
    // foo(b); // 无法编译：v[0] 返回代理对象，不能绑定到 bool&

    return 0;
}
