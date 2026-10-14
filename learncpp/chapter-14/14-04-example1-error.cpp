// ============================================================
// 来源小节：14.4 Const class objects and const member functions
// 示例说明：基本类型的 const 对象必须在创建时初始化——const int x; 未初始化
//           会编译失败；y{} 值初始化、z{5} 列表初始化都合法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/const-class-objects-and-const-member-functions/
// 备注：本节代码为按原文描述忠实重建。**预期编译失败**，文件中保留了原文
//       未初始化的那一行，请勿"修复"。
//       预期错误（g++）：uninitialized const 'x'
//       （x/y/z 未使用还可能附带 -Wunused-variable 警告。）
// ============================================================
int main()
{
    const int x;      // compile error: const variable must be initialized
    const int y{};    // ok: value initialized
    const int z{ 5 }; // ok: list initialized

    return 0;
}
