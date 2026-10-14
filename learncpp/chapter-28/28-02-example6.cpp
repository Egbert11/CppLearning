// ============================================================
// 来源小节：28.2 Input with istream（原 Example 6）
// 示例说明：连续两次调用 get(strBuf, 11)。get() 不消费换行符，
//           因此第二次调用会立刻停在那个仍然留在流里的换行符上。
// 原文链接：https://www.learncpp.com/cpp-tutorial/input-with-istream/
// 预期：输入 "Hello!"（回车结束）时，只打印一次 "Hello!" 后就结束，
//       第二次 get() 因首字符是换行符而立即停止。
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块），补上 #include <iostream>。
// ============================================================
#include <iostream>

int main()
{
    char strBuf[11]{};
    // Read up to 10 characters
    std::cin.get(strBuf, 11);
    std::cout << strBuf << '\n';

    // Read up to 10 more characters
    std::cin.get(strBuf, 11);
    std::cout << strBuf << '\n';
    return 0;
}
