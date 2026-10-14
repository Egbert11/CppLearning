# 9.2 Code coverage

> 原文：https://www.learncpp.com/cpp-tutorial/code-coverage/

## 核心概念

- **代码覆盖率（code coverage）**：描述测试运行时，程序源码中有多大比例被实际执行到。存在多种不同的覆盖率度量，本节介绍常见的几种。
- **语句覆盖率（statement coverage）**：测试已执行到的语句所占比例。追求覆盖全部语句是值得的，但它**通常不足以确保正确性**。
- **分支覆盖率（branch coverage）**：测试已执行到的分支所占比例，且**每个可能的分支各自单独计数**。一个 `if` 有两个分支——true 一个、false 一个——即使没有 `else` 也是如此；`switch` 可能有多个分支。语句覆盖率满，分支覆盖率仍可能不满。
  - 对于 `switch`，多个 `case` 共用同一段语句体时无需逐个测试："if one works, they all should."（一个能工作，其余也应该能。）
  - 链式 `if`/`else if`/`else` 需要每个目标结果各调用一次（示例用 3 次调用，并与"18 京次"的玩笑式对比）。
- **循环覆盖率（loop coverage，"0, 1, 2 测试"）**：对任何循环，都应在迭代 **0 次、1 次、2 次**三种情况下验证其行为。如果 2 次能正常工作，更多次也应正常，因此这三种情况覆盖了所有可能（循环迭代次数不可能为负）。
- **测试不同类别的输入（categories of input）**：一个"类别"是特征相同的一组输入。给出的指导：
  - **整数**：考虑负数、零、正数；如相关，检查溢出。
  - **浮点数**：测试有精度问题的值——`0.1` / `-0.1`（略大于预期值）与 `0.7` / `-0.7`（略小于预期值）。
  - **字符串**：空串、含字母数字的串、含前导/尾随/中间空白的串，以及全空白的串。
  - **指针**：还要测试 `nullptr`（不熟悉的话不必担心）。

## 最佳实践

- **Best practice**：Aim for 100% branch coverage of your code.（力求对代码达到 100% 的分支覆盖率。）
- **Best practice**：Use the `0, 1, 2 test` to ensure your loops work correctly with different number of iterations.（用 0、1、2 测试确保循环在不同迭代次数下都正确。）
- **Best practice**：Test different categories of input values to make sure your unit handles them properly.（测试不同类别的输入值，确保你的单元能正确处理它们。）

## 代码示例

- [9-02-example1.cpp](9-02-example1.cpp)：`int foo(int x, int y)`——一次 `foo(1, 0)` 覆盖了全部语句，却只覆盖了一半分支，演示语句覆盖率与分支覆盖率的差别。
- [9-02-example2.cpp](9-02-example2.cpp)：`isLowerVowel(char c)` 的 `switch`——需要两次调用才能触达所有语句/分支。
- [9-02-example3.cpp](9-02-example3.cpp)：`compare(int x, int y)` 的 `if` / `else if` / `else` 链——需要三次调用才能完成全部分支覆盖。
- [9-02-example4.cpp](9-02-example4.cpp)：循环示例——`for (int count{ 0 }; count < timesToPrint; ++count)` 打印 `"Spam! "`，演示 0/1/2 迭代测试法。
- [9-02-quiz1.cpp](9-02-quiz1.cpp)：测验题中的 `isLowerVowel(char c, bool yIsVowel)`——`switch` 对 a/e/i/o/u 返回 `true`、对 `'y'` 返回 `yIsVowel`、默认返回 `false`，演示参数驱动的分支需要四次测试。

> 说明：本节代码为按原文描述**忠实重建**（抓取工具无法逐字返回完整代码块）。

## 测验

**测验 1**：什么是分支覆盖率？
解答：branch coverage 指已被执行到的分支所占百分比，其中"成立"与"不成立"两种情形分别计数。

**测验 2**：下面的函数需要多少次测试才能保证完整覆盖？
```cpp
bool isLowerVowel(char c, bool yIsVowel)
{
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    case 'y':
        return yIsVowel;
    default:
        return false;
    }
}
```
解答：需要 4 次测试——一次覆盖 a/e/i/o/u，一次覆盖 default 情形，以及分别针对 `('y', true)` 与 `('y', false)` 各一次。代码见 [9-02-quiz1.cpp](9-02-quiz1.cpp)。
