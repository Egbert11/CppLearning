// 来源小节：9.6 Assert and static_assert
// 示例说明：编译期断言 static_assert 检查类型大小——若条件为假则编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/
//
// 编译：g++ -std=c++20 -Wall 9-06-example9-error.cpp -o a   （预期编译失败）
// 预期错误：形如 error: static assertion failed: long must be 8 bytes
//           （在 Windows / MinGW 上 sizeof(long) == 4，因此第一条 static_assert 失败；
//             在 LP64 的 64 位 Linux 上 sizeof(long) == 8，本文件反而能编译通过。）
//
// 本节代码为按原文描述重建。本文件预期编译失败，请勿"修复"。
// 说明：static_assert 是关键字，不需要任何头文件；它在 release 构建中也不会被停用。

static_assert(sizeof(long) == 8, "long must be 8 bytes");
static_assert(sizeof(int) >= 4, "int must be at least 4 bytes");

int main()
{
    return 0;
}
