// 来源小节：3.1 Syntax and semantic errors
// 示例说明：演示“编译期语义错误”——语法合法但违反语言规则。
//           该程序含原文故意保留的错误，**故意无法编译**（这正是被演示的对象，请勿“修复”）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/syntax-and-semantic-errors/
//
// 说明：本节示例为按原文描述重建。
//
// 编译器应当报告的错误：
//   - 5 = x;      给字面量赋值（x 未声明，且不能给 5 赋值）
//   - return "hello";  字符串字面量无法转换为 int

int main()
{
    5 = x; // x not declared, and you can't assign a value to a literal 5

    return "hello"; // "hello" cannot be converted to an int
}
