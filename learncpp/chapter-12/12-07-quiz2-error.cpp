// ============================================================
// 来源小节：12.7 Introduction to pointers
// 示例说明：测验 2——该片段无法编译：*ptr 是 int，而 &v2 是 int*，
//           把地址赋给整数是非法的。正确写法是 ptr = &v2;
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
// !! -error：预期编译失败，勿修复。
//   预期错误：invalid conversion from 'int*' to 'int'（*ptr = &v2 一行）。
// 备注：本节代码为按原文描述忠实重建（原 Quiz 2）。
// ============================================================
int main()
{
    int v1 { 45 };
    int v2 { 55 };

    int* ptr { &v1 };

    *ptr = &v2; // error: *ptr is an int, but &v2 is an int*
    // fix: ptr = &v2;

    return 0;
}
