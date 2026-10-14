// ============================================================
// 来源小节：17.7 Introduction to C-style arrays
// 示例说明：不能对整个 C 风格数组赋值——赋值要求左侧是可修改的 lvalue，而
//           数组不是可修改的 lvalue；逐元素赋值则没问题。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
// 预期错误：编译错误——assignment to expression with array type。
// 备注：本文件为预期编译失败示例（-error），请勿修复。整体拷贝可用
//       std::copy，见 17-07-example16.cpp。
// ============================================================
int main()
{
    int arr[] { 1, 2, 3 };

    arr[0] = 4;        // ok: assign to a single element
    arr = { 5, 6, 7 }; // compile error: cannot assign to an entire C-style array

    return arr[0];
}
