// ============================================================
// 来源小节：13.10 Passing and returning structs
// 示例说明：按值返回结构体；优先直接返回无名对象、可省略类型、可用空花括号值初始化。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-and-returning-structs/
// 备注：本节代码为按原文描述忠实重建。返回局部变量必须按值返回，否则得到悬垂引用。
// ============================================================
#include <iostream>

struct Point3d
{
    double x { 0 };
    double y { 0 };
    double z { 0 };
};

// --- 原文示例片段（原 Example 5）：先建具名局部变量再返回 ---
// Point3d getZeroPoint()
// {
//     Point3d temp { 0.0, 0.0, 0.0 };
//     return temp;
// }

// --- 原文示例片段（原 Example 7、8）：返回无名对象，省略类型，甚至用空花括号 ---
Point3d getZeroPoint()
{
    return { 0.0, 0.0, 0.0 }; // return an unnamed Point3d (the type is implied by the return type)
}

int main()
{
    Point3d zero{ getZeroPoint() };

    if (zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0)
        std::cout << "The point is zero\n";
    else
        std::cout << "The point is not zero\n";

    return 0;
}

// 预期输出：
// The point is zero
