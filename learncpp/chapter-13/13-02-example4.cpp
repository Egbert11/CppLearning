// ============================================================
// 来源小节：13.2 Unscoped enumerations
// 示例说明：定义无作用域枚举 Color，并用它的枚举量初始化变量。枚举变量只能
//           用本类型的枚举量初始化，用别的值会编译失败（见文件末注释）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================

// Define a new unscoped enumeration named Color
enum Color
{
    // Here are the enumerators
    // These symbolic constants define all the possible values this type can hold
    // Each enumerator is separated by a comma, not a semicolon
    red,
    green,
    blue, // trailing comma optional but recommended
}; // the enum definition must end with a semicolon

int main()
{
    // Define a few variables of enumerated type Color
    Color apple { red };   // our apple is red
    Color shirt { green }; // our shirt is green
    Color cup { blue };    // our cup is blue

    (void)apple;
    (void)shirt;
    (void)cup;

    // 以下两行是编译错误，原文专门列出以示警告：
    // Color socks { white }; // error: white is not an enumerator of Color
    // Color hat { 2 };       // error: 2 is not an enumerator of Color

    return 0;
}
