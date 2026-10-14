// 来源小节：7.1 Compound statements (blocks)
// 示例说明：函数体本身就是一个复合语句（块）。演示块以 { 开始、以 } 结束，块尾不需要分号。
//           （对应原文 Example 1）
// 原文链接：https://www.learncpp.com/cpp-tutorial/compound-statements-blocks/
//
// ※ 本节示例为按原文描述重建，语义与原文一致。
//   `value` 加 [[maybe_unused]] 仅为在 -Wall 下保持无警告。

int add(int x, int y)
{ // start block
    return x + y;
} // end block (no semicolon)

int main()
{ // start block

    // multiple statements
    [[maybe_unused]] int value {}; // this is initialization, not a block
    add(3, 4);

    return 0;

} // end block (no semicolon)
