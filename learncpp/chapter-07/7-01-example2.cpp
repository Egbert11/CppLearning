// 来源小节：7.1 Compound statements (blocks)
// 示例说明：在 main 的外层块中再嵌套一个内层块（inner/nested block）。
//           块可以嵌套在块里（函数不能嵌套在函数里）。（对应原文 Example 2）
// 原文链接：https://www.learncpp.com/cpp-tutorial/compound-statements-blocks/
//
// ※ 本节示例为按原文描述重建，语义与原文一致。
//   `value` 加 [[maybe_unused]] 仅为在 -Wall 下保持无警告。

int add(int x, int y)
{ // block
    return x + y;
} // end block

int main()
{ // outer block

    // multiple statements
    [[maybe_unused]] int value {};

    { // inner/nested block
        add(3, 4);
    } // end inner/nested block

    return 0;

} // end outer block
