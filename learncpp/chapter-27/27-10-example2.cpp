// 来源小节：27.10 std::move_if_noexcept
// 示例说明：改用 std::move_if_noexcept 保持强异常保证——std::pair 的移动构造函数并非 noexcept
//           （截至 C++20），因此 move_if_noexcept 返回 my_pair 的左值引用，触发拷贝而非移动；
//           拷贝不会修改源对象，异常安全，源对象 my_pair.first 仍保留 13。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdmove_if_noexcept/
// 预期输出：
//   destroying MoveClass(empty)
//   my_pair.first: MoveClass(13)
//   destroying MoveClass(13)
//   Error found: abort!
//   my_pair.first: MoveClass(13)
//   destroying MoveClass(13)

#include <iostream>
#include <utility> // For std::pair, std::make_pair, std::move, std::move_if_noexcept
#include <stdexcept> // std::runtime_error

class MoveClass
{
private:
  int* m_resource{};

public:
  MoveClass() = default;

  MoveClass(int resource)
    : m_resource{ new int{ resource } }
  {}

  // Copy constructor
  MoveClass(const MoveClass& that)
  {
    // deep copy
    if (that.m_resource != nullptr)
    {
      m_resource = new int{ *that.m_resource };
    }
  }

  // Move constructor
  MoveClass(MoveClass&& that) noexcept
    : m_resource{ that.m_resource }
  {
    that.m_resource = nullptr;
  }

  ~MoveClass()
  {
    std::cout << "destroying " << *this << '\n';

    delete m_resource;
  }

  friend std::ostream& operator<<(std::ostream& os, const MoveClass& moveClass)
  {
    os << "MoveClass(";

    if (moveClass.m_resource == nullptr)
    {
      os << "empty";
    }
    else
    {
      os << *moveClass.m_resource;
    }

    os << ')';

    return os;
  }
};


class CopyClass
{
public:
  bool m_throw{};

  CopyClass() = default;

  // Copy constructor throws an exception when copying from
  // a CopyClass object where its m_throw is 'true'
  CopyClass(const CopyClass& that)
    : m_throw{ that.m_throw }
  {
    if (m_throw)
    {
      throw std::runtime_error{ "abort!" };
    }
  }
};

int main()
{
  // We can make a std::pair without any problems:
  std::pair my_pair{ MoveClass{ 13 }, CopyClass{} };

  std::cout << "my_pair.first: " << my_pair.first << '\n';

  // But the problem arises when we try to move that pair into another pair.
  try
  {
    my_pair.second.m_throw = true; // To trigger copy constructor exception

    // The following line will throw an exception
    //std::pair moved_pair{std::move(my_pair)}; // comment out this line now
    std::pair moved_pair{std::move_if_noexcept(my_pair)}; // and uncomment this line

    std::cout << "moved pair exists\n"; // Never prints
  }
  catch (const std::exception& ex)
  {
      std::cerr << "Error found: " << ex.what() << '\n';
  }

  std::cout << "my_pair.first: " << my_pair.first << '\n';

  return 0;
}
