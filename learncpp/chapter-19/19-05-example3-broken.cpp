// ============================================================
// 来源小节：19.5 Void pointers
// 示例说明：类型标签写错时编译器不会报错，但行为不可预测——
//           把 int* 当作 C 字符串打印。void 指针绕过了类型检查。
// 原文链接：https://www.learncpp.com/cpp-tutorial/void-pointers/
// 预期输出：不确定（把 int 的字节当作 char* 解释，可能打印乱码甚至越界读取）
// 备注：坏实践示例（-broken），能编译，但请勿运行/依赖其输出。
//       原文 Example 6 的演示。
// ============================================================
#include <cassert>
#include <iostream>

enum class Type
{
    tInt,
    tFloat,
    tCString
};

void printValue(void* ptr, Type type)
{
    switch (type)
    {
    case Type::tInt:
        std::cout << *static_cast<int*>(ptr) << '\n';
        break;
    case Type::tFloat:
        std::cout << *static_cast<float*>(ptr) << '\n';
        break;
    case Type::tCString:
        std::cout << static_cast<char*>(ptr) << '\n';
        break;
    default:
        std::cerr << "printValue(): invalid type provided\n";
        assert(false && "type not found");
        break;
    }
}

int main()
{
    int nValue{ 5 };

    // 类型标签与实际类型不符：编译器不会阻止你，但结果是不可预测的
    printValue(&nValue, Type::tCString);

    return 0;
}
