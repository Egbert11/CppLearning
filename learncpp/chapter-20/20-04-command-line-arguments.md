# 20.4 Command line arguments

> 原文：https://www.learncpp.com/cpp-tutorial/command-line-arguments/

## 核心概念

- **启动时需要输入**：程序常需要输入才能工作；原文以"缩略图程序必须知道要读哪个图片文件"为例。
- **交互式提示的局限**：向用户询问文件名适合手动运行一次，但在批处理、或由另一个程序启动时就不实用了。
- **自动化场景**：给很多文件生成缩略图、或在网站上传后自动生成缩略图，都需要外部程序在启动时把文件名传进来。
- **定义**：命令行参数（command line arguments）是操作系统在程序启动时传给程序的**可选字符串参数**；程序可以用也可以忽略。
- **类比**：它们让人或程序把输入传给程序，正如函数参数把输入传给函数。
- **带参数运行**：Windows 上按名字运行可执行文件（如 `WordCount`）；Unix 上用 `./WordCount`。参数跟在可执行文件名之后，用空格分隔。
- **多个参数**：例如 `WordCount Myfile.txt Myotherfile.txt` 提供两个文件名。
- **IDE 支持**：Visual Studio 用项目属性 → "Configuration Properties" → "Debugging" → "Command Arguments"；Code::Blocks 用 "Project -> Set program's arguments"。
- **main 签名**：用 `int main(int argc, char* argv[])` 访问参数；`int main(int argc, char** argv)` 等价，但前者更受推荐。
- **argc**：整数，"argument count"；总是至少为 1，因为第一个参数是程序名。用户每多提供一个参数它就加 1。
- **argv**："argument values"（也叫 argument vectors）；是一个 C 风格数组，元素是指向 C 风格字符串的 `char` 指针，长度为 argc。
- **遍历注意**：不能用 range-based for 遍历 argv，因为"range-based for 不能作用于已退化的 C 风格数组"。
- **数字参数**：参数总以字符串传入，即使看起来是数字。要用 `std::stringstream` 和 `operator>>` 转成数字。
- **std::stringstream 行为**："std::stringstream 的行为和 std::cin 很像。"示例用 `argv[1]` 初始化它，提取一个 int，转换失败则默认取 0。
- **操作系统解析**：操作系统在程序拿到参数之前先解析命令行，对引号和反斜杠有特殊规则。
- **引号规则**：未加引号的空格会切分参数；双引号把一段字符串视为整体；用反斜杠转义引号可以包含字面引号。"其它字符可能也需要反斜杠转义，取决于你的操作系统如何解释它们。"
- **结论**：优先把必需的启动输入做成命令行参数；如果缺失就检测到并向用户询问，这样程序两种方式都能用。

## 最佳实践

本节无 Best practice / Author's note / Warning 块。

## 代码示例

- [20-04-example1.cpp](20-04-example1.cpp)：打印 argc 与 argv 全部内容。
- [20-04-example2.cpp](20-04-example2.cpp)：用 `std::stringstream` 把命令行参数转成整数，并处理缺少参数的情况。

> 原文中以"缩略图生成"和"用户输入文件名"作引入动机的片段是示意性伪代码（依赖图像库），无法构成可编译程序，故未生成本地文件。
> 本节代码为按原文描述重建（原文中的长代码块未能逐字获取）。
