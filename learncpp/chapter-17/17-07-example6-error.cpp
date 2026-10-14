// ============================================================
// 来源小节：17.7 Introduction to C-style arrays
// 示例说明：C 风格数组不做类型推导——元素类型必须显式写出；CTAD 不适用
//           （它们不是类模板），auto 也无法推导元素类型。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
// 预期错误：编译错误——'squares' declared as array of 'auto'（不能推导元素类型）。
// 备注：本文件为预期编译失败示例（-error），请勿修复。
// ============================================================
int main()
{
    auto squares[5] { 1, 4, 9, 16, 25 }; // compile error: can't deduce element type

    return squares[1];
}
