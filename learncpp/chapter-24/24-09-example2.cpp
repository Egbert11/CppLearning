// ============================================================
// 来源小节：24.9 Multiple inheritance（原 Example 2）
// 示例说明：混入（mixin）示例。Box、Label、Tooltip 各自提供一小块功能，Button
//           同时继承三者。因为 Label::setText 与 Tooltip::setText 原型相同，
//           调用时必须显式加作用域前缀，否则会产生歧义编译错误。
// 原文链接：https://www.learncpp.com/cpp-tutorial/multiple-inheritance/
// 预期输出：
//   (label text not readable externally; see comments)
//   本示例主要用于展示语法，未对外输出。
// 备注：本节代码为按原文描述重建（h/t 读者 Waldo）。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

struct Point2D
{
    int x{};
    int y{};
};

class Box // mixin Box class
{
public:
    void setTopLeft(Point2D point) { m_topLeft = point; }
    void setBottomRight(Point2D point) { m_bottomRight = point; }
private:
    Point2D m_topLeft{};
    Point2D m_bottomRight{};
};

class Label // mixin Label class
{
public:
    void setText(std::string_view str) { m_text = str; }
    void setFontSize(int fontSize) { m_fontSize = fontSize; }
private:
    std::string m_text{};
    int m_fontSize{};
};

class Tooltip // mixin Tooltip class
{
public:
    void setText(std::string_view str) { m_text = str; }
private:
    std::string m_text{};
};

class Button : public Box, public Label, public Tooltip {}; // Button using three mixins

int main()
{
    Button button{};
    button.Box::setTopLeft({ 1, 1 });
    button.Box::setBottomRight({ 10, 10 });
    button.Label::setText("Submit");
    button.Label::setFontSize(6);
    button.Tooltip::setText("Submit the form to the server");

    std::cout << "Button configured using three mixins.\n";

    return 0;
}
