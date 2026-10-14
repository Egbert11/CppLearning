// 来源小节：27.9 Exception specifications and noexcept
// 示例说明：noexcept 运算符——在表达式里使用，返回编译器认为该表达式是否会抛出异常的 true/false；
//           它在编译期求值，且并不真正求值其操作数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept/
// 预期输出：b1=true b2=false b3=false b4=true b5=true

#include <iostream>

// --- 原文示例片段 ---
void foo() {throw -1;}
void boo() {};
void goo() noexcept {};
struct S{};

constexpr bool b1{ noexcept(5 + 3) }; // true; ints are non-throwing
constexpr bool b2{ noexcept(foo()) }; // false; foo() throws an exception
constexpr bool b3{ noexcept(boo()) }; // false; boo() is implicitly noexcept(false)
constexpr bool b4{ noexcept(goo()) }; // true; goo() is explicitly noexcept(true)
constexpr bool b5{ noexcept(S{}) };   // true; a struct's default constructor is noexcept by default
// --- 原文示例片段结束 ---

// 编译期校验原文注释里给出的结论
static_assert(b1 && !b2 && !b3 && b4 && b5, "unexpected noexcept operator results");

int main()
{
    std::cout << std::boolalpha
              << "b1=" << b1 << " b2=" << b2 << " b3=" << b3
              << " b4=" << b4 << " b5=" << b5 << '\n';
    return 0;
}
