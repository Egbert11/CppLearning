# 27.10 std::move_if_noexcept

> 原文：https://www.learncpp.com/cpp-tutorial/stdmove_if_noexcept/

## 核心概念

1. **承前启后**：本节结合了 `std::move`（把左值转换为右值以启用移动语义）与 `noexcept` 说明符/运算符两个概念。
2. **强异常保证**：函数被异常中断时不得泄漏内存，且程序状态不得改变。构造函数尤其应当遵守它。
3. **拷贝失败无副作用**：因为拷贝不需要修改源对象，拷贝失败时可以简单地丢弃结果。
4. **移动失败很危险**：移动会把资源的所有权从源转移到目标；若在所有权转移**之后**发生异常，源对象就被留在了被改动（受损）的状态。对于非临时对象，这破坏了源对象。
5. **失败后无法可靠地"移回去"**：要恢复资源需要一次反向移动，而它本身也可能失败。
6. **移动构造函数可能间接抛出**：即便函数体本身不抛异常，它也可能调用其它可能抛出的构造函数——例如 `std::pair` 的移动构造函数必须逐个移动各子对象。
7. **`noexcept` 移动构造函数天然满足强保证**：因为它们不可能失败，所以隐式满足强异常保证的条件。
8. **`std::move_if_noexcept()` 在移动与拷贝间抉择**：用法与 `std::move` 相同；当移动安全（存在 `noexcept` 移动构造函数）时返回右值，否则返回普通左值引用（触发拷贝）。
9. **标准库的用法**：`std::vector::resize` 在元素类型的移动构造函数为 `noexcept` 时用移动，否则用拷贝——因此 `noexcept` 移动通常让 `std::vector` 更快。
10. **仅可移动类型是例外**：当类型既有"可能抛出的移动"又"删除了拷贝"时，`std::move_if_noexcept` 会**放弃强保证而采用移动语义**——这种有条件的豁免在标准库容器类中很常见。

## 最佳实践

- **Key insight**：`std::move_if_noexcept` 会"在对象具有 `noexcept` 移动构造函数时返回可移动的右值，否则返回可拷贝的左值"；把 `noexcept` 说明符与它结合使用，就能只在强异常保证成立时使用移动语义，否则使用拷贝语义。
- **Warning**：若某类型既有"可能抛出的移动语义"又"删除了拷贝语义"（拷贝构造与拷贝赋值不可用），`std::move_if_noexcept` 会**豁免强保证并调用移动语义**。这种有条件的豁免在标准库容器类中普遍存在，因为它们频繁使用 `std::move_if_noexcept`。

## 代码示例

- [27-10-example1.cpp](27-10-example1.cpp) — 用 `std::move` 移动 `std::pair` 时，子对象的拷贝构造抛异常导致源对象 `my_pair.first` 被掏空（输出第二处 `MoveClass(empty)` 即受损证据）。
- [27-10-example2.cpp](27-10-example2.cpp) — 改用 `std::move_if_noexcept` 后触发拷贝（`std::pair` 的移动构造非 `noexcept`），源对象保持 `MoveClass(13)`，强异常保证得以保持。

> 说明：`std::pair` 的移动构造函数定义（原文用以说明问题来源的片段）示意为：
> ```cpp
> template <typename T1, typename T2>
> pair<T1,T2>::pair(pair&& old)
>   : first(std::move(old.first)),
>     second(std::move(old.second))
> {}
> ```
> 它是库实现里的成员定义写法，无法作为独立程序编译，故不生成对应的 cpp 文件；example1/2 已完整演示它带来的后果。
