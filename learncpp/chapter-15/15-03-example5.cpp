// ============================================================
// 来源小节：15.3 Nested types (member types)
// 示例说明：嵌套类型可以先在外层类内前向声明，之后再定义——定义既可以
//           在外层类内部，也可以在外层类之后。
// 原文链接：https://www.learncpp.com/cpp-tutorial/nested-types-member-types/
// 预期输出：（无，仅演示语法可编译）
// 备注：本节代码为按原文描述重建。
// ============================================================
class outer
{
public:
	class inner1;    // 在外层类内前向声明嵌套类型
	class inner1 {}; // 在外层类内定义嵌套类型

	class inner2;    // 在外层类内前向声明嵌套类型
};

class outer::inner2 {}; // 在外层类之后定义嵌套类型

int main()
{
	outer::inner1 a{};
	outer::inner2 b{};
	(void)a;
	(void)b;

	return 0;
}
