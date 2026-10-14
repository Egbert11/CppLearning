// ============================================================
// 来源小节：22.2 R-value references（本节测验）
// 示例说明：原文测验——下面 A~H 八条定义中，B、E、G 三条会编译失败：
//           B: int& ref2{ 5 };     非 const 左值引用不能用右值初始化
//           E: int&& ref5{ x };    右值引用不能用左值初始化
//           G: const int&& ref7{ x }; const 右值引用同样不能用左值初始化
// 原文链接：https://www.learncpp.com/cpp-tutorial/rvalue-references/
// 预期错误：编译失败（勿修复）。典型报错：
//   error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
//   error: cannot bind rvalue reference of type 'int&&' to lvalue of type 'int'
// 备注：本节代码为按原文描述重建（原测验代码块）。
// ============================================================
int main()
{
    int x{};

    // l-value references
    int& ref1{ x }; // A (ok)
    int& ref2{ 5 }; // B (ERROR: 非 const 左值引用不能绑定右值)

    const int& ref3{ x }; // C (ok)
    const int& ref4{ 5 }; // D (ok)

    // r-value references
    int&& ref5{ x }; // E (ERROR: 右值引用不能绑定左值)
    int&& ref6{ 5 }; // F (ok)

    const int&& ref7{ x }; // G (ERROR: const 右值引用也不能绑定左值)
    const int&& ref8{ 5 }; // H (ok)

    return 0;
}
