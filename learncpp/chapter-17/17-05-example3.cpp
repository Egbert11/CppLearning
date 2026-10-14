// ============================================================
// 来源小节：17.5 Arrays of references via std::reference_wrapper
// 示例说明：std::reference_wrapper<T>（定义于 <functional>）是对 T 的可修改
//           lvalue 引用替身。注意赋值时不写 .get() 会产生歧义（编译器分不清
//           是要重绑定还是给被引用对象赋值），故用 arr[1].get() = 5；而打印
//           时它可以隐式转换为 int&，无需 .get()。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-of-references-via-stdreference_wrapper/
// 预期输出：55
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <functional> // for std::reference_wrapper
#include <iostream>

int main()
{
    int x { 1 };
    int y { 2 };
    int z { 3 };

    std::array<std::reference_wrapper<int>, 3> arr { x, y, z };

    arr[1].get() = 5; // modify the object in array element 1

    std::cout << arr[1] << y << '\n'; // show that we modified arr[1] and y, prints 55

    return 0;
}
