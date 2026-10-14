// 来源小节：4.2 Void
// 示例说明：不完整类型 void 不能用来定义变量 —— 本文件故意无法编译。
//           编译器报错信息形如：error: variable or field 'value' declared void
// 原文链接：https://www.learncpp.com/cpp-tutorial/void/
//
// 编译：g++ -std=c++20 -Wall 4-02-example1-error.cpp -o a   （预期编译失败）

int main()
{
    // --- 原文示例片段 ---
    void value; // won't work, variables can't be defined with incomplete type void
    // --- 原文示例片段结束 ---

    return 0;
}
