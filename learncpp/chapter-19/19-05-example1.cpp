// ============================================================
// 来源小节：19.5 Void pointers
// 示例说明：用 void* + 类型标签（enum class）实现同一函数打印不同类型值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/void-pointers/
// 预期输出：
//   5
//   7.5
//   Mollie
// 备注：本节代码为按原文描述重建（原文的主示例）。
// ============================================================
#include <cassert>
#include <iostream>

enum class Type
{
    tInt, // note: we can't use "int" here because it's a keyword, so we'll use "tInt" instead
    tFloat,
    tCString
};

void printValue(void* ptr, Type type)
{
    switch (type)
    {
    case Type::tInt:
        std::cout << *static_cast<int*>(ptr) << '\n'; // cast to int pointer and perform indirection
        break;
    case Type::tFloat:
        std::cout << *static_cast<float*>(ptr) << '\n'; // cast to float pointer and perform indirection
        break;
    case Type::tCString:
        std::cout << static_cast<char*>(ptr) << '\n'; // cast to char pointer (no indirection)
        // std::cout will treat char* as a C-style string
        // if we were to perform indirection through the result, then we'd just print the single char that ptr is pointing to
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
    float fValue{ 7.5f };
    char szValue[]{ "Mollie" };

    printValue(&nValue, Type::tInt);
    printValue(&fValue, Type::tFloat);
    printValue(szValue, Type::tCString);

    return 0;
}
