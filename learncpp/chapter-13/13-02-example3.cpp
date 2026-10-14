// ============================================================
// 来源小节：13.2 Unscoped enumerations
// 示例说明：用类型别名 `using Color = int;` 给颜色一个可搜索的类型名，
//           但因为它本质仍是 int，依然无法强制只使用合法取值——
//           `Color eyeColor { 8 };` 语法上合法，语义上毫无意义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
using Color = int; // define a type alias named Color

// The following color values should be used for a Color
constexpr Color red { 0 };
constexpr Color green { 1 };
constexpr Color blue { 2 };

int main()
{
    [[maybe_unused]] Color appleColor { red };   // Our apple is red (represented as 0)
    [[maybe_unused]] Color shirtColor { green }; // Our shirts are green (represented as 1)
    [[maybe_unused]] Color cupColor { blue };    // Our cup is blue (represented as 2)

    // Color 只是 int 的别名，下面这行没有任何机制阻止：
    [[maybe_unused]] Color eyeColor { 8 }; // syntactically valid, semantically meaningless

    return 0;
}
