// 来源小节：27.9 Exception specifications and noexcept
// 示例说明：旧的"动态异常规范"（dynamic exception specifications）语法——用 throw 关键字列出函数
//           可能抛出的异常类型。它在 C++11 被弃用，并在 C++17/C++20 从语言中移除。
// 原文链接：https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept/
// 预期编译失败（请勿修复，此文件用于演示该语法已被移除）：
//   - 带类型列表的形式 `throw(std::out_of_range, int*)`：
//       error: ISO C++17 does not allow dynamic exception specifications
//   - 省略号形式 `throw(...)`：
//       error: ISO C++17 does not allow dynamic exception specifications
//       （并伴随 error: expected type-specifier before '...' token）
//   注意：空列表形式 `throw()` 在 g++ 的 -std=c++17/c++20 下仍被接受（等价于 noexcept(true)，
//   属于已弃用而非删除），因此不会报错。
// 编译与验证：g++ -std=c++20 -Wall 编译本文件应失败（exit 非 0）。

#include <stdexcept>

int doSomething() throw(); // does not throw exceptions
int doSomething() throw(std::out_of_range, int*); // may throw either std::out_of_range or a pointer to an integer
int doSomething() throw(...); // may throw anything
