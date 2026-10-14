// ============================================================
// 来源小节：24.8 Hiding inherited functionality（原 Example 5，For advanced readers）
// 示例说明：Base A 的 fun() 是 public 虚函数，派生类 B 把它改为 private。直接调用
//           b.fun() 因为私有【预期编译失败】；但把 b 转换为 A& 后调用可以编译通过，
//           并在运行期分派到 B 的【私有】版本——说明访问控制在运行期不强制执行。
// 因此本文件预期编译失败（因 b.fun() 那一行），将坏行注释后才能编译看到运行结果。
// 原文链接：https://www.learncpp.com/cpp-tutorial/hiding-inherited-functionality/
// 预期错误（g++ 报错信息类似）：
//   error: 'virtual void B::fun()' is private within this context
// 预期运行输出（若注释掉 b.fun(); 那行后编译）：
//   public A::fun()
//   private B::fun()
// 备注：本节代码为按原文描述重建。此文件预期编译失败，请勿修复；编译失败源于 b.fun()。
// ============================================================
#include <iostream>

class A
{
public:
    virtual void fun()
    {
        std::cout << "public A::fun()\n";
    }
};

class B : public A
{
private:
    virtual void fun()
    {
        std::cout << "private B::fun()\n";
    }
};

int main()
{
    B b{};
    b.fun();                  // ERROR: not allowed as B::fun() is private
    static_cast<A&>(b).fun(); // okay: A::fun() is public, resolves to private B::fun() at runtime

    return 0;
}
