// ============================================================
// 来源小节：14.4 Const class objects and const member functions
// 示例说明：类类型对象也可以被声明为 const，并且同样必须在创建时初始化
//           （这里用聚合初始化）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/const-class-objects-and-const-member-functions/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
struct Date
{
    int year {};
    int month {};
    int day {};
};

int main()
{
    [[maybe_unused]] const Date today { 2020, 10, 14 }; // const class type object

    return 0;
}
