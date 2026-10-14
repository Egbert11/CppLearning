// 来源小节：9.6 Assert and static_assert
// 示例说明：把断言与错误处理结合起来——先 assert(x != 0.0) 捕捉编程错误，
//           再用 if (x == 0.0) 优雅地处理这一（本不该发生的）情形。
// 原文链接：https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/
//
// 编译：g++ -std=c++20 -Wall 9-06-example11.cpp -o a
// 预期输出：0.5
// 说明：main() 只传入合法值 2.0，因此断言不会触发。若调用 getInverse(0.0)：
//       在启用断言（debug）时 assert 会触发并 std::abort；在定义了 NDEBUG（release）
//       时断言被编译掉，则走 if 分支优雅返回 0.0。
//
// 本节代码为按原文描述重建。原文给出的 if (x == 0.0) 分支体是空注释，这里补上
// 一个返回 0.0 的处理以便编译通过。

#include <cassert>  // for assert
#include <iostream>

double getInverse(double x)
{
    assert(x != 0.0); // detect the programming error while developing

    if (x == 0.0)
        return 0.0; // handle the error somehow (e.g. throw an exception)

    return 1.0 / x;
}

int main()
{
    std::cout << getInverse(2.0) << '\n'; // 0.5

    // getInverse(0.0) would trip the assert in debug builds,
    // or return the graceful 0.0 in release builds (NDEBUG defined).

    return 0;
}
