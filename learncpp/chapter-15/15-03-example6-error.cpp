// ============================================================
// 来源小节：15.3 Nested types (member types)
// 示例说明：在外层类定义之前前向声明它的嵌套类型是错误——外层类必须先
//           定义，才知道它有哪些嵌套类型。
// 原文链接：https://www.learncpp.com/cpp-tutorial/nested-types-member-types/
// 预期错误（不要修复）：
//   error: invalid use of incomplete type 'class outer'
//   （因为 outer 此时只有前向声明，是不完整类型）
// 备注：这是演示预期编译失败的示例文件，请勿修复。
//        另注：在外层类定义之后再前向声明其嵌套类型虽然合法，但纯属多余，
//             因为类定义本身已经声明了它。
// ============================================================
class outer;         // 外层类的前向声明：可以
class outer::inner1; // 错误：在外层类定义之前声明其嵌套类型

class outer
{
public:
	class inner1 {};
};

class outer::inner1; // 合法但多余：类定义中已经声明过了

int main()
{
	return 0;
}
