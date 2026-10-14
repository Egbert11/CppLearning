// 来源小节：20.4 Command line arguments
// 示例说明：打印 argc 与 argv 的全部内容。
//           第一个参数总是程序自身的名字，所以 argc 至少为 1。
// 原文链接：https://www.learncpp.com/cpp-tutorial/command-line-arguments/
// 说明：本节代码为按原文描述重建。
// 运行示例（Windows）：MyArgs Myfile.txt 100
// 预期输出：
//   There are 3 arguments:
//   0 C:\MyArgs
//   1 Myfile.txt
//   2 100
// 注意：不能用 range-based for 遍历 argv，因为 range-based for 不能作用于已退化的 C 风格数组。

#include <iostream>

// --- 原文示例片段 ---
int main(int argc, char* argv[])
{
    std::cout << "There are " << argc << " arguments:\n";

    // Loop through each argument and print its number and value
    for (int count{ 0 }; count < argc; ++count)
    {
        std::cout << count << ' ' << argv[count] << '\n';
    }

    return 0;
}
// --- 原文示例片段结束 ---
