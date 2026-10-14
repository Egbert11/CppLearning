# learncpp 整理规范（所有子代理必读）

本目录是 learncpp.com 教程的中文整理笔记库。你（子代理）负责其中某一章的若干小节。**你只允许写你被指定的章节目录，绝不要动仓库里其他任何文件，也不要修改其他章节目录里已有的文件。**

## 第一步：获取小节清单

用 WebFetch 抓取 https://www.learncpp.com/ ，prompt 写成：“List every lesson in Chapter N (<章标题>) of the table of contents, with the lesson number, exact title, and full URL (href), one per line. Include the x-numbered summary/quiz lesson.”（N 换成你的章号。）按任务指定的范围处理其中对应的小节。

## 每个小节的处理流程

1. 用 WebFetch 抓取该小节 URL。提取 prompt：“Extract from this C++ tutorial lesson: (1) the exact lesson title; (2) all key concepts, definitions and rules in order, each with a 1-2 sentence explanation; (3) ALL C++ code examples VERBATIM and COMPLETE (including their comments and any expected output shown), each labeled Example 1, Example 2... with a one-line description of what it demonstrates; (4) any 'Best practice' / 'Author's note' / 'Warning' callouts. Output as markdown.”
   - 已知限制：抓取工具对长代码块有约 125 字符的逐字引用上限，常返回"代码清单 + 描述"而非完整代码。此时按清单与 learncpp 标准示例**忠实重建**完整可编译程序（语义与预期输出一致），并在 md 的代码示例节注明"本节代码为按原文描述重建"。
   - 若内容缺失，可再抓一次，prompt 只写 “List every C++ code block in this lesson verbatim, complete, in order.”
   - 若某小节两次抓取都失败，在报告中注明并跳过。

2. 写笔记 `X-YY-slug.md`（X=章号，YY=两位小节号，slug=URL 末段；x 编号的总结小节用"下一个顺延号"作 YY，md 里注明官方编号为 X.x）。md 用中文，固定结构：
   - `# X.Y 英文标题`（官方编号；总结小节写 `# X.x ...`）
   - `> 原文：<URL>`
   - `## 核心概念`（按原文顺序用中文概括，不要整段翻译）
   - `## 最佳实践`（原文 Best practice/Rule/Warning/Tip；没有则注明"本节无"）
   - `## 代码示例`（相对链接每个 cpp + 一句话说明；无代码则注明"本节无代码示例"）
   - 总结小节额外：`## 本章知识速览` + `## 测验`（题目列表，解答代码见对应 quiz cpp）

3. 写源码：每个有意义的示例一个 cpp，命名 `X-YY-exampleN.cpp`；测验解答 `X-YY-quizN.cpp`。要求：
   - 尽量是 `g++ -std=c++20 -Wall` 可编译的完整程序；补需要的 `#include`；片段包进 `main()` 并用 `// --- 原文示例片段 ---` 标出边界
   - 文件头中文注释块：来源小节、示例说明、原文链接、（如为重建）注明
   - 保留原文英文注释；演示 UB/坏实践/故意错误的输出依实现而定的，在注释里说明
   - 命名后缀约定：`-error` = 预期编译失败（文件头写明预期错误、勿修复）；`-linkerror` = 能编译但预期链接失败；`-broken` = 坏实践；`-ub` = 未定义行为演示（要能编译）；`-warning` = 预期产生警告；`-cpp23` = 需要 `g++ -std=c++23`；依赖第三方库的用 `-库名` 后缀（如 `-plog`）
   - 多文件示例（.h + 多 .cpp）放子文件夹 `X-YY-exampleN/`，内含按原文命名的文件，保证 `g++ -std=c++20 -Wall X-YY-exampleN/*.cpp` 可编译；include 用 `#include "xxx.h"`
   - 原文中"编译失败/链接失败"的教学示例：能用后缀表达的就生成文件；表达不了的（如需要两个互相冲突的文件）在 md 里专门说明，不生成不可构建的文件

## 完成后

报告：创建的 md 与 cpp 路径分列、编译验证结果（用 g++ -std=c++20 -Wall，-error/-linkerror 等按预期验证失败）、运行抽验的输出对照、遇到的问题。不要改本文件，不要更新 README.md（由主会话统一维护）。
